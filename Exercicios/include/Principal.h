#pragma once
#include "Pessoa.h"

class Principal {
private:
  Pessoa Einstein;
  Pessoa Newton;

  int diaAtual;
  int mesAtual;
  int anoAtual;

public:
  Principal ();
  ~Principal ();
  void Executar ();
};
