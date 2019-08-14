#ifndef ___EXERCICIOS_H__
#define ___EXERCICIOS_H__
#include <stdio.h>

struct Pessoa {
public:
  int dia;
  int mes;
  int ano;
  int idade;

  Pessoa (int diaN, int mesN, int anoN) {
    dia = diaN;
    mes = mesN;
    ano = anoN;
    calculaIdade(13, 3, 2019);
  }

  void calculaIdade (int diaAtual, int mesAtual, int anoAtual) {
    idade = anoAtual - ano;
    if(mesAtual < mes || (mesAtual == mes && diaAtual < dia))
      idade--;
  }
};

#endif /* ___EXERCICIOS_H__ */
