#include "stdafx.h"
#include "elAluno.h"

elAluno::elAluno (Aluno *L) {
  alu = L;
  P1 = P2 = F = 0;
  faltas = 0;
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

void elAluno::setP1 (float nota) {
  P1 = nota;
}

float elAluno::getP1 () {
  return P1;
}

void elAluno::setP2 (float nota) {
  P2 = nota;
}

float elAluno::getP2 () {
  return P2;
}

void elAluno::setFinal (float nota) {
  F = nota;
}

float elAluno::getFinal () {
  return F;
}

void elAluno::faltou () {
  faltas++;
}

int elAluno::getFaltas () {
  return faltas;
}
