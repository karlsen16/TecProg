#pragma once
#include "Universidade.h"

class Principal {
private:
  Menu menu;

    class Menu {
    private:
      // Dados *pArq;
      Dados arquivo;
      bool fim;

        class Dados {
        private:
          // Lista<Universidade> *pLU;
          Lista<Universidade> listaUniversidades;
          Lista<Departamento> listaDepartamentos;
          Lista<Disciplina> listaDisciplinas;
          Lista<Pessoa> listaPessoas;
          Lista<Professor> listaProfessores;
          Lista<Aluno> listaAlunos;

          int contIDUni, contIDDep, contIDDis,
              contIDPrf, contIDAlu, ents, ct;

        public:
          Dados (Lista<Universidade> *plu = NULL, Menu *menu = NULL);
          ~Dados ();

          void erro ();
          void s_E ();
          void carregando ();

          void Carregar ();
          bool cr_Info ();
          void cr_Uni (bool res);
          void cr_Dep (bool res);
          void cr_Dis (bool res);
          void cr_Prf (bool res);
          void cr_Mat (bool res);

          Departamento* localizaDep (string S);
          Disciplina* localizaDis (string S);
          Aluno* localizaAlu (string A);

          void Gravar ();
          void gv_Info ();
          void gv_Uni ();
          void gv_Dep ();
          void gv_Dis ();
          void gv_Prf ();
          void gv_Alu ();
          void gv_Mat ();

          int IDUni ();
          int IDDep ();
          int IDDis ();
          int IDPrf ();
          int IDAlu ();

        };

    public:
      Menu (Lista<Universidade> *plu = NULL, Dados *dat = NULL);
      ~Menu ();

      void Inicial ();
      void transicao (string S, bool d);
      void esperar ();
      void invalido (bool d);
      void voltar ();
      void sair ();

      void Cad ();
      void CadUniversidade ();
      void CadDepartamento ();
      void CadDisciplina ();
      void CadProfessor ();
      void CadAluno ();

      Universidade* localizaUni (string S);
      Departamento* localizaDep (string S, string D);
      Disciplina* localizaDis (string S, string D, string I);

      void Exe ();
      void ExeUniversidade ();
      void ExeDepartamento ();
      void ExeDisciplina ();
      void ExeProfessor ();
      void ExeAluno ();

      void Gravar ();

    };

public:
  Principal ();
  ~Principal ();
  void Executar ();

};
