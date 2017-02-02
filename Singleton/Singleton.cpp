#include <time.h>
#include <iostream>

class Singleton{

private:

  Singleton(){
    instance = this;
  }
  static Singleton * instance;
  time_t tmp;
  struct tm * tiempo;

public:

  void doStuff(){
    std::cout << instance << '\n';
  }

  static Singleton * getSingleton(){
      // if(instance != 0){
      //   return instance;
      // } else {
      //   Singleton();
      //   return instance;
      // }
      static Singleton instance;
      return &instance;
  }

  void getTime(){
      tmp = time(&tmp);
      tiempo = localtime (&tmp);
      std::cout << asctime(tiempo)<<std::endl;
    }

};

Singleton * Singleton::instance = 0;

int main()
{
  Singleton * r = Singleton::getSingleton();
  r->doStuff();
  r->getTime();
  int x;
  std::cin >> x;
  Singleton * r2 = Singleton::getSingleton();
  r2->doStuff();
  r2->getTime();
}
