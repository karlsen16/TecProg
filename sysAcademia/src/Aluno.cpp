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
Disciplina *I4, Disciplina *I5, Disciplina *I6, Disciplina *I7,
Disciplina *I8, Disciplina *I9, Disciplina *I10) {
  if(I1)
    I1->addAluno(this);
  if(I2)
    I2->addAluno(this);
  if(I3)
    I3->addAluno(this);
  if(I4)
    I4->addAluno(this);
  if(I5)
    I5->addAluno(this);
  if(I6)
    I6->addAluno(this);
  if(I7)
    I7->addAluno(this);
  if(I8)
    I8->addAluno(this);
  if(I9)
    I9->addAluno(this);
  if(I10)
    I10->addAluno(this);
}
