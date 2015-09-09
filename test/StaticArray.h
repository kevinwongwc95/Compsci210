 #ifndef StaticArray_h
#define StaticArray_h

template <class DataType, int CAPACITY>
class Array
{
public:
  int lsearch(const DataType& value) const;
  DataType& operator[](int index);
  DataType data[CAPACITY];
  
private:
  DataType dummy;
};

template <class DataType, int CAPACITY>
DataType& Array<DataType, CAPACITY>::operator[](int index)
{
  if (index < 0)
    return dummy;
  if (index >= CAPACITY)
    return dummy;
  return data[index];
}

template <class DataType, int CAPACITY>
int Array <DataType, CAPACITY>::lsearch(const DataType& value) const
{
  int result=-1;
  for(int i=0; i<CAPACITY; i++)
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



