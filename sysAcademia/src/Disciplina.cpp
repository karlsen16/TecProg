#include "stdafx.h"
#include "Disciplina.h"
#include "Universidade.h"

Disciplina::Disciplina () {
  prox = NULL;
  inicializa();
}

Disciplina::Disciplina (char *S, char *A, Departamento *D, int id) {
  prox = NULL;
  inicializa(S, A, D, id);
}

void Disciplina::inicializa (char *S, char *A, Departamento *D, int id) {
  setNome(S);
  setArea(A);
  setDep(D);
  setID(id);
}

Disciplina::~Disciplina () {
  dep = NULL;
  prox = NULL;
}

void Disciplina::setNome (char *S) {
  strcpy(nome, S);
}

char* Disciplina::getNome () {
  return nome;
}

void Disciplina::setArea (char *A) {
  strcpy(area, A);
}

char* Disciplina::getArea () {
  return area;
}

void Disciplina::setDep (Departamento *D) {
  dep = D;
  if(D)
    D->incluirDis(this);
}

Departamento* Disciplina::getDep () {
  return dep;
}

void Disciplina::setProx (Disciplina *I) {
  prox = I;
}

Disciplina* Disciplina::getProx () {
  return prox;
}

void Disciplina::imprimeDis () {
  cout << "Disciplina: " << getNome() << ".\n";
}

void Disciplina::setID (int id) {
  ID = id;
}

int Disciplina::getID () {
  return ID;
}
