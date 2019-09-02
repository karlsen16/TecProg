#include "stdafx.h"
#include "ListaDepartamentos.h"

ListaDepartamentos::ListaDepartamentos(int nd, char* n)
{
	numero_dep			= nd;
	cont_dep			= 0;           

	pElDepartamentoPrim  = NULL;
	pElDepartamentoAtual = NULL;

	strcpy (nome, n ); 
}

ListaDepartamentos::~ListaDepartamentos()
{
   ElDepartamento *paux1, *paux2;
   
   paux1 = pElDepartamentoPrim;
   paux2 = paux1;

   while (paux1 != NULL)
   {
	     paux2 = paux1->pProx;
	     delete (paux1);
         paux1 = paux2;		 
   }

   pElDepartamentoPrim  = NULL;
   pElDepartamentoAtual = NULL;
}

void ListaDepartamentos::setNome (char* n)
{
	strcpy(nome, n);
}

void ListaDepartamentos::incluaDepartamento ( Departamento* pd )
{
    // Aqui � criado um ponteiro para LAluno
    ElDepartamento* paux;
    // Aqui � criado um objeto LAluno, sendo seu endere�o armazenado em aux
    paux = new ElDepartamento ( );

    // Aqui recebe uma c�pia do objeto interm.
    paux->setDepartamento ( pd );

    paux->pProx = NULL;
    paux->pAnte = NULL;

    if ( 
		 ( ( cont_dep < numero_dep ) && ( pd != NULL) ) ||
		 ( ( numero_dep == -1 )		 && ( pd != NULL) ) 
	   )
    {
    
      if ( pElDepartamentoPrim == NULL )
      {
         pElDepartamentoPrim   = paux;
         pElDepartamentoAtual  = paux;
      }
      else
      {
         pElDepartamentoAtual->pProx = paux;
         paux->pAnte            = pElDepartamentoAtual;
         pElDepartamentoAtual   = paux;
      }
      cont_dep++;

    }
    else
    {
       //printf ("Aluno n�o inclu�do. Turma j� lotada em %i alunos \n", numero_alunos );
	   cout << "Departamento n�o inclu�do. Quantia de deps j� lotada em " << numero_dep << " departamentos." << endl;
    }
}

void ListaDepartamentos::listeDepartamentos()
{
    ElDepartamento* paux;
    paux = pElDepartamentoPrim;

    while (paux != NULL)
    {
         //printf(" Aluno %s matriculado na Disciplina %s. \n", aux->getNome(), nome);
		 cout << " Departamento " << paux->getNome() << " da universidade " << nome << "." << endl;
         paux = paux->pProx;
    }
}

void ListaDepartamentos::listeDepartamentos2()
{
    ElDepartamento* paux;
    paux = pElDepartamentoAtual;

    while (paux != NULL)
    {
       //printf(" Aluno %s matriculado na Disciplina %s \n", aux->getNome(), nome);
	   cout << " Departamento " << paux->getNome() << " da Universidade" << nome << "." << endl;
       paux = paux->pAnte;
    }

}
