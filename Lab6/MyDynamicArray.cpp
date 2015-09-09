// Lab 6C Write Dynamic Array Class Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include "DynamicArray.h"

int main()
{
  cout << "Lab 6C, Write Dynamic Array Class Template b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Array <int> a(1000);
  string buf;
  int entry;
  int counter=0;
  int match;
  
  while(1)
  {
    cout<<"Input number: ";
    cin >> buf;
    if(buf=="Q" || buf=="q")
    {
      break;
    }
    entry = atoi(buf.c_str());
    a.data[counter]=entry;
    counter++;
  }
  
  //output loop
  for(int i=0; i<counter;i++)
  {
    cout<<a.data[i]<<", ";
  }
  
  while(1)
  {
    cout<<"Enter number to search for: ";
    cin>>buf;
    if(buf=="Q" || buf=="q")
    {
      break;
    }
    entry = atoi(buf.c_str());
    match=a.lsearch(entry);
    if(match==-1 || match>=counter)
    {
      cout<<"No match found"<<endl;
    }
    else
    {
      cout<<"index: "<<match<<endl;
    }
    
  }
  
}
