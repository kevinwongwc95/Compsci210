//LAB 10a: Write And Test The ListedList Class Template
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef LinkedList_h
#define LinkedList_h

template <class DataType>
struct Node
{
  DataType data;
  Node<DataType>* next;
};

template <class DataType>
class LinkedList
{
private:
  Node<DataType>* start; // initially zero
  Node<DataType>* current; // possibly zero
  int currentIndex=-1;
  int sizeCounter=0;
  
  
public:
  LinkedList(); //default constructor;
  void insert(const DataType&);
  bool first(DataType&);
  bool getNext(DataType&);
  bool find(const DataType&);
  bool retrieve(DataType&);
  bool replace(const DataType&);
  bool remove(DataType&);
  bool isEmpty() const;
  void makeEmpty();
  int length () const;
  DataType& operator[](int index);
  LinkedList<DataType>& operator=(const LinkedList<DataType>&);
  ~LinkedList(); //destructor
  LinkedList(const LinkedList<DataType>&); //copy constructor
  DataType dummy;
  
};

//default constructor
template <class DataType>
LinkedList<DataType>::LinkedList(): start(0), current(0)
{
}

// insert:add to front of list
template <class DataType>
void LinkedList<DataType>::insert(const DataType& parameter) // O(1)
{
  current =0;
  currentIndex=-1;
  Node<DataType>* node = new Node<DataType>;
  node->data = parameter;
  node->next = start;
  start = node;
  sizeCounter++;
}

//first:retrieve first element
template <class DataType>
bool LinkedList<DataType>::first(DataType& parameter) // O(1)
{
  if (!start) return false;
  parameter = start->data;
  current = start;
  currentIndex=0;
  return true;
}

//getNext: retrieve next element
template <class DataType>
bool LinkedList<DataType>::getNext(DataType& parameter) // O(1)
{
  if (!current) return false;
  current = current->next;
  currentIndex++;
  if (!current) return false;
  parameter = current->data;
  return true;
}

//find: true if matching element found
template <class DataType>
bool LinkedList<DataType>::find(const DataType& parameter) // O(n)
{
  DataType temp;
  if (first(temp)) do
  {
    if (parameter == temp) return true; // found it
  } while (getNext(temp));
  return false; // no match
}

template <class DataType>
bool LinkedList<DataType>::retrieve(DataType& parameter) // O(n)
{
  if (!find(parameter)) return false;
  parameter = current->data; // set in find
  return true;
}

template <class DataType>
bool LinkedList<DataType>::replace(const DataType& parameter) // O(1)
{
  if (!current) return false;
  current->data = parameter;
  return true;
}

template <class DataType>
bool LinkedList<DataType>::remove(DataType& parameter) // O(n)
{
  // find node to remove
  Node<DataType>* p;
  Node<DataType>* prev;
  for (prev = 0, p = start; p; prev = p, p = p->next)
    if (p->data == parameter)
      break;
  
  // deallocate node here
  if (!p) return false; // no match
  if (prev) prev->next = p->next; else start = p->next;
  if (p == current)
  {
    current = current->next;
    currentIndex++;
  }
  parameter = p->data;
  delete p;
  sizeCounter=sizeCounter-1;
  return true;
}

//isEmpty function check if empty
template <class DataType>
bool LinkedList<DataType>::isEmpty() const // O(1)
{
  return start == 0;
}

template <class DataType>
void LinkedList<DataType>::makeEmpty() // O(n)
{
  while (start)
  {
    current = start->next;
    delete start;
    start = current;
  }
  sizeCounter=0;
  currentIndex=-1;
}

//getter for size of Linked List
template <class DataType>
int LinkedList <DataType> ::length() const
{
  int temp;
  temp=sizeCounter;
  return sizeCounter;
}

template <class DataType>
LinkedList<DataType>& LinkedList<DataType>::operator=(const LinkedList<DataType>& a)
{
  if (this != &a)
  {
    current = 0;
    Node<DataType>* p;
    Node<DataType>* end = 0;
    while (start)
    {
      p = start->next;
      delete start;
      start = p;
    }
    for (p = a.start; p; p = p->next)
    {
      Node<DataType>* node = new Node<DataType>;
      node->data = p->data;
      node->next = 0;
      if (end) end->next = node;
      else start = node;
      end = node;
      if (p == a.current) current = node;
    }
  }
  return *this;
}

template <class DataType>
DataType& LinkedList<DataType>::operator[](int index)
{
  if(index>=sizeCounter || index<0)
  {
    return dummy;
  }
  else if(index==currentIndex)
  {
    return current->data;
  }
  else if(index == currentIndex + 1 && index>0)
  {
    current = current->next;
    currentIndex++;
    return current->data;
  }
  else
  {
    DataType x;
    if (first(x)) do
    {
      if(index==currentIndex)
      {
        break;
      }
    } while (getNext(x));
    return current->data;
  }
}


//Destructor For Any Linked List
template <class DataType>
LinkedList<DataType>::~LinkedList()
{
  Node<DataType>* p;
  while (start)
  {
    p = start->next;
    delete start;
    start = p;
  }
}

template <class DataType>
LinkedList<DataType>::LinkedList(const LinkedList<DataType>& a)
: start(0), current(0)
{
  Node<DataType>* p;
  Node<DataType>* end = 0;
  for (p = a.start; p; p = p->next)
  {
    Node<DataType>* node = new Node<DataType>;
    node->data = p->data;
    node->next = 0;
    if (end) end->next = node;
    else start = node;
    end = node;
    if (p == a.current) current = node;
  }
}

#endif
