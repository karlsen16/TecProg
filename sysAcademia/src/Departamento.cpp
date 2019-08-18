#include "stdafx.h"
#include "Departamento.h"

Departamento::Departamento (char *S) {
  setNome(S);
}

Departamento::~Departamento () {
}

void Departamento::setNome (char *S) {
  strcpy(nome, S);
}

char* Departamento::getNome () {
  return nome;
}

void Departamento::imprimeDep () {
  cout << "Departamento: " << getNome() << ".\n";
}
