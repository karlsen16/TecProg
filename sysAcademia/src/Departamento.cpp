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

void Departamento::addDis (Disciplina *D) {
  listaDisciplinas->addDis(D);
}

Disciplina* Departamento::getDis (char *S) {
  return listaDisciplinas->getDis(S);
}

void Departamento::removeDis (char *S) {
  listaDisciplinas->removeDis(S);
}

elDisciplina* Departamento::getelDis (char *S) {
  return listaDisciplinas->getelDis(S);
}

void Departamento::imprimeDiss () {
  listaDisciplinas->imprimeDiss();
}

void Departamento::addPrf (Professor *P) {
  listaProfessores->addPrf(P);
}

Professor* Departamento::getPrf (char *S) {
  return listaProfessores->getPrf(S);
}

void Departamento::removePrf (char *S) {
  listaProfessores->removePrf(S);
}

void Departamento::imprimePrfs () {
  listaProfessores->imprimePrfs();
}
