#pragma once
#include "Universidade.h"

class Principal {
private:
  Lista<Universidade> pLU;
  int contIDUni, contIDDep, contIDDis,
      contIDPrf, contIDAlu, ents, ct;
  bool fim;

public:
  Principal ();
  ~Principal ();

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

  void Gravar ();
  void gv_Info ();
  void gv_Uni ();
  void gv_Dep ();
  void gv_Dis ();
  void gv_Prf ();
  void gv_Alu ();
  void gv_Mat ();

  void Carregar ();
  void carregando ();
  bool cr_Info ();
  void cr_Uni ();
  void cr_Dep ();
  void cr_Dis ();
  void cr_Prf ();
  void cr_Mat ();

  int IDUni ();
  int IDDep ();
  int IDDis ();
  int IDPrf ();
  int IDAlu ();

  void erro ();
  Universidade* localizaUni (string S);
  Departamento* localizaDep (string S, string D);
  Disciplina* localizaDis (string S, string D, string I);
  Aluno* localizaAlu (string S, string D, string I, string A);
};
