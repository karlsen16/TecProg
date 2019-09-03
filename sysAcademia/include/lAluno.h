#pragma once
#include "elAluno.h"

class lAluno {
private:
  char nome[150];
  int ID, nAlunos, contAlunos;
  elAluno *pAluIni, *pAluAtual;

public:
  lAluno (char *S = "", int n = 45);
  ~lAluno ();
  void setNome (char *S);
  char* getNome ();
  void setNum (int n);
  void addAluno (Aluno *L);
  Aluno* getAluno (char *S);
  elAluno* getelAluno (char *S);
  void removeAluno (char *S);
  void imprimeAlu ();
  void imprimeAlu2 ();
};
