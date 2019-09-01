#pragma once
#include "Disciplina.h"
class Professor;

class elDisciplina {
private:
  Disciplina *dis;
  elDisciplina *prox, *ant;
  Professor *prof;
  int ID;

public:
  elDisciplina (Disciplina *D, int id = 0);
  ~elDisciplina ();
  Disciplina* getDis ();
  void setID (int id);
  int getID ();
  void setProx (elDisciplina *D);
  elDisciplina* getProx ();
  void setAnt (elDisciplina *D);
  elDisciplina* getAnt ();
  void setProf (Professor *P);
  Professor* getProf ();
};
