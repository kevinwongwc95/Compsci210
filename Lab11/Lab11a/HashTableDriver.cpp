//LAB 11a: Write And Test The HashTable Class Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cstring>
using namespace std;

#include "HashTable.h"
#include "HashTable.h"

struct classSection
{
public:
  bool operator==(const classSection&) const;
  string term;
  string section;
  string course;
  string instructor;
  int hashCode() const;
};

int classSection:: hashCode() const //key values are term section course
{
  int hash=0;
  for(int i=0; i<this->term.length(); i++)
  {
    hash=hash+this->term[i];
  }
  for(int i=0; i<this->section.length(); i++)
  {
    hash=hash+this->section[i];
  }
  for(int i=0; i<this->course.length(); i++)
  {
    hash=hash+this->course[i];
  }
  
  return hash;
}

bool classSection:: operator==(const classSection& a) const
{
  if((this->term.compare(a.term)==0)&&(this->section.compare(a.section)==0)&&(this->course.compare(a.course)==0)&&(this->instructor.compare(a.instructor)==0))
  {
    return true;
  }
  return false;
}

int main()
{
  
  cout << "LAB 11a: Write And Test The HashTable Class Template b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  HashTable <classSection, 1009> test;
  HashTable <classSection, 1009> test2=test;
  HashTable <classSection, 1009> test3;
  
  test=test3;
  ifstream fin;
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  char* token;
  const char* const tab = "\t";
  char buf[1000];
  
  classSection y;
  // read the input file
  int counter;
  for(counter=0; fin.good(), counter<120; counter++)
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
    if (course.find('-') == string::npos) continue; // invalid line
    
    y.term=term;
    y.section=section;
    y.course=course;
    y.instructor=instructor;
    
    test.insert(y);

  }
  fin.close();
  int dup=counter-test.size();
  cout<<"Size should be "<<counter-dup<<endl;
  cout<<"Size is: "<<test.size()<<endl;
  cout<<"Number of duplicates: "<<counter-test.size()<<endl;
  assert(test.size()==counter-dup);
  
  cout<<"Test if first function works"<<endl;
  if(test.first(y)==true)
  {
    cout<<"First function works. "<<endl;
  }
  else
  {
    cout<<"First doesn't work "<<endl;
  }
  assert(test.first(y)==true);
  
  cout<<"Test if getNext function works"<<endl;
  if(test.getNext(y)==true)
  {
    cout<<"getNext function works. "<<endl;
  }
  else
  {
    cout<<"getNext doesn't work "<<endl;
  }
  assert(test.getNext(y)==true);
  
  cout<<"Test clear function"<<endl;
  test.clear();
  cout<<"Function cleared size should be 0"<<endl;
  cout<<"Size: "<<test.size()<<endl;
  assert(test.size()==0);

  
  classSection y2, y3;
  //****SECOND TIME OPENING FILE
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  
  int counter2;
  for(counter2=0; fin.good(), counter<120; counter++)
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
    if (course.find('-') == string::npos) continue; // invalid line
    
    y2.term=term;
    y2.section=section;
    y2.course=course;
    y2.instructor=instructor;
    
    y3=y2;
    if(test.retrieve(y2))
    {
    }
    else
    {
      cout<<"Retrieve Failed" <<endl;
    }
    assert(y3==y2);
    
    //Test remove function
    //remove fails if duplicate encountered
    int before=test.size();
    if(test.remove(y3))
    {
    }
    else
    {
      cout<<"Remove Failed"<<endl;
    }
    assert(test.size()==before-1);
  }
  fin.close();
  
  classSection testReplace;
  testReplace.term="test";
  testReplace.section="test";
  testReplace.course="test";
  testReplace.instructor="test";
  
  HashTable <classSection, 1009> test4;
  
  test4.insert(testReplace);
  cout<<"Testing replace function "<<endl;
  if(test4.replace(testReplace)==true)
  {
    cout<<"Replace Works"<<endl;
  }
  else
  {
    cout<<"Replace Doesn't work"<<endl;
  }
  assert(test4.replace(testReplace)==true);
  
}

