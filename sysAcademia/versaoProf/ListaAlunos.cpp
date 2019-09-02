#include "stdafx.h"
#include "ListaAlunos.h"

ListaAlunos::ListaAlunos(int na, char* n)
{
	numero_alunos = na;
	cont_alunos	  = 0;

	pElAlunoPrim  = NULL;
	pElAlunoAtual = NULL;

	strcpy (nome, n );
}

ListaAlunos::~ListaAlunos()
{
   limpaLista();
}

void ListaAlunos::incluaAluno ( Aluno* pa )
{
    // Aqui e criado um ponteiro para LAluno
    ElAluno* paux;
    // Aqui e criado um objeto LAluno, sendo seu endereco armazenado em aux
    paux = new ElAluno ( );

    // Aqui recebe uma copia do objeto interm.
    paux->setAluno ( pa );

    //paux->pProx = NULL;
    //paux->pAnte = NULL;

    if ( ( cont_alunos < numero_alunos ) && ( pa != NULL) )
    {

      if ( pElAlunoPrim == NULL )
      {
         pElAlunoPrim   = paux;
         pElAlunoAtual  = paux;
      }
      else
      {
         pElAlunoAtual->pProx = paux;
         paux->pAnte            = pElAlunoAtual;
         pElAlunoAtual          = paux;
      }
      cont_alunos++;

    }
    else
    {
       //printf ("Aluno nao incluido. Turma ja lotada em %i alunos \n", numero_alunos );
	   cout << "Aluno nao incluido. Turma ja lotada em " << numero_alunos << " alunos." << endl;
    }

}

void ListaAlunos::listeAlunos()
{
    ElAluno* paux;
    paux = pElAlunoPrim;

    while (paux != NULL)
    {
         //printf(" Aluno %s matriculado na Disciplina %s. \n", aux->getNome(), nome);
		 cout << " Aluno " << paux->getNome() << " matriculado na Disciplina " << nome << "." << endl;
         paux = paux->pProx;
    }
}

void ListaAlunos::listeAlunos2()
{
    ElAluno* paux;
    paux = pElAlunoAtual;

    while (paux != NULL)
    {
       //printf(" Aluno %s matriculado na Disciplina %s \n", aux->getNome(), nome);
	   cout << " Aluno " << paux->getNome() << " matriculado na Disciplina " << nome << "." << endl;
       paux = paux->pAnte;
    }

}

void ListaAlunos::graveAlunos()
{
	ofstream GravacaoAlunos ("alunos.dat", ios::out);

	if (!GravacaoAlunos)
	{
		cerr << "Arquivo nao pode ser aberto" << endl;
		fflush(stdin);
		getchar();
	}

    ElAluno* pauxElAluno;
	pauxElAluno = pElAlunoPrim;

    while (pauxElAluno != NULL)
    {
		 Aluno * pauxAluno;

		 pauxAluno = pauxElAluno->getAluno();

		 GravacaoAlunos << pauxAluno->getId() << ' '
						<< pauxAluno->getRA() << ' '
						<< pauxAluno->getNome()
						<< endl;
         pauxElAluno = pauxElAluno->pProx;
    }

	GravacaoAlunos.close();
}

void ListaAlunos::recupereAlunos()
{
	ifstream RecuperacaoAlunos ("alunos.dat", ios::in);

	if (!RecuperacaoAlunos)
	{
		cerr << "Arquivo nao pode ser aberto" << endl;
		fflush(stdin);
		getchar();
	}

	limpaLista();

	while (!RecuperacaoAlunos.eof())
    {
		Aluno * pauxAluno;

		pauxAluno = new Aluno(-1);

		int				id;
	   	int				RA;
        char			nome[150] ;

		RecuperacaoAlunos	>> id >> RA >> nome;

		if (0 != strcmp(nome, ""))
		{
			pauxAluno->setId(id);
			pauxAluno->setRA(RA);
			pauxAluno->setNome(nome);

			incluaAluno (pauxAluno);
		}
    }

	RecuperacaoAlunos.close();
}

void ListaAlunos::limpaLista()
{
   ElAluno *paux1, *paux2;

   paux1 = pElAlunoPrim;
   paux2 = paux1;

   while (paux1 != NULL)
   {
		paux2 = paux1->pProx;
	    delete (paux1);
        paux1 = paux2;
   }

   pElAlunoPrim  = NULL;
   pElAlunoAtual = NULL;
}
