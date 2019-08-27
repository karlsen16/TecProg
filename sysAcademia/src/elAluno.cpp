#include "stdafx.h"
#include "elAluno.h"

elAluno::elAluno (Aluno *L) {
  alu = L;
  prox = ant = NULL;
}

elAluno::~elAluno () {
  alu = NULL;
  prox = ant = NULL;
}

Aluno* elAluno::getAluno () {
  return alu;
}

void elAluno::setProx (elAluno *p) {
  prox = p;
}

elAluno* elAluno::getProx () {
  return prox;
}

void elAluno::setAnt (elAluno *a) {
  ant = a;
}

elAluno* elAluno::getAnt () {
  return ant;
}
