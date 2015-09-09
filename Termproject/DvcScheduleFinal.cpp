// Term Project: Part 1
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <map>
#include <set>

using namespace std;

int main()
{
  //Declaration of map inside map which has string
  //set for dupes
  set <string> dupes;
  map <string, map<string, int>> dvcSched;
  
  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  
  // print student and program information
  cout << "Term Project: Part 1 b\n";
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
    
    string termSec = term + section;
    
    
    if ( dupes.find ( termSec ) == dupes.end() )
    {
      dupes.insert ( termSec );
      
      if ( dvcSched.find ( subjectCode ) == dvcSched.end() ) //if reach end, new course
      {
        dvcSched[subjectCode].insert ( make_pair ( course, 1 ) );
      }
      else //else add to duplicate count for course
      {
        dvcSched[subjectCode][course]++;
      }
    }
  }
  fin.close();//close file
  
  //Print dvc schedule
  for ( const auto& x : dvcSched )
  {
    cout << endl << x.first << " " << x.second.size() << " course(s)" << endl;
    for ( const auto& y : x.second )
    {
      cout << "  " << y.first << " " << y.second << " class(es) "<<endl;
    }
  }
}
