#pragma once
#include "Universidade.h"

class Pessoa {
private:
  char nome[30];
  int dia;
  int mes;
  int ano;
  int idade;
  Universidade *uni;
  Departamento *dep;

public:
  Pessoa ();
  Pessoa (int diaN, int mesN, int anoN, char *S,
    Universidade *U = NULL, Departamento *D = NULL);
  ~Pessoa ();
  void inicializa (int diaN, int mesN, int anoN,
    char *S = "", Universidade *U = NULL, Departamento *D = NULL);
  void calculaIdade (int diaParam, int mesParam, int anoParam);
  int getIdade ();
  char* getNome ();
  void imprimeIdade ();
  void setUni (Universidade *U);
  void setDep (Departamento *D);
  void printUni ();
  void printDep ();
  void imprimeTudo ();
};
