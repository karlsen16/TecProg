#include "stdafx.h"
#include "Universidade.h"

Universidade::Universidade (string S, int n, int id):
Entidade(S, id) {
  listaDepartamentos = new Lista<Departamento>(S, n);
}

Universidade::~Universidade () {
  if(listaDepartamentos)
    delete(listaDepartamentos);
  listaDepartamentos = NULL;
}

int Universidade::getN(){
  return listaDepartamentos->getN();
}

void Universidade::addDep (Departamento *D) {
  listaDepartamentos->addEnt(D);
}

Departamento* Universidade::getDep (string S) {
  return listaDepartamentos->getEnt(S);
}

Disciplina* Universidade::getDis (string S) {
  Elemento<Departamento> *peao = listaDepartamentos->getIni();
  while(peao) {
    Departamento *d = peao->getInfo();
    Disciplina *i = d->getDis(S);
    if(i)
      return i;
    peao = peao->getProx();
  }
  return NULL;
}

void Universidade::removeDep (string S) {
  listaDepartamentos->removeEnt(S);
}

void Universidade::imprimeDeps () {
  listaDepartamentos->imprimeEnts();
}

Lista<Departamento>* Universidade::getLista () {
  return listaDepartamentos;
}
