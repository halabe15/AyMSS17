/* Memory Leak
    
    Use a VIRTUAL DESTRUCTOR to avoid this memory leak
    if the destructor is not  declared virtual, then, as instance is of class Base 
    (line 25), then only the destructor of Base is called and the destructor of Child leaks
    
*/
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
    Base* polimorphicInstance = new Child();
    delete polimorphicInstance;
}