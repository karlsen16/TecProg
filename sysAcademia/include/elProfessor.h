#pragma once
#include "Professor.h"

class elProfessor {
private:
  Professor *prof;
  elProfessor *prox, *ant;

public:
  elProfessor (Professor *P);
  ~elProfessor ();
  Professor* getPrf ();
  void setProx (elProfessor *p);
  elProfessor* getProx ();
  void setAnt (elProfessor *p);
  elProfessor* getAnt ();
};
