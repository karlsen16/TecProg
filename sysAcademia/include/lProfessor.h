#pragma once
#include "elProfessor.h"

class lProfessor {
private:
  char nome[150];
  int nProfessores, contProfessores;
  elProfessor *pPrfIni, *pPrfAtual;

public:
  lProfessor (char *S = "", int n = 1000);
  ~lProfessor ();
  void setNome (char *S);
  char* getNome ();
  void setNum (int n);
  void addProfessor (Professor *P);
  Professor* getPrf (char *S);
  void removeProfessor (char *S);
  void imprimeProfs ();
  void imprimeProfs2 ();
};
