// Lab 6B Using Dynamic Memory Allocation
// Programmer: Kevin Wong
// Editor(s) used: Codeblocks
// Compiler(s) used: GNU GCC Compiler

#include<iostream>
using std::cout;
using std::endl;
using std::ostream;

class Route;

class Leg
{
private:
	const char* const startLeg;
	const char* const endLeg;
	const int distance;
public:
	Leg(const char* const first,const char* const second, const double miles):startLeg(first),endLeg(second), distance(miles){};
	friend class Route;
	friend void outputLeg(ostream&, const Leg&);
	friend void outputRoute(ostream&, const Route&);
};

class Route
{
private:
	const Leg** leg;
	int counter;
	double totaldistance;
public:
	Route(const Leg&);
	Route(const Route&, const Leg&);
	Route(const Route&);
	~Route()//destructor
  {
    delete[] leg;
  }
	friend void outputRoute(ostream&, const Route&);
};

Route::Route(const Leg& a):leg(new const Leg*[1])//constructor that take in a leg to create a route
{
  counter=1;
  totaldistance=(a.distance);
	leg[0]=&a;
}

Route::Route(const Route& routeA, const Leg& legA):leg(new const Leg*[routeA.counter+1]) //construcotr that adds a leg to an existing route
{
  counter=routeA.counter+1;
  totaldistance=routeA.totaldistance+legA.distance;
	for(int i = 0; i< counter-1; i++)
		leg[i] = routeA.leg[i];

	leg[routeA.counter]=&legA;
}

Route::Route(const Route& a):leg(new const Leg*[counter]) //copy constructor
{
  counter=a.counter;
  totaldistance=a.totaldistance;
	for(int i=0; i<a.counter+1; i++)
		leg[i]=a.leg[i];
}

void outputLeg(ostream&, const Leg&);
void outputRoute(ostream&, const Route&);

int main()
{

  cout << "Lab 6B, Using Dynamic Memory Allocation b\n";
  cout << "Programmer: Kevin Wong\n";
  cout << "Editor(s) used: Codeblocks\n";
  cout << "Compiler(s) used: GNU GCC Compiler\n";
  cout << "File: " << __FILE__ << endl;
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl;

	//creates the legs and prints out the info
	Leg a("Walnut Creek", "San Francisco", 25);
  Leg b("San Francisco", "San Jose", 50);
  Leg c("San Jose", "Los Angeles", 400);
  Leg d("Los Angeles", "Las Vegas", 250);
  Leg e("Las Vegas", "Pheonix", 300);

  //prints legs
	outputLeg(cout, a);
	outputLeg(cout, b);
	outputLeg(cout, c);
	outputLeg(cout, d);
	outputLeg(cout, e);

	//create 5 routes
	Route ra(a);
	Route rb(ra, b);
	Route rc(rb, c);
	Route rd(rc, d);
	Route re(rd, e);

  { // start local scope
    Route rCopy = ra;
    outputRoute(cout, rCopy);
  } // end local scope

	outputRoute(cout, re);
	cout << endl;

}

//output route cities, and total distance
void outputRoute(ostream& out, const Route& route)
{
  out<<route.leg[0]->startLeg;

  for (int i=1; i<route.counter; i++)
  {
    out<<" to " <<route.leg[i]->startLeg;
  }

  out<<" to " <<route.leg[route.counter-1]->endLeg<< ": "<< route.totaldistance<<" miles "<<endl;
}

void outputLeg(ostream& out, const Leg& journey)
{
  out<<journey.startLeg<<" to "<<journey.endLeg<<": "<<journey.distance<<" miles"<<endl;
}
