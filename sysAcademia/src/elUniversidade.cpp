#include "stdafx.h"
#include "elUniversidade.h"

elUniversidade::elUniversidade (Universidade *U) {
  uni = U;
  prox = ant = NULL;
}

elUniversidade::~elUniversidade () {
  uni = NULL;
  prox = ant = NULL;
}

Universidade* elUniversidade::getUni () {
  return uni;
}

void elUniversidade::setProx (elUniversidade *U) {
  prox = U;
}

elUniversidade* elUniversidade::getProx () {
  return prox;
}

void elUniversidade::setAnt (elUniversidade *U) {
  ant = U;
}

elUniversidade* elUniversidade::getAnt () {
  return ant;
}
