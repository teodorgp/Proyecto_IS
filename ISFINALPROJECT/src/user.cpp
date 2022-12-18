/*
 * user.cpp
 *
 *  Created on: Dec 17, 2022
 *      Author: vic
 */

#include "user.h"

user::user(string nombre, string correo, string password, string tipo, string cursosap) {
	this->nombre = nombre;
	this->correo = correo;
	this->password = password;
	this->tipo = tipo;
	this->cursosap= cursosap;

}

string user::getNombre()
{
    return nombre;
}

string user::getCorreo()
{
    return correo;
}

string user::getPassword()
{
    return password;
}

string user::getTipo()
{
    return tipo;
}

string user::getCursosAp(){
	return cursosap;
}

void user::setNombre(string nombre)
{
    this->nombre = nombre;
}

void user::setCorreo(string correo)
{
    this->correo = correo;
}

void user::setPassword(string password)
{
    this->password = password;
}

void user::setTipo(string tipo)
{
    this->tipo = tipo;
}

void user::setCursosAp(string cursosap){
	this->cursosap=cursosap;
}


