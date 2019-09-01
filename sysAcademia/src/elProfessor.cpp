#include "stdafx.h"
#include "elProfessor.h"

elProfessor::elProfessor (Professor *P, int id) {
  prof = P;
  prox = ant = NULL;
  setID(id);
}

elProfessor::~elProfessor () {
  prof = NULL;
  prox = ant = NULL;
}

Professor* elProfessor::getProfessor () {
  return prof;
}

void elProfessor::setID (int id) {
  ID = id;
}

int elProfessor::getID () {
  return ID;
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
