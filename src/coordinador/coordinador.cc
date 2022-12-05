//coordinador.c
//Save a coordinador information

#include "coordinador.h"

Coordinador::Coordinador(string nombre, string apellidos, string dni, string email, string password, int tipo)
{
  setNombre(nombre);
  setApellidos(apellidos);
  setDni(dni);
  setEmail(email);
  setPassword(password);
  setTipo(1);
}