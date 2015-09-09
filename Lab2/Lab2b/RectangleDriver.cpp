// Lab 2B, Writing Templated Classes
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include "Rectangle.h"
#include "Rectangle.h"
#include "Fraction.h"

#include <cassert>

int main()
{
  // print student and program information
  cout << "Lab 2B, Writing Templated Classes b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  Rectangle <int> a;
  a.setlength(5);
  a.setwidth(6);

  Rectangle <int> c=a;

  cout<<"Expected Perimeter:22"<<endl;
  cout<<"Actual Perimeter:"<<c.perimeter()<<endl;
  cout<<"Expected Area:30"<<endl;
  cout<<"Actual Area:"<<c.area()<<endl<<endl;

  assert(22==c.perimeter());
  assert(30==c.area());

  Rectangle <int> d;
  d=a;

  cout<<"Expected Perimeter:22"<<endl;
  cout<<"Actual Perimeter:"<<d.perimeter()<<endl;
  cout<<"Expected Area:30"<<endl;
  cout<<"Actual Area:"<<d.area()<<endl<<endl;

  assert(22==d.perimeter());
  assert(30==d.area());

  Fraction test1={3,4};
  Fraction test2={4,5};

  Rectangle<Fraction> b;
  b.setlength(test1);
  b.setwidth(test2);

  Fraction temp1=b.area();
  cout<<"Expected Area is= 12/20"<<endl;
  cout<<"Actual Area is= "<<temp1.numer<<"/"<<temp1.denom<<endl;
  assert(temp1.numer==12);
  assert(temp1.denom==20);
  temp1=b.perimeter();
  cout<<"Expected Perimeter is= 62/20"<<endl;
  cout<<"Perimeter is ="<<temp1.numer<<"/"<<temp1.denom<<endl;
  assert(temp1.numer==62);
  assert(temp1.denom==20);

  Fraction temp;
  temp=b.area();
  cout<<"Expected Area is= 12/20"<<endl;
  cout<<"Actual Area is= "<<temp.numer<<"/"<<temp.denom<<endl;
  assert(temp.numer==12);
  assert(temp.denom==20);
  temp=b.perimeter();
  cout<<"Expected Perimeter is= 62/20"<<endl;
  cout<<"Perimeter is ="<<temp.numer<<"/"<<temp.denom<<endl;
  assert(temp.numer==62);
  assert(temp.denom==20);

}
