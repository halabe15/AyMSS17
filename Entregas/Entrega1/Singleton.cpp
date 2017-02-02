#include <iostream>
using namespace std;

class Personaje
{
private:
  Personaje(){
    instance = this;
  }

  static Personaje * instance;

public:

  static Personaje * getPersonaje(){
    if(instance != 0){
      return instance;
    } else {
      Personaje();
      return instance;
    }
    // return &instance;
  }

    virtual void correr(){}
    virtual Personaje* clonar(){return this;}
};

template <class SubClase>
class ClonPersonaje : public Personaje
{
public:
    virtual Personaje* clonar()
    {
        return new SubClase(dynamic_cast<SubClase&>(*this));
    }
};

class Principe : public ClonPersonaje<Principe>
{
public:
    void seleccionarArma();
    void atacar();
    void correr()
    {
        cout << "El principe corre rápido" << endl;
    }
};

class Princesa : public ClonPersonaje<Princesa>
{
public:
    void gritar();
    void correr()
    {
        cout << "La princesa corre medio lento" << endl;
    }
};

class Villano : public ClonPersonaje<Villano>
{
public:
    void atacar();
    void atraparPricnesa();
    void correr()
    {
        cout << "El villano no necesita correr" << endl;
    }
};

class VillanoVolador : public ClonPersonaje<VillanoVolador>
{
public:
    void correr()
    {
        cout << "También puede volar" << endl;
    }
};

Personaje * Personaje::instance = 0;

int main()
{
    Personaje* villano = Personaje::getPersonaje();
    villano->correr();

    return 1;
}
