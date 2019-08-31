#include "stdafx.h"
#include "lDisciplina.h"

lDisciplina::lDisciplina () {
  pDisIni = pDisAtual = NULL;
  nDisciplinas = contDisciplinas = 0;
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
  elDisciplina *novo = new elDisciplina(D);
  if(!pDisIni)
    pDisIni = pDisAtual = novo;
  else {
    pDisAtual->setProx(novo);
    novo->setAnt(pDisAtual);
    pDisAtual = novo;
  }
}

void lDisciplina::removeDis (Disciplina *D) {
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
      cout << " nao pertence ao Departamento " << getNome() << ".\n";
  }
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
