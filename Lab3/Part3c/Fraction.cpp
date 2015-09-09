// Lab 3C, More Class Programming And Testing Part 3
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include "Fraction.h"

Fraction Fraction::operator+(const Fraction& a) const
{
  Fraction c;
  int denom1, denom2;
  int numer1, numer2;
  
  denom1=a.denom;
  denom2=denom;
  numer1=a.numer;
  numer2=numer;
  
  numer1=numer1*denom2;
  numer2=numer2*denom1;
  denom1=denom1*denom2;
  denom2=denom1;
  
  c.denom=denom1;
  c.numer=numer1+numer2;
  
  return c;
}

Fraction Fraction::operator*(const Fraction& a) const
{
  Fraction c;
  int denom1, denom2;
  int numer1, numer2;
  
  denom1=a.denom;
  denom2=denom;
  numer1=a.numer;
  numer2=numer;
  
  numer1=numer1*numer2;
  denom1=denom1*denom2;
  
  c.numer=numer1;
  c.denom=denom1;
  
  return c;
  
}

Fraction operator*(const Fraction& a, int b)
{
  Fraction c;
  int denom1;
  int numer1, numer2;
  
  denom1=a.denom;
  numer1=a.numer;
  
  numer2=b*numer1;
  
  c.numer=numer2;
  c.denom=denom1;
  
  return c;
}

Fraction operator*(int a,const Fraction& b)
{
  Fraction c;
  int denom1;
  int numer1, numer2;
  
  denom1=b.denom;
  numer1=b.numer;
  
  numer2=a*numer1;
  
  c.numer=numer2;
  c.denom=denom1;
  
  return c;
}

bool Fraction:: operator>(const Fraction& a) const
{
  int denom1, denom2;
  int numer1, numer2;
  
  denom1=denom;
  denom2=a.denom;
  numer1=numer;
  numer2=a.numer;
  
  numer1=numer1*denom2;
  numer2=numer2*denom1;
  denom1=denom1*denom2;
  denom2=denom1;
  
  if(numer1>numer2)
  {
    return true;
  }
  
  else
  {
    return false;
  }
  
  
}
