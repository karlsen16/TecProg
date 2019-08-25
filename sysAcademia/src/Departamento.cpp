#include "stdafx.h"
#include "Departamento.h"
#include "Universidade.h"

Departamento::Departamento () {
  pDisIni = pDisAtual = NULL;
  inicializa();
}

Departamento::Departamento (char *S, Universidade *U, int id) {
  pDisIni = pDisAtual = NULL;
  inicializa(S, U, id);
}

void Departamento::inicializa (char *S, Universidade *U, int id) {
  setNome(S);
  setUni(U);
  setID(id);
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
  if(U)
    U->incluirDep(this);
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
    dis->setAnt(pDisAtual);
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

void Departamento::imprimeDis2 () {
  Disciplina *peao = pDisAtual;
  while(peao != NULL) {
    cout << "\t\tA Disciplina " << peao->getNome() << " da area " << peao->getArea()
    << " pertence ao Departamento " << getNome() << "\n";
    peao = peao->getAnt();
  }
}

void Departamento::setID (int id) {
  ID = id;
}

int Departamento::getID () {
  return ID;
}
