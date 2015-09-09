// Lab 2B, Writing Templated Classes
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef Rectangle_h
#define Rectangle_h

template <class DataType>
class Rectangle
{
public:
  void setlength(DataType a);
  void setwidth(DataType b);
  bool test();
  DataType area();
  DataType perimeter();

private:
  DataType length, width;
};

template <class DataType>
void Rectangle<DataType>::setlength(DataType a)
{
  length=a;
}

template <class DataType>
void Rectangle<DataType>::setwidth(DataType b)
{
  width=b;
}

template <class DataType>
bool Rectangle<DataType>::test()
{
  if (length>width)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template <class DataType>
DataType Rectangle <DataType>::area()
{
  return length*width;
}

template <class DataType>
DataType Rectangle<DataType>::perimeter()
{
  return ((2*length)+(2*width));
}

#endif
