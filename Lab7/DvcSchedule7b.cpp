// Lab 7B Applying Advanced Linked-List Techniques
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
  cout << " Lab 7B Applying Advanced Linked-List Techniques b\n";
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
  
  Node* start = 0;
  Node* p;
  
  for ( int i = 0; i < classlist.size(); i++ )
  {
    //insert first node
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
    Node* prevx = 0;
    
    while ( true )
    {
      //found node - add to counter
      if ( classlist[i].subjectCode.compare ( x->data.subjectCode ) == 0 )
      {
        x->data.count++;
        break;
      }
      //insertion at middle
      if ( classlist[i].subjectCode.compare ( x->data.subjectCode ) < 0 )
      {
        Node* newnode = new Node;
        //insertion before first node
        if ( start == x )
        {
          start = newnode;
        } else
        {
          prevx->next = newnode;
        }
        newnode->data.subjectCode = classlist[i].subjectCode;
        newnode->data.count = 1;
        newnode->next = x;
        break;
      }
      //insertion at end
      if ( x->next == 0 )
      {
        Node* newnode = new Node;
        x->next = newnode;
        newnode->data.subjectCode = classlist[i].subjectCode;
        newnode->data.count = 1;
        newnode->next = 0;
        break;
      }
      prevx = x;
      x = prevx->next;
    }
  }
  //end
  
  //stop timer**
  double elapsedSeconds = (double)(clock() - startTime) / CLOCKS_PER_SEC;
  
  cout<<endl;
  
  
  for (Node* a = start; a; a = a->next)
  {
    cout<<a->data.subjectCode<<"---"<<a->data.count<<endl;
  }
  
  cout<<endl<<"Program Run Time in seconds: " <<elapsedSeconds<<endl;
  
   
  //dealocate memory
  while (start)
  {
    p = start->next;
    delete start;
    start = p;
  }
}

