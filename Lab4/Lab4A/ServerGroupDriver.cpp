// Lab 4A Introduction To Dynamic Arrays
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include <cassert>

#include "ServerGroup.h"

int main()
{
  cout << "Lab 4A, Introduction To Dynamic Arrays b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  ServerGroup test(3);
  cout<<"Fill server array with 3"<<endl;
  //declare const object
  const ServerGroup test2(1);
  
  
  test.serverFree();
  assert(test.serverFree()==true);
  cout<<"Found server free"<<endl;
  test.useServer(1);
  cout<<"Server in use for 1 minute"<<endl;
  test.serverFree();
  cout<<"Found server free"<<endl;
  assert(test.serverFree()==true);
  test.useServer(2);
  cout<<"Server in use for 2 minutes"<<endl;
  test.serverFree();
  assert(test.serverFree()==true);
  cout<<"Found server free"<<endl;
  test.useServer(3);
  cout<<"Server in use for 3 minutes"<<endl;
  assert(test.spServerFree()==true);
  if(test.spServerFree())
  {
    cout<<"sp server is free"<<endl;
  }
  else
  {
    cout<<"sp server isn't free"<<endl;
  }
  test.usespServer(1);
  cout<<"Sp server in use for 1 minute"<<endl;
  
  assert(test.serverFree()==false);
  if(test.serverFree())
  {
    cout<<"Servers are full"<<endl;
  }
  
  else
  {
    cout<<"At least one server is free"<<endl;
  }
  
  assert(test.spServerFree()==false);
  
  test.decServers();
  cout<<"Time decrement of 1 executed"<<endl;
  cout<<"Sp server free"<<endl;
  assert(test.spServerFree()==true);
  cout<<"At least one server free"<<endl;
  assert(test.serverFree()==true);
  cout<<"One server in use for 1 minute"<<endl;
  test.useServer(1);
  assert(test.serverFree()==false);
  
  //const testing
  test2.spServerFree();
  
}