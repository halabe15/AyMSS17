#include <iostream>

class ArrayNatPerfect;

class Proxy{
private:
  ArrayNatPerfect& arr;
  int idx;

public:
  Proxy(ArrayNatPerfect& arr, int idx) : arr(arr), idx(idx){}
  Proxy operator = (int value);
  friend std::ostream& operator << (std::ostream& os, Proxy&& p);
};

class ArrayNatPerfect{
private:
  int * arr;
  int size;

public:
  friend class Proxy;
  friend std::ostream& operator << (std::ostream& os, Proxy&& p);
  ArrayNatPerfect(int size) : size(size){
    arr = new int[size+1];
  }

  Proxy operator[](int index){

    if(index < 0 || index >= size){
      std::cout << "Error: No existe el índice" << std::endl;
      index = size;
      arr[index] = 0;
    }

    // return arr[index];
    return Proxy(*this, index);
  }

};

Proxy Proxy::operator = (int value){

  if(value >= 0){ // natural perfecto
    arr.arr[idx] = value;
  } else {
    std::cout << "Error no es natural perfecto" << '\n';
  }

  return *this;
}

std::ostream& operator << (std::ostream& os, Proxy&& p){
  os << p.arr.arr[p.idx];
  return os;
}

int main()
{
  ArrayNatPerfect a(5);
  for(int i = 0;i<=5;i++){
    a[i] = i-1;
  }

  std::cout << a[-1] << '\n';
  std::cout << a[2] << '\n';
  std::cout << a[5] << '\n';
}
