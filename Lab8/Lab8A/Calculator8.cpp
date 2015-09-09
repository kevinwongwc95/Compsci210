// Lab 8A Write And Apply A Stack Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include <cstdlib>

#include <string>

#include "Stack.h"


int main()
{
  
  // print student and program information
  cout << "Lab 8A Write And Apply A Stack Template b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  string buf;
  Stack <double> x;
  double input, val1, val2, result;
  
  while(1)
  {
    cout<<"ENTER:  ";
    for (Stack<double> copy = x; !copy.isEmpty(); copy.pop())
    {
      cout<<" "<<copy.peek()<<" ";
    }
    cin >> buf;
    cin.ignore();
    if(buf=="q"||buf=="Q")
    {
      break;
    }
    else if(buf=="+"||buf=="-"||buf=="/"||buf=="*")
    {
      if(x.isEmpty())
      {
        cout<<"Invalid"<<endl;
        continue;
      }
      val1=x.peek();
      x.pop();
      if(x.isEmpty())
      {
        cout<<"Invalid"<<endl;
        x.push(val1);
        continue;
      }
      
      val2=x.peek();
      x.pop();
      
      if(buf=="+")
      {
        result=val1+val2;
        x.push(result);
      }
      
      if(buf=="-")
      {
        result=val2-val1;
        x.push(result);
      }
      
      if(buf=="/")
      {
        result=val2/val1;
        x.push(result);
      }
      
      if(buf=="*")
      {
        result=val1*val2;
        x.push(result);
      }
      
    }
    
    else
    {
      input = atof(buf.c_str());
      x.push(input);
    }
  }
}