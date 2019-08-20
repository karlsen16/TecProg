#include "stdafx.h"
#include "Professor.h"

Professor::Professor (): Pessoa() {
}

Professor::Professor (int diaN, int mesN, int anoN, char *S,
                Universidade *U, Departamento *D):
  Pessoa(diaN, mesN, anoN, S) {
  setUni(U);
  setDep(D);
}

Professor::~Professor () {
  setUni(NULL);
  setDep(NULL);
}

void Professor::setUni (Universidade *U) {
  uni = U;
}

Universidade* Professor::getUni () {
  return uni;
}

void Professor::printUni () {
  uni->imprimeUni();
}

void Professor::setDep (Departamento *D) {
  dep = D;
}

Departamento* Professor::getDep () {
  return dep;
}

void Professor::printDep () {
  dep->imprimeDep();
}

void Professor::imprimeTudo () {
  imprimeIdade();
  printUni();
  printDep();
}
