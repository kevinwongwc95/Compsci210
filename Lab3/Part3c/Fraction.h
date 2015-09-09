// Lab 3C, const And Constructors, Part 3
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef Fraction_h
#define Fraction_h

struct Fraction
{
  
  int numer;
  int denom;

  Fraction operator+(const Fraction &a) const;
  Fraction operator*(const Fraction &a) const;
  bool operator>(const Fraction &a) const;

};

Fraction operator*(int a,const Fraction &b);
Fraction operator*(const Fraction &a, int b);

#endif
