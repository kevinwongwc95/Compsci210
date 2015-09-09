//LAB 10b: Write And Test The ListedList Class Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include <cstring>

#include <cstdlib>

#include "LinkedList.h"


int main()
{
  cout << "LAB 10b: Write And Test The ListedList Class Template b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  
  LinkedList <int> a;
  string buf;
  int entry;
  int counter=0;
  int x;
  
  while(1)
  {
    cout<<"Input number: ";
    cin >> buf;
    if(buf=="Q" || buf=="q")
    {
      break;
    }
    entry = atoi(buf.c_str());
    a.insert(entry);
    counter++;
  }
  
  //output loop
  for(int i=0; i<counter;i++)
  {
    cout<<a[i]<<", ";
  }
  while(1)
  {
    bool found=false;
    int indexCounter=0;
    cout<<endl<<"Enter number to search for: ";
    cin>>buf;
    if(buf=="Q" || buf=="q")
    {
      break;
    }
    entry = atoi(buf.c_str());
    
    for(int i=0; i<a.length(); i++)
    {
      if(i==0)
      {
        a.first(x);
        if(entry==x)
        {
          found=true;
          indexCounter=i;
          break;
        }
      }
      else(a.getNext(x));
      {
        if(entry==x)
        {
          found=true;
          indexCounter=i;
          break;
        }
      }
    }
    if(found==true)
    {
      cout<<"Index: "<<indexCounter<<endl;
    }
    else
    {
      cout<<"No match found. "<<endl;
    }
  }
}


