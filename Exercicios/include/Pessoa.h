#ifndef ___PESSOA_H__
#define ___PESSOA_H__

class Pessoa {
private:
  char nome[30];
  int dia;
  int mes;
  int ano;
  int idade;

public:
  Pessoa ();
  Pessoa (int diaN, int mesN, int anoN, char *S = "");
  void inicializa (int diaN, int mesN, int anoN, char *S = "");
  void calculaIdade (int diaParam, int mesParam, int anoParam);
  int getIdade ();
  char* getNome ();
  void imprimeIdade ();
};

#endif /* ___PESSOA_H__ */
