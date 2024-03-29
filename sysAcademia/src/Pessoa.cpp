#include "stdafx.h"
#include "Pessoa.h"

int Pessoa::contP = 0;

Pessoa::Pessoa ():
Entidade() {
  inicializa(0, 0, 0);
  contP++;
}

Pessoa::Pessoa (int diaN, int mesN, int anoN, string S, int id):
Entidade(S, id) {
  inicializa(diaN, mesN, anoN, S, id);
  contP++;
}

void Pessoa::inicializa (int diaN, int mesN, int anoN, string S, int id) {
  setNome(S);
  dia = diaN;
  mes = mesN;
  ano = anoN;
  calculaIdade();
  setID(id);
}

Pessoa::~Pessoa () {
  contP--;
}

void Pessoa::calculaIdade () {
  int diaParam, mesParam, anoParam;
  time_t T = time(NULL);
  struct tm tm = *localtime(&T);
  diaParam = tm.tm_mday;
  mesParam = tm.tm_mon+1;
  anoParam = tm.tm_year+1900;
  idade = anoParam - ano;
  if(mesParam < mes || (mesParam == mes && diaParam < dia))
    idade--;
}

int Pessoa::getIdade () {
  return idade;
}

int Pessoa::getDia () {
  return dia;
}

int Pessoa::getMes () {
  return mes;
}

int Pessoa::getAno () {
  return ano;
}

void Pessoa::setData (int d, int m, int a) {
  dia = d;
  mes = m;
  ano = a;
}

void Pessoa::imprimeIdade () {
  cout << "A idade de " << getNome() << " seria " << getIdade();
}
