#ifndef _LISTADEPARTAMENTOS_H_
#define _LISTADEPARTAMENTOS_H_

#include "ElDepartamento.h"
#include "Departamento.h"

class ListaDepartamentos
{ 
private:
	int cont_dep;
	int numero_dep;
	char nome[150];

	ElDepartamento *pElDepartamentoPrim;
    ElDepartamento *pElDepartamentoAtual;
public:

	ListaDepartamentos(int nd = 1000, char* n = "");
	~ListaDepartamentos();
	void setNome (char* n);
	void incluaDepartamento(Departamento* pd);
    void listeDepartamentos();
    void listeDepartamentos2();
};

#endif
