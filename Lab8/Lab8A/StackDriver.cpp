//Lab 8A Write And Apply A Stack Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include <cassert>

#include "Stack.h"
#include "Stack.h"

int main()
{
  Stack <int> test;
  Stack <int> copy=test;
  
  Stack<int> copy2;
  
  copy2=test;
  
  assert((test.isEmpty())==true);
  if(test.isEmpty())
  {
    cout<<"Stack empty"<<endl;
  }
  else
  {
    cout<<"Stack not empty"<<endl;
  }
  
  for(int i=0; i<65; i++)
  {
    test.push(i);
  }
  
  cout<<"Top value: 64"<<endl;
  cout<<test.peek()<<endl;
  
  assert(test.pop()==true);
  cout<<"Top value: 63"<<endl;
  
  for(int i=0; i<48;i++)
  {
    test.pop();
  }
  
  test.getcapacity();
  
  cout<<test.peek()<<endl;
  test.makeEmpty();
  assert(test.isEmpty());
  if(test.isEmpty())
  {
    cout<<"Stack empty"<<endl;
  }
  else
  {
    cout<<"Stack not empty"<<endl;
  }
  
  

}