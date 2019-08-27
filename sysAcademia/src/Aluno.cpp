#include "stdafx.h"
#include "Aluno.h"
#include "Disciplina.h"

Aluno::Aluno (): Pessoa() {
  setRA(0);
}

Aluno::Aluno (int diaN, int mesN, int anoN, char *S, int i):
  Pessoa(diaN, mesN, anoN, S) {
  setRA(i);
}

void Aluno::inicializa (char *S, Disciplina *I) {
  setNome(S);
  matricula(I);
}

Aluno::~Aluno () {
}

void Aluno::setRA (int i) {
  RA = i;
}

int Aluno::getRA () {
  return RA;
}

void Aluno::matricula (Disciplina *I) {
  I->addAluno(this);
}
