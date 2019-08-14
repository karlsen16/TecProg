#ifndef ___EXERCICIOS_H__
#define ___EXERCICIOS_H__
#include <stdio.h>

struct Pessoa {
private:
  char nome[30];
  int dia;
  int mes;
  int ano;
  int idade;

public:
  Pessoa (int diaN, int mesN, int anoN, char *S = "");
  void calculaIdade (int diaAtual, int mesAtual, int anoAtual);
  int getIdade ();
  char* getNome ();
  void imprimeIdade ();
};

#endif /* ___EXERCICIOS_H__ */
