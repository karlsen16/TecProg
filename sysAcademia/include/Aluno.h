#pragma once
#include "Pessoa.h"
class Disciplina;

class Aluno: public Pessoa {
private:
  int RA;

public:
  Aluno ();
  Aluno (int diaN, int mesN, int anoN, char *S, int i = 0);
  void inicializa (char *S, Disciplina *I);
  ~Aluno ();
  void setRA (int i);
  int getRA ();
  void matricula (Disciplina *I);
};
