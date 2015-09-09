// Lab 6C Write Dynamic Array Class Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef DynamicArray_h
#define DynamicArray_h

template <class DataType>
class Array
{
public:
  Array(int); //constructor
  Array(const Array<DataType>& a); //copy constructor
  void changeCapacity(int newCapacity);//change capacity
  int lsearch(const DataType& data) const;//search
  Array<DataType>& operator=(const Array<DataType>& a);//equals operator
  ~Array();
  DataType* data;
  
private:
  int capacity;
};

//constructor
template <class DataType>
Array<DataType>::Array(int initialCapacity)
{
  capacity = initialCapacity;
  
  if (capacity <= 0)
    data = 0;
  else
    data = new DataType[capacity];
}

//copy constructor
template <class DataType>
Array<DataType>::Array(const Array<DataType>& a)
{
  capacity = a.capacity;
  data = 0;
  
  if (capacity > 0)
  {
    data = new DataType[capacity];
    for (int i = 0; i < capacity; i++)
      data[i] = a.data[i];
  }
}


//change capacity function
template <class DataType>
void Array<DataType>::changeCapacity(int newCapacity)
{
  if (newCapacity <= 0)
  {
    delete [] data;
    data = 0;
    capacity = newCapacity;
  }
  else
  {
    DataType* newData =
    new DataType[newCapacity];
    int limit = newCapacity > capacity ?
    capacity : newCapacity;
    for (int i = 0; i < limit; i++)
      newData[i] = data[i];
    delete [] data;
    data = newData;
    capacity = newCapacity;
  }
}

//= operator definition
template <class DataType>
Array<DataType>& Array<DataType>::operator=(const Array<DataType>& a)
{
  if (this == &a) return *this;
  
  delete [] data;
  capacity = a.capacity;
  data = 0;
  
  if (capacity > 0)
  {
    data = new DataType[capacity];
    for (int i = 0; i < capacity; i++)
      data[i] = a.data[i];
  }
  return *this;
}

//destructor
template <class DataType>
Array<DataType>::~Array()
{
  delete [] data;
}

//search function
template <class DataType>
int Array<DataType>::lsearch(const DataType& value) const
{
  int capacity=this->capacity;
  int result=-1;
  for(int i=0; i<capacity; i++)
  {
    if(data[i]==value)
    {
      result=i;
      break;
    }
  }
  
  return result;
}


#endif
