#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
#include "MinhaString.h"

MinhaString::MinhaString (char *S) {
  tamanho = strlen(S);
  strcpy(str, S);
}

MinhaString::~MinhaString () {
}

char* MinhaString::getString () {
  return str;
}
