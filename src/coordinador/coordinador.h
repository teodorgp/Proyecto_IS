//coordinador.h
//Save a coordinador information

#ifndef _COORDINADOR_
#define _COORDINADOR_

#include <iostream>
#include <string>

using namespace std;

class Coordinador
{
  private:
  string password_;
  int tipo_;

  public:
  Coordinador(string nombre = "\0", string apellidos = "\0", string dni = "\0", string email = "\0", string password = "\0" );

  inline void setPassword(string password) { password_ = password; }
  inline string getPassword() const { return password_; }

  inline void setTipo(int tipo) { tipo_ = tipo; }
  inline int getTipo() const { return tipo_; }
};


#endif