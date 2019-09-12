#pragma once
#include "Dados.h"
#include "Universidade.h"

class Menu {
private:
  Lista<Universidade>* pLU;
  Dados* pArq;
  int contIDAlu, contIDPrf, contIDDis,
      contIDDep, contIDUni;
  bool fim;

public:
  Menu (Lista<Universidade> *plu = NULL, Dados* dat = NULL);
  ~Menu ();

  void Inicial ();
  void transicao (string S, bool d);
  void esperar ();
  void invalido (bool d);
  void voltar ();
  void sair ();

  void Cad ();
  void CadUniversidade ();
  void CadDepartamento ();
  void CadDisciplina ();
  void CadProfessor ();
  void CadAluno ();

  void Exe ();
  void ExeUniversidade ();
  void ExeDepartamento ();
  void ExeDisciplina ();
  void ExeProfessor ();
  void ExeAluno ();

  void Carregar ();
  void Gravar ();

};
