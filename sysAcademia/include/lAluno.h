#pragma once
#include "elAluno.h"

class lAluno {
private:
  char nome[150];
  int nAlunos, contAlunos;
  elAluno *pAluIni, *pAluAtual;

public:
  lAluno ();
  ~lAluno ();
  void setNome (char *S);
  char* getNome ();
  void setNum (int n);
  void addAluno (Aluno *L);
  void removeAluno (Aluno *L);
  void imprimeAlu ();
  void imprimeAlu2 ();
};
