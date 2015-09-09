// Lab 3B, const And Constructors, Part 2
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include "Time.h"
#include "Time.h"

#include <cassert>

int main ()
{
  const Time test(1,40,30);
  
  // print student and program information
  cout << "Lab 3B, const and Constructors Part 2 b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  cout<<"Expeted Hours= 1"<<endl;
  cout<<"Expected Minutes=40"<<endl;
  cout<<"Expected Seconds=30"<<endl;
  
  cout<<"Expected Hours= 1.675"<<endl;
  cout<<"Actual Hours= "<<test.timeInHours()<<endl;
  cout<<"Expected Minutes= 100.5"<<endl;
  cout<<"Actual Minutes= "<<test.timeInMinutes()<<endl;
  cout<<"Expected Seconds= 6030"<<endl;
  cout<<"Actual Seconds= "<<test.timeInSeconds()<<endl<<endl;
  
  double diff;
  diff=test.timeInHours()-1.675;
  assert(diff> -0.00001 && diff< 0.00001);
  diff=test.timeInMinutes()-100.5;
  assert(diff> -0.00001 && diff< 0.00001);
  diff=test.timeInSeconds()-6030;
  assert(diff> -0.00001 && diff< 0.00001);
  
  const Time test2=test;
  
  cout<<"Expected Hours= 1.675"<<endl;
  cout<<"Actual Hours= "<<test2.timeInHours()<<endl;
  cout<<"Expected Minutes= 100.5"<<endl;
  cout<<"Actual Minutes= "<<test2.timeInMinutes()<<endl;
  cout<<"Expected Seconds= 6030"<<endl;
  cout<<"Actual Seconds= "<<test2.timeInSeconds()<<endl<<endl;
  
  assert(test2.timeInSeconds()==test.timeInSeconds());
  assert(test2.timeInMinutes()==test.timeInMinutes());
  assert(test2.timeInHours()==test.timeInHours());
  
  Time test3;
  test3=test;
  
  cout<<"Expected Hours= 1.675"<<endl;
  cout<<"Actual Hours= "<<test3.timeInHours()<<endl;
  cout<<"Expected Minutes= 100.5"<<endl;
  cout<<"Actual Minutes= "<<test3.timeInMinutes()<<endl;
  cout<<"Expected Seconds= 6030"<<endl;
  cout<<"Actual Seconds= "<<test3.timeInSeconds()<<endl<<endl;
  
  assert(test3.timeInSeconds()==test.timeInSeconds());
  assert(test3.timeInMinutes()==test.timeInMinutes());
  assert(test3.timeInHours()==test.timeInHours());
}
