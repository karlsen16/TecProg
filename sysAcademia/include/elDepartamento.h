#pragma once
#include "Departamento.h"

class elDepartamento {
private:
  Departamento *dep;
  elDepartamento *prox, *ant;

public:
  elDepartamento (Departamento *D);
  ~elDepartamento ();
  Departamento* getDep ();
  void setProx (elDepartamento *D);
  elDepartamento* getProx ();
  void setAnt (elDepartamento *D);
  elDepartamento* getAnt ();
};
