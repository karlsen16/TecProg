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
  Init_Alunos();
  Init_Professores();
  Init_Disciplinas();
  Init_Departamentos();
  Init_Universidades();
}

void Principal::Init_Alunos () {
  fulano.setNome("fulano");
  ciclano.setNome("ciclano");
  judete.setNome("judete");
  julia.setNome("julia");
  juliana.setNome("juliana");
  julius.setNome("julius");
  fulan.setNome("fulan");
  Matriculas();
}

void Principal::Matriculas () {
  fulano.matricula(&tec_2008, &comp1_2019, &comp2_2015, &neut_2001);
  ciclano.matricula(&tec_2008, &disc_2011, &design_2019, &graph_2017);
  judete.matricula(&tec_2008, &mat_2019, &opt_2000, &mat_2019);
  julia.matricula(&tec_2008, &quant_2010, &graph_2017, &opt_2000);
  juliana.matricula(&tec_2008, &disc_2011, &mat_2019, &comp1_2019);
  julius.matricula(&tec_2008, &design_2019, &neut_2001, &graph_2017);
  fulan.matricula(&tec_2008, &graph_2017, &disc_2011, &quant_2010);
}

void Principal::Init_Professores () {
  Joana.inicializa(3, 10, 1987, "Joana", &UTFPR, &DADIN);
  Simao.inicializa(31, 12, 2000, "Simao", &UTFPR, &DAINF);
  Einstein.inicializa(14, 3, 1879, "Einstein", &Princeton, &FisicaP);
  Newton.inicializa(4, 1, 1643, "Newton", &Cambrigde, &MatematicaC);
}

void Principal::Init_Disciplinas () {
  comp1_2019.inicializa("Computacao 1", "Tecnologia", &DAINF, 001);
  tec_2008.inicializa("Tecnicas de Programacao", "Tecnologia", &DAINF, 657);
  design_2019.inicializa("Design", "Publicidade", &DADIN, 902);
  neut_2001.inicializa("Neutrinos", "Fisica", &DAFIS, 165);
  mat_2019.inicializa("Matematica 1", "Exatas", &DAMAT, 127);
  quant_2010.inicializa("Quantum Physics", "Fisica", &FisicaP, 359);
  comp2_2015.inicializa("CS 101", "Tecnologia", &MatematicaP, 778);
  disc_2011.inicializa("Discrete Math", "Exatas", &MatematicaP, 687);
  opt_2000.inicializa("Optics", "Fisica", &FisicaC, 128);
  graph_2017.inicializa("Graph Teory", "Exatas", &MatematicaC, 549);
}

void Principal::Init_Departamentos () {
  DAINF.inicializa("DAINF", &UTFPR, 11);
  DADIN.inicializa("DADIN", &UTFPR, 84);
  DAFIS.inicializa("DAFIS", &UTFPR, 57);
  DAMAT.inicializa("DAMAT", &UTFPR, 75);
  FisicaP.inicializa("Physics (P)", &Princeton, 68);
  MatematicaP.inicializa("Math (P)", &Princeton, 51);
  FisicaC.inicializa("Physics (C)", &Cambrigde, 15);
  MatematicaC.inicializa("Math (C)", &Cambrigde, 53);
}

void Principal::Init_Universidades () {
  UTFPR.setNome("UTFPR");
  Princeton.setNome("Princeton");
  Cambrigde.setNome("Cambrigde");
}

void Principal::Executar () {
  calculaIdadeProfs();
  localTrabalho();
  imprimeDepDisS();
  // comp1_2019.removeAluno(&julius);
  // tec_2008.removeAluno(&fulano);
  // tec_2008.imprimeAlu();
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

void Principal::imprimeDepDisS () {
  UTFPR.imprimeTudo();
  Princeton.imprimeTudo();
  Cambrigde.imprimeTudo();
}
