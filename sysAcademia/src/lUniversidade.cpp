#include "stdafx.h"
#include "lUniversidade.h"

lUniversidade::lUniversidade (char *S, int n) {
  setNome(S);
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

void lUniversidade::setNum (int n) {
  nUniversidades = n;
}

void lUniversidade::addUni (Universidade *U) {
  if(U && contUniversidades < nUniversidades) {
    elUniversidade *novo = new elUniversidade(U);
    if(!pUniIni)
      pUniIni = pUniAtual = novo;
    else {
      elUniversidade *peao = pUniIni, *aux = NULL;
      while(peao && strcmp(peao->getUni()->getNome(), U->getNome()) < 0) {
        aux = peao;
        peao = peao->getProx();
      }
      novo->setProx(peao);
      novo->setAnt(aux);
      if(peao)
        peao->setAnt(novo);
      if(aux)
        aux->setProx(novo);
      if(!novo->getProx())
        pUniAtual = novo;
      if(!novo->getAnt())
        pUniIni = novo;
    }
    contUniversidades++;
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (51).\n";
}

Universidade* lUniversidade::getUni (char *S) {
  if(S && contUniversidades > 0) {
    elUniversidade *peao = pUniIni;
    while(peao && strcmp(peao->getUni()->getNome(), S) != 0) {
      peao = peao->getProx();
    }
    if(peao)
      return peao->getUni();
    else
      cout << "\nA Universidade " << S << " nao pertence a "
           << getNome() << ".\n";
  }
  else
    cout << "\nNao e possivel fazer esta operacao. Erro:(52).\n";
  return NULL;
}

void lUniversidade::removeUni (char *S) {
  if(S && contUniversidades > 0) {
    elUniversidade *peao = pUniIni;
    while(peao && strcmp(peao->getUni()->getNome(), S) != 0)
      peao = peao->getProx();
    if(peao) {
      peao->getAnt()->setProx(peao->getProx());
      peao->getProx()->setAnt(peao->getAnt());
      delete(peao);
      contUniversidades--;
    }
    else
      cout << "\nA " << S << " nao pertence a "
           << getNome() << ".\n";
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (53).\n";
}

void lUniversidade::imprimeUni (char *S) {
  getUni(S)->imprimeUni();
}
