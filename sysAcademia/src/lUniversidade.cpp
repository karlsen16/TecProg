#include "stdafx.h"
#include "lUniversidade.h"

lUniversidade::lUniversidade (char *S, int n, int id) {
  setNome(S);
  setID(id);
  setNum(n);
  contUniversidades = 0;
  pUniIni = pUniAtual = NULL;
}

lUniversidade::~lUniversidade () {
  elUniversidade *peao = pUniIni;
  while(peao) {
    pUniIni = peao->getProx();
    delete (peao);
    peao = pUniIni;
  }
  pUniAtual = NULL;
}

void lUniversidade::setNome (char *S) {
  strcpy(nome, S);
}

char* lUniversidade::getNome () {
  return nome;
}

void lUniversidade::setID (int id) {
  ID = id;
}

int lUniversidade::getID () {
  return ID;
}

void lUniversidade::setNum (int n) {
  nUniversidades = n;
}

void lUniversidade::addUni (Universidade *U) {
  if(contUniversidades < nUniversidades) {
    elUniversidade *novo = new elUniversidade(U);
    if(!pUniIni)
      pUniIni = pUniAtual = novo;
    else {
      pUniAtual->setProx(novo);
      novo->setAnt(pUniAtual);
      pUniAtual = novo;
    }
    contUniversidades++;
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (001).\n";
}

void lUniversidade::removeUni (Universidade *U) {
  if(U && contUniversidades > 0) {
    elUniversidade *peao = pUniIni;
    while(peao && strcmp(peao->getUni()->getNome(), U->getNome()) != 0)
      peao = peao->getProx();
    if(peao) {
      peao->getAnt()->setProx(peao->getProx());
      peao->getProx()->setAnt(peao->getAnt());
      delete(peao);
      contUniversidades--;
    }
    else
      cout << "\nA ";
      U->imprimeUni();
      cout << " nao pertence a " << getNome() << ".\n";
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (002).\n";
}

Universidade* lUniversidade::getUni (char *S) {
  if(S) {
    elUniversidade *peao = pUniIni;
    while(peao && strcmp(S, peao->getUni()->getNome()) != 0) {
      peao = peao->getProx();
    }
    if(peao)
      return peao->getUni();
  }
  return NULL;
}

void lUniversidade::listarUni () {
  elUniversidade *peao = pUniIni;
  while(peao) {
    peao->getUni()->imprimeTudo();
    peao = peao->getProx();
  }
}

void lUniversidade::listarDep () {
  elUniversidade *peao = pUniIni;
  while(peao) {
    peao->getUni()->imprimeDepS();
    peao = peao->getProx();
  }
}

void lUniversidade::listarDis () {
  cout << "\nListando dics..\n";
}

void lUniversidade::listarPrf () {
  cout << "\nListando profs..\n";
}

void lUniversidade::listarAlu () {
  cout << "\nListando alus..\n";
}
