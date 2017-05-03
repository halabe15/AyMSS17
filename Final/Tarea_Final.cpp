/*

Tarea Final

Isaac Halabe
A01021800

halabe15@gmail.com

*/
#include <iostream>

using namespace std;

class MainClass{
public:
  int* p;
  MainClass(){
    p = new int;
  }

  ~MainClass(){
    delete p;
    p = NULL;
  }

  MainClass(const MainClass& o){
    this->p = new int();
    *(this->p) = *(o.p);
  }
};

class Child: public MainClass{};
class Father: public MainClass{};

int main(){
  Child a;
  Child b = a;
  *(a.p) = 5;
  cout << "p de Child 1 << " << *(a.p) << " >>  p de Child 2 << " << *(b.p) << " >>" << endl;

  Father c;
  Father d = c;
  *(c.p) = 5;
  cout << "p de Father 1 << " << *(c.p) << " >>  p de Father 2 << " << *(d.p) << " >>" << endl;
}
