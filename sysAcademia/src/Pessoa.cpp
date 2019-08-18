#include "stdafx.h"
#include "Pessoa.h"

Pessoa::Pessoa () {
  inicializa(0, 0, 0);
}

Pessoa::Pessoa (int diaN, int mesN, int anoN, char *S) {
  inicializa(diaN, mesN, anoN, S);
}

Pessoa::~Pessoa () {
}

void Pessoa::inicializa (int diaN, int mesN, int anoN, char *S) {
  strcpy(nome, S);
  dia = diaN;
  mes = mesN;
  ano = anoN;
  idade = 0;
  uni = NULL;
}

void Pessoa::calculaIdade (int diaParam, int mesParam, int anoParam) {
  idade = anoParam - ano;
  if(mesParam < mes || (mesParam == mes && diaParam < dia))
    idade--;
}

int Pessoa::getIdade () {
  return idade;
}

char* Pessoa::getNome () {
  return nome;
}

void Pessoa::imprimeIdade () {
  cout << "A idade de " << getNome() << " seria " << getIdade() << endl;
}

void Pessoa::setUni (Universidade *U) {
  uni = U;
}

void Pessoa::setDep (Departamento *D) {
  uni->setDep(D);
}

void Pessoa::printUni () {
  uni->imprimeUni();
}

void Pessoa::printDep () {
  uni->imprimeDep();
}
