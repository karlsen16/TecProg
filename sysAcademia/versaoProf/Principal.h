#ifndef _PRINCIPAL_H_
#define _PRINCIPAL_H_

#include "Professor.h"
#include "ListaUniversidades.h"
#include "ListaDepartamentos.h"
#include "ListaDisciplinas.h"
#include "Aluno.h"

class Principal
{
 private:

  // A T E N C A O !!!
  // A ORDEM DA DECLARACAO DOS OBJETOS/VARIAVEIS (AGREGADOS) NUMA CLASSE AFETA
  // A ORDEM DA CHAMADA(OU DA EXECUCAO) DE SEUS CONTRUTORES A PARTIR DO CONSTRUTOR
  // DESTA CLASSE AGREGADORA. NESTE CASO, A CLASSE QUE OS AGREGA E A PRINCIPAL!

    // Contadores para identificadores;
	int cont_idDisc;
	int cont_idDepart;
	int cont_idAluno;

    // Universidades
    Universidade UTFPR;
    Universidade Princeton;
    Universidade Cambridge;

    // Departamentos
    Departamento EletronicaUTFPR;
    Departamento MatematicaUTFPR;
    Departamento FisicaUTFPR;

    Departamento MatematicaPrinceton;
    Departamento FisicaPrinceton;

    Departamento MatematicaCambridge;
    Departamento FisicaCambridge;

    // Professores
    Professor	Simao;
    Professor	Einstein;
    Professor	Newton;

    // Disciplinas
    Disciplina	Computacao1_2006;
    Disciplina	Introd_Alg_2007;
    Disciplina	Computacao2_2007;
    Disciplina	Metodos2_2007;

	// Alunos
    Aluno		AAA;
    Aluno		BBB;
    Aluno		CCC;
    Aluno		DDD;
    Aluno		EEE;

    int			diaAtual;
    int			mesAtual;
    int			anoAtual;

    ListaUniversidades	LUniversidades;
	ListaDepartamentos	LDepartamentos;
	ListaDisciplinas	LDisciplinas;
	ListaAlunos			LAlunos;

  public:

    Principal (  );

    // Inicializacoes...
    void Inicializa();
    void InicializaUnivesidades();
    void InicializaDepartamentos();
    void InicializaProfessores();
    void InicializaAlunos();
    void InicializaDisciplinas();

    void Executar();

    void CalcIdadeProfs();
    void UnivOndeProfsTrabalham();
    void DepOndeProfsTrabalham();
	void ListeDiscDeptos ( );
	void ListeAlunosDisc();

	void CadDisciplina();
	void CadDepartamento();
	void CadUniversidade();
	void CadAluno();

	void GravarTudo();
	void GravarUniversidades();
	void GravarDepartamentos();
	void GravarDisciplinas();
	void GravarAlunos();
	void GravarProfessores();

	void RecuperarTudo();
	void RecuperarUniversidades();
	void RecuperarDepartamentos();
	void RecuperarDisciplinas();
	void RecuperarAlunos();
	void RecuperarProfessores();

	void MenuCad();
	void MenuExe();
	void MenuGravar();
	void MenuRecuperar();
	void Menu();

};

#endif
