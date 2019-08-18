#include "stdafx.h"
#include "Universidade.h"

Universidade::Universidade (char *S, Departamento *dep) {
  setNome(S);
  D[0] = dep;
  int i;
  for(i = 1; i < QD; i++) D[i] = NULL;
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

void Universidade::setDep (Departamento *N, int i) {
  D[i] = N;
}

void Universidade::imprimeDep (int i) {
  D[i]->imprimeDep();
}

void Universidade::imprimeDepS () {
  cout << "\nDepartamentos da Universidade " << getNome() << ":\n";
  int i;
  for(i = 0; i < QD; i++)
    if(D[i] != NULL)
      D[i]->imprimeDep();
}
