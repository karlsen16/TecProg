#include "stdafx.h"
#include "Entidade.h"

int Entidade::cont = 0;

Entidade::Entidade (string S, int id) {
  setNome(S);
  setID(id);
  cont++;
}

Entidade::~Entidade () {
  cont--;
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

static int Entidade::getCont () {
  return cont;
}
