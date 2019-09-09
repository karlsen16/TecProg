#include "stdafx.h"
#include "lDepartamento.h"

lDepartamento::lDepartamento (char *S, int n) {
  setNome(S);
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

void lDepartamento::setNum (int n) {
  nDepartamentos = n;
}

void lDepartamento::addDep (Departamento *D) {
  if(D && contDepartamentos < nDepartamentos) {
    elDepartamento *novo = new elDepartamento(D);
    if(!pDepIni)
      pDepIni = pDepAtual = novo;
    else {
      elDepartamento *peao = pDepIni, *aux = NULL;
      while(peao && strcmp(peao->getDep()->getNome(), D->getNome()) < 0) {
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
        pDepAtual = novo;
      if(!novo->getAnt())
        pDepIni = novo;
    }
    contDepartamentos++;
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (41).\n";
}

Departamento* lDepartamento::getDep (char *S) {
  if(S && contDepartamentos > 0) {
    elDepartamento *peao = pDepIni;
    while(peao && strcmp(peao->getDep()->getNome(), S) != 0)
      peao = peao->getProx();
    if(peao)
      return peao->getDep();
    else
      cout << "\nO Departamento " << S << " nao pertence a Universidade"
           << getNome() << ".\n";
  }
  else
    cout << "\nNao e possivel fazer esta operacao. Erro:(42).\n";
  return NULL;
}

void lDepartamento::removeDep (char *S) {
  if(S && contDepartamentos > 0) {
    elDepartamento *peao = pDepIni;
    while(peao && strcmp(peao->getDep()->getNome(), S) != 0)
      peao = peao->getProx();
    if(peao) {
      peao->getAnt()->setProx(peao->getProx());
      peao->getProx()->setAnt(peao->getAnt());
      delete(peao);
      contDepartamentos--;
    }
    else
      cout << "\nO " << S << " nao pertence a Universidade"
           << getNome() << ".\n";
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (43).\n";
}

void lDepartamento::imprimeDeps () {
  if(contDepartamentos > 0) {
    cout << "Lista de Departamentos:\n";
    elDepartamento *peao = pDepIni;
    int cont = 1;
    while(peao) {
      cout << "\t" << cont << "# " << peao->getDep()->getNome() << "\n";
      cont++;
      peao = peao->getProx();
    }
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (49).\n";
}
