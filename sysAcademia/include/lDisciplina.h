#pragma once
#include "elDisciplina.h"

class lDisciplina {
private:
  char nome[150];
  int nDisciplinas, contDisciplinas;
  elDisciplina *pDisIni, *pDisAtual;

public:
  lDisciplina ();
  ~lDisciplina ();
  void setNome (char *S);
  char* getNome ();
  void setNum (int n);
  void incluirDis (Disciplina *D);
  void removeDis (Disciplina *D);
  void imprimeDis ();
  void imprimeDis2 ();
};
