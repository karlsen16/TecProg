#include <string.h>
#include "exercicios.h"

Pessoa::Pessoa (char *S, int diaN, int mesN, int anoN) {
  strcpy(nome, S);
  dia = diaN;
  mes = mesN;
  ano = anoN;
  calculaIdade(13, 3, 2019);
}

void Pessoa::calculaIdade (int diaAtual, int mesAtual, int anoAtual) {
  idade = anoAtual - ano;
  if(mesAtual < mes || (mesAtual == mes && diaAtual < dia))
    idade--;
}

int Pessoa::getIdade () {
  return idade;
}

char* Pessoa::getNome () {
  return nome;
}

void Pessoa::imprimeIdade () {
  printf("A idade de %s seria %d \n", getNome(), getIdade());
}
