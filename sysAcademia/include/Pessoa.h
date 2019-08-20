#pragma once

class Pessoa {
protected:
  char nome[30];
  int dia;
  int mes;
  int ano;
  int idade;
  int ID;

public:
  Pessoa ();
  Pessoa (int diaN, int mesN, int anoN, char *S);
  ~Pessoa ();
  void inicializa (int diaN, int mesN, int anoN, char *S = "");
  void calculaIdade (int diaParam, int mesParam, int anoParam);
  int getIdade ();
  void setID (int id);
  int getID ();
  void setNome (char *S);
  char* getNome ();
  void imprimeIdade ();
};
