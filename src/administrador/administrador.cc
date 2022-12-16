//administrador.cc

#include "administrador.h"

Administrador::Administrador(string nombre, string apellidos, string email, string password, int tipo)
{
  setNombre(nombre);
  setApellidos(apellidos);
  setEmail(email);
  setPassword(password);
  setTipo(0);
}