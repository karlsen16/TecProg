#pragma once
#include "Entidade.h"

class Pessoa: public Entidade {
protected:
  static int contP;
  int dia, mes, ano, idade;

public:
  Pessoa ();
  Pessoa (int diaN, int mesN, int anoN, string S, int id);
  void inicializa (int diaN, int mesN, int anoN, string S = "", int id = 0);
  ~Pessoa ();
  void calculaIdade ();
  int getIdade ();
  int getDia ();
  int getMes ();
  int getAno ();
  void setData (int d, int m, int a);
  void imprimeIdade ();
  static int getContP ();

};
