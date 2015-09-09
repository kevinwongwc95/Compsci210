// Lab 3B, const And Constructors, Part 2
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef Time_h
#define Time_h

class Time
{
  
public:
  Time();
  Time(int, int, int);
  void setHours(int);
  void setMinutes(int);
  void setSeconds(int);
  
  double timeInHours() const;
  double timeInMinutes() const;
  long int timeInSeconds() const;
  
private:
  int hours;
  int minutes;
  int seconds;
  
};

#endif
