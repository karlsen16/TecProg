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
  cout << "Departamento " << getNome();
}

void Departamento::incluirDis (Disciplina *D) {
  elDisciplina *novo = new elDisciplina(D);
  if(!pDisIni)
    pDisIni = pDisAtual = novo;
  else {
    pDisAtual->setProx(novo);
    novo->setAnt(pDisAtual);
    pDisAtual = novo;
  }
}

void Departamento::removeDis (Disciplina *D) {
  if(D) {
    elDisciplina *peao = pDisIni;
    while(peao && strcmp(peao->getDis()->getNome(), D->getNome()) != 0)
      peao = peao->getProx();
    if(peao) {
      peao->getAnt()->setProx(peao->getProx());
      peao->getProx()->setAnt(peao->getAnt());
      delete(peao);
    }
    else
      cout << "\nA ";
      D->imprimeDis();
      cout << " nao pertence a " << getNome() << ".\n";
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
