#pragma once
#include "Departamento.h"

class elDepartamento {
private:
  Departamento *dep;
  elDepartamento *prox, *ant;
  int ID;

public:
  elDepartamento (Departamento *D, int id = 0);
  ~elDepartamento ();
  Departamento* getDep ();
  void setID (int id);
  int getID ();
  void setProx (elDepartamento *D);
  elDepartamento* getProx ();
  void setAnt (elDepartamento *D);
  elDepartamento* getAnt ();
};
