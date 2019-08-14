#include "exercicios.h"

void inicializa (Pessoa& P, int diaN, int mesN, int anoN) {
  P.dia = diaN;
  P.mes = mesN;
  P.ano = anoN;
  calculaIdade(P, 14, 8, 2019);
}

void calculaIdade (Pessoa& P, int diaAtual, int mesAtual, int anoAtual) {
  P.idade = anoAtual - P.ano;
  if(mesAtual < P.mes || (mesAtual == P.mes && diaAtual < P.dia))
    P.idade--;
}
