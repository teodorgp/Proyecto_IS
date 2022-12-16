//curso.h
//Save a curso information

#ifndef _CURSO_
#define _CURSO_

#include <iostream>
#include <string>

using namespace std;

class Curso
{
  private:
  string nombre_, descripcion_, fecha_inicio_, fecha_fin_;

  public:
  Curso(string nombre = "\0", string descripcion = "\0", string fecha_inicio = "\0", string fecha_fin = "\0");

  inline void setNombre(string nombre) { nombre_ = nombre; }
  inline string getNombre() const { return nombre_; }

  inline void setDescripcion(string descripcion) { descripcion_ = descripcion; }
  inline string getDescripcion() const { return descripcion_; }

  inline void setFecha_inicio(string fecha_inicio) { fecha_inicio_ = fecha_inicio; }
  inline string getFecha_inicio() const { return fecha_inicio_; }

  inline void setFecha_fin(string fecha_fin) { fecha_fin_ = fecha_fin; }
  inline string getFecha_fin() const { return fecha_fin_; }

};


#endif