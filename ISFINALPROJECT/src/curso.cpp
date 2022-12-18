/*
 * Curso.cpp
 *
 *  Created on: Dec 17, 2022
 *      Author: vic
 */

#include "curso.h"

curso::curso()
{
}

curso::curso(string id, string nombre, string descripcion, string fechaInicio, string fechaFin, string ponentes, string aforo, string aforoactual,string menciones, string requerimientos)
{
    this->id = id;
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->fechaInicio = fechaInicio;
    this->fechaFin = fechaFin;
    this->ponentes = ponentes;
    this->aforo = aforo;
    this->aforoactual = aforoactual;
    this->menciones = menciones;
    this->requerimientos = requerimientos;
}

string curso::getId()
{
    return id;
}

string curso::getNombre()
{
    return nombre;
}

string curso::getDescripcion()
{
    return descripcion;
}

string curso::getFechaInicio()
{
    return fechaInicio;
}

string curso::getFechaFin()
{
    return fechaFin;
}

string curso::getPonentes()
{
    return ponentes;
}

string curso::getAforo()
{
    return aforo;
}

string curso::getAforoActual()
{
	return aforoactual;
}

string curso::getMenciones()
{
    return menciones;
}

string curso::getRequerimientos()
{
	return requerimientos;
}

void curso::setId(string id)
{
    this->id = id;
}

void curso::setNombre(string nombre)
{
    this->nombre = nombre;
}

void curso::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}

void curso::setFechaInicio(string fechaInicio)
{
    this->fechaInicio = fechaInicio;
}

void curso::setFechaFin(string fechaFin)
{
    this->fechaFin = fechaFin;
}

void curso::setPonentes(string ponentes)
{
    this->ponentes = ponentes;
}

void curso::setAforo(string aforo)
{
    this->aforo = aforo;
}

void curso::setAforoActual(string aforoactual)
{
	this->aforoactual = aforoactual;
}

void curso::setMenciones(string menciones)
{
    this->menciones = menciones;
}

void curso::setRequerimientos(string requerimientos)
{
	this->requerimientos = requerimientos;
}

