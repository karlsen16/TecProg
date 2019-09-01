#include "stdafx.h"
#include "elDepartamento.h"

elDepartamento::elDepartamento (Departamento *D, int id) {
  dep = D;
  prox = ant = NULL;
  setID(id);
}

elDepartamento::~elDepartamento () {
  dep = NULL;
  prox = ant = NULL;
}

Departamento* elDepartamento::getDep () {
  return dep;
}

void elDepartamento::setID (int id) {
  ID = id;
}

int elDepartamento::getID () {
  return ID;
}

void elDepartamento::setProx (elDepartamento *D) {
  prox = D;
}

elDepartamento* elDepartamento::getProx () {
  return prox;
}

void elDepartamento::setAnt (elDepartamento *D) {
  ant = D;
}

elDepartamento* elDepartamento::getAnt () {
  return ant;
}
