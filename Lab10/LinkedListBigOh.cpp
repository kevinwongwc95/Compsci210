//LAB 10c: Perform Performance Confirmation On The ListedList Class Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream> // for cout and endl
#include <string> // for string
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t
#include <cstdlib>

#include "LinkedList.h"

int main()
{
  
  // print student and program information
  cout << "LAB 10c: Perform Performance Confirmation On The ListedList Class Template b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  
  srand(time(0));
  rand();
  
  LinkedList <double> test;
  
  cout<<"operator[] assignment at zeroth index, O(1)"<<endl<<endl;
  
  // programmer customizations go here
  int n = 80000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(1)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 800000; // for timing fast operations, use REPS up to 100th of the starting n
  
  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    test.makeEmpty();
    for(int i=0; i<n; i++)
    {
      double x=((double) rand()/100);
      test.insert(x);
    }

    // assert that n is the size of the data structure
    //assert(a.size() == n); // or something like that...
   assert(test.length()==n);
    
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    for (int reps = 0; reps < REPS; reps++) // use any value for REPS
    {
      test[0]=10.9;
    }
    clock_t endTime = clock();
    
    // validation block -- assure that process worked
    
    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;
    
    // reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }
  
  n = 50000;
  //test assignment at end****************************
  
  cout<<endl<<endl<<"operator[] assignment at 100th index, O(1)"<<endl<<endl;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    test.makeEmpty();
    for(int i=0; i<n; i++)
    {
      double x=((double) rand()/100);
      test.insert(x);
    }

    // assert that n is the size of the data structure
    //assert(a.size() == n); // or something like that...
    assert(test.length()==n);
    
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    for (int reps = 0; reps < REPS; reps++) // use any value for REPS
    {
      test[99]=10;
    }
    clock_t endTime = clock();
    
    // validation block -- assure that process worked
    
    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;
    
    // reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }
  
  n = 50000;
  bigOh = "O(n)";
  //test assignment Iteration****************************
  
  cout<<endl<<endl<<"iteration from first to last using operator[], O(n) -- using a for-loop"<<endl<<endl;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    test.makeEmpty();
    for(int i=0; i<n; i++)
    {
      double x=((double) rand()/100);
      test.insert(x);
    }

    // assert that n is the size of the data structure
    //assert(a.size() == n); // or something like that...
    assert(test.length()==n);
    
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    for (int i = 0; i < test.length(); i++) // use any value for REPS
    {
      test[i];
    }
    clock_t endTime = clock();
    
    // validation block -- assure that process worked
    
    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;
    
    // reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }
  
  cout<<endl<<endl<<"length, O(1)"<<endl<<endl;
  n = 50000;
  bigOh = "O(1)";
  
  
  //test length ****************************
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    test.makeEmpty();
    for(int i=0; i<n; i++)
    {
      double x=((double) rand()/100);
      test.insert(x);
    }

    assert(test.length()==n);
    // assert that n is the size of the data structure
    //assert(a.size() == n); // or something like that...
    
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    for (int reps = 0; reps < REPS; reps++) // use any value for REPS
    {
      test.length();
    }
    clock_t endTime = clock();
    
    // validation block -- assure that process worked
    
    // compute timing results
    long elapsedTimeTicks = (long)(endTime - startTime);
    double factor = pow(2.0, cycle);
    if (cycle == 0)
      elapsedTimeTicksNorm = elapsedTimeTicks;
    else if (bigOh == "O(1)")
      expectedTimeTicks = elapsedTimeTicksNorm;
    else if (bigOh == "O(log n)")
      expectedTimeTicks = log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n)")
      expectedTimeTicks = factor * elapsedTimeTicksNorm;
    else if (bigOh == "O(n log n)")
      expectedTimeTicks = factor * log(double(n)) / log(n / factor) * elapsedTimeTicksNorm;
    else if (bigOh == "O(n squared)")
      expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;
    
    // reporting block
    cout << elapsedTimeTicks;;
    if (cycle == 0) cout << " (expected " << bigOh << ')';
    else cout << " (expected " << expectedTimeTicks << ')';
    cout << " for n=" << n << endl;
  }
  
}