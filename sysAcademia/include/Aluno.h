#pragma once
#include "Pessoa.h"

class Aluno: public Pessoa {
private:
  int RA;

public:
  Aluno ();
  Aluno (int diaN, int mesN, int anoN, string S, int ra = 0, int id = 0);
  ~Aluno ();
  void setRA (int ra);
  int getRA ();
};
