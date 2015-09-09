// Lab 1B, More Class Programming And Testing
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
  Time test; 
  test.setHours(1);
  test.setMinutes(40);
  test.setSeconds(30);
  
  // print student and program information
  cout << "Lab 1B, More Class Programming and Testing b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  
  cout<<"Expected Hours= 1.675"<<endl;
  cout<<"Actual Hours= "<<test.timeInHours()<<endl;
  cout<<"Expected Minutes= 100.5"<<endl;
  cout<<"Actual Minutes= "<<test.timeInMinutes()<<endl;
  cout<<"Expected Seconds= 6030"<<endl;
  cout<<"Actual Seconds= "<<test.timeInSeconds()<<endl;
  
  double diff;
  diff=test.timeInHours()-1.675;
  assert(diff> -0.00001 && diff< 0.00001);
  diff=test.timeInMinutes()-100.5;
  assert(diff> -0.00001 && diff< 0.00001);
  diff=test.timeInSeconds()-6030;
  assert(diff> -0.00001 && diff< 0.00001);

  Time test2=test;
  
  assert(test2.timeInSeconds()==test.timeInSeconds());
  assert(test2.timeInMinutes()==test.timeInMinutes());
  assert(test2.timeInHours()==test.timeInHours());
  
  Time test3;
  test3=test;
  
  assert(test3.timeInSeconds()==test.timeInSeconds());
  assert(test3.timeInMinutes()==test.timeInMinutes());
  assert(test3.timeInHours()==test.timeInHours());
  
}
