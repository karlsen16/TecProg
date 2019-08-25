#include "stdafx.h"
#include "Aluno.h"
#include "Disciplina.h"

Aluno::Aluno (): Pessoa() {
  prox = ant = NULL;
  setRA(0);
}

Aluno::Aluno (int diaN, int mesN, int anoN, char *S, int i):
  Pessoa(diaN, mesN, anoN, S) {
  prox = ant = NULL;
  setRA(i);
}

void Aluno::inicializa (char *S, Disciplina *I) {
  setNome(S);
  matricula(I);
}

Aluno::~Aluno () {
  prox = ant = NULL;
}

void Aluno::setRA (int i) {
  RA = i;
}

int Aluno::getRA () {
  return RA;
}

void Aluno::setProx (Aluno *p) {
  prox = p;
}

Aluno* Aluno::getProx () {
  return prox;
}

void Aluno::setAnt (Aluno *p) {
  ant = p;
}

Aluno* Aluno::getAnt () {
  return ant;
}

void Aluno::matricula (Disciplina *I) {
  I->addAluno(this);
}
