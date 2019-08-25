#pragma once
#include "Pessoa.h"
class Disciplina;

class Aluno: public Pessoa {
private:
  int RA;
  Aluno *prox, *ant;

public:
  Aluno ();
  Aluno (int diaN, int mesN, int anoN, char *S, int i = 0);
  void inicializa (char *S, Disciplina *I);
  ~Aluno ();
  void setRA (int i);
  int getRA ();
  void setProx (Aluno *p);
  Aluno* getProx ();
  void setAnt (Aluno *p);
  Aluno* getAnt ();
  void matricula (Disciplina *I);
};
