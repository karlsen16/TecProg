#pragma once
#include "Departamento.h"
#define QD 50

class Universidade {
private:
  char nome[50];
  Departamento* D[QD];

public:
  Universidade (char *S = "", Departamento *dep = NULL);
  ~Universidade ();
  void setNome (char *S);
  char* getNome ();
  void imprimeUni ();
  void setDep (Departamento *N, int i);
  void imprimeDep (int i);
  void imprimeDepS ();
};
