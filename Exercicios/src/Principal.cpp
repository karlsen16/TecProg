#include "stdafx.h"
#include "Principal.h"

Principal::Principal (): Einstein(), Newton() {
  Einstein.inicializa(14, 3, 1879, "Einstein");
  Newton.inicializa(4, 1, 1643, "Newton");
  time_t T = time(NULL);
  struct tm tm = *localtime(&T);
  diaAtual = tm.tm_mday;
  mesAtual = tm.tm_mon + 1;
  anoAtual = tm.tm_year +1900;
  Executar();
}

Principal::~Principal () {
}

void Principal::Executar () {
  Einstein.calculaIdade(diaAtual, mesAtual, anoAtual);
  Newton.calculaIdade(diaAtual, mesAtual, anoAtual);
  Einstein.imprimeIdade();
  Newton.imprimeIdade();
}
