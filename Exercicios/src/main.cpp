#include "exercicios.h"

int main () {
  Pessoa Einstein(14, 3, 1879);
  Pessoa Newton(4, 1, 1643);

  printf("A idade de Einstein seria %d \n", Einstein.getIdade());
  printf("A idade de Newton seria %d \n", Newton.getIdade());

  getchar();
  return 0;
}
