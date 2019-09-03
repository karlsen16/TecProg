#pragma once
#include <iostream>
using std::cout;
using std::endl;

class MinhaString {
private:
  int tamanho;
  char str[300];

public:
  MinhaString ();
  MinhaString (char *S);
  ~MinhaString ();
  char* getString ();

};
