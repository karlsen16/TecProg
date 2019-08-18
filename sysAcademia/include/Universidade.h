#pragma once
#include "Departamento.h"

class Universidade {
private:
  char nome[30];
  Departamento *D;

public:
  Universidade (char *S = "", Departamento *dep = NULL);
  ~Universidade ();
  void setNome (char *S);
  char* getNome ();
  void imprimeUni ();
  void setDep (Departamento *N);
  void* imprimeDep ();
};
