#pragma once
#include "lDisciplina.h"
class Universidade;

class Departamento {
private:
  char nome[150];
  Universidade *uni;
  lDisciplina *listaDisciplinas;
  int ID;

public:
  Departamento ();
  Departamento (char *S, Universidade *U, int n, int id);
  void inicializa (char *S = "", Universidade *U = NULL, int n = 1000, int id = 0);
  ~Departamento ();
  void setNome (char *S);
  char* getNome ();
  void setID (int id);
  int getID ();
  void setUni (Universidade *U);
  Universidade* getUni ();
  void imprimeDep ();
  void incluirDis (Disciplina *D);
  void removeDis (Disciplina *D);
  void imprimeDis ();
  void imprimeDis2 ();
};
