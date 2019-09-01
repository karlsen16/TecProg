#pragma once
#include "elUniversidade.h"

class lUniversidade {
private:
  char nome[150];
  int ID, nUniversidades, contUniversidades;
  elUniversidade *pUniIni, *pUniAtual;

public:
  lUniversidade (char *S = "", int n = 100, int id = 0);
  ~lUniversidade ();
  void setNome (char *S);
  char* getNome ();
  void setID (int id);
  int getID ();
  void setNum (int n);
  void addUni (Universidade *U);
  void removeUni (Universidade *U);
  Universidade* getUniI (int i);
};
