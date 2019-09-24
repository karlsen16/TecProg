#pragma once
#include "Lista.h"
class Universidade;

class Departamento: public Entidade {
private:
  Universidade *uni;
  Lista<Disciplina> *listaDisciplinas;
  Lista<Professor> *listaProfessores;
  Lista<Aluno> *listaAlunos;

public:
  Departamento ();
  Departamento (string S, Universidade *U, int n, int np, int na, int id);
  void inicializa (string S = "", Universidade *U = NULL, int n = 1000, int np = 1000, int na = 10000, int id = 0);
  ~Departamento ();
  void setUni (Universidade *U);
  Universidade* getUni ();
  int getN();
  int getNP();
  int getNA();

  void addDis (Disciplina *D);
  Disciplina* getDis (string S);
  void removeDis (string S);
  Elemento<Disciplina>* getelDis (string S);
  void imprimeDiss ();
  Lista<Disciplina>* getLista ();

  void addPrf (Professor *P);
  Professor* getPrf (string S);
  void removePrf (string S);
  void imprimePrfs ();
  Lista<Professor>* getListaP ();

  void addAlu (Aluno *A);
  Aluno* getAlu (string S);
  void removeAlu (string S);
  void imprimeAlus ();
  Lista<Aluno>* getListaA ();

};
