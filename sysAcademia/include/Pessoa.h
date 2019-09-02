#pragma once

class Pessoa {
protected:
  char nome[30];
  int dia, mes, ano, idade, ID;

public:
  Pessoa ();
  Pessoa (int diaN, int mesN, int anoN, char *S);
  void inicializa (int diaN, int mesN, int anoN, char *S = "");
  ~Pessoa ();
  void calculaIdade ();
  int getIdade ();
  void setID (int id);
  int getID ();
  void setNome (char *S);
  char* getNome ();
  void setData (int d, int m, int a);
  void imprimeIdade ();
};
