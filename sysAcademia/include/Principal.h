#pragma once
#include "Professor.h"

class Principal {
private:
  Professor Jean, Simao, Einstein, Newton;
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
