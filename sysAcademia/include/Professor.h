#pragma once
class Universidade;
class Departamento;
#include "Pessoa.h"

class Professor: public Pessoa {
private:
  Universidade *uni;
  Departamento *dep;

public:
  Professor ();
  Professor (int diaN, int mesN, int anoN, char *S,
             Universidade *U, Departamento *D, int id);
  void inicializa (int diaN, int mesN, int anoN, char *S,
             Universidade *U = NULL, Departamento *D = NULL);
  ~Professor ();
  void setUni (Universidade *U);
  Universidade* getUni ();
  void printProf ();
  void printUni ();
  void setDep (Departamento *D);
  Departamento* getDep ();
  void printDep ();
  void imprimeTudo ();
};
