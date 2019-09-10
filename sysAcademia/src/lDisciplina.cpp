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
    cout << "Nao e possivel fazer esta operacao. Erro (33).\n";
}

elDisciplina* lDisciplina::getelDis (char *S) {
  if(S && contDisciplinas > 0) {
    elDisciplina *peao = pDisIni;
    while(peao && strcmp(peao->getDis()->getNome(), S) != 0)
      peao = peao->getProx();
    if(peao)
      return peao;
    else
      cout << "\nO el.Disciplina " << S << " nao pertence ao Departamento"
           << getNome() << ".\n";
  }
  else
    cout << "\nNao e possivel fazer esta operacao. Erro:(34).\n";
  return NULL;
}

void lDisciplina::imprimeDiss () {
  if(contDisciplinas > 0) {
    cout << "Lista de Disciplinas:\n";
    elDisciplina *peao = pDisIni;
    int cont = 1;
    while(peao) {
      cout << "\t" << cont << "# " << peao->getDis()->getNome() << "  -ID: "
           << peao->getDis()->getID() << "\n";
      cont++;
      peao = peao->getProx();
    }
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (39).\n";
}
