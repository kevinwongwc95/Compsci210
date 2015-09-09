// Lab 7A Write A Linked-List Solution
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

struct Node
{
  SubjectCount data;
  Node* next;
};

int main()
{
  // print student and program information
  cout << " Lab 7A Write A Linked-List Solution b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  
  // start the timer
  clock_t startTime = clock();
  
  //#Array Declarations******
  deque <TermClassSections> classlist;
  
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
  
  Node* start=0;
  Node* p;

  //new
  
  for ( int i = 0; i < classlist.size(); i++ )
  {
    if ( start == 0 )
    {
      Node* newnode = new Node;
      newnode->data.subjectCode = classlist[i].subjectCode;
      newnode->data.count = 1;
      newnode->next = 0;
      start = newnode;
      continue;
    }
    
    Node* x = start;
    
    while ( true )
    {
      if ( classlist[i].subjectCode.compare ( x->data.subjectCode ) == 0 )
      {
        x->data.count++;
        break;
      }
      if ( x->next == 0 )
      {
        Node* newnode = new Node;
        x->next = newnode;
        newnode->data.subjectCode = classlist[i].subjectCode;
        newnode->data.count = 1;
        newnode->next = 0;
        break;
      }
      Node* temp = x->next;
      x = temp;
    }
  }
  //end

  
  //Sorting***********

  for (Node* a= start; a; a = a->next)
  {
    for (Node* b= a->next; b; b = b->next)
    {
      if (a->data.subjectCode.compare(b->data.subjectCode) > 0)
      {
        int temp;
        a->data.subjectCode.swap(b->data.subjectCode);
        temp=a->data.count;
        a->data.count=b->data.count;
        b->data.count=temp;
      }
    }
  }
  
  //stop timer**
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  
  //****************************************end alphabetical sorting
  
  cout<<endl;
  
  for (Node* a = start; a; a = a->next)
  {
    cout<<a->data.subjectCode<<"---"<<a->data.count<<endl;
  }
  cout<<endl<<"Program Run Time in seconds: " <<elapsedSeconds<<endl;
  
  while (start)
  {
    p = start->next;
    delete start;
    start = p;
  }
}
