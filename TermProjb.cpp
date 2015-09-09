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

// find and output duplicate term and sections

  string xterm = "";
  string xsection = "";
  string xcourse = "";

  for ( const auto& x : dvcSched )
  {
    if ( x.first.first == xterm && x.first.second == xsection && x.second != xcourse )
    {
      cout << "Duplicate sections found\n" ;
      cout << xterm << " Section: " << xsection << " Course: " << xcourse << "\n";
      cout << x.first.first << " Section: " << x.first.second << " Course: " << x.second << "\n\n";
    }
    xterm = x.first.first;
    xsection = x.first.second;
    xcourse = x.second;
  }
}
