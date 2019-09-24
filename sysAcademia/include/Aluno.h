#pragma once
#include "Pessoa.h"
class Departamento;

class Aluno: public Pessoa {
private:
  int RA;
  Departamento *dep;

public:
  Aluno ();
  Aluno (int diaN, int mesN, int anoN, string S, int ra = 0, Departamento *D = NULL, int id = 0);
  ~Aluno ();
  void setRA (int ra);
  int getRA ();
  void setDep (Departamento *D);
  Departamento* getDep ();
};
