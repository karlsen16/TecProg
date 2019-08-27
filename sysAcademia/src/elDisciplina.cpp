#include "stdafx.h"
#include "elDisciplina.h"

elDisciplina::elDisciplina (Disciplina *D) {
  dis = D;
  prox = ant = NULL;
}

elDisciplina::~elDisciplina () {
  dis = NULL;
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
