#ifndef _LISTADISCIPLINAS_H_
#define _LISTADISCIPLINAS_H_

#include "ElDisciplina.h"
#include "Disciplina.h"

class ListaDisciplinas
{ 
private:

	int cont_disc;
	int numero_disc;
	char nome[150];

	ElDisciplina *pElDisciplinaPrim;
    ElDisciplina *pElDisciplinaAtual;

public:

	ListaDisciplinas(int nd = 1000, char* n = "");
	~ListaDisciplinas();

	void setNome(char* n);

	void incluaDisciplina(Disciplina* pd);
    void listeDisciplinas();
    void listeDisciplinas2();
};

#endif
