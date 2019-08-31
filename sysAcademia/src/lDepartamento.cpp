#include "stdafx.h"
#include "lDepartamento.h"

lDepartamento::lDepartamento () {
  pDepIni = pDepAtual = NULL;
  nDepartamentos = contDepartamentos = 0;
}

lDepartamento::~lDepartamento () {
  elDepartamento *peao = pDepIni;
  while(peao) {
    pDepIni = peao->getProx();
    delete (peao);
    peao = pDepIni;
  }
  pDepAtual = NULL;
}

void lDepartamento::setNome (char *S) {
  strcpy(nome, S);
}

char* lDepartamento::getNome () {
  return nome;
}

void lDepartamento::setNum (int n) {
  nDepartamentos = n;
}

void lDepartamento::incluirDep (Departamento *D) {
  elDepartamento *novo = new elDepartamento(D);
  if(!pDepIni)
    pDepIni = pDepAtual = novo;
  else {
    pDepAtual->setProx(novo);
    novo->setAnt(pDepAtual);
    pDepAtual = novo;
  }
}

void lDepartamento::removeDep (Departamento *D) {
  if(D) {
    elDepartamento *peao = pDepIni;
    while(peao && strcmp(peao->getDep()->getNome(), D->getNome()) != 0)
      peao = peao->getProx();
    if(peao) {
      peao->getAnt()->setProx(peao->getProx());
      peao->getProx()->setAnt(peao->getAnt());
      delete(peao);
    }
    else
      cout << "\nO ";
      D->imprimeDep();
      cout << " nao pertence a " << getNome() << ".\n";
  }
}

Departamento* lDepartamento::getDepI (int i) {
  if(i >= 0) {
    int cont = 0;
    elDepartamento *peao = pDepIni;
    while(peao) {
      if(cont == i)
        return peao->getDep();
      peao = peao->getProx();
      cont++;
    }
  }
  return NULL;
}

void lDepartamento::imprimeDep (int i) {
  getDepI(i)->imprimeDep();
}

void lDepartamento::imprimeDis (int i) {
  getDepI(i)->imprimeDis();
}

void lDepartamento::imprimeDepS () {
  cout << "\nDepartamentos da Universidade " << getNome() << ":\n";
  elDepartamento *peao = pDepIni;
  while(peao) {
    cout << "\t";
    peao->getDep()->imprimeDep();
    peao = peao->getProx();
  }
}

void lDepartamento::imprimeTudo () {
  cout << "\nDepartamentos da Universidade " << getNome() << ":\n";
  elDepartamento *peao = pDepIni;
  while(peao) {
    cout << "\t";
    peao->getDep()->imprimeDep();
    cout << "\n";
    peao->getDep()->imprimeDis();
    peao = peao->getProx();
  }
}
