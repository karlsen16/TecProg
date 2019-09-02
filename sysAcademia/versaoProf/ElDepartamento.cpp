#include "stdafx.h"
#include "ElDepartamento.h"

ElDepartamento::ElDepartamento()
{
	pProx = NULL;
    pAnte = NULL;
}

ElDepartamento::~ElDepartamento()
{
	pProx = NULL;
    pAnte = NULL;
}

void ElDepartamento::setDepartamento(Departamento *pd) 
{  
   pDepartamento = pd; 
}

Departamento* ElDepartamento::getDepartamento() 
{   
   return pDepartamento; 
}

char* ElDepartamento::getNome() 
{
    return pDepartamento->getNome(); 
}

