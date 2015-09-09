// Lab 3B, const And Constructors, Part 2
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include "Time.h"

Time::Time()
{
}

Time::Time(int h, int m, int s)
{
  hours=h;
  minutes=m;
  seconds=s;
}

void Time::setHours(int val)
{
  hours=val;
}

void Time::setMinutes(int val)
{
  minutes=val;
}

void Time::setSeconds(int val)
{
  seconds=val;
}

double Time::timeInHours() const
{
  double val;
  val=hours*3600;
  val=val+(minutes*60);
  val=val+seconds;
  val=val/3600;
  return val;
}

double Time::timeInMinutes() const
{
  double val;
  val=hours*3600;
  val=val+(minutes*60);
  val=val+seconds;
  val=val/60;
  return val;
}

long int Time::timeInSeconds() const
{
  long int val;
  val=hours*3600;
  val=val+(minutes*60);
  val=val+seconds;
  return val;
}
