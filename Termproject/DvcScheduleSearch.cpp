// Term Project Part 3
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

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
  
  map <string, string> latestClass; //declare latestClass map with two strings
  
  // print student and program information
  cout << "Term Project Part 3 b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
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
    
    //spring=1
    //summer=2
    //fall=3
    //sort by semester, code
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
    
    // check for not found or if found term is later than current term on map
    if ( latestClass.find ( course ) == latestClass.end() || termSort > latestClass[course] ) //look for course,
    {
      latestClass[course] = termSort;
    }
    
  }
  
  fin.close();//close file
  
  //string declarations 
  string input;
  string info;
  string semester;
  string year;
  while (true)
  {
    //prompt user if for intput
    //ask if they wish to quit
    cout<<"Input course name or enter x or X to quit: ";
    cin>>input;
    if(input=="x"||input=="X")
    {
      break;
    }
    
    if(latestClass.find (input) == latestClass.end())//if course not found in map
    {
      cout<<endl<<input<<" has not been offered since the year 2000"<<endl<<endl;
      continue;
    }
    
    info=latestClass[input]; //search the map
    semester=info.substr(4,1); //split info into semester
    year=info.substr(0,4); //split info string into year
    
    if(semester=="1")
    {
      cout<<endl<<input<<" was last offered in Spring of "<<year<<endl<<endl;
    }
    if(semester=="2")
    {
      cout<<endl<<input<<" was last offered in Fall of "<<year<<endl<<endl;
    }
    if(semester=="3")
    {
      cout<<endl<<input<<" was last offered in Summer of "<<year<<endl<<endl;;
    }
    
  }//end while loop
}//end main
