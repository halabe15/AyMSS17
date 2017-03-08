#pragma once // Es como IF DEF de C

class Wife; // Declaras Wife antes para utilizarlo
class Husband{
public:
  std::string name;
  Wife* w; // Tiene que ser apuntador pq Wife todavia no se crea
  void addWife();
};

#include "Wife.h"
void Husband::addWife(){
  h = new Wife;
}
