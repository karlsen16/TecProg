#include "stdafx.h"
#include "Professor.h"

Professor::Professor(int diaNa, int mesNa, int anoNa, char* nome):
Pessoa(diaNa, mesNa, anoNa, nome)
{
}

Professor::Professor()
:Pessoa()
{
}

Professor::~Professor()
{
}

void Professor::setUnivFiliado(Universidade* u)
{
     UnivFiliado = u;
}

void Professor::setDepartamento(Departamento* dep)
{
    DptoFiliado = dep;
}

void Professor::OndeTrabalho()
{
     //printf("\n %s trabalha para a %s \n", nomeP, UnivFiliado->getNome());
	 cout << endl << nomeP << " trabalha para a " << UnivFiliado->getNome() << "." << endl;
}

void Professor::QualDepartamentoTrabalho()
{
     /*printf("\n %s trabalha para a %s no departamento de % s \n",
                nomeP,
                UnivFiliado->getNome(),
                DptoFiliado->getNome()
            );  */

	 cout << endl << " "
		  << nomeP
		  << " trabalha para a " 
		  << UnivFiliado->getNome()
		  << " no departamento de "
		  <<  DptoFiliado->getNome()
		  << "." << endl;
}
