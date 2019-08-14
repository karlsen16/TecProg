#ifndef ___EXERCICIOS_H__
#define ___EXERCICIOS_H__
#include <stdio.h>

typedef struct pessoa {
  int dia;
  int mes;
  int ano;
  int idade;
} Pessoa;

void inicializa (Pessoa *P, int diaN, int mesN, int anoN);
int calculaIdade (Pessoa *P, int anoAtual);

#endif /* ___EXERCICIOS_H__ */
