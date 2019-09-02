#include "stdafx.h"
#include "Principal.h"

// A T E N c a O
// A ordem de chamada dos construtores dos objetos (agredados) nesta classe
// e definida pela sua ordem de declaracao na classe Principal e NaO (estra-
// nhamente) pela sua ordem de chamada aqui (a partir do construtor da Principal).

Principal::Principal (  ):
// "geradores" de identificacao
cont_idAluno		(0),
cont_idDisc			(0),
cont_idDepart		(0),
// Contrutores dos objetos da Classe Disciplina
Computacao1_2006	(cont_idDisc++),
Introd_Alg_2007		(cont_idDisc++),
Computacao2_2007	(cont_idDisc++),
Metodos2_2007		(cont_idDisc++),
// Contrutores dos objetos da Classe Aluno
AAA					(cont_idAluno++),
BBB					(cont_idAluno++),
CCC					(cont_idAluno++),
DDD					(cont_idAluno++),
EEE					(cont_idAluno++),
//Contrutores dos Objetos da Classe Departamento
EletronicaUTFPR		(cont_idDepart++),
MatematicaUTFPR		(cont_idDepart++),
FisicaUTFPR			(cont_idDepart++),
MatematicaPrinceton	(cont_idDepart++),
FisicaPrinceton		(cont_idDepart++),
MatematicaCambridge	(cont_idDepart++),
FisicaCambridge		(cont_idDepart++)
{
    diaAtual = 2;
	mesAtual = 9;
	anoAtual = 2019;
    Inicializa ( );
	Executar();
}

void Principal::Inicializa ( )
{
	InicializaAlunos ( );
    InicializaUnivesidades ( );
    InicializaDepartamentos ( );
    InicializaProfessores ( );
    InicializaDisciplinas ( );
}

void Principal::InicializaAlunos()
{
	AAA.setNome	("AAA");
	LAlunos.incluaAluno(&AAA);

	BBB.setNome	("BBB");
	LAlunos.incluaAluno(&BBB);

	CCC.setNome	("CCC");
	LAlunos.incluaAluno(&CCC);

	DDD.setNome	("DDD");
	LAlunos.incluaAluno(&DDD);

	EEE.setNome	("EEE");
	LAlunos.incluaAluno(&EEE);
}

void Principal::InicializaUnivesidades ( )
{
    // Registro do(s) nome(s) da(s) universidade(s)
    UTFPR.setNome     ( "UTFPR"		);
	LUniversidades.incluaUniversidade( &UTFPR );

    Princeton.setNome ( "Princeton" );
	LUniversidades.incluaUniversidade( &Princeton );

    Cambridge.setNome ( "Cambridge" );
	LUniversidades.incluaUniversidade( &Cambridge );
}

void Principal::InicializaDepartamentos ( )
{
    // Registro do(s) nome(s) do(s) departamento(s)
    EletronicaUTFPR.setNome		( "Eletronica UTFPR" );
	MatematicaUTFPR.setNome		( "Matematica UTFPR" );
    FisicaUTFPR.setNome			( "Fisica UTFPR" );
    MatematicaPrinceton.setNome ( "Matematica Princeton" );
    FisicaPrinceton.setNome		( "Fisica Pirnceton" );
    MatematicaCambridge.setNome ( "Matematica Cambridge" );
    FisicaCambridge.setNome		( "Fisica Cambridge" );

	LDepartamentos.incluaDepartamento(&EletronicaUTFPR);
	LDepartamentos.incluaDepartamento(&MatematicaUTFPR);
	LDepartamentos.incluaDepartamento(&FisicaUTFPR);
	LDepartamentos.incluaDepartamento(&MatematicaPrinceton);
	LDepartamentos.incluaDepartamento(&FisicaPrinceton);
	LDepartamentos.incluaDepartamento(&MatematicaCambridge);
	LDepartamentos.incluaDepartamento(&FisicaCambridge);

    // "Agregacao" do(s) Departamento(s) a(s) Universidade(s).
    UTFPR.incluaDepartamento		( &EletronicaUTFPR );
    UTFPR.incluaDepartamento		( &MatematicaUTFPR );
    UTFPR.incluaDepartamento		( &FisicaUTFPR );

    Princeton.incluaDepartamento	( &MatematicaPrinceton );
    Princeton.incluaDepartamento	( &FisicaPrinceton );
    Cambridge.incluaDepartamento	( &MatematicaCambridge );
    Cambridge.incluaDepartamento	( &FisicaCambridge );
}

void Principal::InicializaProfessores ( )
{

    // Inicializacao do(s) ojeto(s) da classe Professor
    Simao.Inicializa	( 3, 10, 1976, "Jean Simao" );
    Einstein.Inicializa ( 14, 3, 1879, "Albert Einstein" );
    Newton.Inicializa	( 4, 1, 1643, "Isaac Newton" );

    // "Filiacao" a universidade.
    Simao.setUnivFiliado	( &UTFPR );
    Einstein.setUnivFiliado ( &Princeton );
    Newton.setUnivFiliado	( &Cambridge );

    // Area de Conhecimento.
    // Simao.setDominio		( "Computacao );
    // Einstein.setDominio	( "Fisica" );
    // Newton.setDominio	( "Matematica-Fisica" );

    // "Filiacao" ao departamento.
    Simao.setDepartamento	( &EletronicaUTFPR );
    Einstein.setDepartamento( &FisicaPrinceton );
    Newton.setDepartamento	( &MatematicaCambridge );
 }

void Principal::InicializaDisciplinas ( )
{
    Computacao1_2006.setNome	( "Computacao I 2006" );
    Introd_Alg_2007.setNome		( "Introducao de Algoritmos de Programacao 2007" );
	Computacao2_2007.setNome	( "Computao II" );
	Metodos2_2007.setNome		( "Metodos II" );

	LDisciplinas.incluaDisciplina(&Computacao1_2006);
	LDisciplinas.incluaDisciplina(&Introd_Alg_2007);
	LDisciplinas.incluaDisciplina(&Computacao2_2007);
	LDisciplinas.incluaDisciplina(&Metodos2_2007);

    Computacao1_2006.setDepartamento  ( &EletronicaUTFPR );
    Introd_Alg_2007.setDepartamento	  ( &EletronicaUTFPR );
    Computacao2_2007.setDepartamento  ( &EletronicaUTFPR );
    Metodos2_2007.setDepartamento     ( &EletronicaUTFPR );

    Metodos2_2007.incluaAluno ( &AAA );
    Metodos2_2007.incluaAluno ( &BBB );
    Metodos2_2007.incluaAluno ( &CCC );
    Metodos2_2007.incluaAluno ( &DDD );
    Metodos2_2007.incluaAluno ( &EEE );

	Computacao2_2007.incluaAluno ( &AAA );
    Computacao2_2007.incluaAluno ( &EEE );
    Computacao2_2007.incluaAluno ( &DDD );
}

void Principal::CalcIdadeProfs ( )
{
    // Calculo da idade.
    Simao.Calc_Idade    ( diaAtual, mesAtual, anoAtual );
    Einstein.Calc_Idade ( diaAtual, mesAtual, anoAtual );
    Newton.Calc_Idade	( diaAtual, mesAtual, anoAtual );
    printf ("\n");
}

void Principal::UnivOndeProfsTrabalham ( )
{
    // Universidade que a Pessoa trabalha.
    Simao.OndeTrabalho ( );
    Einstein.OndeTrabalho ( );
    Newton.OndeTrabalho ( );

	cout << endl;
}

void Principal::DepOndeProfsTrabalham ( )
{
    // Departamento que a Pessoa trabalha.
    Simao.QualDepartamentoTrabalho ( );
    Einstein.QualDepartamentoTrabalho ( );
    Newton.QualDepartamentoTrabalho ( );
    //printf ( "\n" );
	cout << endl;
}

void Principal::ListeDiscDeptos()
{
    EletronicaUTFPR.listeDisciplinas();
 	cout << endl;
}

void Principal::ListeAlunosDisc()
{
    Metodos2_2007.listeAlunos();
    cout << endl;

    Computacao2_2007.listeAlunos();
    cout << endl;

	//Metodos2_2007.listeAlunos2();
    //cout << endl;
}

void Principal::Executar()
{
    //CalcIdadeProfs();
    //UnivOndeProfsTrabalham();
    //DepOndeProfsTrabalham();
	//ListeDiscDeptos();
    //ListeAlunosDisc();
	Menu();
}

void Principal::CadDisciplina()
{

}

void Principal::CadDepartamento()
{
    char nomeUniversidade[150];
	char nomeDepartamento[150];
	Universidade* univ;
	Departamento* depart;

	cout << "Qual o nome da universidade do departamento" << endl;
	cin  >> nomeUniversidade;

	univ = LUniversidades.localizar(nomeUniversidade);

	if ( univ != NULL )
	{
		cout << "Qual o nome do departamento" << endl;
		cin >> nomeDepartamento;
	    depart = new Departamento(cont_idDepart);
		cont_idDepart++;
		depart->setNome(nomeDepartamento);
		LDepartamentos.incluaDepartamento(depart);
		LUniversidades.incluaUniversidade(univ);
	}
	else
	{
		cout << "Universidade inexistente." << endl;
	}
}

void Principal::CadUniversidade()
{
    char nomeUniversidade[150];
	Universidade* univ;

	cout << "Qual o nome da universidade" << endl;
	cin  >> nomeUniversidade;

    univ = new Universidade();
	univ->setNome(nomeUniversidade);

	LUniversidades.incluaUniversidade(univ);
}

void Principal::CadAluno()
{
    char	nomeAluno[150];
	int		ra;
	Aluno*	al;

	cout << "Qual o nome do aluno. " << endl;
	cin  >> nomeAluno;

	cout << "Qual o RA do aluno."	<< endl;
	cin  >> ra;

    al = new Aluno(cont_idAluno++);
	al->setNome(nomeAluno);
	al->setRA(ra);

	LAlunos.incluaAluno(al);
}

void Principal::GravarTudo()
{
}

void Principal::GravarUniversidades()
{
}

void Principal::GravarDepartamentos()
{
}

void Principal::GravarDisciplinas()
{
}

void Principal::GravarAlunos()
{
	LAlunos.graveAlunos();
}

void Principal::GravarProfessores()
{
}

void Principal::RecuperarTudo()
{
}

void Principal::RecuperarUniversidades()
{
}

void Principal::RecuperarDepartamentos()
{
}

void Principal::RecuperarDisciplinas()
{
}

void Principal::RecuperarAlunos()
{
	LAlunos.recupereAlunos();
}

void Principal::RecuperarProfessores()
{
}

void Principal::MenuCad()
{
    int op = -1;

    while (op != 5)
    {
		system("clear");
        cout << "  Informe sua opcao:			"	<< endl;
        cout << "  1 - Cadastrar Disciplina.	"	<< endl;
        cout << "  2 - Cadastrar Departamentos. "	<< endl;
        cout << "  3 - Cadastrar Universidade.	"	<< endl;
		cout << "  4 - Cadastrar Aluno.			"	<< endl;
        cout << "  5 - Sair. "						<< endl;
        cin >> op;

        switch (op)
        {
            case 1 :{ CadDisciplina ();	 }
                break;

            case 2: { CadDepartamento(); }
				break;

			case 3:	{ CadUniversidade(); }
				break;

			case 4:	{ CadAluno(); }
				break;

            case 5:	{ cout << " FIM " << endl; }
                break;

            default:{
					  cout << "opcao Invalida - Pressione uma tecla." << endl;
					  getchar();
				    }
        }
    }
}

void Principal::MenuExe()
{
    int op = -1;

    while (op != 5)
    {
		system("clear");
        cout << "  Informe sua opcao:		"	<< endl;
        cout << "  1 - Listar Disciplinas.  "	<< endl;
        cout << "  2 - Listar Departamentos."	<< endl;
        cout << "  3 - Listar Universidade. "	<< endl;
		cout << "  4 - Listar Alunos. "			<< endl;
        cout << "  5 - Sair. "					<< endl;
        cin >> op;

        switch (op)
        {
			case 1:  {
					   LDisciplinas.listeDisciplinas();
					   fflush(stdin);
					   getchar();
					 }
                break;
			case 2:  {
				       LDepartamentos.listeDepartamentos();
					   fflush(stdin);
					   getchar();
					 }
				break;
			case 3:  {
				       LUniversidades.listeUniversidades();
				       fflush(stdin);
					   getchar();
					 }
				break;
			case 4:  {
					   //cout << "coucou 1" << endl;
					   LAlunos.listeAlunos();
					   //cout << "coucou 2" << endl;

				       fflush(stdin);
					   getchar();
					 }
                break;
            case 5:  { cout << " FIM " << endl; }
                break;
            default: {
					   cout << "opcao Invalida - Pressione uma tecla." << endl;
					   getchar();
					 }
        }
    }
}

void Principal::MenuGravar()
{
	int op = -1;
    while (op != 6)
    {
		system("clear");
        cout << "  Informe sua opcao:			"	<< endl;
		cout << "  0 - Gravar Tudo.				"	<< endl;
        cout << "  1 - Gravar Universidades.	"	<< endl;
        cout << "  2 - Gravar Departamentos.	"	<< endl;
		cout << "  3 - Gravar Disciplinas.		"	<< endl;
		cout << "  4 - Gravar Alunos.			"	<< endl;
		cout << "  5 - Gravar Professores.		"	<< endl;
        cout << "  6  Sair.					"	<< endl;
        cin >> op;

        switch (op)
        {
			case 0: {	GravarTudo();			 }
                break;
            case 1: {	GravarUniversidades();	 }
                break;
            case 2: {	GravarDepartamentos();	 }
				break;
			case 3: {	GravarDisciplinas();	 }
				break;
			case 4: {	GravarAlunos();			 }
				break;
			case 5: {	GravarProfessores();	 }
				break;
			case 6: {	cout << " FIM " << endl; }
                break;
            default: { cout << "opcao Invalida - Pressione uma tecla." << endl;
					   getchar(); }
        }
    }
}

void Principal::MenuRecuperar()
{
	int op = -1;

    while (op != 6)
    {
		system("clear");

        cout << "  Informe sua opcao:			"	<< endl;
		cout << "  0 - Recuperar Tudo.			"	<< endl;
        cout << "  1 - Recuperar Universidades.	"	<< endl;
        cout << "  2 - Recuperar Departamentos.	"	<< endl;
		cout << "  3 - Recuperar Disciplinas.	"	<< endl;
		cout << "  4 - Recuperar Alunos.		"	<< endl;
		cout << "  5 - Recuperar Professores.	"	<< endl;
        cout << "  6  Sair.					"	<< endl;
        cin >> op;

        switch (op)
        {
			case 0: {	RecuperarTudo();			 }
                break;
            case 1: {	RecuperarUniversidades();	 }
                break;
            case 2: {	RecuperarDepartamentos();	 }
				break;
			case 3: {	RecuperarDisciplinas();	 }
				break;
			case 4: {	RecuperarAlunos();			 }
				break;
			case 5: {	RecuperarProfessores();	 }
				break;
			case 6: {	cout << " FIM " << endl; }
                break;
            default: { cout << "opcao Invalida - Pressione uma tecla." << endl;
					   getchar(); }
        }
    }
}


void Principal::Menu()
{
	int op = -1;

    while (op != 5)
    {
		system("clear");
        cout << "  Informe sua opcao:"	<< endl;
        cout << "  1 - Cadastrar.	 "	<< endl;
        cout << "  2 - Executar.	 "	<< endl;
		cout << "  3 - Gravar.		 "  << endl;
		cout << "  4 - Recuperar.	 "  << endl;
        cout << "  5 - Sair.		 "	<< endl;
        cin >> op;

        switch (op)
        {
            case 1: {	MenuCad();			}
                break;
            case 2: {	MenuExe();			}
				break;
			case 3: {	MenuGravar();		}
				break;
			case 4: {	MenuRecuperar();	}
				break;
			case 5: {	cout << " FIM " << endl; }
                break;
            default: { cout << "opcao Invalida - Pressione uma tecla." << endl;
					   getchar(); }
        }
    }
}
