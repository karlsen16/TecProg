#pragma once
#include "Professor.h"

class Principal {
private:
  Professor Joana, Simao, Einstein, Newton;
  Universidade UTFPR, Princeton, Cambrigde;
  Departamento DAINF, DADIN, DAFIS, DAMAT, FisicaP, MatematicaP, FisicaC, MatematicaC;
  Disciplina comp1_2019, mat_2019, design_2019, graph_2017, opt_2000, tec_2008,
             comp2_2015, quant_2010, disc_2011, neut_2001;

  int diaAtual;
  int mesAtual;
  int anoAtual;

public:
  Principal ();
  ~Principal ();

  void Init ();
  void Init_Universidades ();
  void Init_Departamentos ();
  void Init_Professores ();
  void Init_Disciplinas ();

  void Executar ();
  void calculaIdadeProfs ();
  void localTrabalho ();
  void depTrabalho ();
  void imprimeDepDisS ();
};
