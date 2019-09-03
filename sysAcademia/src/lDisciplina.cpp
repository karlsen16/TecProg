#include "stdafx.h"
#include "lDisciplina.h"

lDisciplina::lDisciplina (char *S, int n) {
  setNome(S);
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

void lDisciplina::addDis (Disciplina *D) {
  if(D && contDisciplinas < nDisciplinas) {
    elDisciplina *novo = new elDisciplina(D);
    if(!pDisIni)
      pDisIni = pDisAtual = novo;
    else {
      elDisciplina *peao = pDisIni, *aux = NULL;
      while(peao && strcmp(peao->getDis()->getNome(), D->getNome()) < 0) {
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
        pDisAtual = novo;
      if(!novo->getAnt())
        pDisIni = novo;
    }
    contDisciplinas++;
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (31).\n";
}

Disciplina* lDisciplina::getDis (char *S) {
  if(S && contDisciplinas > 0) {
    elDisciplina *peao = pDisIni;
    while(peao && strcmp(peao->getDis()->getNome(), S) != 0)
      peao = peao->getProx();
    if(peao)
      return peao->getDis();
    else
      cout << "\nA Disciplina " << S << " nao pertence ao Departamento "
           << getNome() << ".\n";
  }
  else
    cout << "\nNao e possivel fazer esta operacao. Erro:(32).\n";
  return NULL;
}

elDisciplina* lDisciplina::getelDis (char *S) {
  if(S && contDisciplinas > 0) {
    elDisciplina *peao = pDisIni;
    while(peao && strcmp(peao->getDis()->getNome(), S) != 0)
      peao = peao->getProx();
    if(peao)
      return peao;
    else
      cout << "\nA el.Disciplina " << S << " nao pertence ao Departamento "
           << getNome() << ".\n";
  }
  else
    cout << "\nNao e possivel fazer esta operacao. Erro:(33).\n";
  return NULL;
}

void lDisciplina::removeDis (char *S) {
  if(S && contDisciplinas > 0) {
    elDisciplina *peao = pDisIni;
    while(peao && strcmp(peao->getDis()->getNome(), S) != 0)
      peao = peao->getProx();
    if(peao) {
      peao->getAnt()->setProx(peao->getProx());
      peao->getProx()->setAnt(peao->getAnt());
      delete(peao);
      contDisciplinas--;
    }
    else
      cout << "\nA Disciplina " << S << " nao pertence ao Departamento "
           << getNome() << ".\n";
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (34).\n";
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
