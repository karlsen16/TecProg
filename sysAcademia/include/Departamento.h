#pragma once

class Departamento {
private:
  char nome[30];

public:
  Departamento (char *S = "");
  ~Departamento ();
  void setNome (char *S);
  char* getNome ();
  void imprimeDep ();
};
