// Lab 3A, const And Constructors, Part 1
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include "Road.h"

Road::Road(double l, double w)
{
  length=l;
  width=w;
}

void Road::setwidth(double value)
{
  width=value;
}

void Road::setlength(double value)
{
  length=value;
}

double Road::getwidth() const
{
  return width;
}

double Road::getlength() const
{
  return length;
}

double Road::asphault(double value) const
{
  double cubic;
  double ln =(length*5280);
  double dv = value/12;
  double xx = ln * dv;
  cubic = width * xx;
  return cubic;
}
