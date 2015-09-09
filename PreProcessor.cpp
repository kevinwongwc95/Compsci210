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


int main()
{
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
          cout<<"Found */ without opener on line: "<<counter<<" in "<<filename<<endl;
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
          cout<<"Found /* without closer on line: "<<test.linenumber<<" in "<<filename<<endl;
          break;
        }

      }

      //if find closing }
      else if(buf[i]=='}')
      {
        //check if stack is already empty
        if(mystack.empty()==true)
        {
          found=true;
          cout<<"Found } without opener on line: "<<counter<<" in "<<filename<<endl;
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
          cout<<"Found { without closer on line: "<<test.linenumber<<" in "<<filename<<endl;
          break;
        }
      }

      //if found closing ]
      else if(buf[i]==']')
      {
        //check if stack is already empty
        if(mystack.empty()==true)
        {
          found=true;
          cout<<"Found ] without opener on line: "<<counter<<" in "<<filename<<endl;
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
          cout<<"Found [ without closer on line: "<<test.linenumber<<" in "<<filename<<endl;
          break;
        }
      }

      //if found closing )
      else if(buf[i]==')')
      {
        //check if stack is already empty
        if(mystack.empty()==true)
        {
          found=true;
          cout<<"Found ) without opener on line: "<<counter<<" in "<<filename<<endl;

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
          cout<<"Found ( without closer on line: "<<" in "<<filename<<endl;
          break;
        }
      }
    }

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
    cout<<"Found "<<test.symbol<<" without closer on line: "<<test.linenumber<<" in "<<filename<<endl;
  }
  if (mystack.empty()==true && found==false)
  {
    cout<<"No mismatches found by my preprocessor in "<<filename<<endl;
  }

}

//temp path name /Users/Kevin/Desktop/test.txt
