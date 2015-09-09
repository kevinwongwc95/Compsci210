// LAB 15c: Write A Function For Cheapest Route
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <fstream>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

#include <cstdlib>

struct Vertex
{
  string name;
  
  bool isVisited;
  list<pair<int, double> > adjacentVertices;
  int prev;
  double cost;
};

struct Container // vertex container, for multiple ways to get to a vertex
{
  int vertex; // index in database array
  int prev; // index in database array
  double cost;
  
  bool operator<(const Container& v) const
  {
    return cost > v.cost;
  }
};

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Vertex>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it;
  for(int i=0; i<database.size(); i++)
  {
    database[i].prev=-1;
    database[i].cost=0;
    database[i].isVisited=false;
  }
  priority_queue<Container> x;
  Container start;
  start.cost=0;
  start.prev=-1;
  start.vertex=iStart;
  x.push(start); //push start container on priority queue
  while(x.size()!=0)
  {
    Container temp;
    temp=x.top();
    x.pop();
    int index=temp.vertex;
    if(database[index].isVisited==true)
    {
      continue;
    }
    database[index].isVisited=true;
    database[index].cost=temp.cost;
    database[index].prev=temp.prev;
    if(index==iEnd)
    {
      break;
    }
    for(it=database[index].adjacentVertices.begin();it!=database[index].adjacentVertices.end();it++)
    {
      int index2=it->first;
      double edgeCost=it->second;
      if(database[index2].isVisited==false)
      {
        Container temp2;
        temp2.cost=database[index].cost+edgeCost; //CHECK LATER
        temp2.prev=index;
        temp2.vertex=index2;
        x.push(temp2);
      }
    }
  }
  result.second=database[iEnd].cost;
  int i=iEnd;
  
  while(1)//mark
  {
    result.first.push(i);
    i=database[i].prev;
    if(i<0)
    {
      break;
    }
  }

  return result;
}

int main()
{
  // print student and program information
  cout << " LAB 15c: Write A Function For Cheapest Route b\n";
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
    string fromCity, toCity, cost;
    
    // read one edge
    getline(fin, fromCity);
    getline(fin, toCity);
    getline(fin, cost);
    fin.ignore(1000, 10); // skip the separator
    // TO DO -- code to eliminate whitespace
    fromCity.erase(remove_if(fromCity.begin(), fromCity.end(), ::isspace), fromCity.end());
    toCity.erase(remove_if(toCity.begin(), toCity.end(), ::isspace), toCity.end());
    
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
    double edgeCost = atof(cost.c_str());
    database[iFromVertex].adjacentVertices.push_back(pair<int, double>(iToVertex, edgeCost));
    database[iToVertex].adjacentVertices.push_back(pair<int, double>(iFromVertex, edgeCost));
  }
  fin.close();
  cout << "Input file processed\n\n";
  
  while (true)
  {
    string fromCity, toCity;
    cout << "\nEnter the source city [blank to exit]: ";
    getline(cin, fromCity);
    if (fromCity.length() == 0) break;
    
    // find the from city
    int iFrom;
    for (iFrom = 0; iFrom < database.size(); iFrom++)
      if (database[iFrom].name == fromCity)
        break;
    
    cout << "Enter the destination city [blank to exit]: ";
    getline(cin, toCity);
    if (toCity.length() == 0) break;
    
    // find the destination city
    int iTo;
    for (iTo = 0; iTo < database.size(); iTo++)
      if (database[iTo].name == toCity)
        break;
    
    // TO DO -- skip the next code block if no matching cites are found
    
    if ( iFrom < database.size() && iTo < database.size() )
    {
      cout << "Route";
      pair<stack<int>, double> result = getShortestRoute ( iFrom, iTo, database );
      while ( !result.first.empty() )
      {
        cout << '-' << database[result.first.top()].name;
        result.first.pop();
      }
      cout << endl << "Total edges: " << result.second;
      cout << endl;
    }
    else
    {
      if ( iFrom >= database.size() )
      {
        cout << "Source City is invalid: " << fromCity << "\n";
      }
      if ( iTo >= database.size() )
      {
        cout << "Destination City is invalid: " << toCity << "\n";
      }
    }
  }
}