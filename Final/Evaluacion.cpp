/*

Evaluacion Final

Isaac Halabe
A01021800

halabe15@gmail.com

*/
#include <iostream>

class Factory;
class SpaceCraft;
class Asteroids;
class Planets;
class Visitor
{
public:
    virtual void visit(SpaceCraft*) = 0;
    virtual void visit(Asteroids*) = 0;
    virtual void visit(Planets*) = 0;

    template <class T>
    static T * getSingleton(){
        static T instance;
        return &instance;
      }
};

class CollideSpaceCraft : public Visitor {
public:
    void visit(SpaceCraft*){
        std::cout << "SpaceCraft colisiono contra otra SpaceCraft" << '\n';
    }
    void visit(Asteroids*){
      std::cout << "Asteroid colisiono contra SpaceCraft" << '\n';
    }
    void visit(Planets*){
      std::cout << "Planets colisiono contra SpaceCraft" << '\n';
    }
};

class CollideAsteroid : public Visitor {
public:
    void visit(SpaceCraft*){
        std::cout << "SpaceCraft colisiono contra Asteroid" << '\n';
    }
    void visit(Asteroids*){
      std::cout << "Asteroid colisiono contra otro Asteroid" << '\n';
    }
    void visit(Planets*){
      std::cout << "Planets colisiono contra Asteroid" << '\n';
    }
};

class CollidePlanet : public Visitor {
public:
    void visit(SpaceCraft*){
        std::cout << "SpaceCraft colisiono contra Planet" << '\n';
    }
    void visit(Asteroids*){
      std::cout << "Asteroid colisiono contra Planet" << '\n';
    }
    void visit(Planets*){
      std::cout << "Planets colisiono contra otro Planet" << '\n';
    }
};
class Factory{
public:

  template <class T>
  static T * getSingleton(){
      static T instance;
      return &instance;
  }

  virtual void operacion1() = 0;
  virtual void operacion2() = 0;
  virtual void operacion3() = 0;
  virtual void operacion4() = 0;
  virtual void operacion5() = 0;
  virtual void accept(Visitor* v) = 0;

  template <class T>
  static Factory* factoryMethod(){
    T * t = Factory::getSingleton<T>();
    t->operacion1();
    t->operacion2();
    t->operacion3();
    t->operacion4();
    t->operacion5();
    std::cout << '\n';
    return t;
  }
};

class SpaceCraft : public Factory{
public:

  void operacion1(){std::cout << "Op 1 de SpaceCraft" << '\n';}
  void operacion2(){std::cout << "Op 2 de SpaceCraft" << '\n';}
  void operacion3(){std::cout << "Op 3 de SpaceCraft" << '\n';}
  void operacion4(){std::cout << "Op 4 de SpaceCraft" << '\n';}
  void operacion5(){std::cout << "Op 5 de SpaceCraft" << '\n';}

  void accept(Visitor* v){
      v->visit(this);
  }
};

class Asteroids : public Factory{
public:

  void operacion1(){std::cout << "Op 1 de Asteroids" << '\n';}
  void operacion2(){std::cout << "Op 2 de Asteroids" << '\n';}
  void operacion3(){std::cout << "Op 3 de Asteroids" << '\n';}
  void operacion4(){std::cout << "Op 4 de Asteroids" << '\n';}
  void operacion5(){std::cout << "Op 5 de Asteroids" << '\n';}

  void accept(Visitor* v){
      v->visit(this);
  }
};

class Planets : public Factory{
public:

  void operacion1(){std::cout << "Op 1 de Planets" << '\n';}
  void operacion2(){std::cout << "Op 2 de Planets" << '\n';}
  void operacion3(){std::cout << "Op 3 de Planets" << '\n';}
  void operacion4(){std::cout << "Op 4 de Planets" << '\n';}
  void operacion5(){std::cout << "Op 5 de Planets" << '\n';}

  void accept(Visitor* v){
      v->visit(this);
  }
};

int main(){
  // Inicializamos los 3 elementos que crea FactoryMethod los creamos doble para verificar el Singleton
  Factory* prueba = Factory::factoryMethod<SpaceCraft>();
  Factory* prueba2 = Factory::factoryMethod<Asteroids>();
  Factory* prueba3 = Factory::factoryMethod<Planets>();
  Factory* prueba4 = Factory::factoryMethod<SpaceCraft>();
  Factory* prueba5 = Factory::factoryMethod<Asteroids>();
  Factory* prueba6 = Factory::factoryMethod<Planets>();

  // Inicializamos los Visitor de colisiones
  CollideSpaceCraft* colSpaceCraft = Visitor::getSingleton<CollideSpaceCraft>();
  CollideAsteroid* colAsteroid = Visitor::getSingleton<CollideAsteroid>();
  CollidePlanet* colPlanet = Visitor::getSingleton<CollidePlanet>();

  // Los metemos a Arrays para poder hacer loops
  Visitor* v[] = { colSpaceCraft, colAsteroid, colPlanet };
  Factory* f[] = {prueba, prueba2, prueba3, prueba4, prueba5, prueba6};
  int countVisitor = sizeof(v)/sizeof(Visitor*);
  int countFactory = sizeof(f)/sizeof(Factory*);

  std::cout << "Instancias de SpaceCraft" << '\n';
  std::cout << prueba << '\n';
  std::cout << prueba4 << '\n';
  std::cout << '\n';
  std::cout << "Instancias de Asteroids" << '\n';
  std::cout << prueba2 << '\n';
  std::cout << prueba5 << '\n';
  std::cout << '\n';
  std::cout << "Instancias de Planets" << '\n';
  std::cout << prueba3 << '\n';
  std::cout << prueba6 << '\n';
  std::cout << '\n';

  for(int i=0;i<countFactory;i++){
    for(int j=0;j<countVisitor;j++)
      f[i]->accept(v[j]);
    std::cout << '\n';
  }
}
