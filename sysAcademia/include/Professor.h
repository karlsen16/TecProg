#pragma once
#include "Pessoa.h"
class Universidade;
class Departamento;

class Professor: public Pessoa {
private:
  Universidade *uni;
  Departamento *dep;

public:
  Professor ();
  Professor (int diaN, int mesN, int anoN, string S,
             Universidade *U, Departamento *D, int id);
  void inicializa (int diaN, int mesN, int anoN, string S,
             Universidade *U = NULL, Departamento *D = NULL);
  ~Professor ();
  void setUni (Universidade *U);
  Universidade* getUni ();
  void setDep (Departamento *D);
  Departamento* getDep ();
  
};
