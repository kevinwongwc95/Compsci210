// Lab 1B, More Class Programming And Testing
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef Time_h
#define Time_h

class Time
{
  
public:
  void setHours(int);
  void setMinutes(int);
  void setSeconds(int);
  
  double timeInHours();
  double timeInMinutes();
  long int timeInSeconds();
  
private:
  int hours;
  int minutes;
  int seconds;
  
};



#endif
