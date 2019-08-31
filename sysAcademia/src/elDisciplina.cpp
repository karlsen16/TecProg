#include "stdafx.h"
#include "elDisciplina.h"

elDisciplina::elDisciplina (Disciplina *D) {
  dis = D;
  prof = NULL;
  prox = ant = NULL;
}

elDisciplina::~elDisciplina () {
  dis = NULL;
  prof = NULL;
  prox = ant = NULL;
}

Disciplina* elDisciplina::getDis () {
  return dis;
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
