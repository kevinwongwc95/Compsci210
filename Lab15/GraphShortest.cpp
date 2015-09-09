// LAB 15b: Write A Function For Shortest Route
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

pair<stack<int>, double> getShortestRoute(int iStart, int iEnd, vector<Vertex>& database)
{
  pair<stack<int>, double> result;
  list<pair<int, double> >::iterator it;
  list<pair<int, double> >::iterator it2;
  for(int i=0; i<database.size(); i++)
  {
    database[i].prev=-1;
    database[i].cost=0;
    database[i].isVisited=false;
  }
  queue<int> considered;//considered queue
  database[iStart].isVisited=true;
  considered.push(iStart);
  while(considered.size()!=0)
  {
    int index=considered.front();
    considered.pop();
    bool repeat=true;
    for(it=database[index].adjacentVertices.begin(); it!=database[index].adjacentVertices.end();it++)
    {
      int neighbor=it->first;
      if(database[neighbor].isVisited==false)
      {
        database[neighbor].isVisited=true;
        database[neighbor].cost=(1+(database[index].cost));
        database[neighbor].prev=index;
        considered.push(neighbor);
      }
      if(neighbor==iEnd)
      {
        for(int i=0; i<considered.size();i++)
        {
          considered.pop();
        }
        repeat=false;
        break;
      }
    }
  }
    result.second=database[iEnd].cost;
    int i=iEnd;
    while(1)
    {
      result.first.push(i);
      i=database[i].prev;
      if(i==iStart)
      {
        break;
      }
    }
  return result;
}

int main()
{
  // print student and program information
  cout << " LAB 15b: Write A Function For Shortest Route b\n";
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