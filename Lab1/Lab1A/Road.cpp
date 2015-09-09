// Lab 1A, Class Programming and Testing
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include "Road.h"

void Road::setwidth(double value)
{
    width=value;
}

void Road::setlength(double value)
{
    length=value;
}

double Road::getwidth()
{
    return width;
}

double Road::getlength()
{
    return length;
}

double Road::asphault(double value)
{
    double cubic;
    double ln =(length*5280);
    double dv = value/12;
    double xx = ln * dv;
    cubic = width * xx;
    return cubic;
}
