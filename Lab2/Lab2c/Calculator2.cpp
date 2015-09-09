// Lab 2C, Using Templated Classes
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include <stack>

#include <cstdlib>

#include <string>


int main()
{
  
  // print student and program information
  cout << "Lab 2C, Using Templated Classes b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  
  
  string buf;
  stack <double> x;
  double input, val1, val2, result;
  
  while(1)
  {
    cout<<"ENTER:  ";
    for (stack<double> copy = x; !copy.empty(); copy.pop())
    {
      cout<<" "<<copy.top()<<" ";
    }

    cin >> buf;
    if(buf=="q"||buf=="Q")
    {
      break;
    }
    else if(buf=="+"||buf=="-"||buf=="/"||buf=="*")
    {
      if(x.empty())
      {
        cout<<"Invalid"<<endl;
        continue;
      }
      val1=x.top();
      x.pop();
      if(x.empty())
      {
        cout<<"Invalid"<<endl;
        x.push(val1);
        continue;
      }
      
      val2=x.top();
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