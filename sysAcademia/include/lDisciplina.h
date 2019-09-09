#pragma once
#include "elDisciplina.h"

class lDisciplina {
private:
  char nome[150];
  int nDisciplinas, contDisciplinas;
  elDisciplina *pDisIni, *pDisAtual;

public:
  lDisciplina (char *S = "", int n = 1000);
  ~lDisciplina ();
  void setNome (char *S);
  char* getNome ();
  void setNum (int n);
  void addDis (Disciplina *D);
  Disciplina* getDis (char *S);
  void removeDis (char *S);
  elDisciplina* getelDis (char *S);
  void imprimeDiss ();
};
