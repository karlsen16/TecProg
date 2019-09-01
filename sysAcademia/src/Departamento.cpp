#include "stdafx.h"
#include "Departamento.h"
#include "Universidade.h"

Departamento::Departamento () {
  listaDisciplinas = new lDisciplina();
  inicializa();
}

Departamento::Departamento (char *S, Universidade *U, int n, int id) {
  listaDisciplinas = new lDisciplina();
  inicializa(S, U, id, n);
}

void Departamento::inicializa (char *S, Universidade *U, int n, int id) {
  setNome(S);
  setUni(U);
  setID(id);
  listaDisciplinas->setNome(S);
  listaDisciplinas->setNum(n);
}

Departamento::~Departamento () {
  uni = NULL;
  if(listaDisciplinas)
    delete(listaDisciplinas);
  listaDisciplinas = NULL;
}

void Departamento::setNome (char *S) {
  strcpy(nome, S);
}

char* Departamento::getNome () {
  return nome;
}

void Departamento::setID (int id) {
  ID = id;
}

int Departamento::getID () {
  return ID;
}

void Departamento::setUni (Universidade *U) {
  uni = U;
  if(U)
    U->incluirDep(this);
}

Universidade* Departamento::getUni () {
  return uni;
}

void Departamento::imprimeDep () {
  cout << "Departamento " << getNome();
}

void Departamento::incluirDis (Disciplina *D) {
  listaDisciplinas->incluirDis(D);
}

void Departamento::removeDis (Disciplina *D) {
  listaDisciplinas->removeDis(D);
}

void Departamento::imprimeDis () {
  listaDisciplinas->imprimeDis();
}

void Departamento::imprimeDis2 () {
  listaDisciplinas->imprimeDis2();
}
