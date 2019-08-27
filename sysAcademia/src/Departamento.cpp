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
  elDisciplina *peao = pDisIni;
  while(peao) {
    pDisIni = peao->getProx();
    delete (peao);
    peao = pDisIni;
  }
  uni = NULL;
  pDisAtual = NULL;
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
  elDisciplina *novo = new elDisciplina(dis);
  if(!pDisIni)
    pDisIni = pDisAtual = novo;
  else {
    pDisAtual->setProx(novo);
    novo->setAnt(pDisAtual);
    pDisAtual = novo;
  }
}

void Departamento::imprimeDis () {
  elDisciplina *peao = pDisIni;
  while(peao) {
    cout << "\t\tA Disciplina " << peao->getDis()->getNome()
    << " da area " << peao->getDis()->getArea()
    << " pertence ao Departamento " << getNome() << "\n";
    peao->getDis()->imprimeAlu();
    peao = peao->getProx();
  }
}

void Departamento::imprimeDis2 () {
  elDisciplina *peao = pDisAtual;
  while(peao) {
    cout << "\t\tA Disciplina " << peao->getDis()->getNome()
    << " da area " << peao->getDis()->getArea()
    << " pertence ao Departamento " << getNome() << "\n";
    peao->getDis()->imprimeAlu2();
    peao = peao->getAnt();
  }
}

void Departamento::setID (int id) {
  ID = id;
}

int Departamento::getID () {
  return ID;
}
