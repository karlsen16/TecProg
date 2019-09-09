#include "stdafx.h"
#include "Aluno.h"

Aluno::Aluno (): Pessoa() {
  setRA(0);
}

Aluno::Aluno (int diaN, int mesN, int anoN, char *S, int id, int ra):
  Pessoa(diaN, mesN, anoN, S, id) {
  setRA(ra);
}

Aluno::~Aluno () {
}

void Aluno::setRA (int ra) {
  RA = ra;
}

int Aluno::getRA () {
  return RA;
}
