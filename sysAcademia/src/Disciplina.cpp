#include "stdafx.h"
#include "Disciplina.h"
#include "Departamento.h"
#include "Lista.h"

Disciplina::Disciplina ():
Entidade() {
  listaAlunos = new Lista<Aluno>();
  inicializa();
}

Disciplina::Disciplina (string S, string A, Departamento *D, int n, int id):
Entidade(S, id) {
  listaAlunos = new Lista<Aluno>();
  inicializa(S, A, D, n, id);
}

void Disciplina::inicializa (string S, string A, Departamento *D, int n, int id) {
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

void Disciplina::setArea (string A) {
  area = A;
}

string Disciplina::getArea () {
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

int Disciplina::getN(){
  return listaAlunos->getN();
}

void Disciplina::addAluno (Aluno *L) {
  listaAlunos->addEnt(L);
}

Aluno* Disciplina::getAluno (string S) {
  return listaAlunos->getEnt(S);
}

void Disciplina::removeAluno (string S) {
  listaAlunos->removeEnt(S);
}

Elemento<Aluno>* Disciplina::getelAluno (string S) {
  return listaAlunos->getel(S);
}

void Disciplina::imprimeAlus () {
  listaAlunos->imprimeEnts();
}

Lista<Aluno>* Disciplina::getLista () {
  return listaAlunos;
}
