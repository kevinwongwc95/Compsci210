// Lab 8A Write And Apply A Stack Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef Stack_h
#define Stack_h

template <class DataType>
class Stack
{
public: 
  Stack();
  bool isEmpty() const;
  void push(const DataType& parameter);
  DataType peek() const;
  bool pop();
  void makeEmpty();
  void getcapacity ()const;
  
private:
  DataType* data;
  int capacity;
  int top; // track newest value
};

//REMOVE LATER(*************************
template <class DataType>
void Stack <DataType>::getcapacity() const
{
  cout<<"capacity: "<<capacity<<endl;
}


template <class DataType>
Stack<DataType>::Stack(): capacity(2), data(new DataType[2]), top(-1)
{
}

template <class DataType>
bool Stack<DataType>::isEmpty() const
{
  if(top==-1)
  {
    return true;
  }
  else
  {
    return false;
  }
}
  
template <class DataType>
void Stack<DataType>::push(const DataType& parameter)
{
  if (++top == capacity)
  {
    DataType* temp = new DataType[capacity * 2];
    for (int i = 0; i < capacity; i++)
    {
      temp[i] = data[i];
    }
    delete [] data;
    data = temp;
    capacity=capacity*2;
  }
  //double the capacity
  data[top] = parameter;
}

template <class DataType>
DataType Stack<DataType>::peek() const
{
  DataType x=data[top];
  return x; // success
}

template <class DataType>
bool Stack<DataType>::pop()
{
  if (-1 == top)
  {
    return false; // failed
  }
  
  top=top-1;
  
  if (top > 2 && top < capacity / 4)
  {
    DataType* temp = new DataType[capacity/2];
    for (int i = 0; i < capacity; i++)
    {
      temp[i] = data[i];
    }
    delete [] data;
    data = temp;
    capacity=capacity/2;
    //halve the capacity
  }
    return true; // success
}

template <class DataType>
void Stack<DataType>::makeEmpty()
{
  top = -1;
}


#endif
