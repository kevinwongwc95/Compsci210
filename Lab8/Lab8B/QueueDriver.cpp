// Lab 8B Write And Test A Queue Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler


#include <iostream>
using namespace std;

#include <cassert>

#include "Queue.h"

int main()
{
  // print student and program information
  cout << "Lab 8B Write And Test A Queue Template b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  
  Queue <int> test;
  Queue <int> copy=test;
  
  Queue <int> copy2;
  copy2=test;
  
  test.getinfo();
  
  assert(test.isEmpty()==true);
  if(test.isEmpty())
  {
    cout<<"Queue empty"<<endl;
  }
  else
  {
    cout<<"Queue not empty"<<endl;
  }

  for(int i=1; i<101; i++)
  {
    test.push(i);
  }
  
  test.getinfo();
  
  assert(test.peek()==1);
  cout<<"Top value: 1"<<endl;
  cout<<"Actual: "<<test.peek()<<endl;
  
  assert(test.pop()==true);
  cout<<"Top value: 2"<<endl;
  assert(test.peek()==2);
  cout<<"Actual: "<<test.peek()<<endl;
  
  for(int i=0; i<96;i++)
  {
    test.pop();
  }
  
  test.getinfo();
  
  cout<<test.peek()<<endl;
  test.makeEmpty();
  assert(test.isEmpty());
  if(test.isEmpty())
  {
    cout<<"Queue empty"<<endl;
  }
  else
  {
    cout<<"Queue not empty"<<endl;
  }
  
}