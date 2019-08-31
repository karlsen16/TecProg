#include "stdafx.h"
#include "Universidade.h"

Universidade::Universidade (char *S) {
  pDepIni = pDepAtual = NULL;
  setNome(S);
}

Universidade::~Universidade () {
  elDepartamento *peao = pDepIni;
  while(peao) {
    pDepIni = peao->getProx();
    delete(peao);
    peao = pDepIni;
  }
  pDepAtual = NULL;
}

void Universidade::setNome (char *S) {
  strcpy(nome, S);
}

char* Universidade::getNome () {
  return nome;
}

void Universidade::imprimeUni () {
  cout << "Universidade " << getNome();
}

void Universidade::incluirDep (Departamento *D) {
  elDepartamento *novo = new elDepartamento(D);
  if(!pDepIni)
    pDepIni = pDepAtual = novo;
  else {
    pDepAtual->setProx(novo);
    novo->setAnt(pDepAtual);
    pDepAtual = novo;
  }
}

void Universidade::removeDep (Departamento *D) {
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

Departamento* Universidade::getDepI (int i) {
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

void Universidade::imprimeDep (int i) {
  getDepI(i)->imprimeDep();
}

void Universidade::imprimeDis (int i) {
  getDepI(i)->imprimeDis();
}

void Universidade::imprimeDepS () {
  cout << "\nDepartamentos da ";
  imprimeUni();
  cout << ":\n";
  elDepartamento *peao = pDepIni;
  while(peao) {
    cout << "\t";
    peao->getDep()->imprimeDep();
    peao = peao->getProx();
  }
}

void Universidade::imprimeTudo () {
  cout << "\nDepartamentos da ";
  imprimeUni();
  cout << ":\n";
  elDepartamento *peao = pDepIni;
  while(peao) {
    cout << "\t";
    peao->getDep()->imprimeDep();
    cout << "\n";
    peao->getDep()->imprimeDis();
    peao = peao->getProx();
  }
}
