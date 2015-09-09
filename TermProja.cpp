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
    set <string> dupes;
    map <string, map<string, int>> dvcSched;

    // for parsing the inputfile
    char* token;
    char buf[1000];
    const char* const tab = "\t";

    // open the input file
    ifstream fin;
    fin.open ( "dvc-schedule.txt" );
    if ( !fin.good() ) throw "I/O error";

    // read the input file
    while ( fin.good() ) {
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

        if ( dupes.find ( termSec ) == dupes.end() ) {
            dupes.insert ( termSec );
            if ( dvcSched.find ( subjectCode ) == dvcSched.end() ) {
                dvcSched[subjectCode].insert ( make_pair ( course, 1 ) );
            } else {
                dvcSched[subjectCode][course]++;
            }
        }

    }
    fin.close();

    for ( const auto& x : dvcSched ) {
        cout << "\n" << x.first << " " << x.second.size() << " course(s)" << "\n";
        for ( const auto& y : x.second ) {
            cout << "  " << y.first << " " << y.second << " class(es) \n";
        }
    }
}
