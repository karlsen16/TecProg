#pragma once
#include "elDisciplina.h"

class lDisciplina {
private:
  char nome[150];
  int ID, nDisciplinas, contDisciplinas;
  elDisciplina *pDisIni, *pDisAtual;

public:
  lDisciplina (char *S = "", int n = 1000, int id = 0);
  ~lDisciplina ();
  void setNome (char *S);
  char* getNome ();
  void setID (int id);
  int getID ();
  void setNum (int n);
  void incluirDis (Disciplina *D);
  void removeDis (Disciplina *D);
  void imprimeDis ();
  void imprimeDis2 ();
};
