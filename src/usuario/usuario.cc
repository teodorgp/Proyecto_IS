//usuario.cc

#include "usuario.h"

Usuario::Usuario(string nombre, string apellidos, string dni, string email, string password,int tipo)
{
  setNombre(nombre);
  setApellidos(apellidos);
  setDNI(dni);
  setEmail(email);
  setPassword(password);
  setTipo(2);
}
