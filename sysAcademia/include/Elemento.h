#pragma once
#include "Disciplina.h"

template<class TIPO>
class Elemento {
private:
  TIPO *info;
  Elemento<TIPO> *prox, *ant;

public:
  Elemento (TIPO *p = NULL);
  ~Elemento ();
  void setInfo (TIPO *p);
  TIPO* getInfo ();
  void setProx (Elemento<TIPO> *p);
  Elemento<TIPO>* getProx ();
  void setAnt (Elemento<TIPO> *p);
  Elemento<TIPO>* getAnt ();

};

template<class TIPO>
Elemento<TIPO>::Elemento (TIPO *p) {
  info = p;
  prox = ant = NULL;
}

template<class TIPO>
Elemento<TIPO>::~Elemento () {
  info = NULL;
  prox = ant = NULL;
}

template<class TIPO>
void  Elemento<TIPO>::setInfo (TIPO *p) {
  info = p;
}

template<class TIPO>
TIPO* Elemento<TIPO>::getInfo () {
  return info;
}

template<class TIPO>
void Elemento<TIPO>::setProx (Elemento<TIPO> *p) {
  prox = p;
}

template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::getProx () {
  return prox;
}

template<class TIPO>
void Elemento<TIPO>::setAnt (Elemento<TIPO> *p) {
  ant = p;
}

template<class TIPO>
Elemento<TIPO>* Elemento<TIPO>::getAnt () {
  return ant;
}

template<>
class Elemento<Aluno> {
private:
  Aluno *info;
  Elemento<Aluno> *prox, *ant;
  float P1, P2, F;
  int faltas;

public:
  Elemento (Aluno *p = NULL) {
    info = p;
    prox = ant = NULL;
    P1 = P2 = F = 0;
    faltas = 0;
  }

  ~Elemento (){
    info = NULL;
    prox = ant = NULL;
  }

  void setInfo (Aluno *p){
    info = p;
  }

  Aluno* getInfo (){
    return info;
  }

  void setProx (Elemento<Aluno> *p){
    prox = p;
  }

  Elemento<Aluno>* getProx (){
    return prox;
  }

  void setAnt (Elemento<Aluno> *p){
    ant = p;
  }

  Elemento<Aluno>* getAnt (){
    return ant;
  }

  void setP1 (float nota){
    P1 = nota;
  }

  float getP1 (){
    return P1;
  }

  void setP2 (float nota){
    P2 = nota;
  }

  float getP2 () {
    return P2;
  }

  void setFinal (float nota){
    F = nota;
  }

  float getFinal (){
    return F;
  }

  void faltou (){
    faltas++;
  }

  int getFaltas (){
    return faltas;
  }

};

// template<>
// Elemento<Aluno>::Elemento (Aluno *p) {
//   info = p;
//   prox = ant = NULL;
//   P1 = P2 = F = 0;
//   faltas = 0;
// }
//
// template<>
// Elemento<Aluno>::~Elemento () {
//   info = NULL;
//   prox = ant = NULL;
// }
//
// template<>
// void Elemento<Aluno>::setInfo (Aluno *p) {
//   info = p;
// }
//
// template<>
// Aluno* Elemento<Aluno>::getInfo () {
//   return info;
// }
//
// template<>
// void Elemento<Aluno>::setProx (Elemento<Aluno> *p) {
//   prox = p;
// }
//
// template<>
// Elemento<Aluno>* Elemento<Aluno>::getProx () {
//   return prox;
// }
//
// template<>
// void Elemento<Aluno>::setAnt (Elemento<Aluno> *p) {
//   ant = p;
// }
//
// template<>
// Elemento<Aluno>* Elemento<Aluno>::getAnt () {
//   return ant;
// }
//
// template<>
// void Elemento<Aluno>::setP1 (float nota) {
//   P1 = nota;
// }
//
// template<>
// float Elemento<Aluno>::getP1 () {
//   return P1;
// }
//
// template<>
// void Elemento<Aluno>::setP2 (float nota) {
//   P2 = nota;
// }
//
// template<>
// float Elemento<Aluno>::getP2 () {
//   return P2;
// }
//
// template<>
// void Elemento<Aluno>::setFinal (float nota) {
//   F = nota;
// }
//
// template<>
// float Elemento<Aluno>::getFinal () {
//   return F;
// }
//
// template<>
// void Elemento<Aluno>::faltou () {
//   faltas++;
// }
//
// template<>
// int Elemento<Aluno>::getFaltas () {
//   return faltas;
// }

template<>
class Elemento<Disciplina> {
private:
  Disciplina *info;
  Elemento<Disciplina> *prox, *ant;
  Professor *prof;

public:
  Elemento (Disciplina *p = NULL){
    info = p;
    prox = ant = NULL;
    prof = NULL;
  }

  ~Elemento<Disciplina> (){
      info = NULL;
      prox = ant = NULL;
      prof = NULL;
  }

  void setInfo (Disciplina *p){
    info = p;
  }

  Disciplina* getInfo (){
    return info;
  }

  void setProx (Elemento<Disciplina> *p) {
    prox = p;
  }

  Elemento<Disciplina>* getProx () {
    return prox;
  }

  void setAnt (Elemento<Disciplina> *p){
    ant = p;
  }

  Elemento<Disciplina>* getAnt (){
    return ant;
  }

  void setProf (Professor *P){
    prof = P;
  }

  Professor* getProf (){
    return prof;
  }

};

// template<>
// Elemento<Disciplina>::Elemento (Disciplina *p) {
//   info = p;
//   prox = ant = NULL;
//   prof = NULL;
// }
//
// template<>
// Elemento<Disciplina>::~Elemento () {
//     info = NULL;
//     prox = ant = NULL;
//     prof = NULL;
// }
//
// template<>
// void  Elemento<Disciplina>::setInfo (Disciplina *p) {
//   info = p;
// }
//
// template<>
// Disciplina* Elemento<Disciplina>::getInfo () {
//   return info;
// }
//
// template<>
// void Elemento<Disciplina>::setProx (Elemento<Disciplina> *p) {
//   prox = p;
// }
//
// template<>
// Elemento<Disciplina>* Elemento<Disciplina>::getProx () {
//   return prox;
// }
//
// template<>
// void Elemento<Disciplina>::setAnt (Elemento<Disciplina> *p) {
//   ant = p;
// }
//
// template<>
// Elemento<Disciplina>* Elemento<Disciplina>::getAnt () {
//   return ant;
// }
//
// template<>
// void Elemento<Disciplina>::setProf (Professor *P) {
//   prof = P;
// }
//
// template<>
// Professor* Elemento<Disciplina>::getProf () {
//   return prof;
// }
