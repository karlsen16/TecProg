

#include "stdafx.h"
#include "Departamento.h"
#include "Universidade.h"

Departamento::Departamento ():
Entidade() {
  listaDisciplinas = new Lista<Disciplina>();
  listaProfessores = new Lista<Professor>();
  listaAlunos = new Lista<Aluno>();
  inicializa();
}

Departamento::Departamento (string S, Universidade *U, int n, int np, int na, int id):
Entidade(S, id) {
  listaDisciplinas = new Lista<Disciplina>();
  listaProfessores = new Lista<Professor>();
  listaAlunos = new Lista<Aluno>();
  inicializa(S, U, n, np, na, id);
}

void Departamento::inicializa (string S, Universidade *U, int n, int np, int na, int id) {
  setNome(S);
  setUni(U);
  setID(id);
  listaDisciplinas->setNome(S);
  listaDisciplinas->setNum(n);
  listaProfessores->setNome(S);
  listaProfessores->setNum(np);
  listaAlunos->setNome(S);
  listaAlunos->setNum(na);
}

Departamento::~Departamento () {
  uni = NULL;
  if(listaDisciplinas)
    delete(listaDisciplinas);
  listaDisciplinas = NULL;
  if(listaProfessores)
    delete(listaProfessores);
  listaProfessores = NULL;
  if(listaAlunos)
    delete(listaAlunos);
  listaAlunos = NULL;
}

void Departamento::setUni (Universidade *U) {
  uni = U;
  if(U)
    U->addDep(this);
}

Universidade* Departamento::getUni () {
  return uni;
}

int Departamento::getN(){
  return listaDisciplinas->getN();
}

int Departamento::getNP(){
  return listaProfessores->getN();
}

int Departamento::getNA(){
  return listaAlunos->getN();
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

Lista<Disciplina>* Departamento::getLista () {
  return listaDisciplinas;
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

Lista<Professor>* Departamento::getListaP () {
  return listaProfessores;
}

void Departamento::addAlu (Aluno *A) {
  listaAlunos->addEnt(A);
}

Aluno* Departamento::getAlu (string S) {
  return listaAlunos->getEnt(S);
}

void Departamento::removeAlu (string S) {
  listaAlunos->removeEnt(S);
}

void Departamento::imprimeAlus () {
  listaAlunos->imprimeEnts();
}

Lista<Aluno>* Departamento::getListaA () {
  return listaAlunos;
}
