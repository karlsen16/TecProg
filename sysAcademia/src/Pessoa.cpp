#include "stdafx.h"
#include "Pessoa.h"

Pessoa::Pessoa () {
  inicializa(0, 0, 0);
}

Pessoa::Pessoa (int diaN, int mesN, int anoN, char *S) {
  inicializa(diaN, mesN, anoN, S);
}

void Pessoa::inicializa (int diaN, int mesN, int anoN, char *S) {
  setNome(S);
  dia = diaN;
  mes = mesN;
  ano = anoN;
  idade = 0;
  ID = 0;
}

Pessoa::~Pessoa () {
}

void Pessoa::calculaIdade (int diaParam, int mesParam, int anoParam) {
  idade = anoParam - ano;
  if(mesParam < mes || (mesParam == mes && diaParam < dia))
    idade--;
}

int Pessoa::getIdade () {
  return idade;
}

void Pessoa::setID (int id) {
  ID = id;
}

int Pessoa::getID () {
  return ID;
}

void Pessoa::setNome (char *S) {
  strcpy(nome, S);
}

char* Pessoa::getNome () {
  return nome;
}

void Pessoa::setData (int d, int m, int a) {
  dia = d;
  mes = m;
  ano = a;
}

void Pessoa::imprimeIdade () {
  cout << "A idade de " << getNome() << " seria " << getIdade() << endl;
}
