#pragma once
#include "Pessoa.h"
class Disciplina;

class Aluno: public Pessoa {
private:
  int RA;

public:
  Aluno ();
  Aluno (int diaN, int mesN, int anoN, char *S, int i = 0);
  ~Aluno ();
  void setRA (int i);
  int getRA ();
  void matricula (Disciplina *I1 = NULL, Disciplina *I2 = NULL, Disciplina *I3 = NULL,
  Disciplina *I4 = NULL, Disciplina *I5 = NULL, Disciplina *I6 = NULL, Disciplina *I7 = NULL,
  Disciplina *I8 = NULL, Disciplina *I9 = NULL, Disciplina *I10 = NULL);
};
