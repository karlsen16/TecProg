#include "stdafx.h"
#include "Disciplina.h"
#include "Universidade.h"
#include "Aluno.h"

Disciplina::Disciplina () {
  prox = ant = NULL;
  pAluIni = pAluAtual = NULL;
  contAlunos = 0;
  nAlunos = 45;
  inicializa();
}

Disciplina::Disciplina (char *S, char *A, Departamento *D, int id) {
  prox = ant = NULL;
  pAluIni = pAluAtual = NULL;
  contAlunos = 0;
  nAlunos = 45;
  inicializa(S, A, D, id);
}

void Disciplina::inicializa (char *S, char *A, Departamento *D, int id) {
  setNome(S);
  setArea(A);
  setDep(D);
  setID(id);
}

Disciplina::~Disciplina () {
  dep = NULL;
  prox = ant = NULL;
  pAluIni = pAluAtual = NULL;
}

void Disciplina::setNome (char *S) {
  strcpy(nome, S);
}

char* Disciplina::getNome () {
  return nome;
}

void Disciplina::setArea (char *A) {
  strcpy(area, A);
}

char* Disciplina::getArea () {
  return area;
}

void Disciplina::setDep (Departamento *D) {
  dep = D;
  if(D)
    D->incluirDis(this);
}

Departamento* Disciplina::getDep () {
  return dep;
}

void Disciplina::setProx (Disciplina *I) {
  prox = I;
}

Disciplina* Disciplina::getProx () {
  return prox;
}

void Disciplina::setAnt (Disciplina *I) {
  ant = I;
}

Disciplina* Disciplina::getAnt () {
  return ant;
}

void Disciplina::imprimeDis () {
  cout << "Disciplina: " << getNome() << ".\n";
}

void Disciplina::setID (int id) {
  ID = id;
}

int Disciplina::getID () {
  return ID;
}

void Disciplina::addAluno (Aluno *L) {
  if(contAlunos <= nAlunos) {
    if(!pAluIni)
      pAluIni = pAluAtual = L;
    else {
      Aluno *peao = pAluIni, *aux = NULL;
      while(peao != NULL && strcmp(peao->getNome(), L->getNome()) < 0) {
        aux = peao;
        peao = peao->getProx();
      }
      L->setProx(peao);
      L->setAnt(aux);
      if(peao)
        peao->setAnt(L);
      if(aux)
        aux->setProx(L);
      if(!L->getProx())
        pAluAtual = L;
      if(!L->getAnt())
        pAluIni = L;
    }
    contAlunos++;
  }
  else
    cout << "\nTurma cheia! Tente novamente no proximo semestre..\n";
}

void Disciplina::removeAluno (Aluno *L) {
  if(contAlunos > 0) {
    Aluno *peao = pAluIni;
    while(peao != NULL && strcmp(peao->getNome(), L->getNome()) != 0)
      peao = peao->getProx();
    if(peao) {
      peao->getAnt()->setProx(peao->getProx());
      peao->getProx()->setAnt(peao->getAnt());
      contAlunos--;
    }
    else
      cout << "\nO aluno " << L->getNome() << " nao pertence a " << getNome() << ".\n";
  }
  else
    cout << "\nTurma de " << getNome() << " vazia!\n";
}

void Disciplina::imprimeAlu () {
  Aluno *peao = pAluIni;
  int cont = 1;
  if(contAlunos > 0) {
    cout << "\t\t\tLista de Alunos:\n";
    while(peao != NULL) {
      cout << "\t\t\t" << cont << "# " << peao->getNome() << "\n";
      cont++;
      peao = peao->getProx();
    }
  }
}

void Disciplina::imprimeAlu2 () {
  Aluno *peao = pAluAtual;
  int cont = 1;
  cout << "\t\t\tLista de Alunos:\n";
  while(peao != NULL) {
    cout << "\t\t\t" << cont << "# " << peao->getNome() << "\n";
    cont++;
    peao = peao->getAnt();
  }
}
