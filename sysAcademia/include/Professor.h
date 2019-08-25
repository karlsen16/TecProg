#pragma once
#include "Universidade.h"
#include "Pessoa.h"

class Professor: public Pessoa {
private:
  Universidade *uni;
  Departamento *dep;

public:
  Professor ();
  Professor (int diaN, int mesN, int anoN, char *S,
             Universidade *U, Departamento *D);
  void inicializa (int diaN, int mesN, int anoN, char *S,
             Universidade *U = NULL, Departamento *D = NULL);
  ~Professor ();
  void setUni (Universidade *U);
  Universidade* getUni ();
  void printUni ();
  void setDep (Departamento *D);
  Departamento* getDep ();
  void printDep ();
  void imprimeTudo ();
};
