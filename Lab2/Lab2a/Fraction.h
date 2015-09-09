// Lab 2A, Writing Overloaded Operators
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef Fraction_h
#define Fraction_h

struct Fraction
{
  int numer;
  int denom;
};

Fraction operator+(Fraction a, Fraction b);
Fraction operator*(Fraction a, Fraction b);
Fraction operator*(Fraction a, int b);
Fraction operator*(int a, Fraction b);
bool operator>(Fraction a, Fraction b);

#endif
