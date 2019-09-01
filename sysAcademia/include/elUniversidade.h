#pragma once
#include "Universidade.h"

class elUniversidade {
private:
  Universidade *uni;
  elUniversidade *prox, *ant;
  int ID;

public:
  elUniversidade (Universidade *U, int id = 0);
  ~elUniversidade ();
  Universidade* getUni ();
  void setID (int id);
  int getID ();
  void setProx (elUniversidade *U);
  elUniversidade* getProx ();
  void setAnt (elUniversidade *U);
  elUniversidade* getAnt ();
};
