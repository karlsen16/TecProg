#include "stdafx.h"
#include "Departamento.h"
#include "Universidade.h"

Departamento::Departamento ():
Entidade() {
  listaDisciplinas = new Lista<Disciplina>();
  listaProfessores = new Lista<Professor>();
  inicializa();
}

Departamento::Departamento (string S, Universidade *U, int n, int np, int id):
Entidade(S, id) {
  listaDisciplinas = new Lista<Disciplina>();
  listaProfessores = new Lista<Professor>();
  inicializa(S, U, n, np, id);
}

void Departamento::inicializa (string S, Universidade *U, int n, int np, int id) {
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

void Departamento::setUni (Universidade *U) {
  uni = U;
  if(U)
    U->addDep(this);
}

Universidade* Departamento::getUni () {
  return uni;
}

void Departamento::addDis (Disciplina *D) {
  listaDisciplinas->addEnt(D);
}

Disciplina* Departamento::getDis (string S) {
  return listaDisciplinas->getEnt(S);
}

void Departamento::removeDis (string S) {
  listaDisciplinas->removeEnt(S);
}

Elemento<Disciplina>* Departamento::getelDis (string S) {
  return listaDisciplinas->getel(S);
}

void Departamento::imprimeDiss () {
  listaDisciplinas->imprimeEnts();
}

void Departamento::addPrf (Professor *P) {
  listaProfessores->addEnt(P);
}

Professor* Departamento::getPrf (string S) {
  return listaProfessores->getEnt(S);
}

void Departamento::removePrf (string S) {
  listaProfessores->removeEnt(S);
}

void Departamento::imprimePrfs () {
  listaProfessores->imprimeEnts();
}
