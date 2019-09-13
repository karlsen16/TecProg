#pragma once
#include "Menu.h"

class Principal {
private:
  Lista<Universidade> listaUniversidades;
  Dados arquivo;
  Menu menu;

public:
  Principal ();
  ~Principal ();
  void Executar ();

};
