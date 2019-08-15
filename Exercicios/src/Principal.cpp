#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include "Principal.h"

Principal::Principal () {
  Einstein.inicializa(14, 3, 1879, "Einstein");
  Newton.inicializa(4, 1, 1643, "Newton");
  cout << "Informe o dia/mes/ano:" << endl;
  cin >> diaAtual >> mesAtual >> anoAtual;
  Executar();
}

void Principal::Executar () {
  Einstein.calculaIdade(diaAtual, mesAtual, anoAtual);
  Newton.calculaIdade(diaAtual, mesAtual, anoAtual);
  Einstein.imprimeIdade();
  Newton.imprimeIdade();
}
