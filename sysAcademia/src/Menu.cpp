#include "stdafx.h"
#include "Menu.h"
#define TE 6

Menu::Menu (Lista<Universidade> *plu, Dados* dat):
contIDAlu(1000), contIDPrf(1000), contIDDis(1000),
contIDDep(10), contIDUni(1),
fim(false) {
  pLU = plu;
  pArq = dat;
}

Menu::~Menu () {
  pLU = NULL;
  pArq = NULL;
}

void Menu::Inicial () {
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
      default: invalido(1);
    }
    if(fim)
      break;
  }
}

void Menu::transicao (string S, bool d) {
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

void Menu::esperar () {
  char c = 'n';
  cout << "\n\n Informe quando quiser voltar digitando 'y'.\n";
  do {cin >> c;} while(c != 'y');
}

void Menu::invalido (bool d) {
  if(d)
    cout << "Opcao invalida.\n";
  else
    cout << "Opcoes invalidas.\n";
  usleep(1000000);
}

void Menu::voltar () {
  transicao("Voltando", true);
}

void Menu::sair () {
  transicao("Finalizando", false);
  fim = true;
}

void Menu::Cad () {
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
      default: invalido(true);
    }
  }
}

void Menu::CadUniversidade () {
  string S;
  int qnt;
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  cout << "Quantos Departamentos ela tem?\n";
  cin >> qnt;
  Universidade *uni = new Universidade(S, qnt, contIDUni++);
  pLU->addEnt(uni);
  esperar();
}

void Menu::CadDepartamento () {
  string S;
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  Universidade *uni = localizaUni(S);
  if(uni) {
    string D;
    int qnt, qntp;
    cout << "Qual o nome do Departamento?\n";
    cin >> D;
    cout << "Quantas Disciplinas ele tem?\n";
    cin >> qnt;
    cout << "Quantos Professores ele tem?\n";
    cin >> qntp;
    Departamento *dep = new Departamento(D, uni, qnt, qntp, uni->getID()+contIDDep++);
    return;
  }
  else
    cout << "A Universidade " << S << " nao esta cadastrada.\n";
  cout << "Nao foi possivel fazer esta operacao. Erro (99).\n";
  esperar();
}

void Menu::CadDisciplina () {
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
      int qnta;
      cout << "Qual o nome da Disciplina?\n";
      cin >> I;
      cout << "Qual o nome da Area?\n";
      cin >> A;
      cout << "Quantos Alunos ela tem?\n";
      cin >> qnta;
      Disciplina *dis = new Disciplina(I, A, dep, qnta, uni->getID()+dep->getID()+contIDDis++);
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

void Menu::CadProfessor () {
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
      Professor *prf = new Professor(dia, mes, ano, P, uni, dep, uni->getID()+dep->getID()+contIDPrf++);
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

void Menu::CadAluno () {
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
        Aluno *alu = new Aluno(dia, mes, ano, A, ra, uni->getID()+dep->getID()+contIDAlu++);
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

Universidade* Menu::localizaUni (string S) {
  return pLU->getEnt(S);
}

Departamento* Menu::localizaDep (string S, string D) {
  return pLU->getEnt(S)->getDep(D);
}

Disciplina* Menu::localizaDis (string S, string D, string I) {
  return pLU->getEnt(S)->getDep(D)->getDis(I);
}

void Menu::Exe () {
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
      default: invalido(true);
    }
  }
}

void Menu::ExeUniversidade () {
  pLU->imprimeEnts();
}

void Menu::ExeDepartamento () {
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

void Menu::ExeDisciplina () {
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

void Menu::ExeProfessor () {
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

void Menu::ExeAluno () {
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

void Menu::Carregar () {
  transicao("Carregando", false);
  // pArq->Carregar();
}

void Menu::Gravar () {
  transicao("Gravando", false);
  // pArq->Gravar();
}
