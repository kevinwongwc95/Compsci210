// Lab 3C, const And Constructors, Part 3
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler


#ifndef Rectangle_h
#define Rectangle_h

template <class DataType>
class Rectangle
{
public:
  Rectangle();
  Rectangle(const DataType& a, const DataType& b);
  void setlength(const DataType& a);
  void setwidth(const DataType& b);
  DataType area() const;
  DataType perimeter() const;
  
private:
  DataType length, width;
  bool test() const;
};

template <class DataType>
Rectangle<DataType>::Rectangle()
{
}

template <class DataType>
Rectangle<DataType>::Rectangle(const DataType& a, const DataType& b)
{
  length=a;
  width=b;
}

template <class DataType>
void Rectangle<DataType>::setlength(const DataType& a)
{
  length=a;
}

template <class DataType>
void Rectangle<DataType>::setwidth(const DataType& b)
{
  width=b;
}

template <class DataType>
bool Rectangle<DataType>::test() const
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
DataType Rectangle <DataType>::area() const
{
  return length*width;
}

template <class DataType>
DataType Rectangle<DataType>::perimeter() const
{
  return ((2*length)+(2*width));
}

#endif
