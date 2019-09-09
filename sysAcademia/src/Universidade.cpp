#include "stdafx.h"
#include "Universidade.h"

Universidade::Universidade (char *S, int n, int id) {
  setNome(S);
  listaDepartamentos = new lDepartamento(S, n);
  setID(id);
}

Universidade::~Universidade () {
  if(listaDepartamentos)
    delete(listaDepartamentos);
  listaDepartamentos = NULL;
}

void Universidade::setNome (char *S) {
  strcpy(nome, S);
}

char* Universidade::getNome () {
  return nome;
}

void Universidade::setID (int id) {
  ID = id;
}

int Universidade::getID () {
  return ID;
}

void Universidade::addDep (Departamento *D) {
  listaDepartamentos->addDep(D);
}

Departamento* Universidade::getDep (char *S) {
  listaDepartamentos->getDep(S);
}

void Universidade::removeDep (char *S) {
  listaDepartamentos->removeDep(S);
}

void Universidade::imprimeDeps () {
  listaDepartamentos->imprimeDeps();
}
