#include "stdafx.h"
#include "elProfessor.h"

elProfessor::elProfessor (Professor *P) {
  prof = P;
  prox = ant = NULL;
}

elProfessor::~elProfessor () {
  prof = NULL;
  prox = ant = NULL;
}

Professor* elProfessor::getPrf () {
  return prof;
}

void elProfessor::setProx (elProfessor *p) {
  prox = p;
}

elProfessor* elProfessor::getProx () {
  return prox;
}

void elProfessor::setAnt (elProfessor *a) {
  ant = a;
}

elProfessor* elProfessor::getAnt () {
  return ant;
}
