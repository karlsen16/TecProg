#include "stdafx.h"
#include "Principal.h"

Principal::Principal ():
listaUniversidades(),
arquivo(&listaUniversidades, &menu),
menu(&listaUniversidades, &arquivo) {
  Executar();
}

Principal::~Principal () {
}

void Principal::Executar () {
  arquivo.Carregar();
  menu.Inicial();
}
