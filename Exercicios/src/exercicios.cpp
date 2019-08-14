#include "exercicios.h"

void inicializa (Pessoa *P, int diaN, int mesN, int anoN) {
  P->dia = diaN;
  P->mes = mesN;
  P->ano = anoN;
  P->idade = calculaIdade(P, 2019);
}

int calculaIdade (Pessoa *P, int anoAtual) {
  return anoAtual - P->ano;
}
