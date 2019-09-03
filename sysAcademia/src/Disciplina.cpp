#include "stdafx.h"
#include "Disciplina.h"
#include "Departamento.h"

Disciplina::Disciplina () {
  listaAlunos = new lAluno();
  inicializa();
}

Disciplina::Disciplina (char *S, char *A, Departamento *D, int n, int id) {
  listaAlunos = new lAluno();
  inicializa(S, A, D, n, id);
}

void Disciplina::inicializa (char *S, char *A, Departamento *D, int n, int id) {
  setNome(S);
  setArea(A);
  setDep(D);
  setID(id);
  listaAlunos->setNome(S);
  listaAlunos->setNum(n);
}

Disciplina::~Disciplina () {
  dep = NULL;
  if(listaAlunos)
    delete(listaAlunos);
  listaAlunos = NULL;
}

void Disciplina::setNome (char *S) {
  strcpy(nome, S);
}

char* Disciplina::getNome () {
  return nome;
}

void Disciplina::setID (int id) {
  ID = id;
}

int Disciplina::getID () {
  return ID;
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
    D->addDis(this);
}

Departamento* Disciplina::getDep () {
  return dep;
}

void Disciplina::imprimeDis () {
  cout << "Disciplina " << getNome() << ".\n";
}

void Disciplina::addAluno (Aluno *L) {
  listaAlunos->addAluno(L);
}

Aluno* Disciplina::getAluno (char *S) {
  return listaAlunos->getAluno(S);
}

elAluno* Disciplina::getelAluno (char *S) {
  return listaAlunos->getelAluno(S);
}

void Disciplina::removeAluno (char *S) {
  listaAlunos->removeAluno(S);
}

void Disciplina::imprimeAlu () {
  listaAlunos->imprimeAlu();
}

void Disciplina::imprimeAlu2 () {
  listaAlunos->imprimeAlu2();
}
