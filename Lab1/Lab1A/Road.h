// Lab 1A, Class Programming and Testing
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef Road_h
#define Road_h

class Road
{

public:
  void setwidth(double value);
  void setlength(double value);
  double getwidth();
  double getlength();
  double asphault(double value); //returns cubic feet

private:
  double width;
  double length;
};

#endif