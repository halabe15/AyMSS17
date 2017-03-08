#include <iostream>

template<class T>
class Iterator;

template<class T>
class Aggregate // Contenedor de elementos
{
protected:
    T* list;
    int size;
    int numElems;
public:
    friend Iterator<T>;
    Aggregate(int size = 10)
    {
        this->size = size;
        numElems = 0;
        list = new T[size];
    }
    void add(T value)
    {
        if(numElems<size)
        {
            list[numElems++] = value;
        }
    }
    Iterator<T>* createIterator();
};

template <class T>
class Iterator
{
protected:
  Aggregate<T>& container;
  int idx;
public:
  Iterator(Aggregate<T>& container) : container(container), idx(0){}

  T first(){
    idx = 0;
    return container.list[idx];
  }

  T next(){
    if(idx == 0){
      std::cout << "<<Error>>" << '\n';
      return container.list[idx];
    }

    if(idx<container.numElems)
      return container.list[++idx];
    else if (idx>= container.numElems)
      return

  }

  bool isDone(){
    if(container.numElems == idx+1)
      return true;
    return false;
  }

  T currentItem(){
    return container.list[idx];
  }

};

template<class T>
Iterator<T>* Aggregate<T>::createIterator()
{
    return new Iterator<T>(*this);
}

int main(){

  Aggregate<int> a(5);
  for(int i=0;i<5;i++){
    a.add(i+1);
  }

  Iterator<int>* it = a.createIterator();

  std::cout << it->first() << '\n';
  std::cout << it->next() << '\n';
  std::cout << it->next() << '\n';
  std::cout << it->next() << '\n';
  std::cout << it->next() << '\n';
  std::cout << it->currentItem() << '\n';


  if(it->isDone())
    std::cout << "Acabo" << '\n';
  else
    std::cout << "Todavia no" << '\n';
}
