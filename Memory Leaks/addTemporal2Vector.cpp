/*
    Agregar elementos a un vector puede hacerse de dos formas:
    
    1) The new element is initialized as a copy of value.
    2) value is moved into the new element.
    
    los prototipos de la función push_back son los siguientes (respectivamente)
    
    (1) void push_back( const T& value );
	
    (2) void push_back( T&& value );    //(since C++11)

*/

#include <iostream>
#include<vector>
using namespace std;

class Object
{
public:
    int attr1;
    ~Object()
    {
        cout << "destructor called with attr" << attr1 << endl;
    }
};

vector<Object*> vo;

void addTemporal(int val)
{
    Object* a = new Object;
    a->attr1 = val;
    vo.push_back(a);
    //delete a;  
    /*si eliminamos la memoria aquí, entonces habrá problemas porque el 
      objeto que que se agregó al vector "a" fue "movido", utilizando move semantics,
      dentro del vector por lo tanto si liberamos el espacio de a, habrá un  memory leak
    */
}

int main()
{
    addTemporal(5);
    cout << vo.at(0)->attr1 << endl;
    //delete vo.at(0);  
    /* aquí sí se debe liberar la memoria reservada en la posición 0, de lo contrario
    habrá un memory Leak
    */
    vo.pop_back();
};