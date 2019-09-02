#ifndef _LISTAUNIVERSIDADES_H_
#define _LISTAUNIVERSIDADES_H_

#include "ElUniversidade.h"
#include "Universidade.h"

class ListaUniversidades
{ 
private:
	int  cont_univ;
	int  numero_univ;
	char nome[150];

	ElUniversidade *pElUniversidadePrim;
    ElUniversidade *pElUniversidadeAtual;
public:

	ListaUniversidades(int nu = 1000, char* n = "");
	~ListaUniversidades();
	void incluaUniversidade(Universidade* pu);
    void listeUniversidades();
    void listeUniversidades2();

	Universidade* localizar(char* n);	
};

#endif
