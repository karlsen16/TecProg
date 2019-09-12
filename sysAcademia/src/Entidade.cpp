#include "stdafx.h"
#include "Entidade.h"

Entidade::Entidade (string S, int id) {
  setNome(S);
  setID(id);
}

Entidade::~Entidade () {
}

void Entidade::setNome (string S) {
  nome = S;
}

string Entidade::getNome () {
  return nome;
}

void Entidade::setID (int id) {
  ID = id;
}

int Entidade::getID () {
  return ID;
}
