#pragma once
#include "Professor.h"

class elProfessor {
private:
  Professor *prof;
  elProfessor *prox, *ant;
  int ID;

public:
  elProfessor (Professor *P, int id = 0);
  ~elProfessor ();
  Professor* getProfessor ();
  void setID (int id);
  int getID ();
  void setProx (elProfessor *p);
  elProfessor* getProx ();
  void setAnt (elProfessor *p);
  elProfessor* getAnt ();
};
