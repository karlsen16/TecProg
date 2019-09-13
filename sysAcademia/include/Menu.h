#pragma once
#include "Dados.h"

class Menu {
private:
  Lista<Universidade> *pLU;
  Dados *pArq;
  bool fim;

public:
  Menu (Lista<Universidade> *plu = NULL, Dados *dat = NULL);
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

  Universidade* localizaUni (string S);
  Departamento* localizaDep (string S, string D);
  Disciplina* localizaDis (string S, string D, string I);

  void Exe ();
  void ExeUniversidade ();
  void ExeDepartamento ();
  void ExeDisciplina ();
  void ExeProfessor ();
  void ExeAluno ();

  void Carregar ();
  void Gravar ();

};
