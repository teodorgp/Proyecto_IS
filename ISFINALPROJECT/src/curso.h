/*
 * Curso.h
 *
 *  Created on: Dec 17, 2022
 *      Author: vic
 */

#ifndef CURSO_H_
#define CURSO_H_

#include <iostream>
#include <string>

using namespace std;

class curso {
private:
	string id;
	string nombre;
	string descripcion;
	string fechaInicio;
	string fechaFin;
	string ponentes;
	string aforo;
	string aforoactual;
	string menciones;
	string requerimientos;
public:
	curso();
	curso(string id, string nombre, string descripcion, string fechaInicio, string fechaFin, string ponentes, string aforo, string aforoactual,string menciones, string requerimientos);
	string getId();
	string getNombre();
	string getDescripcion();
	string getFechaInicio();
	string getFechaFin();
	string getPonentes();
	string getAforo();
	string getAforoActual();
	string getMenciones();
	string getRequerimientos();
	void setId(string id);
	void setNombre(string nombre);
	void setDescripcion(string descripcion);
	void setFechaInicio(string fechaInicio);
	void setFechaFin(string fechaFin);
	void setPonentes(string ponentes);
	void setAforo(string aforo);
	void setAforoActual(string aforoactual);
	void setMenciones(string menciones);
	void setRequerimientos(string requerimientos);
};

#endif /* CURSO_H_ */
