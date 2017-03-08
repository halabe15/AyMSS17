#include <iostream>
#include <vector>
#include <string.h>

class Observer;
class Subject{
protected:
  std::string dice;
  std::vector<Observer *> obs;
  std::string nombre;

public:
  Subject() = default;
  Subject(std::string nombre) : nombre(nombre){}
  Subject(std::string dice, std::string nombre) : dice(dice), nombre(nombre){}

  void setDice(std::string dice){
    this->dice = dice;
    notify();
  }

  std::string getDice(){
    return dice;
  }

  void setNombre(std::string nombre){
    this->nombre = nombre;
  }

  std::string getNombre(){
    return nombre;
  }

  void addObserver(Observer * ob){
    obs.push_back(ob);
  }

  void notify();
};

class Observer {
protected:
  std::string nombre;

public:
  Observer() = default;
  Observer(std::string nombre) : nombre(nombre){}

  void setNombre(std::string nombre){
    this->nombre = nombre;
  }

  std::string getNombre(){
    return nombre;
  }

  void sigue(Subject* s){
    s->addObserver(this);
  }

  void escucha(Subject* s){
    std::cout << "Soy "<< getNombre() <<" y " << s->getNombre() << " dijo: " << s->getDice() << '\n';
  }

};

void Subject::notify(){
  for(int i=0;i<obs.size();i++)
    obs[i]->escucha(this);
}

int main() {
  Subject* penia = new Subject("Peña");
  Subject* trump = new Subject("Trump");

  Observer* reforma = new Observer("Reforma");
  Observer* televisa = new Observer("Televisa");
  Observer* nbc = new Observer("NBC News");

  reforma->sigue(penia);
  televisa->sigue(penia);
  nbc->sigue(penia);

  reforma->sigue(trump);
  televisa->sigue(trump);
  nbc->sigue(trump);

  penia->setDice("Soy Peña");
  trump->setDice("Soy Trump");

  return 0;
}
