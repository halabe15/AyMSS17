#include <iostream>
#include <vector>

struct A{

  int x, y;

  // Default Constructor, default initialization
  A() = default;
  // A(int x = 0) : x(x){
  //   std::cout << "Default constructor" << '\n';
  // }

  // Params constructor
  explicit A(int x, int y) : x(x), y(y){
    std::cout << "Params Constructor" << '\n';
  }

  // Copy constructor
  A(const A&){
    std::cout << "Copy Constructor" << '\n';
  }

  // Move constructor
  A(A&& a){
    std::cout << "Move Constructor" << '\n';
    x = a.x;
  }
};


A llamaCopyConstructor(A a){
  A tmp(a);
  return tmp;
}

int main(){
  A uno;
  A dos(5, 10);
  A tres(dos);
  llamaCopyConstructor(uno);

  std::vector<A> myVect;
  myVect.push_back(A(1,2));

  A a(A(1,1));

}
