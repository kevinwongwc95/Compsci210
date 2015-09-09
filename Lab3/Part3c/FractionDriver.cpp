// Lab 2A, Writing Overloaded Operators
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include "Fraction.h"
#include "Fraction.h"

#include <cassert>

int main()
{

  // print student and program information
  cout << "Lab 2A, Writing Overloaded Operators b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Fraction c, d, result;
  c.numer=3;
  c.denom=4;
  d.numer=5;
  d.denom=6;

  Fraction e=c;

  assert(c.numer=e.numer);
  assert(c.denom=e.denom);

  Fraction f;
  f=c;

  assert(c.numer==f.numer);
  assert(c.denom==f.denom);

  cout<<"C is: "<<c.numer<<"/"<<c.denom<<endl;
  cout<<"D is: "<<d.numer<<"/"<<d.denom<<endl;

  result=c*d;
  cout<<"Expected result c*d=15/24"<<endl;
  cout<<"Fractionc*d= "<<result.numer<<"/"<<result.denom<<endl;
  assert(result.numer==15);
  assert(result.denom=24);
  result=c*3;
  cout<<"Expected result c*3=9/4"<<endl;
  cout<<"Fraction c*3= "<<result.numer<<"/"<<result.denom<<endl;
  assert(result.numer==9);
  assert(result.denom=4);
  result=4*d;
  cout<<"Expected result 4*d=20/6"<<endl;
  cout<<"Fraction 4*d= "<<result.numer<<"/"<<result.denom<<endl;
  assert(result.numer==20);
  assert(result.denom=6);
  result=c+d;
  cout<<"Expected result c+d "<<"38/24"<<endl;
  cout<<"Fraction c+d= "<<result.numer<<"/"<<result.denom<<endl;
  assert(result.numer==38);
  assert(result.denom=24);

  cout<<"Expected result of comparison is: c isn't greater than d"<<endl;
  cout<<"Actual result: ";
  
  assert(c>d==0);

  if(c>d)
  {
    cout<<"c is greater than d!"<<endl;
  }
  else
  {
    cout<<"c isn't greater than d"<<endl;
  }

}
