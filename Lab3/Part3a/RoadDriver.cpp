// Lab 3A, const And Constructors, Part 1
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include "Road.h"
#include "Road.h"

#include <cassert>

int main()
{
  
  // print student and program information
  cout << "Lab 3A, const And Constructors, Part 1 b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  const Road r(1.1,2.2);
  
  assert(1.1==r.getlength());
  assert(2.2==r.getwidth());
  
  cout<<"Expected set length= 1.1"<<endl;
  cout<<"Actual Length:"<<r.getlength()<<endl;
  cout<<"Expected set width= 2.2"<<endl;
  cout<<"Width:"<<r.getwidth()<<endl;
  cout<<"Thickness: 5.5"<<endl;
  
  cout<<"Expected result: 5856.4"<<endl;
  cout<<"Actual result: "<<r.asphault(5.5)<<endl;
  
  double diff=r.asphault(5.5)-5856.4;
  
  assert( diff> -0.00001 && diff< 0.00001   );
  
  
  
  //object copy testing
  
  cout<<"Original Length: "<<r.getlength()<<endl;
  cout<<"Original Width: "<<r.getwidth()<<endl;
  
  const Road r2=r;
  
  cout<<"Copied Length: "<<r2.getlength()<<endl;
  cout<<"Copied Width: "<<r2.getwidth()<<endl;
  
  assert(r.getlength()==r2.getlength());
  assert(r.getwidth()==r2.getwidth());
  
  Road copy(0,0);
  
  cout<<"Original Length: "<<r.getlength()<<endl;
  cout<<"Original Width: "<<r.getwidth()<<endl;
  
  copy=r;
  
  cout<<"Copied Length: "<<copy.getlength()<<endl;
  cout<<"Copied Width: "<<copy.getwidth()<<endl;
  
  assert(r.getlength()==copy.getlength());
  assert(r.getwidth()==copy.getwidth());
  
  
}
