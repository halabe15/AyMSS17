#include <iostream>

using namespace std;

class Product
{
public:
    virtual void operacion1() = 0;
    virtual void operacion2() = 0;

    template <class T>
    static Product* factoryMethod()
    {
        T* t = new T;
        t->operacion1();
        t->operacion2();
        return t;
    }
};

class Prod1 : public Product
{
public:
    void operacion1(){ cout << "OP1 de Prod1" << endl; }
    void operacion2(){ cout << "OP2 de Prod1" << endl; }
};

class Prod2 : public Product
{
public:
    void operacion1(){ cout << "OP1 de Prod2" << endl; }
    void operacion2(){ cout << "OP2 de Prod2" << endl; }
};

int main()
{
    Product* miProducto1 = Product::factoryMethod<Prod1>();

    Product* miProducto2 = Product::factoryMethod<Prod2>();

}
