//LAB 10a: Write And Test The ListedList Class Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include <cassert>

#include "LinkedList.h"
#include "LinkedList.h"

int main()
{
  cout << "LAB 10a: Write And Test The ListedList Class Template b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  LinkedList <int> test;
  LinkedList <int> test2;
  LinkedList <int> test3=test;
  LinkedList<int> test4;
  
  cout<<"Inserted 0-9"<<endl;
  for(int i=0; i<10; i++)
  {
    test.insert(i);
  }
  
  for(int i=0; i<10; i++)
  {
    cout<<test[i]<<endl;
  }

  cout<<test[3];
  assert(test[3]==6);
  assert(test[0]==9);
  
  int x;
  
  test.first(x);
  assert(x==9);//test if first function works right
  cout<<"Test first function, x=9"<<endl;
  
  test.getNext(x);
  assert(x==8);
  cout<<"Test next function x=8"<<endl;

  assert(test.find(x)==true);//test the find function
  cout<<"Test find function, should return true"<<endl;
  
  x=20;
  assert(test.retrieve(x)==false); //test retrieve function
  cout<<"Test retrieve 20, should return false"<<endl;
  
  x=8;
  assert(test.retrieve(x)==true);
  cout<<"Test retrieve 8, should return true"<<endl;
  
  assert(test.length()==10);
  cout<<"Test length should return 10"<<endl;
  
  assert(test.find(9)==true);
  cout<<"Test find should return true"<<endl;
  
  assert(test.replace(100));
  
  cout<<"Replace 9 with 100"<<endl;
  
  assert(test[0]==100);
  
  test.makeEmpty();
  cout<<"Emptied linked list"<<endl;
  assert(test.isEmpty()==true);
  
  for(int i=0 ;i<100; i++)
  {
    test4.insert(i);
  }
  
  for(int i=0 ;i<100; i++)
  {
    cout<<test4[i]<<endl;
  }
  
}

