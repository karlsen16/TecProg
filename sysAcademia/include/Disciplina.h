#pragma once
class Departamento;
class Universidade;
class Aluno;

class Disciplina {
private:
  char nome[150];
  char area[150];
  Departamento *dep;
  Disciplina *prox, *ant;
  int ID, nAlunos, contAlunos;
  Aluno *pAluIni, *pAluAtual;

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
  void setAnt (Disciplina *I);
  Disciplina* getAnt ();
  void imprimeDis ();
  void setID (int id);
  int getID ();
  void addAluno (Aluno *L);
  void removeAluno (Aluno *L);
  void imprimeAlu ();
  void imprimeAlu2 ();
};
