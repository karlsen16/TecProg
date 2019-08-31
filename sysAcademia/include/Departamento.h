#pragma once
#include "lDisciplina.h"
class Universidade;

class Departamento {
private:
  char nome[150];
  Universidade *uni;
  int ID;
  lDisciplina *listaDisciplinas;

public:
  Departamento ();
  Departamento (char *S, Universidade *U, int id, int n);
  void inicializa (char *S = "", Universidade *U = NULL, int id = 0, int n = 1000);
  ~Departamento ();
  void setNome (char *S);
  char* getNome ();
  void setUni (Universidade *U);
  Universidade* getUni ();
  void imprimeDep ();
  void setID (int id);
  int getID ();
  void incluirDis (Disciplina *D);
  void removeDis (Disciplina *D);
  void imprimeDis ();
  void imprimeDis2 ();
};
