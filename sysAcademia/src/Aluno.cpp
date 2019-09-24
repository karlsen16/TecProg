#include "stdafx.h"
#include "Aluno.h"
#include "Departamento.h"

Aluno::Aluno (): Pessoa() {
  setRA(0);
  setDep(NULL);
}

Aluno::Aluno (int diaN, int mesN, int anoN, string S, int ra, Departamento *D, int id):
  Pessoa(diaN, mesN, anoN, S, id) {
  setRA(ra);
  setDep(D);
}

Aluno::~Aluno () {
}

void Aluno::setRA (int ra) {
  RA = ra;
}

int Aluno::getRA () {
  return RA;
}

void setDep (Departamento *D) {
  dep = D;
}

Departamento* getDep () {
  return dep;
}
