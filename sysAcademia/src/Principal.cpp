#include "stdafx.h"
#include "Principal.h"

Principal::Principal () {
  Init();

  time_t T = time(NULL);
  struct tm tm = *localtime(&T);
  diaAtual = tm.tm_mday;
  mesAtual = tm.tm_mon + 1;
  anoAtual = tm.tm_year +1900;

  Executar();
}

Principal::~Principal () {
}

void Principal::Init () {
  Init_Disciplinas();
  Init_Departamentos();
  Init_Universidades();
  Init_Professores();
}

void Principal::Init_Disciplinas () {
  comp1_2019.inicializa("Computacao 1", "Tecnologia", &DAINF, 001);
  tec_2008.inicializa("Tecnicas de Programacao", "Tecnologia", &DAINF, 657);
  comp1_2019.setProx(&tec_2008);
  design_2019.inicializa("Design", "Publicidade", &DADIN, 902);
  neut_2001.inicializa("Neutrinos", "Fisica", &DAFIS, 165);
  mat_2019.inicializa("Matematica 1", "Exatas", &DAMAT, 127);
  quant_2010.inicializa("Quantum Physics", "Fisica", &FisicaP, 359);
  comp2_2015.inicializa("CS 101", "Tecnologia", &MatematicaP, 778);
  disc_2011.inicializa("Discrete Math", "Exatas", &MatematicaP, 687);
  comp2_2015.setProx(&disc_2011);
  opt_2000.inicializa("Optics", "Fisica", &FisicaC, 128);
  graph_2017.inicializa("Graph Teory", "Exatas", &MatematicaC, 549);
}

void Principal::Init_Departamentos () {
  DAINF.inicializa("DAINF", &UTFPR, &comp1_2019, 11);
  DADIN.inicializa("DADIN", &UTFPR, &design_2019, 84);
  DAFIS.inicializa("DAFIS", &UTFPR, &neut_2001, 57);
  DAMAT.inicializa("DAMAT", &UTFPR, &mat_2019, 75);
  FisicaP.inicializa("Physics (P)", &Princeton, &quant_2010, 68);
  MatematicaP.inicializa("Math (P)", &Princeton, &comp2_2015, 51);
  FisicaC.inicializa("Physics (C)", &Cambrigde, &opt_2000, 15);
  MatematicaC.inicializa("Math (C)", &Cambrigde, &graph_2017, 53);
}

void Principal::Init_Universidades () {
  UTFPR.inicializa("UTFPR", &DAINF);
  UTFPR.incluirDep(&DADIN);
  UTFPR.incluirDep(&DAFIS);
  UTFPR.incluirDep(&DAMAT);
  Princeton.inicializa("Princeton", &FisicaP);
  Princeton.incluirDep(&MatematicaP);
  Cambrigde.inicializa("Cambrigde", &FisicaC);
  Cambrigde.incluirDep(&MatematicaC);
}


void Principal::Init_Professores () {
  Joana.inicializa(3, 10, 1987, "Joana", &UTFPR, &DADIN);
  Simao.inicializa(31, 12, 2000, "Simao", &UTFPR, &DAINF);
  Einstein.inicializa(14, 3, 1879, "Einstein", &Princeton, &FisicaP);
  Newton.inicializa(4, 1, 1643, "Newton", &Cambrigde, &MatematicaC);
}

void Principal::Executar () {
  calculaIdadeProfs();
  localTrabalho();
  depTrabalho();
  imprimeDepDisS();
}

void Principal::calculaIdadeProfs () {
  Joana.calculaIdade(diaAtual, mesAtual, anoAtual);
  Simao.calculaIdade(diaAtual, mesAtual, anoAtual);
  Einstein.calculaIdade(diaAtual, mesAtual, anoAtual);
  Newton.calculaIdade(diaAtual, mesAtual, anoAtual);
}

void Principal::localTrabalho () {
  Joana.imprimeTudo();
  Simao.imprimeTudo();
  Einstein.imprimeTudo();
  Newton.imprimeTudo();
}

void Principal::depTrabalho () {
  Joana.printUni();
  Simao.printUni();
  Einstein.printUni();
  Newton.printUni();
}

void Principal::imprimeDepDisS () {
  UTFPR.imprimeTudo();
  Princeton.imprimeTudo();
  Cambrigde.imprimeTudo();
}
