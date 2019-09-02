#include "stdafx.h"
#include "ElAluno.h"

ElAluno::ElAluno()
{
	pProx = NULL;
    pAnte = NULL;
}

ElAluno::~ElAluno()
{
	pProx = NULL;
    pAnte = NULL;
}

void ElAluno::setAluno(Aluno *pa) 
{  
   pAluno = pa; 
}

Aluno* ElAluno::getAluno() 
{   
   return pAluno; 
}

char* ElAluno::getNome() 
{
    return pAluno->getNome(); 
}

