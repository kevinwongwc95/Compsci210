//LAB 12a: Write And Test A Priority Queue Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef PriorityQueue_h
#define PriorityQueue_h

template <class DataType>
struct PriorityQueue
{
private:
  int size; //size
  int capacity;
  DataType* data;
  
public:
  void enqueue(const DataType&);
  DataType dequeue();
  int getSize() const;
  PriorityQueue();
};

template <class DataType>
int PriorityQueue <DataType>::getSize() const
{
  return size;
}

template <class DataType>
PriorityQueue<DataType>::PriorityQueue(): capacity(2), data(new DataType[2]),size(0)
{
}

template <class DataType>
DataType PriorityQueue <DataType>::dequeue()
{
  DataType save=data[0];
  int index=0;
  while(1)
  {
    int leftChild=2*index+1;
    int rightChild=2*index+2;
    if(leftChild>=size)
    {
      break;
    }
    if(leftChild==size-1||data[leftChild]>=data[rightChild])
    {
      data[index]=data[leftChild];
      index=leftChild;
    }
    else
    {
      data[index]=data[rightChild];
      index=rightChild;
    }
  }
  size--;
  if(size<capacity/4)//Halving capacity if needed
  {
    DataType* temp = new DataType[capacity/2];
    for (int i = 0, j=0; i <size; i++, j++)
    {
      temp[i] = data[j];
    }
    delete [] data;
    data = temp;
    capacity=capacity/2;
  }
  data[index]=data[size];
  while(1)
  {
    int parentIndex=(index+1)/2-1;
    if(parentIndex<0)
    {
      break;
    }
    if(data[parentIndex]>=data[index])
    {
      break;
    }
    DataType temp;
    temp=data[parentIndex];
    data[parentIndex]=data[index];
    data[index]=temp;
    index=parentIndex;
  }
  return save;
}

template <class DataType>
 void PriorityQueue <DataType>:: enqueue(const DataType& x)
{
  int index=size;
  if(index>=capacity)//double capacity if index greater or equal to capacity
  {
    DataType* temp = new DataType[capacity*2];
    for (int i=0, j=0; i<size; i++, j++)
    {
      temp[i]=data[i];
    }
    delete [] data;
    data = temp;
    capacity=capacity*2;
  }
  data[index]=x;
  while(1)
  {
    int parentIndex = (index+1)/2 - 1;
    if (parentIndex < 0)
    {
      break;
    }
    if(data[parentIndex]>=data[index])
    {
      break;
    }
    DataType temp=data[parentIndex];
    data[parentIndex]=data[index];
    data[index]=temp;
    index=parentIndex;
  }
  size++;
}

#endif
