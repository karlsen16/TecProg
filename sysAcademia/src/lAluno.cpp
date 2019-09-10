#include "stdafx.h"
#include "lAluno.h"

lAluno::lAluno (char *S, int n) {
  setNome(S);
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

void lAluno::setNum (int n) {
  nAlunos = n;
}

void lAluno::addAluno (Aluno *L) {
  if(L && contAlunos < nAlunos) {
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
      cout << "\nO Aluno " << S << " nao pertence a Disciplina"
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

elAluno* lAluno::getelAluno (char *S) {
  if(S && contAlunos > 0) {
    elAluno *peao = pAluIni;
    while(peao && strcmp(peao->getAluno()->getNome(), S) != 0)
      peao = peao->getProx();
    if(peao)
      return peao;
    else
      cout << "\nO el.Aluno " << S << " nao pertence a Disciplina"
           << getNome() << ".\n";
  }
  else
    cout << "\nNao e possivel fazer esta operacao. Erro:(14).\n";
  return NULL;
}

void lAluno::imprimeAlus () {
  if(contAlunos > 0) {
    cout << "Lista de Alunos:\n";
    elAluno *peao = pAluIni;
    int cont = 1;
    while(peao) {
      cout << "\t" << cont << "# " << peao->getAluno()->getNome() << "  -ID: "
           << peao->getAluno()->getID() << "\n";
      cont++;
      peao = peao->getProx();
    }
  }
  else
    cout << "Nao e possivel fazer esta operacao. Erro (19).\n";
}

void lAluno::faltou (char *S) {
  getelAluno(S)->faltou();
}
