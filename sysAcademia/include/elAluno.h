#pragma once
#include "Aluno.h"

class elAluno {
private:
  Aluno *alu;
  elAluno *prox, *ant;
  float P1, P2, F;
  int ID, faltas;

public:
  elAluno (Aluno *L, int id = 0);
  ~elAluno ();
  Aluno* getAluno ();
  void setID (int id);
  int getID ();
  void setProx (elAluno *p);
  elAluno* getProx ();
  void setAnt (elAluno *p);
  elAluno* getAnt ();
  void setP1 (float nota);
  float getP1 ();
  void setP2 (float nota);
  float getP2 ();
  void setFinal (float nota);
  float getFinal ();
  void faltou ();
  int getFaltas ();
};
