#ifndef _ELDISCIPLINA_H_
#define _ELDISCIPLINA_H_

#include "Disciplina.h"

class ElDisciplina
{
 private:
    Disciplina* pDisciplina;

 public:
    ElDisciplina( );
    ~ElDisciplina( );
    ElDisciplina *pProx;
    ElDisciplina *pAnte;
    void setDisciplina (Disciplina* pd);
    Disciplina* getDisciplina ( );

    char* getNome();
};

#endif