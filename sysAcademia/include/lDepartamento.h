#pragma once
#include "elDepartamento.h"

class lDepartamento {
private:
  char nome[150];
  int nDepartamentos, contDepartamentos;
  elDepartamento *pDepIni, *pDepAtual;

public:
  lDepartamento (char *S = "", int n = 1000);
  ~lDepartamento ();
  void setNome (char *S);
  char* getNome ();
  void setNum (int n);
  void addDep (Departamento *D);
  Departamento* getDep (char *S);
  void removeDep (char *S);
  void imprimeDeps ();
};
