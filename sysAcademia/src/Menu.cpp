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
  char S[150];
  int qnt;
  Universidade *uni = NULL;
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  cout << "Quantos Departamentos ela tem?\n";
  cin >> qnt;
  uni = new Universidade(S, qnt, contIDUni);
  contIDUni++;
  pLU->addEnt(uni);
}

void Menu::CadDepartamento () {
  char S[150], D[150];
  int qnt, qntp;
  Departamento *dep = NULL;
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  cout << "Qual o nome do Departamento?\n";
  cin >> D;
  cout << "Quantas Disciplinas ele tem?\n";
  cin >> qnt;
  cout << "Quantos Professores ele tem?\n";
  cin >> qntp;
  dep = new Departamento(D, pLU->getEnt(S), qnt, qntp,
    pLU->getEnt(S)->getID()+contIDDep);
  contIDDep++;
}

void Menu::CadDisciplina () {
  char S[150], D[150], I[150], A[150];
  int qnt, qnta;
  Disciplina *dis = NULL;
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  cout << "Qual o nome do Departamento?\n";
  cin >> D;
  cout << "Qual o nome da Disciplina?\n";
  cin >> I;
  cout << "Qual o nome da Area?\n";
  cin >> A;
  cout << "Quantos Alunos ela tem?\n";
  cin >> qnta;
  dis = new Disciplina(I, A, pLU->getEnt(S)->getDep(D), qnta,
    pLU->getEnt(S)->getID()+pLU->getEnt(S)->getDep(D)->getID()+contIDDis);
  contIDDis++;
}

void Menu::CadProfessor () {
  char S[150], D[150], P[50];
  int dia, mes, ano;
  Professor *prf = NULL;
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  cout << "Qual o nome do Departamento?\n";
  cin >> D;
  cout << "Qual o nome do Professor?\n";
  cin >> P;
  cout << "Qual a data de nascimento?\n";
  cin >> dia >> mes >> ano;
  prf = new Professor(dia, mes, ano, P, pLU->getEnt(S),
      pLU->getEnt(S)->getDep(D),
      pLU->getEnt(S)->getID()+pLU->getEnt(S)->getDep(D)->getID()+contIDPrf);
  contIDPrf++;
}

void Menu::CadAluno () {
  char S[150], D[150], I[150], A[150];
  int dia, mes, ano, ra;
  Aluno *alu = NULL;
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  cout << "Qual o nome do Departamento?\n";
  cin >> D;
  cout << "Qual o nome da Disciplina?\n";
  cin >> I;
  cout << "Qual o nome do Aluno?\n";
  cin >> A;
  cout << "Qual a data de nascimento?\n";
  cin >> dia >> mes >> ano;
  cout << "Qual o RA?\n";
  cin >> ra;
  alu = new Aluno(dia, mes, ano, A, ra,
    pLU->getEnt(S)->getID()+pLU->getEnt(S)->getDep(D)->getID()+contIDAlu);
  contIDAlu++;
  pLU->getEnt(S)->getDep(D)->getDis(I)->addAluno(alu);
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
  char S[150];
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  if(pLU->getEnt(S))
    pLU->getEnt(S)->imprimeDeps();
  else
    cout << "Nao e possivel fazer esta operacao. Erro (40).\n";
}

void Menu::ExeDisciplina () {
  char S[150], D[150];
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  cout << "Qual o nome do Departamento?\n";
  cin >> D;
  if(pLU->getEnt(S) && pLU->getEnt(S)->getDep(D))
    pLU->getEnt(S)->getDep(D)->imprimeDiss();
  else
    cout << "Nao e possivel fazer esta operacao. Erro (30).\n";
}

void Menu::ExeProfessor () {
  char S[150], D[150];
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  cout << "Qual o nome do Departamento?\n";
  cin >> D;
  if(pLU->getEnt(S) && pLU->getEnt(S)->getDep(D))
    pLU->getEnt(S)->getDep(D)->imprimePrfs();
  else
    cout << "Nao e possivel fazer esta operacao. Erro (20).\n";
}

void Menu::ExeAluno () {
  char S[150], D[150], I[150];
  cout << "Qual o nome da Universidade?\n";
  cin >> S;
  cout << "Qual o nome do Departamento?\n";
  cin >> D;
  cout << "Qual o nome da Disciplina?\n";
  cin >> I;
  if(pLU->getEnt(S) && pLU->getEnt(S)->getDep(D)
    && pLU->getEnt(S)->getDep(D)->getDis(I))
    pLU->getEnt(S)->getDep(D)->getDis(I)->imprimeAlus();
  else
    cout << "Nao e possivel fazer esta operacao. Erro (10).\n";
}

void Menu::Carregar () {
  transicao("Carregando", false);
  // pArq->Carregar();
}

void Menu::Gravar () {
  transicao("Gravando", false);
  // pArq->Gravar();
}
