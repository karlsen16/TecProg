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

void Universidade::imprimeUni () {
  cout << "Universidade " << getNome();
}

void Universidade::addDep (Departamento *D) {
  listaDepartamentos->addDep(D);
}

void Universidade::removeDep (Departamento *D) {
  listaDepartamentos->removeDep(D);
}

Departamento* Universidade::getDepI (int i) {
  listaDepartamentos->getDepI(i);
}

void Universidade::imprimeDep (int i) {
  listaDepartamentos->imprimeDep(i);
}

void Universidade::imprimeDis (int i) {
  listaDepartamentos->imprimeDis(i);
}

void Universidade::imprimeDepS () {
  listaDepartamentos->imprimeDepS();
}

void Universidade::imprimeTudo () {
  listaDepartamentos->imprimeTudo();
}
