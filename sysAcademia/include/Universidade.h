#pragma once
#include "Departamento.h"

class Universidade: public Entidade {
private:
  Lista<Departamento> *listaDepartamentos;

public:
  Universidade (string S = "", int n = 1000, int id = 0);
  ~Universidade ();
  int getN();

  void addDep (Departamento *D);
  Departamento* getDep (string S);
  Disciplina* getDis (string S);
  void removeDep (string S);
  void imprimeDeps ();
  Lista<Departamento>* getLista ();

};
