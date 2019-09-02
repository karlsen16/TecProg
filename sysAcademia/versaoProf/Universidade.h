
#ifndef _UNIVERSIDADE_H_
#define _UNIVERSIDADE_H_

#include "ListaDepartamentos.h"

class Universidade
{
  private:
      char nome[130];
      ListaDepartamentos ObjLDepartamentos;

  public:
      Universidade();
      ~Universidade();

      void setNome(char* n);
      char* getNome();

	  void incluaDepartamento(Departamento* pd);
      void listeDepartamentos();
      void listeDepartamentos2();

};

#endif
