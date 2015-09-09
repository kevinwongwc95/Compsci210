// Lab 1B, More Class Programming And Testing
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include "Time.h"

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

double Time::timeInHours()
{
  double val;
  val=hours*3600;
  val=val+(minutes*60);
  val=val+seconds;
  val=val/3600;
  return val;
  
}


double Time::timeInMinutes()
{
  double val;
  val=hours*3600;
  val=val+(minutes*60);
  val=val+seconds;
  val=val/60;
  return val;
}

long int Time::timeInSeconds()
{
  long int val;
  val=hours*3600;
  val=val+(minutes*60);
  val=val+seconds;
  return val;

}