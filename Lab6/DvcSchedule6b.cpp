// Lab 6B Using A Data Structure As A Data Member
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

#include <vector>


struct TermClassSections
{
  string term;
  string section;
  string subjectCode;
  string course;
};


struct Course
{
  string name;
  int count;
};

struct SubjectCode
{
  string name;
  vector<Course> course; // or deque
};


int main()
{
  // start the timer
  clock_t startTime = clock();
  
  // print student and program information
  cout << " Lab 6B Using A Data Structure As A Data Member b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  
  vector <TermClassSections> classlist;
  vector <SubjectCode> subjectCodes;
  
  // for parsing the inputfile
  char* token;
  char buf[1000];
  const char* const tab = "\t";
  int index=0;
  int duplicate=0;
  bool decision=false;
  int output=0;//used for output to "." progress bar
  
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
    for(unsigned int i=0; i<classlist.size(); i++)
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
      TermClassSections temp;
      //fills classList array
      temp.term=term;
      temp.section=section;
      temp.subjectCode=subjectCode;
      temp.course=course;
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
  
  //output duplicate count
  cout<<endl<<"Duplicate Count: "<<duplicate<<endl<<endl;
  
  
  for(unsigned int i=0; i<classlist.size(); i++)
  {
    bool subjectFound=false;
    for(int j=0; j<subjectCodes.size(); j++)
    {
      if(classlist[i].subjectCode==subjectCodes[j].name)
      {
        bool courseFound=false;
        for(unsigned int k=0; k<subjectCodes[j].course.size(); k++)
        {
          if(classlist[i].course.compare(subjectCodes[j].course[k].name)==0)
          {
            subjectCodes[j].course[k].count++;
            courseFound=true;
          }
        }
        if(!courseFound) //if not found
        {
          Course temp;
          temp.name=classlist[i].course;
          temp.count=1;
          subjectCodes[j].course.push_back(temp);
        }
        subjectFound=true;
      }
    }
    if(!subjectFound)
    {
      SubjectCode temp1;
      Course temp2;
      temp2.name=classlist[i].course;
      temp2.count=1;
      temp1.course.push_back(temp2);
      temp1.name=classlist[i].subjectCode;
      subjectCodes.push_back(temp1);
    }
  }
  
  //alphabatize vector************
  for(unsigned int i=0; i<(subjectCodes.size()-1); i++)
  {
    for(int j=i+1; j<subjectCodes.size();j++)
    {
      if(subjectCodes[i].name.compare(subjectCodes[j].name)>0)
      {
        SubjectCode temp=subjectCodes[i];
        subjectCodes[i]=subjectCodes[j];
        subjectCodes[j]=temp;
      }
    }
  }
  
  //**cout classes
  for(unsigned int i=0; i<subjectCodes.size(); i++)
  {
    cout<<subjectCodes[i].name<<", ";
    cout<<subjectCodes[i].course.size()<<" course(s)"<<endl;
    for(int j=0; j<subjectCodes[i].course.size(); j++)
    {
      cout<<"   "<<subjectCodes[i].course[j].name;
      cout<<", "<<subjectCodes[i].course[j].count<<" class(es)"<<endl;
    }
    
  }
  
  //stop timer
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;

  cout<<endl<<"Program Run Time in seconds: " <<elapsedSeconds<<endl;
  
}