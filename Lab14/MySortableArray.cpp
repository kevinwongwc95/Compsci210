// LAB 14a: Write A Sortable Array Class Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include <cstring>

#include <cstdlib>

#include "SortableArray.h"


int main()
{
  cout << "LAB 14a: Write A Sortable Array Class Template b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  
  SortableArray<int, 1000> a;
  string buf;
  string buf2;
  int entry;
  int counter=0;
  int match;
  int search;
  int size;
  
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
  
  size=counter;
  
  for(int i=0; i<counter; i++)
  {
    cout<<a.data[i]<<", ";
  }
  cout<<endl;
  
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

  a.sort(counter);
  cout<<endl;
  
  for(int i=0; i<counter; i++)
  {
    cout<<a.data[i]<<", ";
  }
  
  cout<<endl; 
  
  while(1)
  {
    cout<<"Enter number to search for: ";
    cin>>buf;
    if(buf=="Q" || buf=="q")
    {
      break;
    }
    
    search = atoi(buf.c_str());
    match=a.bsearch(search, counter);
    cout<<"Match: "<<match<<endl;
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
