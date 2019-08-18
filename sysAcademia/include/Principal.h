#pragma once
#include "Pessoa.h"

class Principal {
private:
  Pessoa Jean, Simao, Einstein, Newton;
  Universidade UTFPR, Princeton, Cambrigde;
  Departamento DAINF, DAELN, Fisica, Matematica;

  int diaAtual;
  int mesAtual;
  int anoAtual;

public:
  Principal ();
  ~Principal ();
  void Executar ();
};
