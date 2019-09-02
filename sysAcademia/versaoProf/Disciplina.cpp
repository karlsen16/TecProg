#include "stdafx.h"
#include "Disciplina.h"

Disciplina::Disciplina(int na, char* ac):
ObjLAlunos(na, ac)
{
    pDeptoAssociado		= NULL;
    pProx				= NULL;
    pAnte				= NULL;

    strcpy (area_conhecimento, ac );
}

Disciplina::~Disciplina()
{
   pDeptoAssociado  = NULL;
   pProx            = NULL;
   pAnte            = NULL;
}


void  Disciplina::setId ( int i )
{
	id = i;
}

int   Disciplina::getId ( )
{
	return id;
}

void  Disciplina::setNome(char* n)
{
	strcpy(nome, n);
}

char* Disciplina::getNome()
{
	return nome;
}

void Disciplina::setDepartamento(Departamento* pd)
{
  // Cada vez que um Departamento e associado a uma Disciplina,
  // esta Disciplina passa a fazer parte da lista de disciplina
  // do Departamento, por meio do comando abaixo.
  pDeptoAssociado = pd;
  pDeptoAssociado->incluaDisciplina ( this );
}

Departamento* Disciplina::getDepartamento ( )
{
  return  pDeptoAssociado;
}


void Disciplina::incluaAluno ( Aluno* pa )
{
    ObjLAlunos.incluaAluno(pa);
}

void Disciplina::listeAlunos()
{
    ObjLAlunos.listeAlunos();
}

void Disciplina::listeAlunos2()
{
    ObjLAlunos.listeAlunos2();
}
