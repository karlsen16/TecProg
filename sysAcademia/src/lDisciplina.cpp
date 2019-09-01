#include "stdafx.h"
#include "lDisciplina.h"

lDisciplina::lDisciplina (char *S, int n, int id) {
  setNome(S);
  setID(id);
  setNum(n);
  contDisciplinas = 0;
  pDisIni = pDisAtual = NULL;
}

lDisciplina::~lDisciplina () {
  elDisciplina *peao = pDisIni;
  while(peao) {
    pDisIni = peao->getProx();
    delete (peao);
    peao = pDisIni;
  }
  pDisAtual = NULL;
}

void lDisciplina::setNome (char *S) {
  strcpy(nome, S);
}

char* lDisciplina::getNome () {
  return nome;
}

void lDisciplina::setNum (int n) {
  nDisciplinas = n;
}

void lDisciplina::incluirDis (Disciplina *D) {
  if(contDisciplinas < nDisciplinas) {
    elDisciplina *novo = new elDisciplina(D);
    if(!pDisIni)
      pDisIni = pDisAtual = novo;
    else {
      pDisAtual->setProx(novo);
      novo->setAnt(pDisAtual);
      pDisAtual = novo;
    }
    contDisciplinas++;
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (005).\n";
}

void lDisciplina::removeDis (Disciplina *D) {
  if(D && contDisciplinas > 0) {
    elDisciplina *peao = pDisIni;
    while(peao && strcmp(peao->getDis()->getNome(), D->getNome()) != 0)
      peao = peao->getProx();
    if(peao) {
      peao->getAnt()->setProx(peao->getProx());
      peao->getProx()->setAnt(peao->getAnt());
      delete(peao);
      contDisciplinas--;
    }
    else
      cout << "\nA ";
      D->imprimeDis();
      cout << " nao pertence ao Departamento " << getNome() << ".\n";
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (006).\n";
}

void lDisciplina::imprimeDis () {
  elDisciplina *peao = pDisIni;
  while(peao) {
    cout << "\t\tA Disciplina " << peao->getDis()->getNome()
    << " da area " << peao->getDis()->getArea()
    << " pertence ao Departamento " << getNome() << "\n";
    peao->getDis()->imprimeAlu();
    peao = peao->getProx();
  }
}

void lDisciplina::imprimeDis2 () {
  elDisciplina *peao = pDisAtual;
  while(peao) {
    cout << "\t\tA Disciplina " << peao->getDis()->getNome()
    << " da area " << peao->getDis()->getArea()
    << " pertence ao Departamento " << getNome() << "\n";
    peao->getDis()->imprimeAlu2();
    peao = peao->getAnt();
  }
}
