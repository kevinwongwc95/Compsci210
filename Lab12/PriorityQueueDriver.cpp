//LAB 12a: Write And Test A Priority Queue Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include <cassert>

#include "PriorityQueue.h"
#include "PriorityQueue.h"

int main()
{
  cout << "LAB 12a: Write And Test A Priority Queue Template b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  PriorityQueue<int> test;
  PriorityQueue<int> test2=test;
  PriorityQueue<int> test3;
  test3=test;
  
  cout<<"Enqueue numbers 16-1"<<endl;
  for(int i=16; i>0; i--)
  {
    test.enqueue(i);
  }
  
  assert(test.getSize()==16);
  if(test.getSize()==16)
  {
    cout<<"SIZE: "<<test.getSize()<<endl<<endl;
  }
  
  cout<<"dequeue once size should be 15"<<endl;
  test.dequeue();
  
  assert(test.getSize()==15);
  if(test.getSize()==15)
  {
    cout<<"SIZE: "<<test.getSize()<<endl<<endl;
  }
  
  cout<<"Dequeue 12 times, size should be 3 "<<endl; 
  for(int i=0 ;i<12; i++)
  {
    test.dequeue();
  }
  
  assert(test.getSize()==3);
  if(test.getSize()==3)
  {
    cout<<"SIZE: "<<test.getSize()<<endl<<endl;
  }
  
}
