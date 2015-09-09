// Lab 3A, const And Constructors, Part 1
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef Road_h
#define Road_h

class Road
{
  
public:
  Road(double l,double w);
  void setwidth(double value);
  void setlength(double value);
  double getwidth() const;
  double getlength() const;
  double asphault(double value) const; //returns cubic feet
  
private:
  double width;
  double length;
};

#endif