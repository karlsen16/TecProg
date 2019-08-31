#pragma once
#include "Professor.h"
#include "Aluno.h"

class Principal {
private:
  Professor Joana, Simao, Einstein, Newton;
  Universidade UTFPR, Princeton, Cambrigde;
  Departamento DAINF, DADIN, DAFIS, DAMAT, FisicaP, MatematicaP, FisicaC, MatematicaC;
  Disciplina comp1_2019, mat_2019, design_2019, graph_2017, opt_2000, tec_2008,
             comp2_2015, quant_2010, disc_2011, neut_2001;
  Aluno fulano, ciclano, judete, julia, juliana, julius, fulan;

  int diaAtual;
  int mesAtual;
  int anoAtual;

public:
  Principal ();
  ~Principal ();

  void Init ();
  void Init_Alunos ();
  void Matriculas ();
  void Init_Professores ();
  void Init_Disciplinas ();
  void Init_Departamentos ();
  void Init_Universidades ();

  void Executar ();
  void calculaIdadeProfs ();
  void localTrabalho ();
  void imprimeDepDisS ();
};
