#include "stdafx.h"
#include "Universidade.h"

Universidade::Universidade (char *S, Departamento *dep) {
  setNome(S);
  D = dep;
}

Universidade::~Universidade () {
}

void Universidade::setNome (char *S) {
  strcpy(nome, S);
}

char* Universidade::getNome () {
  return nome;
}

void Universidade::imprimeUni () {
  cout << "Universidade: " << getNome() << ".\n";
}

void Universidade::setDep (Departamento *N) {
  D = N;
}

void* Universidade::imprimeDep () {
  D->imprimeDep();
}
