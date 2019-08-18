#include "stdafx.h"
#include "Departamento.h"
#include "Universidade.h"

Departamento::Departamento (char *S, Universidade *U) {
  setNome(S);
  setUni(U);
}

Departamento::~Departamento () {
}

void Departamento::setNome (char *S) {
  strcpy(nome, S);
}

char* Departamento::getNome () {
  return nome;
}

void Departamento::setUni (Universidade *U) {
  uni = U;
}

Universidade* Departamento::getUni () {
  return uni;
}

void Departamento::imprimeDep () {
  cout << "Departamento: " << getNome() << ".\n";
}
