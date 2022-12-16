
// NO ESTÁ COMPLETO

// curso.h
// Save a curse information

#ifndef _CURSO_
#define _CURSO_ value

#include <iostream>
#include <string>
#include <list>

using std::list;
using std::string;

class Curso
{
private:
  int curseID_, capacity_;
  float success_;
  string nombre_, description_, start_date_, finish_date_, mentions_;
  list<string> ponentes_;            // Lista que almacena los ponentes que imparten un curso
  list<Participante> participantes_; // Lista que almacena los alumnos inscritos en el curso
  list<string> listaEsperaDNI_;      // Lista que almacena los alumnos que se encuntran en espera para acceder al curso

public:
  Curso(int curseID = 0, string nombre = "\0", string description = "\0", string start_date = "\0", string finish_date = "\0", int capacity = 0, string mentions = "\0", float success = 0.0);

  inline void setID(int curseID) { curseID_ = curseID; }
  inline int getID() const { return curseID_; }

  inline void setNombre(string nombre) { nombre_ = nombre; }
  inline string getNombre() const { return nombre_; }

  inline void setDescription(string description) { description_ = description; }
  inline string getDescription() const { return description_; }

  inline void setStartDate(string start_date) { start_date_ = start_date; }
  inline string getStartDate() const { return start_date_; }

  inline void setFinishDate(string finish_date) { finish_date_ = finish_date; }
  inline string getFinishDate() const { return finish_date_; }

  inline void setCapacity(int capacity) { capacity_ = capacity; }
  inline int getCapacity() const { return capacity_; }

  inline void setMentions(string mentions) { mentions_ = mentions; }
  inline string getMentions() const { return mentions_; }

  inline void setSuccess(float success) { success_ = success; }
  inline float getSuccess() const { return success_; }

  inline list<string> getPonentes() { return ponentes_; }

  inline list<string> getListaEsperaDNI() { return listaEsperaDNI_; }
};

#endif
