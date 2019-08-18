#pragma once

class Universidade;

class Departamento {
private:
  char nome[50];
  Universidade *uni;

public:
  Departamento (char *S = "", Universidade *U = NULL);
  ~Departamento ();
  void setNome (char *S);
  char* getNome ();
  void setUni (Universidade *U);
  Universidade* getUni ();
  void imprimeDep ();
};
