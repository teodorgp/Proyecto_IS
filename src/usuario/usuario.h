//usuario.h
//Save a usuario information

#ifndef _USUARIO_
#define _USUARIO_ value

#include <iostream>
#include <string>

using std::string;

class Usuario
{
  private:
  string nombre_, apellidos_, dni_, email_;

  public:
  Usuario(string nombre = "\0", string apellidos = "\0", string dni = "\0", string email = "\0" );

  inline void setNombre(string nombre) { nombre_ = nombre; }
  inline string getNombre() const { return nombre_; }

  inline void setApellidos(string apellidos) { apellidos_ = apellidos; }
  inline string getApellidos() const { return apellidos_; }

  inline void setDNI(string dni) { dni_ = dni; }
  inline string getDNI() const { return dni_; }

  inline void setEmail(string email) { email_ = email; }
  inline string getEmail() const { return email_; }

  inline string getApellidosyNombre() const { return apellidos_ + ", " + nombre_; }

};

#endif
