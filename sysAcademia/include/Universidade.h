#pragma once
#include "Departamento.h"

class Universidade {
private:
  char nome[150];
  vector<Departamento*> D;

public:
  Universidade ();
  Universidade (char *S, Departamento *dep);
  void inicializa (char *S = "", Departamento *dep = NULL);
  ~Universidade ();
  void setNome (char *S);
  char* getNome ();
  void imprimeUni ();
  void incluirDep (Departamento *dep);
  void imprimeDep (int i);
  void imprimeDis (int i);
  void imprimeDepS ();
  void imprimeTudo ();
};
