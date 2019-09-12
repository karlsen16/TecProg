#pragma once
#include "Elemento.h"

template<class TIPO>
class Lista {
private:
  string nome;
  int nEnt, contEnt;
  Elemento<TIPO> *pEntIni, *pEntAtual;

public:
  Lista (string S = "", int n = 100);
  ~Lista ();
  void setNome (string S);
  string getNome ();
  void setNum (int n);
  void addEnt (TIPO *p);
  TIPO* getEnt (string S);
  void removeEnt (string S);
  void imprimeEnts ();
  Elemento<TIPO>* getel (string S);

};

template<class TIPO>
Lista<TIPO>::Lista (string S, int n) {
  setNome(S);
  setNum(n);
  contEnt = 0;
  pEntIni = pEntAtual = NULL;
}

template<class TIPO>
Lista<TIPO>::~Lista () {
  Elemento<TIPO> *peao = pEntIni;
  while(peao) {
    pEntIni = peao->getProx();
    delete (peao);
    peao = pEntIni;
  }
  pEntAtual = NULL;
}

template<class TIPO>
void Lista<TIPO>::setNome (string S) {
  nome = S;
}

template<class TIPO>
string Lista<TIPO>::getNome () {
  return nome;
}

template<class TIPO>
void Lista<TIPO>::setNum (int n) {
  nEnt = n;
}

template<class TIPO>
void Lista<TIPO>::addEnt (TIPO *p) {
  if(contEnt < nEnt) {
    Elemento<TIPO> *novo = new Elemento<TIPO>(p);
    if(!pEntIni)
      pEntIni = pEntAtual = novo;
    else {
      Elemento<TIPO> *peao = pEntIni, *aux = NULL;
      while(peao && p->getNome().compare(peao->getInfo()->getNome()) < 0) {
        aux = peao;
        peao = peao->getProx();
      }
      novo->setProx(peao);
      novo->setAnt(aux);
      if(peao)
        peao->setAnt(novo);
      if(aux)
        aux->setProx(novo);
      if(!novo->getProx())
        pEntAtual = novo;
      if(!novo->getAnt())
        pEntIni = novo;
    }
    contEnt++;
    cout << "Cadastro de "<< p->getNome() << " realizado com sucesso!\n";
  }
  else
    cout << "Nao foi possivel fazer esta operacao. Erro (01).\n";
  usleep(2000000);
}

template<class TIPO>
TIPO* Lista<TIPO>::getEnt (string S) {
  if(contEnt > 0) {
    Elemento<TIPO> *peao = pEntIni;
    while(peao && S.compare(peao->getInfo()->getNome()) != 0) {
      peao = peao->getProx();
    }
    if(peao)
      return peao->getInfo();
    else
      cout << "\n" << S << " nao pertence a " << getNome() << ".\n";
  }
  else
    cout << "\nNao foi possivel fazer esta operacao. Erro:(02).\n";
  return NULL;
}

template<class TIPO>
void Lista<TIPO>::removeEnt (string S) {
  if(contEnt > 0) {
    Elemento<TIPO> *peao = pEntIni;
    while(peao && S.compare(peao->getInfo()->getNome()) != 0)
      peao = peao->getProx();
    if(peao) {
      peao->getAnt()->setProx(peao->getProx());
      peao->getProx()->setAnt(peao->getAnt());
      delete(peao);
      contEnt--;
      cout << "Remocao de cadastro de "<< S << " realizado com sucesso!\n";
    }
    else
      cout << "\n " << S << " nao pertence a " << getNome() << ".\n";
  }
  else
    cout << "Nao foi possivel fazer esta operacao. Erro (03).\n";
  usleep(2000000);
}

template<class TIPO>
void Lista<TIPO>::imprimeEnts () {
  if(contEnt > 0) {
    cout << "Lista de " << getNome() << ":\n";
    Elemento<TIPO> *peao = pEntIni;
    int cont = 1;
    while(peao) {
      cout << "\t" << cont << "# " << peao->getInfo()->getNome() << "\t\t-ID: "
           << peao->getInfo()->getID() << "\n";
      cont++;
      peao = peao->getProx();
    }
  }
  else
    cout << "Nao foi possivel fazer esta operacao. Erro (09).\n";
}

template<class TIPO>
Elemento<TIPO>* Lista<TIPO>::getel (string S) {
  if(contEnt > 0) {
    Elemento<TIPO> *peao = pEntIni;
    while(peao && S.compare(peao->getInfo()->getNome()) != 0)
      peao = peao->getProx();
    if(peao)
      return peao;
    else
      cout << "\n " << S << " nao pertence a "
           << getNome() << ".\n";
  }
  else
    cout << "\nNao foi possivel fazer esta operacao. Erro:(04).\n";
  return NULL;
}
