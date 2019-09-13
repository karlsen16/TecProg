#pragma once
#include "Universidade.h"
class Menu;

class Dados {
private:
  Lista<Universidade> *pLU;
  Menu *pMenu;
  int contIDUni, contIDDep, contIDDis,
      contIDPrf, contIDAlu, ents, ct;

public:
  Dados (Lista<Universidade> *plu = NULL, Menu *menu = NULL);
  ~Dados ();

  void erro ();
  void s_E ();
  void carregando ();

  void Carregar ();
  bool cr_Info ();
  void cr_Uni (bool res);
  void cr_Dep (bool res);
  void cr_Dis (bool res);
  void cr_Prf (bool res);
  void cr_Mat (bool res);

  Departamento* localizaDep (string S);
  Disciplina* localizaDis (string S);
  Aluno* localizaAlu (string A);

  void Gravar ();
  void gv_Info ();
  void gv_Uni ();
  void gv_Dep ();
  void gv_Dis ();
  void gv_Prf ();
  void gv_Alu ();
  void gv_Mat ();

  int IDUni ();
  int IDDep ();
  int IDDis ();
  int IDPrf ();
  int IDAlu ();

};
