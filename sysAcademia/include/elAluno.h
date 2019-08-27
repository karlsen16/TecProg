#pragma once
#include "Aluno.h"

class elAluno {
private:
  Aluno *alu;
  elAluno *prox, *ant;

public:
  elAluno (Aluno *L);
  ~elAluno ();
  Aluno* getAluno ();
  void setProx (elAluno *p);
  elAluno* getProx ();
  void setAnt (elAluno *p);
  elAluno* getAnt ();
};
