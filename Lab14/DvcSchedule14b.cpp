//LAB 14b: Applying A Data Structure To A Database Program
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <fstream>
#include <iostream>
#include <string>
using namespace std;

#include <ctime>

#include <cstring>

#include <string>

#include <cassert>

#include "SortableArray.h"

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
  bool operator<(const SubjectCount&) const;
};

bool SubjectCount:: operator<(const SubjectCount& x) const
{
  if(this->subjectCode.compare(x.subjectCode)>0)
  {
    return false;
  }
  else
  {
    return true;
  }
}

int main()
{
  
  // print student and program information
  cout << " LAB 14b: Applying A Data Structure To A Database Program b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  
  // start the timer
  clock_t startTime = clock();
  
  SortableArray<TermClassSections,70000> classlist;
  SortableArray<SubjectCount,200> classlist2;
  
  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  int index=0;
  int duplicate=0;
  bool decision=false;
  int output=0;
  int index2=0;
  
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
    for(int i=0; i<index; i++)
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
      classlist[index].term=term;
      classlist[index].section=section;
      classlist[index].subjectCode=subjectCode;
      
      //increment index
      index++;
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
  
  //assertion to prevent overshooting size of static array
  assert(index<70000);
  
  //output duplicate count
  cout<<"Duplicate Count: "<<duplicate<<endl;
  
  
  //******************************************** Creating new array
  for(int i=0; i<index;i++)
  {
    bool found=false;
    
    for(int x=0; x<index2; x++)
    {
      if(classlist2[x].subjectCode==classlist[i].subjectCode)
      {
        classlist2[x].count++;
        found=true;
      }
    }
    if(found==false)
    {
      classlist2[index2].subjectCode=classlist[i].subjectCode;
      classlist2[index2].count=1;
      index2++;
    }
  }
  //****************************************end alphabetical sorting
  
  classlist2.sort(index2);
  
  //stop timer
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  
  
  cout<<endl;
  
  for(int i=0; i<index2; i++)
  {
    cout<<classlist2[i].subjectCode<<"---"<<classlist2[i].count<<endl;
  }
  
  cout<<endl<<"Program Run Time in seconds: " <<elapsedSeconds<<endl;
  
}