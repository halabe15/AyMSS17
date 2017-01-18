#include <iostream>

class Product {
public:
  virtual void setUp() = 0;
};

class Prod1 : public Product{
public:
  void setUp(){
    std::cout << "Constructor del objeto complejo" << '\n';
  }
};

class FactoryMethod{

protected:
  virtual Product * factoryMethod() = 0;


public:
  static Product * create(){
    Product* p = factoryMethod();
    p->setUp();
    return p;
  }

};

class ConcreteFactory : public FactoryMethod {

  Product* factoryMethod(){
    return new Prod1;
  }

};



int main()
{
  Product * p = FactoryMethod::create();
}
