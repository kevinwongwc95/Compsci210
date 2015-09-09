// Lab 2A, Writing Overloaded Operators
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include "Fraction.h"

Fraction operator+(Fraction a, Fraction b)
{
  Fraction c;
  int denom1, denom2;
  int numer1, numer2;

  denom1=a.denom;
  denom2=b.denom;
  numer1=a.numer;
  numer2=b.numer;

  numer1=numer1*denom2;
  numer2=numer2*denom1;
  denom1=denom1*denom2;
  denom2=denom1;

  c.denom=denom1;
  c.numer=numer1+numer2;

  return c;
}

Fraction operator*(Fraction a, Fraction b)
{
  Fraction c;
  int denom1, denom2;
  int numer1, numer2;

  denom1=a.denom;
  denom2=b.denom;
  numer1=a.numer;
  numer2=b.numer;

  numer1=numer1*numer2;
  denom1=denom1*denom2;

  c.numer=numer1;
  c.denom=denom1;

  return c;

}

Fraction operator*(Fraction a, int b)
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

Fraction operator*(int a, Fraction b)
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

bool operator>(Fraction a, Fraction b)
{
  int denom1, denom2;
  int numer1, numer2;

  denom1=a.denom;
  denom2=b.denom;
  numer1=a.numer;
  numer2=b.numer;

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

