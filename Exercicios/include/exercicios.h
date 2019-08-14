#ifndef ___EXERCICIOS_H__
#define ___EXERCICIOS_H__
#include <stdio.h>

struct Pessoa {
private:
  int dia;
  int mes;
  int ano;
  int idade;

public:
  Pessoa (int diaN, int mesN, int anoN);
  void calculaIdade (int diaAtual, int mesAtual, int anoAtual);
  int getIdade ();
};

#endif /* ___EXERCICIOS_H__ */
