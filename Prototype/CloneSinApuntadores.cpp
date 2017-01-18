#include <iostream>
using namespace std;

class SubClass;
class Base
{
public:
    int value;
    int* secondValue;
    virtual SubClass clone() = 0;
};

class SubClass : public Base
{
public:
    SubClass clone()
    {
        return *this;
    }
};

int main()
{
    Base* a = new SubClass();
    a->value = 5;
    a->secondValue = new int(100);

    SubClass b = a->clone();
    b.value = 10;
    b.secondValue = new int(200);

    cout <<"a: " << *a->secondValue << endl;
    cout <<"b: " << *b.secondValue << endl;
}
