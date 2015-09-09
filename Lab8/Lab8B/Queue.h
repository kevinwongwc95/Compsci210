// Lab 8B Write And Test A Queue Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef Queue_h
#define Queue_h

template <class DataType>
class Queue
{
public:
  Queue();
  bool isEmpty() const;
  void push(const DataType& parameter);
  DataType peek() const;
  bool pop();
  void makeEmpty();
  void getinfo() const;
  
private:
  DataType* data; 
  int capacity; //tracks capcaity of the queue
  int element; //tracks the element of the back of the queue
  int top; // tracks the element of the front of the queue
};

template <class DataType>
void Queue<DataType>:: getinfo()const
{
  cout<<"Capacity: "<<capacity<<endl;
  cout<<"element: "<<element<<endl;
  cout<<"top: "<<top<<endl;
}


template <class DataType>
Queue<DataType>::Queue(): capacity(2), data(new DataType[2]), element(-1), top(-1)
{
}

template <class DataType>
bool Queue<DataType>::isEmpty() const
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
void Queue<DataType>::push(const DataType& parameter)
{
  if(element==-1)
  {
    top=0;
  }
  element++;
  if (element== capacity)
  {
    DataType* temp = new DataType[capacity * 2];
    for (int i = 0, j=top; i <element; i++, j++)
    {
      temp[i] = data[j];
    }
    element=(element-top);
    top=0;
    delete [] data;
    data = temp;
    capacity=capacity*2;
  }
  //double the capacity
  data[element] = parameter;
}

template <class DataType>
DataType Queue<DataType>::peek() const
{
  DataType x=data[top];
  return x; // success
}

template <class DataType>
bool Queue<DataType>::pop()
{
  if (-1 == element)
  {
    return false; // failed
  }
  top=top+1;
  if((element-top)<=(capacity/4))
  {
    DataType* temp = new DataType[capacity/2];
    for (int i = 0, j=top; i <(element-top); i++, j++)
    {
      temp[i] = data[j];
    }
    element=(element-top);
    delete [] data;
    data = temp;
    capacity=capacity/2;
    top=0;
  }
  if(top==element)
  {
    top=-1;//empty queue
    element=-1;
  }
  return true; // success
}

template <class DataType>
void Queue<DataType>::makeEmpty()
{
  element=-1;
  top=-1;
}

#endif
