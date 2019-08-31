#pragma once
#include "elDepartamento.h"

class lDepartamento {
private:
  char nome[150];
  int nDepartamentos, contDepartamentos;
  elDepartamento *pDepIni, *pDepAtual;

public:
  lDepartamento ();
  ~lDepartamento ();
  void setNome (char *S);
  char* getNome ();
  void setNum (int n);
  void incluirDep (Departamento *D);
  void removeDep (Departamento *D);
  Departamento* getDepI (int i);
  void imprimeDep (int i);
  void imprimeDis (int i);
  void imprimeDepS ();
  void imprimeTudo ();
};
