// Lab 0c, The Basics
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler


#include <iostream>

#include <iomanip>

using namespace std;




int main()
{
  // print student and program information
  cout << "Lab 0c, The Basics b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  //Declaring variables
  string buf;
  string name;
  string city;
  double temperature;
  double celsius;
  int age;
  
  //Get age from console
  cout<<"Enter your age: ";
  cin>>buf;
  age = atoi(buf.c_str());
  cin.ignore(1000,10);
  
  //Get name from console
  cout<<"Enter your name: ";
  getline(cin,name);
  
  //Get temperature from console
  cout<<"Enter the Temperature outside right now (degrees F): ";
  cin>>buf;
  temperature=atof(buf.c_str());
  cin.ignore(1000,10);
  
  //Convert Fahrenheit to Celsius
  celsius= (((temperature-32)*5)/9);
  
  //Get city information from console
  cout<<"What city are you in right now? ";
  getline(cin,city);
  
  //Display information and make value of celsius have one decimal point
  cout<<endl<<name<<" is "<<age<<" years old now, and will be "<<age+1<<" a year from now."<<endl;
  cout<<"It's "<<temperature<<" degrees F in "<<city<<" -- that's ";
  cout.setf(ios::fixed|ios::showpoint);
  cout<<setprecision(1)<<celsius<<" C."<<endl;
  
}
