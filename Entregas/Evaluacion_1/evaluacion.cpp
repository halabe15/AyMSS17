// Realiza un programa en C++ que facilite el trabajo de la empresa Chell A.S., una empresa dedicada a la producción, almacenamiento y distribución de videojuegos. Los tipos de videojuegos son:
// Estrategia (Lucha y Arcade)
// Aventura (Plataforma y Gráfica)
// Aprendizaje (Idiomas, Música)
// Se pide que inventes al menos 5 atributos para cada tipo de videojuego
// La creación de videojuegos involucra las siguientes operaciones:
// Concepción
// Diseño
// Planificación
// Producción
// Pruebas de aceptación
// Se pide que selecciones un (varios) patrón(es) que permiten encapsular la creación de videojuegos. Además, dado que se producen muchas copias de un mismo videojuego, se pide que agregues la operación clonar en cada tipo de videojuego
// Además de la definición de los productos se pide que elabores un almacén (una clase que encapsule los procesos de un almacén de videojuegos). Las operaciones disponibles para el almacén son:
// Crea el inventario:
// Pasa como parámetro el tamaño máximo de elementos del inventario
// Sólo hay una instancia del inventario, pero el tamaño del inventario puede crecer según se requiera (se sugiere utilizar un singleton)
// Selecciona una estructura de datos para guardar el almacén
// Agregar videojuegos al inventario
// Sí se pueden agregar más elementos de los que están disponibles en el almacén (el tamaño del almacén puede crecer si es necesario)
// Eliminar videojuegos del inventario (elimina por número de serie o por nombre).
// Incluye una función que permite deshacer las últimas tres operaciones de eliminar (re-hacer)
// Ordenar los videojuegos que se tienen disponibles
// Por precio de menor a mayor y viceversa
// Buscar videojuegos
// La búsqueda se puede realizar por número de serie (único) o por nombre
// Obtener el número total de elementos en el inventario
// Imprimir todos los elementos del inventario
// Crea un método que permita realizar operaciones sobre los precios de los productos del inventario. Las operaciones que se pueden realizar son incrementar o reducir el precio en un cierto porcentaje. Crea un método que reciba como parámetros el inventario y la función a realizar (operación: incremento, etc.).
// Agrega un menú en que se permita acceder a todas las funciones anteriores

#include <iostream>
#include <string>
#include <vector>

class SubClase;
class Videojuego{
protected:
  // Atributos
  std::string nombre;
  float precio;
  int edadMin;
  int edadMax;

public:
  // Constructor
  Videojuego(){}
  Videojuego(std::string n, float p, int eMin, int eMax) : nombre(n), precio(p), edadMin(eMin), edadMax(eMax){
    std::cout << "Constructor Parametros" << '\n';
  }

  void setNombre(std::string n){nombre = n;}
  void setPrecio(float p){precio = p;}
  void setEdadMin(int eMin){edadMin = eMin;}
  void setEdadMax(int eMax){edadMax = eMax;}

  std::string getNombre() {return nombre;}
  float getPrecio() {return precio;}
  int getEdadMin() {return edadMin;}
  int getEdadMax() {return edadMax;}

};

class SubClase : public Videojuego{
public:

  // Metodos
  virtual void concepcion() = 0;
  virtual void disenio() = 0;
  virtual void planificacion() = 0;
  virtual void produccion() = 0;
  virtual void pruebasDeAceptacion() = 0;

  // Fcatory Method
  template <class T>
  static T* factoryMethod(){
    T* t = new T;
    t->concepcion();
    t->disenio();
    t->planificacion();
    t->produccion();
    t->pruebasDeAceptacion();

    return t;
  }
};

class Estrategia : public SubClase{
private:
  int dificultad;

public:
  void concepcion(){
    std::cout << "Metodo de concepcion de estrategia\n";
  }
  void disenio(){
    std::cout << "Metodo de diseño de estrategia\n";
  }
  void planificacion(){
    std::cout << "Metodo de palnificacion de estrategia\n";
  }
  void produccion(){
    std::cout << "Metodo de produccion de estrategia\n";
  }
  void pruebasDeAceptacion(){
    std::cout << "Pruebas de Aceptación de estrategia\n";
  }

  Estrategia clonar(){
    return * this;
  }
};

class Aventura : public SubClase{
private:
  int NumeroPersonajes;

public:
  void concepcion(){
    std::cout << "Metodo de concepcion de aventura\n";
  }
  void disenio(){
    std::cout << "Metodo de diseño de aventura\n";
  }
  void planificacion(){
    std::cout << "Metodo de palnificacion de aventura\n";
  }
  void produccion(){
    std::cout << "Metodo de produccion de aventura\n";
  }
  void pruebasDeAceptacion(){
    std::cout << "Pruebas de Aceptación de aventura\n";
  }

  Aventura clonar(){
    return * this;
  }
};

class Aprendizaje : public SubClase{
private:
  float duracion;

public:
  void concepcion(){
    std::cout << "Metodo de concepcion de aprendizaje\n";
  }
  void disenio(){
    std::cout << "Metodo de diseño de aprendizaje\n";
  }
  void planificacion(){
    std::cout << "Metodo de palnificacion de aprendizaje\n";
  }
  void produccion(){
    std::cout << "Metodo de produccion de aprendizaje\n";
  }
  void pruebasDeAceptacion(){
    std::cout << "Pruebas de Aceptación de aprendizaje\n";
  }

  Aprendizaje clonar(){
    return * this;
  }
};

class Almacen : public Estrategia{
private:

  Almacen(){
    instance = this;
  }
  static Almacen * instance;

  std::vector<Estrategia> v;
  std::vector<Estrategia> papelera;

public:

  void agrega(Estrategia e){
    v.push_back(e);
    std::cout << v.back().getNombre() << " agregado correctamente" << '\n';
  }

  void elimina(int num){
    if(papelera.size() > 3){
      papelera.erase(papelera.begin());
    }
    papelera.push_back(v.at(num));
    v.erase(v.begin() + num);
    std::cout << papelera.back().getNombre() << " eliminado correctamente" << '\n';
  }

  void undo(){
    for(int i = 0; i<papelera.size(); i++){
      v.push_back(papelera.at(i));
      std::cout << papelera.at(i).getNombre() << " agregado de nuevo" << '\n';
    }

    if(!papelera.empty())
      papelera.clear();
  }

  void elementos(){
    std::cout << "Total de Videojuegos en el alamcen: " << v.size() << '\n';
  }

  void listar(){
    for(int i=0;i< v.size();i++)
      std::cout << i+1 << ": " << v.at(i).getNombre() << '\n';
  }

  static Almacen * getAlmacen(){
      static Almacen instance;
      return &instance;
  }

};

Almacen * Almacen::instance = 0;

void menu(){
  int choice = 0, num;
  bool almacenCreado = false;


  // Declaramos el almacen pero no lo creamos
  Almacen *a;
  // Creamos una clase de estrategia para clonar de aqui
  Estrategia * e = SubClase::factoryMethod<Estrategia>();

  // Creamos vector para os videojuegos fuera del alamcen
  std::vector<Estrategia> v;

  // Creamos Videojuegos Clones como ejemplo para que se ingresen al inventario
  Estrategia copia0 = e->clonar();
  Estrategia copia1 = e->clonar();
  Estrategia copia2 = e->clonar();
  Estrategia copia3 = e->clonar();
  Estrategia copia4 = e->clonar();
  Estrategia copia5 = e->clonar();

  // Les damos propiedades a las copias
  copia0.setNombre("Call Of Duty");
  copia1.setNombre("Gear of Wars");
  copia2.setNombre("Minecraft");
  copia3.setNombre("Super Mario");
  copia4.setNombre("Crazy Taxi");
  copia5.setNombre("FIFA");

  // Los metemos al vector
  v.push_back(copia0);
  v.push_back(copia1);
  v.push_back(copia2);
  v.push_back(copia3);
  v.push_back(copia4);
  v.push_back(copia5);


  do{
    std::cout << "\n\t\t/* Almacen */\n" << '\n';
    std::cout << "\t1. Crear inventario" << '\n';
    std::cout << "\t2. Agregar al inventario" << '\n';
    std::cout << "\t3. Elimina del inventario" << '\n';
    std::cout << "\t4. Deshacer las ultimas 3 acciones" << '\n';
    std::cout << "\t5. Listar videojuegos disponibles por precio de mayor a menor" << '\n';
    std::cout << "\t6. Listar videojuegos disponibles por precio de menor a mayor" << '\n';
    std::cout << "\t7. Buscar Videojuegos" << '\n';
    std::cout << "\t8. Total de inventario" << '\n';
    std::cout << "\t9. Listar todos los elementos del almacen" << '\n';
    std::cout << "\t10. Listar todos los elementos fuera del alamcen\n" << '\n';
    std::cout << "\t0. Salir" << '\n';

    std::cout << "Tu opción: ";
    std::cin >> choice;

    if((choice != 1 && !almacenCreado) && choice != 0){
      std::cout << "Opcion Invalida.. No has creado ningun almacen" << '\n';
      continue;
    }

    switch (choice) {
      case 0:
        std::cout << "1º Evaluacion - Isaac Halabe - A01021800" << '\n';
        break;

      case 1:
        std::cout << "Crear inventario" << '\n';
        a = Almacen::getAlmacen();
        almacenCreado = true;
        break;

      case 2:
        std::cout << "Agregar al inventario\n" << '\n';
        std::cout << "¿Cual es el numero del videojuego que deseas agregar?" << '\n';
        for(int i=0;i<v.size();i++)
          std::cout << i+1 << ": " << v.at(i).getNombre()<< '\n';
        std::cin >> num;
        a->agrega(v.at(num-1));
        v.erase(v.begin() + num-1);
        break;

      case 3:
        std::cout << "Elimina del inventario" << '\n';
        std::cout << "¿Cual es el numero del videojuego que deseas eliminar?" << '\n';
        a->listar();
        std::cin >> num;
        a->elimina(num-1);
        break;

      case 4:
        std::cout << "Agregar de nuevo los ultimos 3 videojuegos borrados" << '\n';
        a->undo();
        break;

      case 5:
        std::cout << "Listar videojuegos disponibles por precio de mayor a menor" << '\n';
        a->listar();
        break;

      case 6:
        std::cout << "Listar videojuegos disponibles por precio de menor a mayor" << '\n';
        a->listar();
        break;

      case 7:
        std::cout << "Buscar Videojuegos" << '\n';
        break;

      case 8:
        std::cout << "Total de inventario" << '\n';
        a->elementos();
        break;

      case 9:
        std::cout << "Listar todos los elementos del Alamcen" << '\n';
        a->listar();
        break;

      case 10:
        std::cout << "Listar todos los elementos fuera del almacen" << '\n';
        for(int i=0;i<v.size();i++)
          std::cout << i+1 << ": " << v.at(i).getNombre()<< '\n';
        break;

      default:
        std::cout << "Opcion no disponible" << '\n';
        break;
    }
  } while (choice != 0);

}

int main(){
  // Creamos un Videojuego de Estrategia
  Estrategia* estrategia = SubClase::factoryMethod<Estrategia>();

  // Lo Clonamos y modificamos variables
  Estrategia estrategia2 = estrategia->clonar();
  estrategia->setPrecio(60);
  estrategia2.setPrecio(70);
  std::cout << "Original: precio $"<< estrategia->getPrecio() << '\n';
  std::cout << "Clone: precio $"<< estrategia2.getPrecio() << "\n\n";

  // Creamos un Videojuego de Aventura
  Aventura* aventura = SubClase::factoryMethod<Aventura>();
  std::cout << "" << '\n';

  // Creamos un Videojuego de Aprendizaje
  Aprendizaje* aprendizaje = SubClase::factoryMethod<Aprendizaje>();
  std::cout << "\n\n";

  menu();
}
