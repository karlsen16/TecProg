#pragma once
#include "elDepartamento.h"

class lDepartamento {
private:
  char nome[150];
  int ID, nDepartamentos, contDepartamentos;
  elDepartamento *pDepIni, *pDepAtual;

public:
  lDepartamento (char *S = "", int n = 1000, int id = 0);
  ~lDepartamento ();
  void setNome (char *S);
  char* getNome ();
  void setID (int id);
  int getID ();
  void setNum (int n);
  void incluirDep (Departamento *D);
  void removeDep (Departamento *D);
  Departamento* getDepI (int i);
  void imprimeDep (int i);
  void imprimeDis (int i);
  void imprimeDepS ();
  void imprimeTudo ();
};
