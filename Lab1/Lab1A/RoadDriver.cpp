// Lab 1A, Class Programming and Testing
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include "Road.h"
#include "Road.h"

#include <cassert>

int main()
{

    // print student and program information
    cout << "Lab 1A, Class Programming and Testing b\n";
    cout << "Programmer: Kevin Wong\n";
    cout << "Editor(s) used: Codeblocks\n";
    cout << "Compiler(s) used: GNU GCC Compiler\n";
    cout << "File: " << __FILE__ << endl;
    cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

    Road r;
    r.setlength(1.1);
    r.setwidth(2.2);

    cout<<"Length:"<<r.getlength()<<endl;
    cout<<"Width:"<<r.getwidth()<<endl;
    cout<<"Thickness: 5.5"<<endl;

    cout<<"Expected result: 5856.4"<<endl;
    cout<<"Acutal result: "<<r.asphault(5.5)<<endl;

    double diff=r.asphault(5.5)-5856.4;

    assert( diff> -0.00001 && diff< 0.00001   );



    //object copy testing

    cout<<"Original Length: "<<r.getlength()<<endl;
    cout<<"Original Width: "<<r.getwidth()<<endl;

    Road r2=r;

    cout<<"Copied Length: "<<r2.getlength()<<endl;
    cout<<"Copied Width: "<<r2.getwidth()<<endl;

    assert(r.getlength()==r2.getlength());
    assert(r.getwidth()==r2.getwidth());

    Road r3;

    cout<<"Original Length: "<<r.getlength()<<endl;
    cout<<"Original Width: "<<r.getwidth()<<endl;

    r3=r;

    cout<<"Copied Length: "<<r3.getlength()<<endl;
    cout<<"Copied Width: "<<r3.getwidth()<<endl;

    assert(r.getlength()==r3.getlength());
    assert(r.getwidth()==r3.getwidth());


}
