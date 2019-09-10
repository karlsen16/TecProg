#pragma once
#include "lUniversidade.h"

class Principal {
private:
  lUniversidade listaUniversidades;

  int contIDAlu, contIDPrf, contIDDis, contIDDep, contIDUni;

public:
  Principal ();
  ~Principal ();

  void Menu ();
  void transicao (char *S);
  void esperar ();

  void MenuCad ();
  void CadUniversidade ();
  void CadDepartamento ();
  void CadDisciplina ();
  void CadProfessor ();
  void CadAluno ();

  void MenuExe ();
  void ExeUniversidade ();
  void ExeDepartamento ();
  void ExeDisciplina ();
  void ExeProfessor ();
  void ExeAluno ();

  void Invalido (int op);
  void Finalizar ();
  void Carregar ();
  void Gravar ();




  // void Init ();
  // void Init_Alunos ();
  // void Matriculas ();
  // void Init_Professores ();
  // void Init_Disciplinas ();
  // void Init_Departamentos ();
  // void Init_Universidades ();
  //
  // void Executar ();
  // void calculaIdadeProfs ();
  // void localTrabalho ();
  // void imprimeDepDisS ();
};

/*class Principal {
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
};*/
