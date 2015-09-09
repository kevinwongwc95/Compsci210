#include <iostream>
using namespace std;

#include <cstdlib>

#include "Checkbook.h"

int main()
{
  Checkbook <float> test;
  
  while(1)
  {
    string buf;
    int choice;
    float balance;
    float amount;
    
    cout<<"1. Get Balance"<<endl;
    cout<<"2. Write a Check"<<endl;
    cout<<"3. Make a Deposit"<<endl;
    cout<<"4. Output All Checks"<<endl;
    cout<<"5. Quit"<<endl;
    
    cout<<"Input number and press Enter: ";
    
    cin >> buf;
    choice = atoi(buf.c_str());
    
    if (choice<=0 || choice>5)
    {
      cout<<"Invalid input, try again"<<endl;
      continue;
    }
    
    if(choice==5)
    {
      break;
    }
    
    //get balance
    if(choice==1)
    {
      balance=test.getBalance();
      cout<<"Balance is: $"<<balance<<endl;
    }
    
    if(choice==2)
    {
      cout<<"Input Check amount: $";
      cin>>buf;
      amount = atof(buf.c_str());
      if(test.writeCheck(amount)==false)
      {
        cout<<"Not enough balance"<<endl;
      }
      else
      cout<<"Check successfully written for amount $"<<amount<<endl;
    }
    
    if(choice==3)
    {
      cout<<"Input Deposit amount: $";
      cin>>buf;
      cout<<endl;
      amount = atof(buf.c_str());
      test.deposit(amount);
    }
    
    if(choice==4)
    {
      int num;
      num=test.checkCount();
      float* checks;
      checks=test.getChecks();
      for(int x=0;x<num;x++)
      {
        cout<<"Check #"<<(x+1)<<"  $"<<checks[x]<<endl;
      }
      delete[] checks;
    }
  }
  
}