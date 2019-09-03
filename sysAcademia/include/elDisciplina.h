#pragma once
#include "Disciplina.h"
class Professor;

class elDisciplina {
private:
  Disciplina *dis;
  elDisciplina *prox, *ant;
  Professor *prof;

public:
  elDisciplina (Disciplina *D);
  ~elDisciplina ();
  Disciplina* getDis ();
  void setProx (elDisciplina *D);
  elDisciplina* getProx ();
  void setAnt (elDisciplina *D);
  elDisciplina* getAnt ();
  void setProf (Professor *P);
  Professor* getProf ();
};
