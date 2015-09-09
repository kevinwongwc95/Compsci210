// Lab 8C Use A Stack
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include <fstream>

#include <string>

#include <cstring>

#include <stack>

struct bracket
{
public:
  char symbol;
  int linenumber;
};

char match (char);


int main()
{
  // print student and program information
  cout << "Lab 8C Use A Stack b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  //declarations
  char buf[1000];
  stack <bracket> mystack;
  string filename;
  ifstream fin;
  int counter=0;
  bool found=false;
  
  cout<<"Enter filename (H, CPP, JAVA, HTML, or JS): ";
  cin>>filename;
  
  fin.open(filename.c_str());
  
  if (!fin.good())
  {
    throw "I/O error";
  }
  
  while (fin.good())
  {
    // read the line
    string line;
    getline(fin, line);
    counter++;
    strcpy(buf, line.c_str());
    
    for(int i=0; buf[i]!='\0'; i++)
    {
      if(buf[i]=='/'&& buf[i+1]=='*')
      {
        bracket*newsymbol=new bracket;
        newsymbol->symbol=buf[i];
        newsymbol->linenumber=counter;
        mystack.push(*newsymbol);
        i++;
        continue;
      }
      
      //if find opening braces
      if(buf[i]=='{'||buf[i]=='['||buf[i]=='(')
      {
        bracket* newsymbol=new bracket;
        newsymbol->symbol=buf[i];
        newsymbol->linenumber=counter;
        mystack.push(*newsymbol);
      }
      //if found closing */
      if(buf[i]=='*'&& buf[i+1]=='/')
      {
        if(mystack.empty()==true)
        {
          found=true;
          cout<<"Found closing */ on line: "<<counter<<" in "<<filename<<endl;
          cout<<"But no matching opening /* found"<<endl;
          break;
        }
        bracket test;
        test=mystack.top();
        if(test.symbol=='/')
        {
          mystack.pop();
        }
        else
        {
          found=true;
          if(test.symbol=='/')
          {
            cout<<"Found opening /* on line: "<<test.linenumber<<" in "<<filename<<endl;
            cout<<"But no matching closing */ found."<<endl;
          }
          else
          {
            cout<<"Found opening "<<test.symbol<<" on line: "<<test.linenumber<<" in "<<filename<<endl;
            cout<<"But no matching closing "<<match(test.symbol)<<" found."<<endl;
            break;
          }
        }
        
      }
      //if find closing }
      else if(buf[i]=='}')
      {
        //check if stack is already empty
        if(mystack.empty()==true)
        {
          found=true;
          cout<<"Found closing } on line: "<<counter<<" in "<<filename<<endl;
          cout<<"But no matching opening { found"<<endl;
          break;
        }
        bracket test;
        test=mystack.top();
        if(test.symbol=='{')
        {
          mystack.pop();
        }
        else
        {
          found=true;
          if(test.symbol=='/')
          {
            cout<<"Found opening /* on line: "<<test.linenumber<<" in "<<filename<<endl;
            cout<<"But no matching closing */ found."<<endl;
          }
          else
          {
            cout<<"Found opening "<<test.symbol<<" on line: "<<test.linenumber<<" in "<<filename<<endl;
            cout<<"But no matching closing "<<match(test.symbol)<<" found."<<endl;
            break;
          }
        }
      }
      
      //if found closing ]
      else if(buf[i]==']')
      {
        //check if stack is already empty
        if(mystack.empty()==true)
        {
          found=true;
          cout<<"Found closing ] on line: "<<counter<<" in "<<filename<<endl;
          cout<<"But no matching opening [ found"<<endl;
          break;
        }
        bracket test;
        test=mystack.top();
        if(test.symbol=='[')
        {
          mystack.pop();
        }
        else
        {
          found=true;
          if(test.symbol=='/')
          {
            cout<<"Found opening /* on line: "<<test.linenumber<<" in "<<filename<<endl;
            cout<<"But no matching closing */ found."<<endl;
          }
          else
          {
            cout<<"Found opening "<<test.symbol<<" on line: "<<test.linenumber<<" in "<<filename<<endl;
            cout<<"But no matching closing "<<match(test.symbol)<<" found."<<endl;
            break;
          }
        }
      }
      
      //if found closing )
      else if(buf[i]==')')
      {
        //check if stack is already empty
        if(mystack.empty()==true)
        {
          found=true;
          cout<<"Found closing ) on line: "<<counter<<" in "<<filename<<endl;
          cout<<"But no matching opening ( found"<<endl;
          break;
        }
        bracket test;
        test=mystack.top();
        if(test.symbol=='(')
        {
          mystack.pop();
        }
        else
        {
          found=true;
          if(test.symbol=='/')
          {
            cout<<"Found opening /* on line: "<<test.linenumber<<" in "<<filename<<endl;
            cout<<"But no matching closing */ found."<<endl;
          }
          else
          {
            cout<<"Found opening "<<test.symbol<<" on line: "<<test.linenumber<<" in "<<filename<<endl;
            cout<<"But no matching closing "<<match(test.symbol)<<" found."<<endl;
            break;
          }
        }

      }
    }//end for loop
    
    if(found==true)
    {
      break;
    }
  }//end while
  
  fin.close();//close file;
  
  if(mystack.empty()==false && found==false)
  {
    bracket test;
    test=mystack.top();
    if(test.symbol=='/')
    {
      cout<<"Found opening /* on line: "<<counter<<" in "<<filename<<endl;
      cout<<"But no matching closer */ found."<<endl;
    }
    else
    {
      cout<<"Found opening "<<test.symbol<<" on line: "<<test.linenumber<<" in "<<filename<<endl;
      cout<<"But no matching closing "<<match(test.symbol)<<" found."<<endl;
    }

  }
  if (mystack.empty()==true && found==false)
  {
    cout<<"No mismatches found by my preprocessor in "<<filename<<endl;
  }
}

char match (char symbol)
{
  char x;
  if(symbol=='(')
  {
    x=')';
  }
  if(symbol=='[')
  {
    x=']';
  }
  if(symbol=='{')
  {
    x='}';
  }
  return x;
}
