// LAB 15a: Write Functions For BFS and DFS
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <string>
#include <vector>
#include <stack>
#include <iterator>
#include <algorithm>
using namespace std;

struct Vertex
{
  string name;

  bool isVisited;
  list<int> adjacentVertices;
};

queue<int> doBreadthFirstSearch(int iOriginVertex, vector<Vertex>& database)
{
  int index=0;
  queue<int> searchOrder; // return this queue of indices
  queue<int> considered;

  for(int i=0; i<database.size(); i++)
  {
    database[i].isVisited=false;
  }
  database[iOriginVertex].isVisited=true;
  searchOrder.push(iOriginVertex);
  considered.push(iOriginVertex);
  while(considered.size()!=0)
  {
    index=considered.front();
    considered.pop();
    for(list <int>::iterator it=database[index].adjacentVertices.begin();it!=database[index].adjacentVertices.end();it++)
    {
      if(database[*it].isVisited==false)
      {
        database[*it].isVisited=true;
        searchOrder.push(*it);
        considered.push(*it);
      }
    }
  }

  return searchOrder;
}

queue<int> doDepthFirstSearch(int iOriginVertex, vector<Vertex>& vertices)
{
  queue<int> searchOrder;
  stack<int> considered;
  int index=0;
  for(int i=0; i<vertices.size(); i++)
  {
    vertices[i].isVisited=false;
  }
  considered.push(iOriginVertex);
  while(considered.size()!=0)
  {
    index=considered.top();
    considered.pop();
    if(vertices[index].isVisited==false)
    {
      vertices[index].isVisited=true;
      searchOrder.push(index);
      //reverse iterator
      for(list <int>::reverse_iterator rit=vertices[index].adjacentVertices.rbegin(); rit!=vertices[index].adjacentVertices.rend();rit++)
      {
        if(vertices[*rit].isVisited==false)
        {
          considered.push(*rit);
        }
      }
    }
  }

  return searchOrder;
}

int main()
{
  // print student and program information
  cout << " LAB 15a: Write Functions For BFS and DFS b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;


  ifstream fin;
  fin.open("cities.txt");
  if (!fin.good()) throw "I/O error";

  // process the input file
  vector<Vertex> database;
  while (fin.good()) // EOF loop
  {
    string fromCity, toCity;

    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());
    toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());
    fin.ignore(1000, 10); // skip the line with distance
    fin.ignore(1000, 10); // skip the separator
    // TO DO -- code to eliminate whitespace

    // add vertices for new cities included in the edge
    int iToVertex = -1, iFromVertex = -1, i;
    for (i = 0; i < database.size(); i++) // seek "to" city
      if (database[i].name == fromCity)
        break;
    if (i == database.size()) // not in database yet
    {
      // store the vertex if it is new
      Vertex fromVertex;
      fromVertex.name = fromCity;
      database.push_back(fromVertex);
    }
    iFromVertex = i;

    for (i = 0; i < database.size(); i++) // seek "from" city
      if (database[i].name == toCity)
        break;
    if (i == database.size()) // not in vector yet
    {
      // store the vertex if it is new
      Vertex toVertex;
      toVertex.name = toCity;
      database.push_back(toVertex);
    }
    iToVertex = i;

    // store bi-directional edges
    database[iFromVertex].adjacentVertices.push_back(iToVertex);
    database[iToVertex].adjacentVertices.push_back(iFromVertex);
  }
  fin.close();
  cout << "Input file processed\n\n";

  while (true)
  {
    bool found=false;
    // get the start city for the search
    string startCity;
    cout << "\nEnter the start city [blank to exit]: ";
    getline(cin, startCity);
    if (startCity.length() == 0) break;

    // find the start city
    int i;
    for (i = 0; i < database.size(); i++)
      if (database[i].name == startCity)
      {
        found=true;
        break;
      }
    if(found==false)
    {
      cout<<"Invalid City, try again"<<endl;
      continue;
    }

    // TO DO -- skip the next code blocks if no matching city is found


    // BFS result
    cout << "BFS";
    queue<int> q = doBreadthFirstSearch(i, database);
    while(!q.empty())
    {
      cout  << '-'<< database[q.front()].name;
      q.pop();
    }
    cout << endl;

    cout << "DFS";
    q = doDepthFirstSearch(i, database);
    while(!q.empty())
    {
      cout  << '-'<< database[q.front()].name;
      q.pop();
    }
    cout << endl;;
  }
}
