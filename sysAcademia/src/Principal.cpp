#include "stdafx.h"
#include "Principal.h"

Principal::Principal ():
  Einstein(14, 3, 1879, "Einstein"),
  Newton(4, 1, 1643, "Newton"),
  Princeton("Princeton - Nova Jersey (USA)"),
  Cambrigde("Cambrigde (Inglaterra)"),
  Fisica("Fisica"),
  Matematica("Matematica")
 {
  time_t T = time(NULL);
  struct tm tm = *localtime(&T);
  diaAtual = tm.tm_mday;
  mesAtual = tm.tm_mon + 1;
  anoAtual = tm.tm_year +1900;

  Einstein.setUni(&Princeton);
  Einstein.setDep(&Fisica);
  Newton.setUni(&Cambrigde);
  Newton.setDep(&Matematica);

  Executar();
}

Principal::~Principal () {
}

void Principal::Executar () {
  Einstein.calculaIdade(diaAtual, mesAtual, anoAtual);
  Einstein.imprimeIdade();
  Einstein.printUni();
  Einstein.printDep();

  Newton.calculaIdade(diaAtual, mesAtual, anoAtual);
  Newton.imprimeIdade();
  Newton.printUni();
  Newton.printDep();
}
