#include "stdafx.h"
#include "Universidade.h"

Universidade::Universidade():
ObjLDepartamentos(-1, "")
{

}

Universidade::~Universidade()
{
}

char* Universidade::getNome()
{
   return nome;
}

void Universidade::setNome(char* n)
{
   strcpy(nome, n);
   ObjLDepartamentos.setNome(n);
}

void Universidade::incluaDepartamento (Departamento* pd)
{
    ObjLDepartamentos.incluaDepartamento(pd);
}

void Universidade::listeDepartamentos()
{
    ObjLDepartamentos.listeDepartamentos();
}

void Universidade::listeDepartamentos2()
{
    ObjLDepartamentos.listeDepartamentos2();
}
