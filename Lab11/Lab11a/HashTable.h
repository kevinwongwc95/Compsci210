//LAB 11a: Write And Test The HashTable Class Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef HashTable_h
#define HashTable_h

#include <list>
#include <iterator>
#include <string>
#include <algorithm>
#include <cassert>

template <class DataType, int CAPACITY>
struct HashTable
{
public:
  void insert(const DataType& );
  bool retrieve(DataType&);
  bool replace(const DataType&);
  bool remove(DataType&);
  int size() const;
  bool first(DataType&);
  bool getNext(DataType&);
  void clear();
  
private:
  list <DataType> data[CAPACITY];
  int count=0;
  int current=0;
  typename list<DataType>::const_iterator itCurrent;
  int getWrappedIndex(const DataType&) const;
};

//Gets wrapped Index from parameter
template <class DataType, int CAPACITY>
int HashTable <DataType, CAPACITY>:: getWrappedIndex(const DataType& x) const
{
  int desiredIndex=x.hashCode();
  int wrappedIndex=desiredIndex%CAPACITY;
  if (wrappedIndex<0)
  {
    wrappedIndex=wrappedIndex+CAPACITY;
  }
  return wrappedIndex;
}

//size function
template <class DataType, int CAPACITY>
int HashTable <DataType,CAPACITY>::size() const
{
  return count;
}

// INSERT function
template <class DataType, int CAPACITY>
void HashTable <DataType,CAPACITY>::insert(const DataType& x)
{
  int i= getWrappedIndex(x);
  
  typename list<DataType>::iterator it;
  it = find(data[i].begin(), data[i].end(), x);
  if (it != data[i].end())
  {
    *it = x; // replace
  }
  else
  {
    data[i].push_back(x); ++count;
  }
}

//Retrieve function
template <class DataType, int CAPACITY>
bool HashTable <DataType, CAPACITY>::retrieve(DataType& x)
{
  int i= getWrappedIndex(x);
  
  typename list<DataType>::const_iterator it; // const_ for retrieve only!
  it = find(data[i].begin(), data[i].end(), x);
  if (it == data[i].end())
  {
     return false;
  }
  else
  {
    x = *it;
    return true; 
  }
}

//Replace function
template <class DataType, int CAPACITY>
bool HashTable <DataType, CAPACITY>::replace(const DataType& x)
{
  int i= getWrappedIndex(x);
  
  typename list<DataType>::iterator it; // const_ for retrieve only!
  it = find(data[i].begin(), data[i].end(), x);
  if (it == data[i].end())
  {
    return false;
  }
  
  else
  {
    *it=x;
    return true;
  }
}

//clear
template <class DataType, int CAPACITY>
void HashTable <DataType, CAPACITY>::clear()
{
  for(int i=0; i<CAPACITY; i++)
  {
    data[i].clear();
  }
  count=0;
}

//Remove function
template <class DataType, int CAPACITY>
bool HashTable <DataType, CAPACITY>::remove(DataType& x)
{
  int i= getWrappedIndex(x);
  
  typename list<DataType>::iterator it;
  it = find(data[i].begin(), data[i].end(), x);
  if (it == data[i].end())
  {
    return false;
  }
  else
  {
    x=*it;
    data[i].erase(it); --count;
    return true;
    
  }
}

template <class DataType, int CAPACITY>
bool HashTable<DataType,CAPACITY>::first(DataType& parameter)
{
  assert(current >= -1 && current < CAPACITY);
  for (current = 0; current < CAPACITY; current++)
  {
    if (!data[current].empty())
    {
      itCurrent = data[current].begin();
      break;
    }
  }
  if (current == CAPACITY) current = -1;
  if (current == -1) return false;
  parameter = *itCurrent;
  return true;
}

template <class DataType, int CAPACITY>
bool HashTable<DataType,CAPACITY>::getNext(DataType& parameter)
{
  assert(current >= -1 && current < CAPACITY);
  if (current == -1) return false;
  assert(!data[current].empty());
  if (++itCurrent == data[current].end())
  {
    for (current = current + 1; current < CAPACITY; current++)
    {
      if (!data[current].empty())
      {
        itCurrent = data[current].begin();
        break;
      }
    }
  }
  
  if (current == CAPACITY) current = -1;
  else parameter = *itCurrent;
  return current >= 0;
}

#endif
