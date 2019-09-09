#pragma once
#include "elUniversidade.h"

class lUniversidade {
private:
  char nome[150];
  int nUniversidades, contUniversidades;
  elUniversidade *pUniIni, *pUniAtual;

public:
  lUniversidade (char *S = "", int n = 100);
  ~lUniversidade ();
  void setNome (char *S);
  char* getNome ();
  void setNum (int n);
  void addUni (Universidade *U);
  Universidade* getUni (char *S);
  void removeUni (char *S);
  void imprimeUni (char *S);
};
