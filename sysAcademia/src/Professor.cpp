#include "stdafx.h"
#include "Professor.h"
#include "Universidade.h"
#include "Departamento.h"

Professor::Professor (): Pessoa() {
  inicializa(0, 0, 0, "");
}

Professor::Professor (int diaN, int mesN, int anoN, char *S,
                Universidade *U, Departamento *D, int id):
  Pessoa(diaN, mesN, anoN, S, id) {
  inicializa(diaN, mesN, anoN, S, U, D);
}

void Professor::inicializa (int diaN, int mesN, int anoN, char *S,
                Universidade *U, Departamento *D) {
  setNome(S);
  setUni(U);
  setDep(D);
}

Professor::~Professor () {
  uni = NULL;
  dep = NULL;
}

void Professor::setUni (Universidade *U) {
  uni = U;
}

Universidade* Professor::getUni () {
  return uni;
}

void Professor::printProf () {
  cout << "Professor " << getNome();
}

void Professor::printUni () {
  printProf();
  cout << " trabalha na ";
  uni->imprimeUni();
}

void Professor::setDep (Departamento *D) {
  dep = D;
}

Departamento* Professor::getDep () {
  return dep;
}

void Professor::printDep () {
  printProf();
  cout << " leciona no ";
  dep->imprimeDep();
}

void Professor::imprimeTudo () {
  imprimeIdade();
  cout << "\n";
  printUni();
  cout << "\n";
  printDep();
  cout << "\n\n";
}
