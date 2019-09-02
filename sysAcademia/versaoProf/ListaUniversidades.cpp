#include "stdafx.h"
#include "ListaUniversidades.h"

ListaUniversidades::ListaUniversidades(int nu, char* n)
{
	numero_univ = nu;
	cont_univ	  = 0;

	pElUniversidadePrim  = NULL;
	pElUniversidadeAtual = NULL;

	strcpy (nome, n );
}

ListaUniversidades::~ListaUniversidades()
{
   ElUniversidade *paux1, *paux2;

   paux1 = pElUniversidadePrim;
   paux2 = paux1;

   while (paux1 != NULL)
   {
	     paux2 = paux1->pProx;
	     delete (paux1);
         paux1 = paux2;
   }

   pElUniversidadePrim  = NULL;
   pElUniversidadeAtual = NULL;
}

void ListaUniversidades::incluaUniversidade ( Universidade* pu )
{
    // Aqui e criado um ponteiro para LAluno
    ElUniversidade* paux;
    // Aqui e criado um objeto LAluno, sendo seu endereco armazenado em aux
    paux = new ElUniversidade ( );

    // Aqui recebe uma copia do objeto interm.
    paux->setUniversidade ( pu );

    paux->pProx = NULL;
    paux->pAnte = NULL;

    if (
		  ( ( cont_univ < numero_univ ) && ( pu != NULL) ) ||
		  ( ( numero_univ == -1 )		&& ( pu != NULL) )
	   )
    {

      if ( pElUniversidadePrim == NULL )
      {
         pElUniversidadePrim   = paux;
         pElUniversidadeAtual  = paux;
      }
      else
      {
         pElUniversidadeAtual->pProx	= paux;
         paux->pAnte					= pElUniversidadeAtual;
         pElUniversidadeAtual			= paux;
      }
      cont_univ++;

    }
    else
    {
       //printf ("Aluno nao incluido. Turma ja lotada em %i alunos \n", numero_alunos );
	   cout << "Universidade nao incluida. Sistema ja lotado em " << numero_univ << " universidades." << endl;
    }

}

void ListaUniversidades::listeUniversidades()
{
    ElUniversidade* paux;
    paux = pElUniversidadePrim;

    while (paux != NULL)
    {
         //printf(" Aluno %s matriculado na Disciplina %s. \n", aux->getNome(), nome);
		 cout << " Universidade " << paux->getNome() << " no sistema " << nome << "." << endl;
         paux = paux->pProx;
    }
}

void ListaUniversidades::listeUniversidades2()
{
    ElUniversidade* paux;
    paux = pElUniversidadeAtual;

    while (paux != NULL)
    {
       //printf(" Aluno %s matriculado na Disciplina %s \n", aux->getNome(), nome);
	   cout << " Universidade " << paux->getNome() << " no sistema " << nome << "." << endl;
       paux = paux->pAnte;
    }

}

Universidade* ListaUniversidades::localizar(char* n)
{
	ElUniversidade* paux;
    paux = pElUniversidadePrim;
    while (paux != NULL)
    {
		if (0 == strcmp(n, paux->getNome()))
		{
			return paux->getUniversidade();
		}
        paux = paux->pProx;
    }
	return NULL;
}
