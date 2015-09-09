// Lab 4A Introduction To Dynamic Arrays
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include "ServerGroup.h"

ServerGroup:: ServerGroup(int a)
{
  size=a;
  int* servers=new int[size];
  tracker=servers;
  for (int i=0; i<size; i++)
  {
    servers[i]=0;
  }
  spServer=0;
}

bool ServerGroup::spServerFree() const
{
  bool result=false;
  if(spServer==0)
  {
    result=true;
    return result;
  }
  return result;
}

bool ServerGroup::serverFree()
{
  bool result=false;
  int a;
  for(int i=0;i<size;i++)
  {
    a=tracker[i];
    if(a==0)
    {
      freeServer=i;
      result=true;
      return result;
    }
  }
  return result;
}

void ServerGroup::useServer(int avTransTime)
{
  tracker[freeServer]=avTransTime;
}

void ServerGroup:: usespServer(int avTransTime)
{
  spServer=avTransTime;
}

void ServerGroup:: decServers()
{
  int a;
  
  if(spServer!=0)
  {
    spServer=spServer-1;
  }
  
  for(int i=0;i<size;i++)
  {
    a=tracker[i];
    if(a!=0)
    {
      a=a-1;
      tracker[i]=a;
    }
  }
}