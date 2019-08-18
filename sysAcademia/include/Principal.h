#pragma once
#include "Pessoa.h"
#include "Universidade.h"
#include "Departamento.h"

class Principal {
private:
  Pessoa Einstein;
  Pessoa Newton;

  Universidade Princeton;
  Universidade Cambrigde;

  Departamento Fisica;
  Departamento Matematica;

  int diaAtual;
  int mesAtual;
  int anoAtual;

public:
  Principal ();
  ~Principal ();
  void Executar ();
};
