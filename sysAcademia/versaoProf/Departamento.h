
#ifndef _DEPARTAMENTO_H_
#define _DEPARTAMENTO_H_

//#include "ListaDisciplinas.H"
//#include "Universidade.h"

class Universidade;
class Disciplina;
class ListaDisciplinas;

class Departamento
{
  private:
     char nome[130];

	 int id;

     // Associacao para com uma Universidade.
     Universidade* pUniv;
     // Associacao para com varias Disciplinas.
     ListaDisciplinas* pObjLDisciplinas;

  public:
     Departamento();
	 Departamento(int i);
     ~Departamento();

     void setNome(char* n);
     char* getNome();

     void setUniversidade(Universidade* pu);
     Universidade* getUniversidade();

     void incluaDisciplina ( Disciplina* pd );
     void listeDisciplinas();
     void listeDisciplinas2();
};

#endif
