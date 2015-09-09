//LAB 12b: Perform A Simple Timing Study
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream> // for cout and endl
#include <string> // for string
using namespace std;

#include <cassert> // for assert
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t
#include "PriorityQueue.h"

int main()
{
  cout << "LAB 12b: Perform A Simple Timing Study b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

  
  cout<<"Timing test for enqueue"<<endl<<endl;
  // problem setup goes here
  
  // programmer customizations go here
  int n = 6000000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  string bigOh = "O(log n)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
  const int REPS = 60000; // for timing fast operations, use REPS up to 100th of the starting n
  
  int elapsedTimeTicksNorm = 0;
  double expectedTimeTicks = 0;
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    PriorityQueue<int> test;
    for(int i=n; i>0; i--)
    {
      test.enqueue(i);
    }
    
    assert(test.getSize()==n);
    // assert that n is the size of the data structure
    //assert(a.size() == n); // or something like that...
    
    
    
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    // do something where n is the "size" of the problem
    for (int reps = 0; reps < REPS; reps++) // use any value for REPS
    {
      test.enqueue(n+1+reps);
    }
    clock_t endTime = clock();
    
    assert(test.getSize()==n+REPS);
    
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
  
  //SECOND TIMING Test **********************************************
  // problem setup goes here
  
  cout<<endl<<endl<<"Timing test for dequeue"<<endl<<endl;
  // programmer customizations go here
  n = 600000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
  const int REPS2 = 6000; // for timing fast operations, use REPS up to 100th of the starting n
  
  for (int cycle = 0; cycle < 4; cycle++, n*= 2)
  {
    PriorityQueue<int> test;
    for(int i=n; i>0; i--)
    {
      test.enqueue(i);
    }
    
    assert(test.getSize()==n);
    // assert that n is the size of the data structure
    //assert(a.size() == n); // or something like that...
    
    
    // start the timer, do something, and stop the timer
    clock_t startTime = clock();
    // do something where n is the "size" of the problem
    for (int reps = 0; reps < REPS2; reps++) // use any value for REPS
    {
      test.dequeue();
    }
    clock_t endTime = clock();
    
    int first=0;
    int second=0;
    int temp2=test.getSize();
    for(int i=0; i<temp2;i++)
    {
      first=test.dequeue();
      if(i==0)
      {
        continue;
      }
      second=first;
      assert(second>=first);
    }
    
    assert(test.getSize()==0);
    
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
