#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
#include "Pessoa.h"

Pessoa::Pessoa () {
  inicializa(0, 0, 0);
}

Pessoa::Pessoa (int diaN, int mesN, int anoN, char *S) {
  inicializa(diaN, mesN, anoN, S);
}

void Pessoa::inicializa (int diaN, int mesN, int anoN, char *S) {
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
  cout << "A idade de " << getNome() << " seria " << getIdade() << endl;
}