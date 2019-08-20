#include "stdafx.h"
#include "Principal.h"

Principal::Principal ():
  DAINF("Informatica"), DAELN("Elétrica"), Fisica("Fisica"), Matematica("Matematica"),
  UTFPR("Tecnologica Federal do Parana (Brasil)", &DAINF),
  Princeton("Princeton - Nova Jersey (USA)", &Fisica),
  Cambrigde("Cambrigde (Inglaterra)", &Matematica),
  Jean(3, 10, 1987, "Jean", &UTFPR, &DAINF),
  Simao(31, 12, 2000, "Simao", &UTFPR, &DAELN),
  Einstein(14, 3, 1879, "Einstein", &Princeton, &Fisica),
  Newton(4, 1, 1643, "Newton", &Cambrigde, &Matematica)
 {
  UTFPR.setDep(&DAELN);
  Fisica.setUni(&Princeton);
  Matematica.setUni(&Cambrigde);

  time_t T = time(NULL);
  struct tm tm = *localtime(&T);
  diaAtual = tm.tm_mday;
  mesAtual = tm.tm_mon + 1;
  anoAtual = tm.tm_year +1900;
  Jean.calculaIdade(diaAtual, mesAtual, anoAtual);
  Simao.calculaIdade(diaAtual, mesAtual, anoAtual);
  Einstein.calculaIdade(diaAtual, mesAtual, anoAtual);
  Newton.calculaIdade(diaAtual, mesAtual, anoAtual);

  Executar();
}

Principal::~Principal () {
}

void Principal::Executar () {
  Jean.imprimeTudo();
  Simao.imprimeTudo();
  Einstein.imprimeTudo();
  Newton.imprimeTudo();

  UTFPR.imprimeDepS();
  Princeton.imprimeDepS();
  Cambrigde.imprimeDepS();
}
