#pragma once
#include "elAluno.h"

class lAluno {
private:
  char nome[150];
  int ID, nAlunos, contAlunos;
  elAluno *pAluIni, *pAluAtual;

public:
  lAluno (char *S = "", int n = 45, int id = 0);
  ~lAluno ();
  void setNome (char *S);
  char* getNome ();
  void setID (int id);
  int getID ();
  void setNum (int n);
  void addAluno (Aluno *L);
  void removeAluno (Aluno *L);
  void imprimeAlu ();
  void imprimeAlu2 ();
};
