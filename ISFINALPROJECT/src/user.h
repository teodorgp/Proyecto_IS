/*
 * user.h
 *
 *  Created on: Dec 17, 2022
 *      Author: vic
 */

#ifndef USER_H_
#define USER_H_

#include <iostream>
#include <string>

using namespace std;

class user{
private:
	string nombre;
	string correo;
	string password;
	string tipo;
	string cursosap;
public:
	user(string nombre, string correo, string password, string tipo, string cursosap);
	user(){};

	string getNombre();
	string getCorreo();
	string getPassword();
	string getTipo();
	string getCursosAp();

	void setNombre(string nombre);
	void setCorreo(string correo);
	void setPassword(string password);
	void setTipo(string tipo);
	void setCursosAp(string cursosap);

};

#endif /* USER_H_ */
