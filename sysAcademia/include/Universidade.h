#pragma once
#include "Departamento.h"
#include <vector>
using namespace std;

class Universidade {
private:
  char nome[50];
  vector<Departamento*> D;

public:
  Universidade (char *S = "", Departamento *dep = NULL);
  ~Universidade ();
  void setNome (char *S);
  char* getNome ();
  void imprimeUni ();
  void setDep (Departamento *dep);
  void imprimeDep (int i);
  void imprimeDepS ();
};
