#include "stdafx.h"
#include "lDepartamento.h"

lDepartamento::lDepartamento (char *S, int n, int id) {
  setNome(S);
  setID(id);
  setNum(n);
  contDepartamentos = 0;
  pDepIni = pDepAtual = NULL;
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

void lDepartamento::setID (int id) {
  ID = id;
}

int lDepartamento::getID () {
  return ID;
}

void lDepartamento::setNum (int n) {
  nDepartamentos = n;
}

void lDepartamento::incluirDep (Departamento *D) {
  if(contDepartamentos < nDepartamentos) {
    elDepartamento *novo = new elDepartamento(D);
    if(!pDepIni)
      pDepIni = pDepAtual = novo;
    else {
      pDepAtual->setProx(novo);
      novo->setAnt(pDepAtual);
      pDepAtual = novo;
    }
    contDepartamentos++;
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (003).\n";
}

void lDepartamento::removeDep (Departamento *D) {
  if(D && contDepartamentos > 0) {
    elDepartamento *peao = pDepIni;
    while(peao && strcmp(peao->getDep()->getNome(), D->getNome()) != 0)
      peao = peao->getProx();
    if(peao) {
      peao->getAnt()->setProx(peao->getProx());
      peao->getProx()->setAnt(peao->getAnt());
      delete(peao);
      contDepartamentos--;
    }
    else
      cout << "\nO ";
      D->imprimeDep();
      cout << " nao pertence a " << getNome() << ".\n";
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (004).\n";
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
