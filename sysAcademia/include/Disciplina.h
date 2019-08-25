#pragma once
class Departamento;
class Universidade;

class Disciplina {
private:
  char nome[150];
  char area[150];
  Departamento *dep;
  Disciplina *prox;
  int ID;

public:
  Disciplina ();
  Disciplina (char *S, char *A, Departamento *D, int id);
  ~Disciplina ();
  void inicializa (char *S = "", char *A = "", Departamento *D = NULL, int id = 0);
  void setNome (char *S);
  char* getNome ();
  void setArea (char *A);
  char* getArea ();
  void setDep (Departamento *D);
  Departamento* getDep ();
  void setProx (Disciplina *I);
  Disciplina* getProx ();
  void imprimeDis ();
  void setID (int id);
  int getID ();
};