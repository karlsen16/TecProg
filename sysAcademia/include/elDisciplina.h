#pragma once
#include "Disciplina.h"

class elDisciplina {
private:
  Disciplina *dis;
  elDisciplina *prox, *ant;

public:
  elDisciplina (Disciplina *D);
  ~elDisciplina ();
  Disciplina* getDis ();
  void setProx (elDisciplina *D);
  elDisciplina* getProx ();
  void setAnt (elDisciplina *D);
  elDisciplina* getAnt ();
};
