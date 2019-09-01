#include "stdafx.h"
#include "elDisciplina.h"

elDisciplina::elDisciplina (Disciplina *D) {
  dis = D;
  prox = ant = NULL;
  prof = NULL;
  setID(id);
}

elDisciplina::~elDisciplina () {
  dis = NULL;
  prof = NULL;
  prox = ant = NULL;
}

Disciplina* elDisciplina::getDis () {
  return dis;
}

void elDisciplina::setID (int id) {
  ID = id;
}

int elDisciplina::getID () {
  return ID;
}

void elDisciplina::setProx (elDisciplina *D) {
  prox = D;
}

elDisciplina* elDisciplina::getProx () {
  return prox;
}

void elDisciplina::setAnt (elDisciplina *D) {
  ant = D;
}

elDisciplina* elDisciplina::getAnt () {
  return ant;
}

void elDisciplina::setProf (Professor *P) {
  prof = P;
}

Professor* elDisciplina::getProf () {
  return prof;
}
