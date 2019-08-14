#include "exercicios.h"

int main () {
  Pessoa Einstein("Einstein", 14, 3, 1879);
  Pessoa Newton("Newton", 4, 1, 1643);

  Einstein.imprimeIdade();
  Newton.imprimeIdade();

  getchar();
  return 0;
}
