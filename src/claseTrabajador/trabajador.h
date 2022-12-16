// NO ESTÁ COMPLETO

#ifndef TRABAJADOR_H
#define TRABAJADOR_H
#include <iostream>
#include <string>
#include <list>
#include "../clasePersona/persona.h"
#include "../claseParticipante/participante.h"
#include "../claseMaterial/material.h"
#include "../claseCurso/curso.h"
using namespace std;

class Trabajador : public Persona
{
private:
  string email_;
  string address_;

public:
  Trabajador(string dni, string name, string birthday, string surnames, string email, string address) : Persona(dni, name, birthday, surnames)
  {
    setEmail(email);
    setAddress(address);
  }

  string getAddress() { return address_; }
  string getEmail() { return email_; }

  inline bool setAddress(string address)
  {
    if (address.empty())
    {
      return false;
    }
    address_ = address;
    return true;
  }
  inline bool setEmail(string email)
  {
    if (email.empty())
    {
      return false;
    }
    email_ = email;
    return true;
  }

  bool addMaterial(list<Material> &listOfMaterials, int curseID, int MaterialID);
  bool editMaterial(list<Material> &listOfMaterials, int curseID, int MaterialID);

  bool addParticipante(list<Participante> &listOfParticipantes, string dni);
  Participante viewParticipante(list<Participante> &listOfParticipantes, string dni);

  bool addCurse(list<Curso> &listOfCurses, int curseID);
  bool editCurse(list<Curso> &listOfCurses, int curseID);
  Curso viewCurso(list<Curso> &listOfCurses, int coureID);
};
#endif
