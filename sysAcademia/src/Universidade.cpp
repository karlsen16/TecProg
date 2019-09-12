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

void Universidade::addDep (Departamento *D) {
  listaDepartamentos->addEnt(D);
}

Departamento* Universidade::getDep (string S) {
  return listaDepartamentos->getEnt(S);
}

void Universidade::removeDep (string S) {
  listaDepartamentos->removeEnt(S);
}

void Universidade::imprimeDeps () {
  listaDepartamentos->imprimeEnts();
}
