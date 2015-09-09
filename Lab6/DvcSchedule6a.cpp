// Lab 6A Applying The STL deque
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include <fstream>

#include <deque>

#include <ctime>

#include <cstring>

#include <string>

struct TermClassSections
{
  string term;
  string section;
  string subjectCode;
};

struct SubjectCount
{
  string subjectCode;
  int count;
};

int main()
{
  
  // print student and program information
  cout << " Lab 6A Applying The STL deque b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  
  // start the timer
  clock_t startTime = clock();
  
  //#Array Declarations******
  deque <TermClassSections> classlist;
  deque <SubjectCount> classlist2;
  
  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  int duplicate=0;
  bool decision=false;
  int output=0;

  
  // open the input file
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  
  // read the input file
  while (fin.good())
  {
    // read the line
    string line;
    getline(fin, line);
    strcpy(buf, line.c_str());
    if (buf[0] == 0) continue;
    
    // parse the line
    const string term(token = strtok(buf, tab));
    const string section(token = strtok(0, tab));
    const string course((token = strtok(0, tab)) ? token : "");
    const string instructor((token = strtok(0, tab)) ? token : "");
    const string whenWhere((token = strtok(0, tab)) ? token : "");
    if (course.find('-') == string::npos) continue; // invalid line
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    
    decision=false;
    for(int i=0; i<classlist.size(); i++)
    {
      if((classlist[i].section==section)&& (classlist[i].term==term))
      {
        duplicate++;
        decision=true;
        break;
      }
    }
    
    if(decision==false)
    {
      //fills classList array
      TermClassSections temp;
      temp.term=term;
      temp.section=section;
      temp.subjectCode=subjectCode;
      classlist.push_back(temp);
      
      output++;
    }
    
    //progress bar output
    if(output==1000)
    {
      output=0;
      cout<<". ";
      cout.flush();
    }
    
  }
  fin.close();
  
  cout<<endl;
  
  
  //output duplicate count
  cout<<endl<<"Duplicate Count: "<<duplicate<<endl<<endl;
  
  
  //******************************************** Creating new array
  for(int i=0; i<classlist.size();i++)
  {
    bool found=false;
    
    for(int x=0; x<classlist2.size(); x++)
    {
      if(classlist2[x].subjectCode==classlist[i].subjectCode)
      {
        classlist2[x].count++;
        found=true;
      }
    }
    if(found==false)
    {
      SubjectCount temp;
      temp.subjectCode=classlist[i].subjectCode;
      temp.count=1;
      classlist2.push_back(temp);
    }
  }
  
  //*********************************** alphabetical sorting
  int compare;
  bool exchange;
  do
  {
    exchange=false;
    for(int i=0; i<((classlist2.size())-1);i++)
    {
      compare=(classlist2[i].subjectCode.compare(classlist2[i+1].subjectCode));
      if (compare==0 || compare<0)
      {
        continue;
      }
      if(compare>0)
      {
        swap(classlist2[i].subjectCode,classlist2[i+1].subjectCode);
        swap(classlist2[i].count,classlist2[i+1].count);
        exchange=true;
      }
    }
    
  }while(exchange==true);
  
  //stop timer**
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  
  //****************************************end alphabetical sorting
  
  cout<<endl;
  
  for(int i=0; i<classlist2.size(); i++)
  {
    cout<<classlist2[i].subjectCode<<"---"<<classlist2[i].count<<endl;
  }
  
  cout<<endl<<"Program Run Time in seconds: " <<elapsedSeconds<<endl;
  
}
