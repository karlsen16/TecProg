
#ifndef _PROFESSOR_H_
#define _PROFESSOR_H_

#include "Pessoa.h"
#include "Universidade.h"

class Professor : public Pessoa
{
private:
   Universidade* UnivFiliado;
   Departamento* DptoFiliado;
   
public:
    Professor(	int diaNa, int mesNa, int anoNa, char* nome = "");
    Professor();
    ~Professor();

    void setUnivFiliado(Universidade* u);
    void setDepartamento(Departamento* dep);
    void OndeTrabalho();
    void QualDepartamentoTrabalho();
};

#endif