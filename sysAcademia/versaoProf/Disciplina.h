#ifndef _DISCIPLINA_H_
#define _DISCIPLINA_H_

#include "ListaAlunos.h"
#include "Departamento.h"

class Disciplina
{ 
private:
    int id;
    char nome[150];
    char area_conhecimento[150];
     
    Departamento* pDeptoAssociado;
    
    ListaAlunos ObjLAlunos;

  public:
    Disciplina(int na = 45, char* ac = "");
    ~Disciplina();

	Disciplina* pProx;
    Disciplina* pAnte;

    void setId(int i);
	int getId();

	void setNome(char* n);
	char* getNome();
	
	void setDepartamento(Departamento* pd);
	Departamento* getDepartamento();

    void incluaAluno(Aluno* pa);
    void listeAlunos();
    void listeAlunos2();
};
#endif
