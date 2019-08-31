#include "stdafx.h"
#include "lAluno.h"

lAluno::lAluno () {
  pAluIni = pAluAtual = NULL;
  nAlunos = contAlunos = 0;
}

lAluno::~lAluno () {
  elAluno *peao = pAluIni;
  while(peao) {
    pAluIni = peao->getProx();
    delete (peao);
    peao = pAluIni;
  }
  pAluAtual = NULL;
}

void lAluno::setNome (char *S) {
  strcpy(nome, S);
}

char* lAluno::getNome () {
  return nome;
}

void lAluno::setNum (int n) {
  nAlunos = n;
}

void lAluno::addAluno (Aluno *L) {
  if(contAlunos < nAlunos) {
    elAluno *novo = new elAluno(L);
    if(!pAluIni)
      pAluAtual = pAluIni = novo;
    else {
      elAluno *peao = pAluIni, *aux = NULL;
      while(peao && strcmp(peao->getAluno()->getNome(), L->getNome()) < 0) {
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
        pAluAtual = novo;
      if(!novo->getAnt())
        pAluIni = novo;
    }
    contAlunos++;
  }
  else
    cout << "\nTurma cheia! Tente novamente no proximo semestre..\n";
}

void lAluno::removeAluno (Aluno *L) {
  if(contAlunos > 0) {
    elAluno *peao = pAluIni;
    while(peao && strcmp(peao->getAluno()->getNome(), L->getNome()) != 0)
      peao = peao->getProx();
    if(peao) {
      peao->getAnt()->setProx(peao->getProx());
      peao->getProx()->setAnt(peao->getAnt());
      delete(peao);
      contAlunos--;
    }
    else
      cout << "\nO aluno " << L->getNome() << " nao pertence a Disciplina"
           << getNome() << ".\n";
  }
  else
    cout << "\nTurma vazia!\n";
}

void lAluno::imprimeAlu () {
  elAluno *peao = pAluIni;
  int cont = 1;
  if(contAlunos > 0) {
    cout << "\t\t\tLista de Alunos:\n";
    while(peao) {
      cout << "\t\t\t" << cont << "# " << peao->getAluno()->getNome() << "\n";
      cont++;
      peao = peao->getProx();
    }
  }
}

void lAluno::imprimeAlu2 () {
  elAluno *peao = pAluAtual;
  int cont = 1;
  cout << "\t\t\tLista de Alunos:\n";
  while(peao) {
    cout << "\t\t\t" << cont << "# " << peao->getAluno()->getNome() << "\n";
    cont++;
    peao = peao->getAnt();
  }
}
