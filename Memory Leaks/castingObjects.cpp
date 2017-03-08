#include<iostream>
using namespace std;

class Base
{
public:  
    int* p;
    Base(){ p = new int; }
    ~Base(){ delete p;} //must be virtual
};

class Child : public Base
{
public:
    int* myP;
    Child(){myP = new int; }
    ~Child(){delete myP; }
};

int main()
{
    Child* theChild = new Child();
    Base* polimorphicInstance = (Base*)theChild;
    
    // Memory leak because destructor of base is not virtual
    delete polimorphicInstance;
}