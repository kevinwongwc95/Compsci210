#ifndef Checkbook_h
#define Checkbook_h

template <class DataType>
class Checkbook
{
public:
  Checkbook();
  bool writeCheck(const DataType & amount);
  void deposit(float amount);
  float getBalance() const;
  DataType* getChecks() const;
  int checkCount() const;
  void setBalance(float amount);
  
private:
  int capacity;
  float balance;
  int numChecks;
  void doubleArray();
  DataType* tracker;
};

#endif

template <class DataType>
Checkbook <DataType>::Checkbook()
{
  DataType* checks=new DataType[2];
  tracker=checks;
  numChecks=0;
  capacity=2;
  balance=0;
}

template <class DataType>
void Checkbook <DataType>::setBalance(float amount)
{
  balance=amount;
}

template <class DataType>
bool Checkbook<DataType>::writeCheck(const DataType & amount)
{
  if(amount>balance)
  {
    return false;
  }
  balance-=amount;
  tracker[numChecks]=amount;
  numChecks++;
  
  if (numChecks==capacity)
  {
    doubleArray();
  }

  return true;
}

template <class DataType>
void Checkbook <DataType>::deposit(float amount)
{
  balance+=amount;
}

template <class DataType>
float Checkbook<DataType>::getBalance()const
{
  return balance;
}

template <class DataType>
void Checkbook <DataType>::doubleArray()
{
  DataType* temp = new DataType[capacity * 2];
  for (int i = 0; i < capacity; i++)
    temp[i] = tracker[i];
  delete [] tracker;
  tracker = temp;
  capacity=capacity*2;
}

//dynamic array created will not be deleted, free memory of array a after usage
template <class DataType>
DataType* Checkbook <DataType>:: getChecks() const
{
  DataType* a=new DataType[numChecks];
  for(int i=0; i<numChecks;i++)
  {
    a[i]=tracker[i];
  }
  return a;
}

template <class DataType>
int Checkbook <DataType> ::checkCount() const
{
  int num;
  num=numChecks;
  return num;
}

