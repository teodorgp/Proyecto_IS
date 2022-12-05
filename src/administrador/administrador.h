//administrador.h
//Save a administrador information

#ifndef _ADMINISTRADOR_
#define _ADMINISTRADOR_

#include <iostream>
#include <string>

using namespace std;

class Administrador
{
  private:
  string password_;
  int tipo_;

  public:
  Administrador(string nombre = "\0", 
                string apellidos = "\0", 
                string email = "\0", 
                string password = "\0",
                int tipo = 0);

  inline void setPassword(string password) { password_ = password; }
  inline string getPassword() const { return password_; }
  inline void setTipo(int tipo) { tipo_ = tipo; }
  inline int getTipo() const { return tipo_; }

};