#include "stdafx.h"
#include "Aluno.h"

Aluno::Aluno (): Pessoa() {
}

Aluno::Aluno (int diaN, int mesN, int anoN, char *S, int i):
  Pessoa(diaN, mesN, anoN, S) {
  setRA(i);
}

Aluno::~Aluno () {
}

void Aluno::setRA (int i) {
  RA = i;
}

int Aluno::getRA () {
  return RA;
}
