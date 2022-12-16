// ESTÁ TODO BIEN

#ifndef PARTICIPANTE_H
#define PARTICIPANTE_H
#include <iostream>
#include <string>
using namespace std;

#include "../clasePersona/persona.h"

class Participante : public Persona
{
private:
  int identifier_;
  string password_, email_;

public:
  Participante(string dni, string name, string birthday, string surnames, int identifier, string password, string email) : Persona(dni, name, birthday, surnames)
  {
    setPassword(password);
    setEmail(email);
  }

  inline string getPassword() { return password_; }
  inline string getEmail() { return email_; }

  inline void setPassword(string password) { password_ = password; }
  inline void setEmail(string email) { email_ = email; }
};

#endif
