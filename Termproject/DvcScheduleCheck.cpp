// Term Project: Part 2
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <map>

using namespace std;

int main()
{
  multimap <pair<string, string>, string> dvcSched;
  
  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  bool found=false;
  
  // print student and program information
  cout << "Term Project: Part 2 b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // open the input file
  ifstream fin;
  fin.open ( "dvc-schedule.txt" );
  if ( !fin.good() ) throw "I/O error";
  
  // read the input file
  while ( fin.good() )
  {
    // read the line
    string line;
    getline ( fin, line );
    strcpy ( buf, line.c_str() );
    if ( buf[0] == 0 ) continue;
    
    // parse the line
    const string term ( token = strtok ( buf, tab ) );
    const string section ( token = strtok ( 0, tab ) );
    const string course ( ( token = strtok ( 0, tab ) ) ? token : "" );
    const string instructor ( ( token = strtok ( 0, tab ) ) ? token : "" );
    const string whenWhere ( ( token = strtok ( 0, tab ) ) ? token : "" );
    if ( course.find ( '-' ) == string::npos ) continue; // invalid line
    const string subjectCode ( course.begin(), course.begin() + course.find ( '-' ) );
    
    dvcSched.insert ( pair<pair<string, string>, string> ( pair<string, string> ( term, section ), course ) );
  }
  fin.close();
  //close file
  
  // find and output duplicate term and sections
  
  string xterm = "";
  string xsection = "";
  string xcourse = "";
  
  //go through courses
  for ( const auto& x : dvcSched )
  {
    //duplicate search
    if ( x.first.first == xterm && x.first.second == xsection && x.second != xcourse )
    {
      found=true; //set found bool to true
      cout << "Duplicate sections found"<<endl ;
      cout << xterm << " Section: " << xsection << " Course: " << xcourse << endl;
      cout << x.first.first << " Section: " << x.first.second << " Course: " << x.second <<endl<<endl;
    }
    //assign class strings
    xterm = x.first.first;
    xsection = x.first.second;
    xcourse = x.second;
  }
  //if no duplicates found output
  if(found==false)
  {
    cout<<"No Duplicates found in file"<<endl;
  }
}
