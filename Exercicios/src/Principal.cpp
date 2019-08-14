#include "Principal.h"

Principal::Principal () {
  Einstein.inicializa(14, 3, 1879, "Einstein");
  Newton.inicializa(4, 1, 1643, "Newton");
  Executar();
}

void Principal::Executar () {
  Einstein.imprimeIdade();
  Newton.imprimeIdade();
}
