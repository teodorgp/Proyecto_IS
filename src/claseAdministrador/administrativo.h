// NO ESTÁ COMPLETO

#ifndef ADMINISTRATIVO_H
#define ADMINISTRATIVO_H
#include <iostream>

#include "../claseCoordinador/coordinador.h"
#include "../claseParticipante/participante.h"
#include "../claseTrabajador/trabajador.h"
#include "../claseMaterial/material.h"
#include "../claseCurso/curso.h"

class Administrativo : public Trabajador
{
public:
  Administrativo(string dni, string name, string birthday, string surnames, string email, string address) : Trabajador(dni, name, birthday, surnames, email, address){};

  bool addCurse(list<Curso> &listOfCurses, int curseID);
  bool editCurse(list<Curso> &listOfCurses, int curseID);
  Curso viewCurse(list<Curso> &listOfCurses, int curseID);

  bool addMaterial(list<Material> &listOfMaterials, int curseID, int MaterialID);
  bool editMaterial(list<Material> &listOfMaterials, int curseID, int MaterialID);
  bool deleteMaterial(list<Material> &listOfMaterials, int curseID, int MaterialID);
  Material viewMaterial(list<Material> &listOfMaterials, int mcurseID, int MaterialID);

  bool addCoordinador(list<Coordinador> &listOfCoordinadors, string dni);
  bool editCoordinador(list<Coordinador> &listOfCoordinadors, string dni);
  bool deleteCoordinador(list<Coordinador> &listOfCoordinadors, string dni);
  Coordinador viewCoordinador(list<Coordinador> &listOfCoordinadors, string dni);

  bool addAdministrator(list<Administrativo> &listOfAdministrators, string dni);
  bool editAdministrator(list<Administrativo> &listOfAdministrators, string dni);
  bool deleteAdministrator(list<Administrativo> &listOfAdministrators, string dni);
  Administrativo viewAdministrator(list<Administrativo> &listOfAdministrators, string dni);

  bool addParticipante(list<Participante> &listOfParticipantes, string dni);
  bool editParticipante(list<Participante> &listOfParticipantes, string dni);
  bool deleteParticipante(list<Participante> &listOfParticipantes, string dni);
  Participante viewParticipante(list<Participante> &listOfParticipantes, string dni);

  bool addParticipanteToCurse(list<Curso> &listOfCurses, int courseID, string dni);
  bool deleteParticipanteFromCourse(list<Curso> &listOfCurses, int curseID, string dni);
};
#endif
