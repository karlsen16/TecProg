#pragma once
#include "elDepartamento.h"

class Universidade {
private:
  char nome[150];
  elDepartamento *pDepIni, *pDepAtual;

public:
  Universidade (char *S = "");
  ~Universidade ();
  void setNome (char *S);
  char* getNome ();
  void imprimeUni ();
  void incluirDep (Departamento *dep);
  Departamento* getDepI (int i);
  void imprimeDep (int i);
  void imprimeDis (int i);
  void imprimeDepS ();
  void imprimeTudo ();
};
