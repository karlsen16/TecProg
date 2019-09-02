#include "stdafx.h"
#include "ListaDisciplinas.h"

ListaDisciplinas::ListaDisciplinas(int nd, char* n)
{
	numero_disc		= nd;
	cont_disc		= 0;

	pElDisciplinaPrim  = NULL;
	pElDisciplinaAtual = NULL;

	strcpy (nome, n );
}

ListaDisciplinas::~ListaDisciplinas()
{
   ElDisciplina *paux1, *paux2;

   paux1 = pElDisciplinaPrim;
   paux2 = paux1;

   while (paux1 != NULL)
   {
	     paux2 = paux1->pProx;
	     delete (paux1);
         paux1 = paux2;
   }

   pElDisciplinaPrim  = NULL;
   pElDisciplinaAtual = NULL;
}


void ListaDisciplinas::setNome(char* n)
{
	strcpy(nome, n);
}

void ListaDisciplinas::incluaDisciplina ( Disciplina* pd )
{
    // Aqui e criado um ponteiro para LAluno
    ElDisciplina* paux;
    // Aqui e criado um objeto LAluno, sendo seu endereco armazenado em aux
    paux = new ElDisciplina ( );

    // Aqui recebe uma copia do objeto interm.
    paux->setDisciplina ( pd );

    //aux->prox = NULL;
    //aux->ante = NULL;

    if (
		  ( ( cont_disc < numero_disc ) && ( pd != NULL) ) ||
		  ( ( numero_disc == -1 )		&& ( pd != NULL) )
	   )
    {

      if ( pElDisciplinaPrim == NULL )
      {
         pElDisciplinaPrim   = paux;
         pElDisciplinaAtual  = paux;
      }
      else
      {
         pElDisciplinaAtual->pProx  = paux;
         paux->pAnte				= pElDisciplinaAtual;
         pElDisciplinaAtual          = paux;
      }
      cont_disc++;

    }
    else
    {
       //printf ("Aluno nao incluido. Turma ja lotada em %i alunos \n", numero_alunos );
	   cout << "Disciplina nao incluida. Quantia de disc. ja lotada em " << numero_disc << " disciplinas." << endl;
    }
}

void ListaDisciplinas::listeDisciplinas()
{
    ElDisciplina* paux;
    paux = pElDisciplinaPrim;

    while (paux != NULL)
    {
         //printf(" Aluno %s matriculado na Disciplina %s. \n", aux->getNome(), nome);
		 cout << " Disciplina " << paux->getNome() << " do deparatamento " << nome << "." << endl;
         paux = paux->pProx;
    }
}

void ListaDisciplinas::listeDisciplinas2()
{
    ElDisciplina* paux;
    paux = pElDisciplinaAtual;

    while (paux != NULL)
    {
       //printf(" Aluno %s matriculado na Disciplina %s \n", aux->getNome(), nome);
	   cout << " Disciplina " << paux->getNome() << " do Departamento " << nome << "." << endl;
       paux = paux->pAnte;
    }

}
