#pragma once
#include "Professor.h"
#include "Aluno.h"
class Departamento;
template <class TIPO> class Lista;
template <class TIPO> class Elemento;

class Disciplina: public Entidade {
private:
  string area;
  Departamento *dep;
  Lista<Aluno> *listaAlunos;

public:
  Disciplina ();
  Disciplina (string S, string A, Departamento *D, int n, int id);
  ~Disciplina ();
  void inicializa (string S = "", string A = "", Departamento *D = NULL, int n = 45, int id = 0);
  void setArea (string A);
  string getArea ();
  void setDep (Departamento *D);
  Departamento* getDep ();
  int getN();

  void addAluno (Aluno *L);
  Aluno* getAluno (string S);
  void removeAluno (string S);
  Elemento<Aluno>* getelAluno (string S);
  void imprimeAlus ();
  Lista<Aluno>* getLista ();

};
