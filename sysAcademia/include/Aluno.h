#pragma once
#include "Pessoa.h"

class Aluno: public Pessoa {
private:
  int RA;

public:
  Aluno ();
  Aluno (int diaN, int mesN, int anoN, char *S, int i = 0);
  ~Aluno ();
  void setRA (int i);
  int getRA ();
};
