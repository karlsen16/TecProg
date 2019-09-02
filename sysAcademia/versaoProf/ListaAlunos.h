#ifndef _LISTAALUNOS_H_
#define _LISTAALUNOS_H_

#include "ElAluno.h"
#include "Aluno.h"

class ListaAlunos
{ 
private:
	int cont_alunos;
	int numero_alunos;
	char nome[150];

	ElAluno *pElAlunoPrim;
    ElAluno *pElAlunoAtual;
public:

	//ListaAlunos(int na, char* n);
	ListaAlunos(int na = 45, char* n = "");
	~ListaAlunos();
	void incluaAluno(Aluno* pa);
    void listeAlunos();
    void listeAlunos2();

	void graveAlunos();
	void recupereAlunos();

	void limpaLista();
};

#endif
