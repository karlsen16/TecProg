#include "stdafx.h"
#include "Universidade.h"

Universidade::Universidade () {
  setNome("");
}

Universidade::Universidade (char *S, Departamento *dep) {
  inicializa(S, dep);
}

void Universidade::inicializa (char *S, Departamento *dep) {
  setNome(S);
  incluirDep(dep);
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
  cout << "Universidade " << getNome() << ".\n";
}

void Universidade::incluirDep (Departamento *dep) {
  D.push_back(dep);
}

void Universidade::imprimeDep (int i) {
  D[i]->imprimeDep();
}

void Universidade::imprimeDis (int i) {
  D[i]->imprimeDis();
}

void Universidade::imprimeDepS () {
  cout << "\nDepartamentos da Universidade " << getNome() << ":\n";
  int i, tam = (int)D.size();
  for(i = 0; i < tam; i++)
    imprimeDep(i);
}

void Universidade::imprimeTudo () {
  cout << "\nDepartamentos da Universidade " << getNome() << ":\n";
  int i, tam = (int)D.size();
  for(i = 0; i < tam; i++) {
    imprimeDep(i);
    imprimeDis(i);
  }
}
