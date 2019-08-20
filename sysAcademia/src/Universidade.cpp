#include "stdafx.h"
#include "Universidade.h"

Universidade::Universidade (char *S, Departamento *dep) {
  setNome(S);
  setDep(dep);
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

void Universidade::setDep (Departamento *dep) {
  D.push_back(dep);
}

void Universidade::imprimeDep (int i) {
  D[i]->imprimeDep();
}

void Universidade::imprimeDepS () {
  cout << "\nDepartamentos da Universidade " << getNome() << ":\n";
  int i, tam = (int)D.size();
  for(i = 0; i < tam; i++)
    D[i]->imprimeDep();
}
