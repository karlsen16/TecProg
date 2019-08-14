#include "exercicios.h"

int main () {
  Pessoa Einstein(14, 3, 1879, "Einstein");
  Pessoa Newton(4, 1, 1643, "Newton");

  Einstein.imprimeIdade();
  Newton.imprimeIdade();

  getchar();
  return 0;
}
