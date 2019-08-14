#include "exercicios.h"

int main () {
  Pessoa Einstein, Newton;

  inicializa(Einstein, 14, 3, 1879);
  inicializa(Newton, 4, 1, 1643);

  printf("A idade de Einstein seria %d \n", Einstein.idade);
  printf("A idade de Newton seria %d \n", Newton.idade);

  getchar();
  return 0;
}
