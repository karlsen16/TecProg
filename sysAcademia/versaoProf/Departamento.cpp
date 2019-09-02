#include "stdafx.h"
#include "Departamento.h"
#include "ListaDisciplinas.h"
#include "Universidade.h"

#include "Disciplina.h"

Departamento::Departamento(int i)
{
	id = i;
	pObjLDisciplinas = new ListaDisciplinas(-1, "");
}

Departamento::Departamento()
{
	pObjLDisciplinas = new ListaDisciplinas(-1, "");
}

Departamento::~Departamento()
{
	if (pObjLDisciplinas)
	{
		delete pObjLDisciplinas;
	}
}

void Departamento::setNome(char* n)
{
    strcpy(nome, n);
	pObjLDisciplinas->setNome(n);
}

char* Departamento::getNome()
{
    return nome;
}


void Departamento::setUniversidade ( Universidade* pu )
{
   pUniv = pu;
}

Universidade* Departamento::getUniversidade ( )
{
   return pUniv;
}

void Departamento::incluaDisciplina ( Disciplina* pd )
{  
	pObjLDisciplinas->incluaDisciplina (pd);
}

void Departamento::listeDisciplinas ( )
{
    pObjLDisciplinas->listeDisciplinas();
}

void Departamento::listeDisciplinas2 ( )
{
     pObjLDisciplinas->listeDisciplinas2();
}

