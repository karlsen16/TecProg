#pragma once

class Entidade {
protected:
  string nome;
  int ID;

public:
  Entidade (string S = "", int id = 0);
  ~Entidade ();
  void setNome (string S);
  string getNome ();
  void setID (int id);
  int getID ();

};
