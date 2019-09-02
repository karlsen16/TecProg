#include "stdafx.h"
#include "lAluno.h"

lAluno::lAluno (char *S, int n, int id) {
  setNome(S);
  setID(id);
  setNum(n);
  contAlunos = 0;
  pAluIni = pAluAtual = NULL;
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

void lAluno::setID (int id) {
  ID = id;
}

int lAluno::getID () {
  return ID;
}

void lAluno::setNum (int n) {
  nAlunos = n;
}

void lAluno::findAluno (elAluno *peao, elAluno *aux, char *S, int op) {
  peao = pAluIni;
  aux = NULL;
  switch(op) {
    case 0: {
      while(peao && strcmp(peao->getAluno()->getNome(), S) < 0) {
        aux = peao;
        peao = peao->getProx();
      }
      break;
    }
    case 1: {
      while(peao && strcmp(peao->getAluno()->getNome(), S) > 0) {
        aux = peao;
        peao = peao->getProx();
      }
      break;
    }
    default: {
      while(peao && strcmp(peao->getAluno()->getNome(), S) != 0) {
        aux = peao;
        peao = peao->getProx();
      }
    }
  }
}

void lAluno::addAluno (Aluno *L) {
  if(L && contAlunos < nAlunos) {
    elAluno *novo = new elAluno(L);
    if(!pAluIni)
      pAluAtual = pAluIni = novo;
    else {
      elAluno *peao, *aux;
      findAluno(peao, aux, L->getNome(), 0);
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
    cout << "\nNao e possivel fazer esta operacao. Erro:(11).\n";
}

Aluno* lAluno::getAluno (char *S) {
  if(S && contAlunos > 0) {
    elAluno *peao = pAluIni;
    while(peao && strcmp(peao->getAluno()->getNome(), S) != 0)
      peao = peao->getProx();
    if(peao)
      return peao->getAluno();
    else
      cout << "\nO aluno " << S << " nao pertence a Disciplina"
           << getNome() << ".\n";
  }
  else
    cout << "\nNao e possivel fazer esta operacao. Erro:(12).\n";
  return NULL;
}

void lAluno::removeAluno (char *S) {
  if(S && contAlunos > 0) {
    elAluno *peao = pAluIni;
    while(peao && strcmp(peao->getAluno()->getNome(), S) != 0)
      peao = peao->getProx();
    if(peao) {
      peao->getAnt()->setProx(peao->getProx());
      peao->getProx()->setAnt(peao->getAnt());
      delete(peao);
      contAlunos--;
    }
    else
      cout << "\nO aluno " << S << " nao pertence a Disciplina"
           << getNome() << ".\n";
  }
  else
    cout << "\nNao e possivel fazer esta operacao. Erro:(13).\n";
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

void lAluno::faltou (char *S) {
  getAluno(S)->faltou();
}
