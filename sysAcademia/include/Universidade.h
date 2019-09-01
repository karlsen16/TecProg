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
  void imprimeUni ();
  void incluirDep (Departamento *D);
  void removeDep (Departamento *D);
  Departamento* getDepI (int i);
  void imprimeDep (int i);
  void imprimeDis (int i);
  void imprimeDepS ();
  void imprimeTudo ();
};
