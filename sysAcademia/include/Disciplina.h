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
  Disciplina (char *S, char *A, Departamento *D, int id, int n);
  ~Disciplina ();
  void inicializa (char *S = "", char *A = "", Departamento *D = NULL, int id = 0, int n = 45);
  void setNome (char *S);
  char* getNome ();
  void setArea (char *A);
  char* getArea ();
  void setDep (Departamento *D);
  Departamento* getDep ();
  void imprimeDis ();
  void setID (int id);
  int getID ();
  void addAluno (Aluno *L);
  void removeAluno (Aluno *L);
  void imprimeAlu ();
  void imprimeAlu2 ();
};
