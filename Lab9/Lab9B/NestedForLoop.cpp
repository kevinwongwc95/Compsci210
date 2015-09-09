// LAB 9b: Perform A Timing Study On Nested For-Loop Sorting
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler


#include <iostream> // for cout and endl
using namespace std;
#include <string> // for string
#include <cassert> // for assert
#include <cstdlib>
#include <cmath> // for log and pow
#include <ctime> // for clock() and clock_t

int main()
{

    // print student and program information
    cout << " LAB 9b: Perform A Timing Study On Nested For-Loop Sorting b\n";
    cout << "Programmer: Kevin Wong\n";
    cout << "Editor(s) used: Codeblocks\n";
    cout << "Compiler(s) used: GNU GCC Compiler\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
    // problem setup goes here


    // programmer customizations go here
    int n = 6000; // THE STARTING PROBLEM SIZE (MAX 250 MILLION)
//    double* array = new double [n];
    string bigOh = "O(n squared)"; // YOUR PREDICTION: O(1), O(log n), O(n), O(n log n), or O(n squared)
    const int REPS = 1; // for timing fast operations, use REPS up to 100th of the starting n

    int elapsedTimeTicksNorm = 0;
    double expectedTimeTicks = 0;
    for ( int cycle = 0; cycle < 4; cycle++, n *= 2 ) {
        // more problem setup goes here -- the stuff not timed

        // assert that n is the size of the data structure
        //assert(array.size() == n); // or something like that...

        // start the timer, do something, and stop the timer
    double* array = new double [n];
    srand(time(0));
    rand();
    for ( int i = 0; i < n; i++ )
    {
      double x=((double) rand()/100);
      array[i] = x;
    }

        // *****************************************
        clock_t startTime = clock();
        // *****************************************


        for ( int i = 0; i < n; i++ ) {
            for ( int j = i + 1; j < n; j++ ) {
//        cout<<"i="<<i<<"  j="<<j<<"  n="<<n<<endl;
                if ( array[i] > array[j] ) {
                    double temp;
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                }
            }
        }
        // do something where n is the "size" of the problem


        // *****************************************
        clock_t endTime = clock();
        // *****************************************

        for (int i = 1; i < n; i++) assert (array[i - 1] <= array[i]);

        delete [] array;

        // validation block -- assure that process worked

        // compute timing results
        long elapsedTimeTicks = ( long ) ( endTime - startTime );
        double factor = pow ( 2.0, cycle );
        if ( cycle == 0 )
            elapsedTimeTicksNorm = elapsedTimeTicks;
        else if ( bigOh == "O(1)" )
            expectedTimeTicks = elapsedTimeTicksNorm;
        else if ( bigOh == "O(log n)" )
            expectedTimeTicks = log ( double ( n ) ) / log ( n / factor ) * elapsedTimeTicksNorm;
        else if ( bigOh == "O(n)" )
            expectedTimeTicks = factor * elapsedTimeTicksNorm;
        else if ( bigOh == "O(n log n)" )
            expectedTimeTicks = factor * log ( double ( n ) ) / log ( n / factor ) * elapsedTimeTicksNorm;
        else if ( bigOh == "O(n squared)" )
            expectedTimeTicks = factor * factor * elapsedTimeTicksNorm;

        // reporting block
        cout << elapsedTimeTicks;;
        if ( cycle == 0 ) cout << " (expected " << bigOh << ')';
        else cout << " (expected " << expectedTimeTicks << ')';
        cout << " for n=" << n << endl;
    }
}
