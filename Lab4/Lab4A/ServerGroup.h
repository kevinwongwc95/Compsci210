// Lab 4A Introduction To Dynamic Arrays
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#ifndef ServerGroup_h
#define ServerGroup_h

class ServerGroup
{
public:
  ServerGroup(int a);
  bool spServerFree() const;
  bool serverFree();
  void useServer(int avTransTime);
  void usespServer(int avTransTime);
  void decServers();
  
private:
  int freeServer;
  int spServer;
  int size;
  int * tracker;
};

#endif
