#include "stdafx.h"
#include "Dados.h"
#include "Menu.h"

Dados::Dados (Lista<Universidade> *plu, Menu *menu) {
  pLU = plu;
  pMenu = menu;
  ct = 0;
}

Dados::~Dados () {
  pLU = NULL;
  pMenu = NULL;
}

void Dados::erro () {
  cerr << "Arquivo nao pode ser aberto.\n";
  exit(1);
}

void Dados::s_E () {
  ents++;
}

void Dados::carregando () {
  ct++;
  system("clear");
  int porc = static_cast<int>(ct*20/ents);
  cout << "     " << "Carregando\n[";
  int j;
  for(j = 0; j < porc; j++) {cout << "#";}
  for(; j < 20; j++) {cout << " ";}
  cout << "]\n";
}

void Dados::Carregar () {
  bool result = cr_Info();
  cr_Uni(result);
  cr_Dep(result);
  cr_Dis(result);
  cr_Prf(result);
  cr_Mat(result);
}

bool Dados::cr_Info () {
  ifstream carregInfo ("./dat/Info.dat", ios::in);

  string S;
  int n;
  bool pv = true;
  if(!carregInfo) {
    system("clear");
    contIDUni = 0;
    contIDDep = 0;
    contIDDis = 0;
    contIDPrf = 0;
    contIDAlu = 0;
    ents = 0;
    cout << "E a primeira vez que voce inicia o sistema, informe para quantas Universidades:\n";
    cin >> n;
    cout << "\nInforme o nome do sistema:\n";
    cin >> S;
    pLU->setNum(n);
    pLU->setNome(S);
  }
  else {
    pv = false;
    int idU, idD, idI, idP, idA, e;
    carregInfo >> S >> n >> idU >> idD >> idI >> idP >> idA >> e;
    contIDUni = idU;
    contIDDep = idD;
    contIDDis = idI;
    contIDPrf = idP;
    contIDAlu = idA;
    ents = e;
    pLU->setNum(n);
    pLU->setNome(S);
    carregando();
  }
  carregInfo.close();
  return pv;
}

void Dados::cr_Uni (bool res) {
  ifstream carreg_Uni ("./dat/Universidades.dat", ios::in);

  if(!carreg_Uni) {
    if(!res)
      erro();
  }
  else {
    while(!carreg_Uni.eof()) {
      string S;
      int n, id;
      carreg_Uni >> S >> n >> id;
      if(S.compare("") != 0) {
        Universidade *uni = new Universidade(S, n, id);
        pLU->addEnt(uni);
        carregando();
      }
    }
  }
  carreg_Uni.close();
}

void Dados::cr_Dep (bool res) {
  ifstream carreg_Dep ("./dat/Departamentos.dat", ios::in);

  if(!carreg_Dep) {
    if(!res)
      erro();
  }
  else {
    while(!carreg_Dep.eof()) {
      string S, U;
      int n, np, id;
      carreg_Dep >> S >> U >> n >> np >> id;
      if(S.compare("") != 0) {
        Universidade *uni = pMenu->localizaUni(U);
        Departamento *dep = new Departamento(S, uni, n, np, id);
        carregando();
      }
    }
  }
  carreg_Dep.close();
}

void Dados::cr_Dis (bool res) {
  ifstream carreg_Dis ("./dat/Disciplinas.dat", ios::in);

  if(!carreg_Dis) {
    if(!res)
      erro();
  }
  else {
    while(!carreg_Dis.eof()) {
      string S, A, D;
      int n, id;
      carreg_Dis >> S >> A >> D >> n >> id;
      if(S.compare("") != 0) {
        Departamento *dep = localizaDep(D);
        Disciplina *dis = new Disciplina(S, A, dep, n, id);
        carregando();
      }
    }
  }
  carreg_Dis.close();
}

void Dados::cr_Prf (bool res) {
  ifstream carreg_Prf ("./dat/Professores.dat", ios::in);

  if(!carreg_Prf) {
    if(!res)
      erro();
  }
  else {
    while(!carreg_Prf.eof()) {
      string S, U, D;
      int dia, mes, ano, id;
      carreg_Prf >> dia >> mes >> ano >> S >> U >> D >> id;
      if(S.compare("") != 0) {
        Universidade *uni = pMenu->localizaUni(U);
        Departamento *dep = localizaDep(D);
        Professor *prf = new Professor(dia, mes, ano, S, uni, dep, id);
        carregando();
      }
    }
  }
  carreg_Prf.close();
}

void Dados::cr_Mat (bool res) {
  ifstream carreg_Mat ("./dat/Matriculas.dat", ios::in);

  if(!carreg_Mat) {
    if(!res)
      erro();
  }
  else {
    while(!carreg_Mat.eof()) {
      string S, A;
      carreg_Mat >> S >> A;
      if(S.compare("") != 0) {
        Disciplina *dis = localizaDis(S);
        Aluno *alu = localizaAlu(A);
        dis->addAluno(alu);
        carregando();
      }
    }
  }
  carreg_Mat.close();
}

Departamento* Dados::localizaDep (string S) {
  Elemento<Universidade> *peao = pLU->getIni();
  while(peao) {
    Universidade *u = peao->getInfo();
    Departamento *d = u->getDep(S);
    if(d)
      return d;
    peao = peao->getProx();
  }
  return NULL;
}

Disciplina* Dados::localizaDis (string S) {
  Elemento<Universidade> *peao = pLU->getIni();
  while(peao) {
    Universidade *u = peao->getInfo();
    Disciplina *d = u->getDis(S);
    if(d)
      return d;
    peao = peao->getProx();
  }
  return NULL;
}

Aluno* Dados::localizaAlu (string A) {
  ifstream carreg_Alu ("./dat/Alunos.dat", ios::in);

  if(carreg_Alu) {
    while(!carreg_Alu.eof()) {
      string S;
      int dia, mes, ano, ra, id;
      carreg_Alu >> dia >> mes >> ano >> S >> ra >> id;
      if(S.compare(A) == 0) {
        Aluno *alu = new Aluno(dia, mes, ano, S, ra, id);
        return alu;
      }
    }
  }
  carreg_Alu.close();
  return NULL;
}

void Dados::Gravar () {
  gv_Info();
  gv_Uni();
  gv_Dep();
  gv_Dis();
  gv_Prf();
  gv_Alu();
  gv_Mat();
}

void Dados::gv_Info () {
  ofstream gravaInfo ("./dat/Info.dat", ios::out);

  if(!gravaInfo)
    erro();
  else {
    gravaInfo << pLU->getNome() << ' ' << pLU->getN() << ' '
              << contIDUni  << ' ' << contIDDep  << ' '
              << contIDDis  << ' ' << contIDPrf  << ' '
              << contIDAlu  << ' ' << ents << "\n";
  }
  gravaInfo.close();
}

void Dados::gv_Uni () {
  ofstream grava_Uni ("./dat/Universidades.dat", ios::out);

  if(!grava_Uni)
    erro();
  else {
    Elemento<Universidade> *peao = pLU->getIni();
    while(peao) {
      Universidade *uni = peao->getInfo();
      grava_Uni << uni->getNome() << ' '
                << uni->getN() << ' '
                << uni->getID() << "\n";
      peao = peao->getProx();
    }
  }
  grava_Uni.close();
}

void Dados::gv_Dep () {
  ofstream grava_Dep ("./dat/Departamentos.dat", ios::out);

  if(!grava_Dep)
    erro();
  else {
    Elemento<Universidade> *peao = pLU->getIni();
    while(peao) {
      Universidade *uni = peao->getInfo();
      Elemento<Departamento> *peao2 = uni->getLista()->getIni();
      while(peao2) {
        Departamento *dep = peao2->getInfo();
        grava_Dep << dep->getNome() << ' '
                  << uni->getNome() << ' '
                  << dep->getN() << ' '
                  << dep->getNP() << ' '
                  << dep->getID() << "\n";
        peao2 = peao2->getProx();
      }
      peao = peao->getProx();
    }
  }
  grava_Dep.close();
}

void Dados::gv_Dis () {
  ofstream grava_Dis ("./dat/Disciplinas.dat", ios::out);

  if(!grava_Dis)
    erro();
  else {
    Elemento<Universidade> *peao = pLU->getIni();
    while(peao) {
      Universidade *uni = peao->getInfo();
      Elemento<Departamento> *peao2 = uni->getLista()->getIni();
      while(peao2) {
        Departamento *dep = peao2->getInfo();
        Elemento<Disciplina> *peao3 = dep->getLista()->getIni();
        while(peao3) {
          Disciplina *dis = peao3->getInfo();
          grava_Dis << dis->getNome() << ' '
                    << dis->getArea() << ' '
                    << dep->getNome() << ' '
                    << dis->getN() << ' '
                    << dis->getID() << "\n";
          peao3 = peao3->getProx();
        }
        peao2 = peao2->getProx();
      }
      peao = peao->getProx();
    }
  }
  grava_Dis.close();
}

void Dados::gv_Prf () {
  ofstream grava_Prf ("./dat/Professores.dat", ios::out);

  if(!grava_Prf)
    erro();
  else {
    Elemento<Universidade> *peao = pLU->getIni();
    while(peao) {
      Universidade *uni = peao->getInfo();
      Elemento<Departamento> *peao2 = uni->getLista()->getIni();
      while(peao2) {
        Departamento *dep = peao2->getInfo();
        Elemento<Professor> *peao3 = dep->getListaP()->getIni();
        while(peao3) {
          Professor *prf = peao3->getInfo();
          grava_Prf << prf->getDia() << ' '
                    << prf->getMes() << ' '
                    << prf->getAno() << ' '
                    << prf->getNome() << ' '
                    << uni->getNome() << ' '
                    << dep->getNome() << ' '
                    << prf->getID() << "\n";
          peao3 = peao3->getProx();
        }
        peao2 = peao2->getProx();
      }
      peao = peao->getProx();
    }
  }
  grava_Prf.close();
}

void Dados::gv_Alu () {
  ofstream grava_Alu ("./dat/Alunos.dat", ios::out);

  if(!grava_Alu)
    erro();
  else {
    Elemento<Universidade> *peao = pLU->getIni();
    while(peao) {
      Universidade *uni = peao->getInfo();
      Elemento<Departamento> *peao2 = uni->getLista()->getIni();
      while(peao2) {
        Departamento *dep = peao2->getInfo();
        Elemento<Disciplina> *peao3 = dep->getLista()->getIni();
        while(peao3) {
          Disciplina *dis = peao3->getInfo();
          Elemento<Aluno> *peao4 = dis->getLista()->getIni();
          while(peao4) {
            Aluno *alu = peao4->getInfo();
            grava_Alu << alu->getDia() << ' '
                      << alu->getMes() << ' '
                      << alu->getAno() << ' '
                      << alu->getNome() << ' '
                      << alu->getRA() << ' '
                      << dis->getID() << "\n";
            peao4 = peao4->getProx();
          }
          peao3 = peao3->getProx();
        }
        peao2 = peao2->getProx();
      }
      peao = peao->getProx();
    }
  }
  grava_Alu.close();
}

void Dados::gv_Mat () {
  ofstream grava_Mat ("./dat/Matriculas.dat", ios::out);

  if(!grava_Mat)
    erro();
  else {
    Elemento<Universidade> *peao = pLU->getIni();
    while(peao) {
      Universidade *uni = peao->getInfo();
      Elemento<Departamento> *peao2 = uni->getLista()->getIni();
      while(peao2) {
        Departamento *dep = peao2->getInfo();
        Elemento<Disciplina> *peao3 = dep->getLista()->getIni();
        while(peao3) {
          Disciplina *dis = peao3->getInfo();
          Elemento<Aluno> *peao4 = dis->getLista()->getIni();
          while(peao4) {
            Aluno *alu = peao4->getInfo();
            grava_Mat << dis->getNome() << ' '
                      << alu->getNome() << "\n";
            peao4 = peao4->getProx();
          }
          peao3 = peao3->getProx();
        }
        peao2 = peao2->getProx();
      }
      peao = peao->getProx();
    }
  }
  grava_Mat.close();
}

int Dados::IDUni (){
  contIDUni += 1;
  return contIDUni;
}

int Dados::IDDep (){
  contIDDep += 10;
  return contIDDep;
}

int Dados::IDDis (){
  contIDDis += 1000;
  return contIDDis;
}

int Dados::IDPrf (){
  contIDPrf += 1000;
  return contIDPrf;
}

int Dados::IDAlu (){
  contIDAlu += 1000;
  return contIDAlu;
}
