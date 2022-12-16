#ifndef Coordinador_H
#define Coordinador_H
#include <iostream>
#include "../claseTrabajador/trabajador.h"

using namespace std;

class Coordinador : public Trabajador
{
private:
  int employeeID;
  enum class Tipo
  {
    CoordinadorCurso,
    CoordinadorMaterial
  };
  Tipo tipo_;

public:
  Coordinador(string dni, string name, string birthday, string surnames, string email, string address, int employeeID, Tipo tipo) : Trabajador(dni, name, birthday, surnames, email, address)
  {
    setEmployeeID(employeeID);
    setTipo(tipo);
  }

  inline int getEmployeeID() { return employeeID_; }
  inline bool setEmployeeID(int employeeID)
  {
    if (employeeID == 0)
    {
      return false;
    }
    employeeID_ = employeeID;
    return true;
  }

  inline Tipo getTipo() const { return tipo_; }
  inline void setTipo(Tipo tipo) { tipo_ = tipo; }
};
#endif
