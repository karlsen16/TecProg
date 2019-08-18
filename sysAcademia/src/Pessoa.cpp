#include "stdafx.h"
#include "Pessoa.h"

Pessoa::Pessoa () {
  inicializa(0, 0, 0);
}

Pessoa::Pessoa (int diaN, int mesN, int anoN, char *S,
                Universidade *U, Departamento *D) {
  inicializa(diaN, mesN, anoN, S, U, D);
}

Pessoa::~Pessoa () {
}

void Pessoa::inicializa (int diaN, int mesN, int anoN,
                         char *S, Universidade *U, Departamento *D) {
  strcpy(nome, S);
  dia = diaN;
  mes = mesN;
  ano = anoN;
  idade = 0;
  uni = U;
  dep = D;
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
  dep = D;
}

void Pessoa::printUni () {
  uni->imprimeUni();
}

void Pessoa::printDep () {
  dep->imprimeDep();
}

void Pessoa::imprimeTudo () {
  imprimeIdade();
  printUni();
  printDep();
}
