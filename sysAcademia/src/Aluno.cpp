#include "stdafx.h"
#include "Aluno.h"
#include "Disciplina.h"

Aluno::Aluno (): Pessoa() {
  setRA(0);
}

Aluno::Aluno (int diaN, int mesN, int anoN, char *S, int i):
  Pessoa(diaN, mesN, anoN, S) {
  setRA(i);
}

Aluno::~Aluno () {
}

void Aluno::setRA (int i) {
  RA = i;
}

int Aluno::getRA () {
  return RA;
}

void Aluno::matricula (Disciplina *I1, Disciplina *I2, Disciplina *I3,
Disciplina *I4) {
  if(I1)
    I1->addAluno(this);
  if(I2)
    I2->addAluno(this);
  if(I3)
    I3->addAluno(this);
  if(I4)
    I4->addAluno(this);
}

void Aluno::rmMatricula (Disciplina *I1, Disciplina *I2, Disciplina *I3,
Disciplina *I4) {
  if(I1)
    I1->removeAluno(this);
  if(I2)
    I2->removeAluno(this);
  if(I3)
    I3->removeAluno(this);
  if(I4)
    I4->removeAluno(this);
}
