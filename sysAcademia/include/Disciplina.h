#pragma once
#include "lAluno.h"
class Departamento;

class Disciplina {
private:
  char nome[150];
  char area[150];
  Departamento *dep;
  int ID;
  lAluno *listaAlunos;

public:
  Disciplina ();
  Disciplina (char *S, char *A, Departamento *D, int n, int id);
  ~Disciplina ();
  void inicializa (char *S = "", char *A = "", Departamento *D = NULL, int n = 45, int id = 0);
  void setNome (char *S);
  char* getNome ();
  void setID (int id);
  int getID ();
  void setArea (char *A);
  char* getArea ();
  void setDep (Departamento *D);
  Departamento* getDep ();
  void addAluno (Aluno *L);
  Aluno* getAluno (char *S);
  void removeAluno (char *S);
  elAluno* getelAluno (char *S);
  void imprimeAlus ();
};
