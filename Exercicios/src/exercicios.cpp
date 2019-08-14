#include "exercicios.h"

void inicializa (Pessoa *P, int diaN, int mesN, int anoN) {
  P->dia = diaN;
  P->mes = mesN;
  P->ano = anoN;
  P->idade = calculaIdade(P, 14, 8, 2019);
}

int calculaIdade (Pessoa *P, int diaAtual, int mesAtual, int anoAtual) {
  int retorno = anoAtual - P->ano;
  if(mesAtual < P->mes || (mesAtual == P->mes && diaAtual < P->dia))
    retorno--;
  return retorno;
}
