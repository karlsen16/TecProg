#include "stdafx.h"
#include "Departamento.h"
#include "Universidade.h"

Departamento::Departamento () {
  inicializa();
}

Departamento::Departamento (char *S, Universidade *U, Disciplina *I, int id) {
  inicializa(S, U, I, id);
}

void Departamento::inicializa (char *S, Universidade *U, Disciplina *I, int id) {
  setNome(S);
  setUni(U);
  setID(id);
  pDisIni = I;
  pDisAtual = I;
}

Departamento::~Departamento () {
  pDisIni = pDisAtual = NULL;
  uni = NULL;
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
  cout << "\tDepartamento " << getNome() << ".\n";
}

void Departamento::incluirDis (Disciplina *dis) {
  if(!pDisIni)
    pDisIni = pDisAtual = dis;
  else {
    pDisAtual->setProx(dis);
    pDisAtual = dis;
  }
}

void Departamento::imprimeDis () {
  Disciplina *peao = pDisIni;
  while(peao != NULL) {
    cout << "\t\tA Disciplina " << peao->getNome() << " da area " << peao->getArea()
    << " pertence ao Departamento " << getNome() << "\n";
    peao = peao->getProx();
  }
}

void Departamento::setID (int id) {
  ID = id;
}

int Departamento::getID () {
  return ID;
}
