#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
#include"MinhaString.h"

int main() {
  char Vet[100] = "Minha primeira string soh minha.";
  MinhaString S1(Vet);
  cout << S1.getString() << endl;
  return 0;
}
