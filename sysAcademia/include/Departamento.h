#pragma once
#include "lDisciplina.h"
#include "lProfessor.h"
class Universidade;

class Departamento {
private:
  char nome[150];
  Universidade *uni;
  lDisciplina *listaDisciplinas;
  lProfessor *listaProfessores;
  int ID;

public:
  Departamento ();
  Departamento (char *S, Universidade *U, int n, int np, int id);
  void inicializa (char *S = "", Universidade *U = NULL, int n = 1000, int np = 1000, int id = 0);
  ~Departamento ();
  void setNome (char *S);
  char* getNome ();
  void setID (int id);
  int getID ();
  void setUni (Universidade *U);
  Universidade* getUni ();
  void imprimeDep ();

  void addDis (Disciplina *D);
  Disciplina* getDis (char *S);
  void removeDis (char *S);
  void imprimeDis ();
  void imprimeDis2 ();

  void addProfessor (Professor *P);
  Professor* getPrf (char *S);
  void removeProfessor (char *S);
  void imprimeProfs ();
  void imprimeProfs2 ();
};
