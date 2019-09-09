#pragma once
#include "Universidade.h"

class elUniversidade {
private:
  Universidade *uni;
  elUniversidade *prox, *ant;

public:
  elUniversidade (Universidade *U);
  ~elUniversidade ();
  Universidade* getUni ();
  void setProx (elUniversidade *U);
  elUniversidade* getProx ();
  void setAnt (elUniversidade *U);
  elUniversidade* getAnt ();
};
