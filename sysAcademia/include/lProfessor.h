#pragma once
#include "elProfessor.h"

class lProfessor {
private:
  char nome[150];
  int ID, nProfessores, contProfessores;
  elProfessor *pPrfIni, *pPrfAtual;

public:
  lProfessor (char *S = "", int n = 1000, int id = 0);
  ~lProfessor ();
  void setNome (char *S);
  char* getNome ();
  void setID (int id);
  int getID ();
  void setNum (int n);
  void addProfessor (Professor *P);
  void removeProfessor (Professor *P);
  void imprimeProfs ();
  void imprimeProfs2 ();
};
