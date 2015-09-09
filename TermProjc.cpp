#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <cstring>

#include <ctime>

#include <string>

#include <map>

int main()
{

  map <string, string> latestClass;


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

    const string termTerm ( term.begin(), term.begin() + term.find ( ' ' ) );
    const string termYear = term.substr ( term.find ( " " ) + 1, 4 );

    string termSort;
    if ( termTerm == "Spring" )
    {
      termSort = termYear + "1";
    }
    else if ( termTerm == "Summer" )
    {
      termSort = termYear + "2";
    }
    else if ( termTerm == "Fall" )
    {
      termSort = termYear + "3";
    }
    else
    {
      termSort = termYear + " ";
    }

    if ( latestClass.find ( course ) == latestClass.end() || termSort > latestClass[course] )
    {
      latestClass[course] = termSort;
    }

  }
  fin.close();

  for ( const auto& x : latestClass )
  {
    cout << x.first << " : " << x.second << endl;
  }


//while (true) {


//}


}
