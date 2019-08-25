#pragma once
#include "Disciplina.h"
class Universidade;

class Departamento {
private:
  char nome[150];
  Universidade *uni;
  Disciplina *pDisIni;
  Disciplina *pDisAtual;
  int ID;

public:
  Departamento ();
  Departamento (char *S, Universidade *U, int id);
  void inicializa (char *S = "", Universidade *U = NULL, int id = 0);
  ~Departamento ();
  void setNome (char *S);
  char* getNome ();
  void setUni (Universidade *U);
  Universidade* getUni ();
  void imprimeDep ();
  void incluirDis (Disciplina *dis);
  void imprimeDis ();
  void setID (int id);
  int getID ();
};
