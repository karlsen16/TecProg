#include "stdafx.h"
#include "Principal.h"

Principal::Principal ():
  Fisica("Fisica"),
  Matematica("Matematica"),
  Princeton("Princeton - Nova Jersey (USA)", &Fisica),
  Cambrigde("Cambrigde (Inglaterra)", &Matematica),
  Einstein(14, 3, 1879, "Einstein", &Princeton, &Fisica),
  Newton(4, 1, 1643, "Newton", &Cambrigde, &Matematica)
 {
  time_t T = time(NULL);
  struct tm tm = *localtime(&T);
  diaAtual = tm.tm_mday;
  mesAtual = tm.tm_mon + 1;
  anoAtual = tm.tm_year +1900;
  Einstein.calculaIdade(diaAtual, mesAtual, anoAtual);
  Newton.calculaIdade(diaAtual, mesAtual, anoAtual);

  Executar();
}

Principal::~Principal () {
}

void Principal::Executar () {
  Einstein.imprimeTudo();
  Newton.imprimeTudo();
}
