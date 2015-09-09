// LAB 13: Write A Customer Service Simulation
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include <iostream>
using namespace std;

#include <fstream>

#include <cstdlib>

#include <string>

#include <ctime>

#include <cmath>

#include <queue>

struct Customer
{
public:
  int arrivalTime;
  int serviceTime=0;
  int completionTime=0;
  char ID;
};

struct serviceEvent
{
public:
  bool operator <(const serviceEvent&) const;
  int endTime;
  int serverNumber;
};

bool serviceEvent::operator <(const serviceEvent &a) const
{
  if(this->endTime<a.endTime)
  {
    return false;
  }
  else
  {
    return true;
  }
}


int getRandomNumberOfServiceRequests(double);
int getRandomNumber(int, int);

int main()
{
  srand(time(0));
  rand();
  // print student and program information
  cout << " LAB 13: Write A Customer Service Simulation b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;
  
  // open the input file
  ifstream fin;
  fin.open("simulation.txt");
  if (!fin.good()) throw "I/O error";
  double x;
  int serverCount; //number of servers 1 or more whole number
  double avgCustomerRate; //average arrival rate of customers, per minute.
  int maxLengthQueue;//maximum length of the wait queue
  int minInterval; //minimum service time interval in minutes
  int maxInterval; //maximum service time interval in minutes
  int stopTime; //the clock time at which new arrivals stop in minutes
  int customersTurnedAway=0;
  int customersCreated=0;
  double turnedAwayAverage=0;
  string end;
  
  
  while(fin.good())
  {
    string line;
    for(int i=0; i<6; i++)
    {
      getline(fin, line, '\n');
      x=atof(line.c_str());
      if(i==0)
      {
        serverCount=x;
      }
      else if(i==1)
      {
        avgCustomerRate=x;
      }
      else if(i==2)
      {
        maxLengthQueue=x;
      }
      else if(i==3)
      {
        minInterval=x;
      }
      else if(i==4)
      {
        maxInterval=x;
      }
      else if(i==5)
      {
        stopTime=x;
      }
    }
  }
  
  cout<<"Number of Servers:  "<<serverCount<<endl;
  cout<<"Customer Arrival Rate: "<<avgCustomerRate<<" per minute, for "<<stopTime<<" minutes"<<endl;
  cout<<"Maximum Queue Length: "<<maxLengthQueue<<endl;
  cout<<"Minimum Service Time: "<<minInterval<<" minutes"<<endl;
  cout<<"Maximum Service Time:  "<<maxInterval<<" minutes"<<endl;
  cout<<endl;
  
  
  //ARRAY AND QUEUE DECLARATIONS**************************
  queue <Customer> line;
  vector <Customer> servedCustomers;
  priority_queue<serviceEvent> tasks;
  Customer*servers=new Customer[serverCount];
  bool *serverStatus=new bool[serverCount];//true means idle, false means busy
  
  for(int i=0; i<serverCount; i++)
  {
    serverStatus[i]=true;
  }
  
  for (int time = 0;; time++) // the clock time
  {
    Customer temp;
    char letter;
    queue <Customer> temp2;
    
    while((!tasks.empty()) && ((tasks.top()).endTime)==time)
    {
      serviceEvent temp;
      temp=tasks.top();
      int num=temp.serverNumber;
      servers[num].completionTime=time;
      servedCustomers.push_back(servers[num]);
      tasks.pop();
      serverStatus[num]=true;
    }

    //handle new arrivals -- can be turned away if wait queue is at maximum length!
    if(time<stopTime)
    {
      int arrivals=getRandomNumberOfServiceRequests(avgCustomerRate);
      for(int i=0; i<arrivals; i++)
      {
        if(maxLengthQueue==line.size())//if the wait queue is full
        {
          customersTurnedAway++;
        }
        else
        {
          Customer *x=new Customer;
          x->arrivalTime=time;
          x->ID=(char)('A' + (customersCreated++ % 26));
          line.push(*x);
        }
      }
    }//end new arrival block
    
     // for idle servers, move customer from wait queue and begin service
    for(int i=0; i<serverCount; i++)
    {
      if(serverStatus[i]==true && !line.empty())
      {
        int num;
        servers[i]=line.front();
        line.pop();
        servers[i].serviceTime=time;
        num=getRandomNumber(minInterval, maxInterval);
        serviceEvent* x=new serviceEvent;
        x->endTime=num+time;
        x->serverNumber=i;
        tasks.push(*x);
        serverStatus[i]=false;
      }
    }
    
    // output the summary
    cout<<endl<<"Time: "<<time<<endl;
    cout<<"---------------------------"<<endl;
    cout<<"line now serving wait queue"<<endl;
    cout<<"---- ----------- ----------"<<endl;
    
    for(int j=0; j<serverCount; j++)
    {
      if(j==0)
      {
        if(serverStatus[0]==false)
        {
          cout<<"  "<<j<<"       "<<servers[j].ID<<"      ";
        }
        else
        {
          cout<<"  "<<j;
        }
        for(int i=0; !line.empty(); i++)
        {
          temp=line.front();
          temp2.push(temp);
          letter=temp.ID;
          line.pop();
          cout<<letter;
        }
        line=temp2;
        cout<<endl;
      }
      else
      {
        if(serverStatus[j]==false)
        {
          cout<<"  "<<j<<"       "<<servers[j].ID<<endl;
        }
        else
        {
          cout<<"  "<<j<<endl;
        }
      }
    }
    
    cout<<"---------------------------"<<endl;
    
    double averageTime=0;
    for(int i=0; i<servedCustomers.size();i++)
    {
      averageTime=averageTime+servedCustomers[i].completionTime-servedCustomers[i].arrivalTime;
    }
    if(servedCustomers.size()!=0)
    {
      averageTime=averageTime/(servedCustomers.size());
    }
    
    if(time!=0 && time<stopTime)
    {
      turnedAwayAverage=(customersTurnedAway/(double)time);
    }
    
    cout<<"Average Time: "<<averageTime<<". Turned Away Per Minute: "<<turnedAwayAverage<<endl;
    
    
    //DEBUG REMOVE LATER
    //cout<<"Number of Events in Event Queue: "<<tasks.size()<<endl;
    //cout<<"Service time of top event: "<<tasks.top().endTime<<endl;
    
    cout<<endl<<"Press ENTER to continue, X-ENTER to exit..."<<endl;
    getline(cin, end);
    
    if(end=="x" || end=="X")
    {
      break;
    }
    else if (end=="")
    {
      continue;
    }
    
  }//end time loop

}

int getRandomNumber(int base, int limit)
{
  return rand() % (limit - base + 1) + base;
}


int getRandomNumberOfServiceRequests(double averageRequestsPerTimeStep)
{
  int requests = 0;
  double probOfnRequests = exp(-averageRequestsPerTimeStep);
  for (double randomValue = (double)rand() / RAND_MAX;
       (randomValue -= probOfnRequests) > 0.0;
       probOfnRequests *= averageRequestsPerTimeStep / (double)++requests);
  return requests;
}

