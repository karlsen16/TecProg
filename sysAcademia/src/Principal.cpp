#include "stdafx.h"
#include "Principal.h"

Principal::Principal () {
  Executar();
}

Principal::~Principal () {
}

void Principal::Executar () {
  menu.Carregar();
  menu.Inicial();
}
