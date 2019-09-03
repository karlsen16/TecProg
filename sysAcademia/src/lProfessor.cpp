#include "stdafx.h"
#include "lProfessor.h"

lProfessor::lProfessor (char *S, int n) {
  setNome(S);
  setNum(n);
  contProfessores = 0;
  pPrfIni = pPrfAtual = NULL;
}

lProfessor::~lProfessor () {
  elProfessor *peao = pPrfIni;
  while(peao) {
    pPrfIni = peao->getProx();
    delete (peao);
    peao = pPrfIni;
  }
  pPrfAtual = NULL;
}

void lProfessor::setNome (char *S) {
  strcpy(nome, S);
}

char* lProfessor::getNome () {
  return nome;
}

void lProfessor::setNum (int n) {
  nProfessores = n;
}

void lProfessor::addProfessor (Professor *P) {
  if(P && contProfessores < nProfessores) {
    elProfessor *novo = new elProfessor(P);
    if(!pPrfIni)
      pPrfAtual = pPrfIni = novo;
    else {
      elProfessor *peao = pPrfIni, *aux = NULL;
      while(peao && strcmp(peao->getPrf()->getNome(), P->getNome()) < 0) {
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
        pPrfAtual = novo;
      if(!novo->getAnt())
        pPrfIni = novo;
    }
    contProfessores++;
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (21).\n";
}

Professor* lProfessor::getPrf (char *S) {
  if(S && contProfessores > 0) {
    elProfessor *peao = pPrfIni;
    while(peao && strcmp(peao->getPrf()->getNome(), S) != 0)
      peao = peao->getProx();
    if(peao)
      return peao->getPrf();
    else
      cout << "\nO Professor " << S << " nao pertence ao Departamento "
           << getNome() << ".\n";
  }
  else
    cout << "\nNao e possivel fazer esta operacao. Erro:(22).\n";
  return NULL;
}

void lProfessor::removeProfessor (char *S) {
  if(S && contProfessores > 0) {
    elProfessor *peao = pPrfIni;
    while(peao && strcmp(peao->getPrf()->getNome(), S) != 0)
      peao = peao->getProx();
    if(peao) {
      peao->getAnt()->setProx(peao->getProx());
      peao->getProx()->setAnt(peao->getAnt());
      delete(peao);
      contProfessores--;
    }
    else
      cout << "\nO Professor " << S << " nao pertence ao Departamento "
           << getNome() << ".\n";
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (23).\n";
}

void lProfessor::imprimeProfs () {
  elProfessor *peao = pPrfIni;
  int cont = 1;
  if(contProfessores > 0) {
    cout << "\t\t\tLista de Professores:\n";
    while(peao) {
      cout << "\t\t\t" << cont << "# " << peao->getPrf()->getNome() << "\n";
      cont++;
      peao = peao->getProx();
    }
  }
}

void lProfessor::imprimeProfs2 () {
  elProfessor *peao = pPrfAtual;
  int cont = 1;
  cout << "\t\t\tLista de Professores:\n";
  while(peao) {
    cout << "\t\t\t" << cont << "# " << peao->getPrf()->getNome() << "\n";
    cont++;
    peao = peao->getAnt();
  }
}
