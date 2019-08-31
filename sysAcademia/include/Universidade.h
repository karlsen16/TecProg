#pragma once
#include "lDepartamento.h"

class Universidade {
private:
  char nome[150];
  lDepartamento *listaDepartamentos;

public:
  Universidade (char *S = "", int n = 1000);
  ~Universidade ();
  void setNome (char *S);
  char* getNome ();
  void imprimeUni ();
  void incluirDep (Departamento *D);
  void removeDep (Departamento *D);
  Departamento* getDepI (int i);
  void imprimeDep (int i);
  void imprimeDis (int i);
  void imprimeDepS ();
  void imprimeTudo ();
};
