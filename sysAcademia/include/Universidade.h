#pragma once
#include "lDepartamento.h"

class Universidade {
private:
  char nome[150];
  lDepartamento *listaDepartamentos;
  int ID;

public:
  Universidade (char *S = "", int n = 1000, int id = 0);
  ~Universidade ();
  void setNome (char *S);
  char* getNome ();
  void setID (int id);
  int getID ();

  void addDep (Departamento *D);
  Departamento* getDep (char *S);
  void removeDep (char *S);
  void imprimeDeps ();
};
