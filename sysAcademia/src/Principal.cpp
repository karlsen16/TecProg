#include "stdafx.h"
#include "Principal.h"
#define TE 6

Principal::Principal ():
contIDUni(0), contIDDep(0), contIDDis(0),
contIDPrf(0), contIDAlu(0), ents(0), ct(0),
fim(false) {
  Carregar();
  Inicial();
}

Principal::~Principal () {
}

void Principal::Inicial () {
  int op = -1;
  while(op != 4) {
    system("clear");
    cout << "\n\n    ....................\n";
    cout << "<--{ Informe sua opcao: }-->\n";
    cout << "<--{--------------------}-->\n";
    cout << "<--{  1 : Cadastrar     }-->\n";
    cout << "<--{  2 : Executar      }-->\n";
    cout << "<--{  3 : Gravar        }-->\n";
    cout << "<--{  4 : Sair          }-->\n";
    cout << "    ''''´´´´´´``````''''\n\n";
    cin >> op;

    switch(op) {
      case 1: Cad(); break;
      case 2: Exe(); break;
      case 3: Gravar(); break;
      case 4: sair(); break;
      default: invalido(true); break;
    }
    if(fim)
      break;
  }
}

void Principal::transicao (string S, bool d) {
  system("clear");
  int i = 0, cont = 0;
  while(i < TE) {
    cout << "     " << S;
    int j;
    for(j = 0; j < cont;j++) {cout << ".";}
    cout << "\n";
    cont = (cont+1)%6;
    usleep(50000);
    system("clear");
    i++;
  }
  if(!d) {
    S = (S.substr(0, S.length()-3)+"do");
    system("clear");
    cout << "     " << S << "!\n";
    usleep(1000000);
  }
}

void Principal::esperar () {
  char c = 'n';
  cout << "\n\n Informe quando quiser voltar digitando 'y'.\n";
  do {cin >> c;} while(c != 'y');
}

void Principal::invalido (bool d) {
  if(d)
    cout << "Opcao invalida.\n";
  else
    cout << "Opcoes invalidas.\n";
  usleep(1000000);
}

void Principal::voltar () {
  transicao("Voltando", true);
}

void Principal::sair () {
  Gravar();
  transicao("Finalizando", false);
  fim = true;
}

void Principal::Cad () {
  int op = -1;
  while(op != 7 && op != 6) {
    system("clear");
    cout << "\n\n    ....................\n";
    cout << "<--{ Informe sua opcao: }-->\n";
    cout << "<--{ Cadastrar..        }-->\n";
    cout << "<--{  1 : Universidade  }-->\n";
    cout << "<--{  2 : Departamento  }-->\n";
    cout << "<--{  3 : Disciplina    }-->\n";
    cout << "<--{  4 : Professor     }-->\n";
    cout << "<--{  5 : Aluno         }-->\n";
    cout << "<--{  6 : Voltar        }-->\n";
    cout << "<--{  7 : Sair          }-->\n";
    cout << "    ''''´´´´´´``````''''\n\n";
    cin >> op;

    switch(op) {
      case 1: CadUniversidade(); break;
      case 2: CadDepartamento(); break;
      case 3: CadDisciplina(); break;
      case 4: CadProfessor(); break;
      case 5: CadAluno(); break;
      case 6: voltar(); break;
      case 7: sair(); break;
      default: invalido(true); break;
    }
  }
}

void Principal::CadUniversidade () {
  string S;
  int n;
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  cout << "Quantos Departamentos ela tem?\n";
  cin >> n;
  Universidade *uni = new Universidade(S, n, IDUni());
  pLU.addEnt(uni);
}

void Principal::CadDepartamento () {
  string S;
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  Universidade *uni = localizaUni(S);
  if(uni) {
    string D;
    int n, np;
    cout << "Qual o nome do Departamento?\n";
    cin >> D;
    cout << "Quantas Disciplinas ele tem?\n";
    cin >> n;
    cout << "Quantos Professores ele tem?\n";
    cin >> np;
    Departamento *dep = new Departamento(D, uni, n, np, uni->getID()+IDDep());
    return;
  }
  else
    cout << "A Universidade " << S << " nao esta cadastrada.\n";
  cout << "Nao foi possivel fazer esta operacao. Erro (99).\n";
  esperar();
}

void Principal::CadDisciplina () {
  string S;
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  Universidade *uni = localizaUni(S);
  if(uni) {
    string D;
    cout << "Qual o nome do Departamento?\n";
    cin >> D;
    Departamento *dep = localizaDep(S, D);
    if(dep) {
      string I, A;
      int n;
      cout << "Qual o nome da Disciplina?\n";
      cin >> I;
      cout << "Qual o nome da Area?\n";
      cin >> A;
      cout << "Quantos Alunos ela tem?\n";
      cin >> n;
      Disciplina *dis = new Disciplina(I, A, dep, n, uni->getID()+dep->getID()+IDDis());
      return;
    }
    else
      cout << "O Departamento " << D << " nao esta cadastrado.\n";
  }
  else
    cout << "A Universidade " << S << " nao esta cadastrada.\n";
  cout << "Nao foi possivel fazer esta operacao. Erro (99).\n";
  esperar();
}

void Principal::CadProfessor () {
  string S;
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  Universidade *uni = localizaUni(S);
  if(uni) {
    string D;
    cout << "Qual o nome do Departamento?\n";
    cin >> D;
    Departamento *dep = localizaDep(S, D);
    if(dep) {
      string P;
      int dia, mes, ano;
      cout << "Qual o nome do Professor?\n";
      cin >> P;
      cout << "Qual a data de nascimento?\n";
      cin >> dia >> mes >> ano;
      Professor *prf = new Professor(dia, mes, ano, P, uni, dep, uni->getID()+dep->getID()+IDPrf());
      return;
    }
    else
      cout << "O Departamento " << D << " nao esta cadastrado.\n";
  }
  else
    cout << "A Universidade " << S << " nao esta cadastrada.\n";
  cout << "Nao foi possivel fazer esta operacao. Erro (99).\n";
  esperar();
}

void Principal::CadAluno () {
  string S;
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  Universidade *uni = localizaUni(S);
  if(uni) {
    string D;
    cout << "Qual o nome do Departamento?\n";
    cin >> D;
    Departamento *dep = localizaDep(S, D);
    if(dep) {
      string I;
      cout << "Qual o nome da Disciplina?\n";
      cin >> I;
      Disciplina *dis = localizaDis(S, D, I);
      if(dis) {
        string A;
        int dia, mes, ano, ra;
        cout << "Qual o nome do Aluno?\n";
        cin >> A;
        cout << "Qual a data de nascimento?\n";
        cin >> dia >> mes >> ano;
        cout << "Qual o RA?\n";
        cin >> ra;
        Aluno *alu = new Aluno(dia, mes, ano, A, ra, uni->getID()+dep->getID()+IDAlu());
        dis->addAluno(alu);
        return;
      }
      else
        cout << "A Disciplina " << I << " nao esta cadastrada.\n";
    }
    else
      cout << "O Departamento " << D << " nao esta cadastrado.\n";
  }
  else
    cout << "A Universidade " << S << " nao esta cadastrada.\n";
  cout << "Nao foi possivel fazer esta operacao. Erro (99).\n";
  esperar();
}

void Principal::Exe () {
  int op = -1;
  while(op != 6 && op != 7) {
    system("clear");
    cout << "\n\n    ....................\n";
    cout << "<--{ Informe sua opcao: }-->\n";
    cout << "<--{ Listar..           }-->\n";
    cout << "<--{  1 : Universidades }-->\n";
    cout << "<--{  2 : Departamentos }-->\n";
    cout << "<--{  3 : Disciplinas   }-->\n";
    cout << "<--{  4 : Professores   }-->\n";
    cout << "<--{  5 : Alunos        }-->\n";
    cout << "<--{  6 : Voltar        }-->\n";
    cout << "<--{  7 : Sair          }-->\n";
    cout << "    ''''´´´´´´``````''''\n\n";
    cin >> op;

    switch(op) {
      case 1: {
        system("clear");
        ExeUniversidade();
        esperar();
        voltar();
        break;
      }
      case 2: {
        system("clear");
        ExeDepartamento();
        esperar();
        voltar();
        break;
      }
      case 3: {
        system("clear");
        ExeDisciplina();
        esperar();
        voltar();
        break;
      }
      case 4: {
        system("clear");
        ExeProfessor();
        esperar();
        voltar();
        break;
      }
      case 5: {
        system("clear");
        ExeAluno();
        esperar();
        voltar();
        break;
      }
      case 6: voltar(); break;
      case 7: sair(); break;
      default: invalido(true); break;
    }
  }
}

void Principal::ExeUniversidade () {
  pLU.imprimeEnts();
}

void Principal::ExeDepartamento () {
  string S;
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  Universidade *uni = localizaUni(S);
  if(uni) {
    uni->imprimeDeps();
    return;
  }
  else
    cout << "A Universidade " << S << " nao esta cadastrada.\n";
  cout << "Nao foi possivel fazer esta operacao. Erro (98).\n";
}

void Principal::ExeDisciplina () {
  string S;
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  Universidade *uni = localizaUni(S);
  if(uni) {
    string D;
    cout << "Qual o nome do Departamento?\n";
    cin >> D;
    Departamento *dep = localizaDep(S, D);
    if(dep) {
      dep->imprimeDiss();
      return;
    }
    else
      cout << "O Departamento " << D << " nao esta cadastrado.\n";
  }
  else
    cout << "A Universidade " << S << " nao esta cadastrada.\n";
  cout << "Nao foi possivel fazer esta operacao. Erro (98).\n";
}

void Principal::ExeProfessor () {
  string S;
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  Universidade *uni = localizaUni(S);
  if(uni) {
    string D;
    cout << "Qual o nome do Departamento?\n";
    cin >> D;
    Departamento *dep = localizaDep(S, D);
    if(dep) {
      dep->imprimePrfs();
      return;
    }
    else
      cout << "O Departamento " << D << " nao esta cadastrado.\n";
  }
  else
    cout << "A Universidade " << S << " nao esta cadastrada.\n";
  cout << "Nao foi possivel fazer esta operacao. Erro (98).\n";
}

void Principal::ExeAluno () {
  string S;
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  Universidade *uni = localizaUni(S);
  if(uni) {
    string D;
    cout << "Qual o nome do Departamento?\n";
    cin >> D;
    Departamento *dep = localizaDep(S, D);
    if(dep) {
      string I;
      cout << "Qual o nome da Disciplina?\n";
      cin >> I;
      Disciplina *dis = localizaDis(S, D, I);
      if(dis) {
        dis->imprimeAlus();
        return;
      }
      else
        cout << "A Disciplina " << I << " nao esta cadastrada.\n";
    }
    else
      cout << "O Departamento " << D << " nao esta cadastrado.\n";
  }
  else
    cout << "A Universidade " << S << " nao esta cadastrada.\n";
  cout << "Nao foi possivel fazer esta operacao. Erro (98).\n";
}

void Principal::Gravar () {
  gv_Info();
  gv_Uni();
  gv_Dep();
  gv_Dis();
  gv_Prf();
  gv_Alu();
  gv_Mat();
  transicao("Gravando", false);
}

void Principal::gv_Info () {
  ofstream gravaInfo ("./dat/Info2.dat", ios::out);

  if(!gravaInfo)
    erro();

  gravaInfo << pLU.getNome() << ' ' << pLU.getN() << ' '
            << contIDUni  << ' ' << contIDDep  << ' '
            << contIDDis  << ' ' << contIDPrf  << ' '
            << contIDAlu  << ' ' << ents << "\n";

  gravaInfo.close();
}

void Principal::gv_Uni () {
  ofstream grava_Uni ("./dat/Universidades2.dat", ios::out);

  if(!grava_Uni)
    erro();

  Elemento<Universidade> *peao = pLU.getIni();
  while(peao) {
    Universidade *uni = peao->getInfo();
    grava_Uni << uni->getID() << ' '
              << uni->getNome() << ' '
              << uni->getN() << "\n";
    peao = peao->getProx();
  }

  grava_Uni.close();
}

void Principal::gv_Dep () {
  ofstream grava_Dep ("./dat/Departamentos2.dat", ios::out);

  if(!grava_Dep)
    erro();

  Elemento<Universidade> *peao = pLU.getIni();
  while(peao) {
    Universidade *uni = peao->getInfo();
    Elemento<Departamento> *peao2 = uni->getLista()->getIni();
    while(peao2) {
      Departamento *dep = peao2->getInfo();
      grava_Dep << dep->getID() << ' '
                << dep->getNome() << ' '
                << uni->getID() << ' '
                << dep->getN() << ' '
                << dep->getNP() << ' '
                << dep->getNA() << "\n";
      peao2 = peao2->getProx();
    }
    peao = peao->getProx();
  }

  grava_Dep.close();
}

void Principal::gv_Dis () {
  ofstream grava_Dis ("./dat/Disciplinas2.dat", ios::out);

  if(!grava_Dis)
    erro();

  Elemento<Universidade> *peao = pLU.getIni();
  while(peao) {
    Universidade *uni = peao->getInfo();
    Elemento<Departamento> *peao2 = uni->getLista()->getIni();
    while(peao2) {
      Departamento *dep = peao2->getInfo();
      Elemento<Disciplina> *peao3 = dep->getLista()->getIni();
      while(peao3) {
        Disciplina *dis = peao3->getInfo();
        grava_Dis << dis->getID() << ' '
                  << dis->getNome() << ' '
                  << dis->getArea() << ' '
                  << dep->getID() << ' '
                  << dis->getN() << "\n";
        peao3 = peao3->getProx();
      }
      peao2 = peao2->getProx();
    }
    peao = peao->getProx();
  }

  grava_Dis.close();
}

void Principal::gv_Prf () {
  ofstream grava_Prf ("./dat/Professores2.dat", ios::out);

  if(!grava_Prf)
    erro();

  Elemento<Universidade> *peao = pLU.getIni();
  while(peao) {
    Universidade *uni = peao->getInfo();
    Elemento<Departamento> *peao2 = uni->getLista()->getIni();
    while(peao2) {
      Departamento *dep = peao2->getInfo();
      Elemento<Professor> *peao3 = dep->getListaP()->getIni();
      while(peao3) {
        Professor *prf = peao3->getInfo();
        grava_Prf << prf->getID() << ' '
                  << prf->getDia() << ' '
                  << prf->getMes() << ' '
                  << prf->getAno() << ' '
                  << prf->getNome() << ' '
                  << uni->getID() << ' '
                  << dep->getID() << "\n";
        peao3 = peao3->getProx();
      }
      peao2 = peao2->getProx();
    }
    peao = peao->getProx();
  }

  grava_Prf.close();
}

void Principal::gv_Alu () {
  ofstream grava_Alu ("./dat/Alunos2.dat", ios::out);

  if(!grava_Alu)
    erro();

  Elemento<Universidade> *peao = pLU.getIni();
  while(peao) {
    Universidade *uni = peao->getInfo();
    Elemento<Departamento> *peao2 = uni->getLista()->getIni();
    while(peao2) {
      Departamento *dep = peao2->getInfo();
      Elemento<Aluno> *peao3 = dep->getListaA()->getIni();
      while(peao3) {
        Aluno *alu = peao3->getInfo();
        grava_Alu << alu->getID() << ' '
                  << alu->getDia() << ' '
                  << alu->getMes() << ' '
                  << alu->getAno() << ' '
                  << alu->getNome() << ' '
                  << alu->getRA() << ' '
                  << dep->getID() << "\n";
        peao3 = peao3->getProx();
      }
      peao2 = peao2->getProx();
    }
    peao = peao->getProx();
  }

  grava_Alu.close();
}

void Principal::gv_Mat () {
  ofstream grava_Mat ("./dat/Matriculas2.dat", ios::out);

  if(!grava_Mat)
    erro();

  Elemento<Universidade> *peao = pLU.getIni();
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
          grava_Mat << dis->getID() << ' '
                    << alu->getID() << "\n";
          peao4 = peao4->getProx();
        }
        peao3 = peao3->getProx();
      }
      peao2 = peao2->getProx();
    }
    peao = peao->getProx();
  }

  grava_Mat.close();
}

void Principal::Carregar () {
  bool result = cr_Info();
  if(result) {
    cr_Uni();
    cr_Dep();
    cr_Dis();
    cr_Prf();
    cr_Mat();
  }
}

void Principal::carregando () {
  ct++;
  system("clear");
  int porc = static_cast<int>(ct*20/ents);
  cout << "     " << "Carregando\n[";
  int j;
  for(j = 0; j < porc; j++) {cout << "#";}
  for(; j < 20; j++) {cout << " ";}
  cout << "]\n";
}

bool Principal::cr_Info () {
  ifstream carregInfo ("./dat/Info2.dat", ios::in);

  string S;
  int n;
  bool pv = true;
  if(!carregInfo) {
    system("clear");
    cout << "E a primeira vez que voce inicia o sistema, informe para quantas Universidades:\n";
    cin >> n;
    cout << "\nInforme o nome do sistema:\n";
    cin >> S;
    pLU.setNum(n);
    pLU.setNome(S);
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
    pLU.setNum(n);
    pLU.setNome(S);
    carregando();
  }

  carregInfo.close();
  return pv;
}

void Principal::cr_Uni () {
  ifstream carreg_Uni ("./dat/Universidades2.dat", ios::in);

  if(!carreg_Uni)
      erro();

  string S;
  int n, id;
  while(carreg_Uni >> id >> S >> n) {
    Universidade *uni = new Universidade(S, n, id);
    pLU.addEnt(uni);
    carregando();
  }

  carreg_Uni.close();
}

void Principal::cr_Dep () {
  ifstream carreg_Dep ("./dat/Departamentos2.dat", ios::in);

  if(!carreg_Dep)
      erro();

  string S;
  int U, n, np, na, id;
  while(carreg_Dep >> id >> S >> U >> n >> np >> na) {
    Universidade *uni = localizaUni(U);
    Departamento *dep = new Departamento(S, uni, n, np, na, id);
    carregando();
  }

  carreg_Dep.close();
}

void Principal::cr_Dis () {
  ifstream carreg_Dis ("./dat/Disciplinas2.dat", ios::in);

  if(!carreg_Dis)
      erro();

  string S, A;
  int D, n, id;
  while(carreg_Dis >> id >> S >> A >> D >> n) {
    Departamento *dep = localizaDep(D);
    Disciplina *dis = new Disciplina(S, A, dep, n, id);
    carregando();
  }

  carreg_Dis.close();
}

void Principal::cr_Prf () {
  ifstream carreg_Prf ("./dat/Professores2.dat", ios::in);

  if(!carreg_Prf)
      erro();

  string S;
  int U, D, dia, mes, ano, id;
  while(carreg_Prf >> id >> dia >> mes >> ano >> S >> U >> D) {
    Universidade *uni = localizaUni(U);
    Departamento *dep = localizaDep(D);
    Professor *prf = new Professor(dia, mes, ano, S, uni, dep, id);
    carregando();
  }

  carreg_Prf.close();
}

void Principal::cr_Mat () {
  ifstream carreg_Mat ("./dat/Matriculas2.dat", ios::in);

  if(!carreg_Mat)
      erro();

  int S, A;
  while(carreg_Mat >> S >> A) {
    Disciplina *dis = localizaDis(S);
    Aluno *alu = localizaAlu(A);
    dis->addAluno(alu);
    carregando();
  }

  carreg_Mat.close();
}

int Principal::IDUni (){
  contIDUni += 1;
  return contIDUni;
}

int Principal::IDDep (){
  contIDDep += 10;
  return contIDDep;
}

int Principal::IDDis (){
  contIDDis += 1000;
  return contIDDis;
}

int Principal::IDPrf (){
  contIDPrf += 1000;
  return contIDPrf;
}

int Principal::IDAlu (){
  contIDAlu += 1000;
  return contIDAlu;
}

void Principal::erro () {
  cerr << "Arquivo nao pode ser aberto.\n";
  exit(1);
}

Universidade* Principal::localizaUni (string S) {
  return pLU.getEnt(S);
}

Departamento* Principal::localizaDep (string S, string D) {
  return pLU.getEnt(S)->getDep(D);
}

Disciplina* Principal::localizaDis (string S, string D, string I) {
  return pLU.getEnt(S)->getDep(D)->getDis(I);
}

Aluno* Principal::localizaAlu (string S, string D, string I, string A) {
  return pLU.getEnt(S)->getDep(D)->getDis(I)->getAluno(A);
}

Universidade* Principal::localizaUni (int S) {
  return pLU.getEnt(S);
}

Departamento* Principal::localizaDep (int S) {
  return pLU.getEnt(S)->getDep(D);
}

Disciplina* Principal::localizaDis (int S) {
  ifstream carreg_Dis ("./dat/Disciplinas2.dat", ios::in);

  return pLU.getEnt(S)->getDep(D)->getDis(I);
}

Aluno* Principal::localizaAlu (int S) {
  ifstream carreg_Uni ("./dat/Universidades2.dat", ios::in);
  ifstream carreg_Dep ("./dat/Departamentos2.dat", ios::in);
  ifstream carreg_Alu ("./dat/Aunos2.dat", ios::in);

  if(!carreg_Uni || !carreg_Dep || !carreg_Alu)
    erro();

  int A, aux;
  string saux;
  while(getline(carreg_Alu, saux)) {
    






  }


  carreg_Uni.close();
  carreg_Dep.close();
  carreg_Alu.close();
}
