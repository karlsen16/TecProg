#include "stdafx.h"
#include "elUniversidade.h"

elUniversidade::elUniversidade (Universidade *U, int id) {
  uni = U;
  prox = ant = NULL;
  setID(id);
}

elUniversidade::~elUniversidade () {
  uni = NULL;
  prox = ant = NULL;
}

Universidade* elUniversidade::getUni () {
  return uni;
}

void elUniversidade::setID (int id) {
  ID = id;
}

char* elUniversidade::getID () {
  return ID;
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
