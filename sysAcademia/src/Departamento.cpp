#include "stdafx.h"
#include "Departamento.h"
#include "Universidade.h"

Departamento::Departamento () {
  listaDisciplinas = new lDisciplina();
  listaProfessores = new lProfessor();
  inicializa();
}

Departamento::Departamento (char *S, Universidade *U, int n, int np, int id) {
  listaDisciplinas = new lDisciplina();
  listaProfessores = new lProfessor();
  inicializa(S, U, n, np, id);
}

void Departamento::inicializa (char *S, Universidade *U, int n, int np, int id) {
  setNome(S);
  setUni(U);
  setID(id);
  listaDisciplinas->setNome(S);
  listaDisciplinas->setNum(n);
  listaProfessores->setNome(S);
  listaProfessores->setNum(np);
}

Departamento::~Departamento () {
  uni = NULL;
  if(listaDisciplinas)
    delete(listaDisciplinas);
  listaDisciplinas = NULL;
  if(listaProfessores)
    delete(listaProfessores);
  listaProfessores = NULL;
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
    U->addDep(this);
}

Universidade* Departamento::getUni () {
  return uni;
}

void Departamento::imprimeDep () {
  cout << "Departamento " << getNome();
}

void Departamento::addDis (Disciplina *D) {
  listaDisciplinas->addDis(D);
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

void Departamento::addProfessor (Professor *P) {
  listaProfessores->addProfessor(P);
}

void Departamento::removeProfessor (Professor *P) {
  listaProfessores->removeProfessor(P);
}

void Departamento::imprimeProfs () {
  listaProfessores->imprimeProfs();
}

void Departamento::imprimeProfs2 () {
  listaProfessores->imprimeProfs2();
}
