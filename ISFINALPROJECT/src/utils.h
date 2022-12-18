/*
 * utils.h
 *
 *  Created on: Dec 17, 2022
 *      Author: vic
 */

#ifndef UTILS_H_
#define UTILS_H_



#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <sstream>

//Incluimos user.h para poder usar la clase Usuario
#include "user.h"
#include "curso.h"

using namespace std;

void menuInicio();

void login(vector<user> usuarios);
bool checkUser(vector<user> usuarios, string correo, string password);
user getUser(vector<user> usuarios, string correo, string password);
void openFile(vector<user> &usuarios);
vector<string> split(string linea, char separador);
void checkType(user usuario);
void menuVisitante();
void menuCoordCursos(user usuario);
void menuCoordRecursos(user usuario);
void menuAdmin(user usuario);
void clearScreen();
void menuAlumno(user usuario);
void openCursos(vector<curso> &cursos);
void mostrarCursos(vector<curso> cursos,user usuario);
void inscripcion(user &usuario, string idCurso);
void volcarUsuarios(vector<user> usuarios);
void actualizarUsuario(user &usuario, vector<user> &usuarios);
void verMisCursos(user &usuario, vector<curso> curso);
void findcurso(string curso_id, vector<curso>curso);

#endif /* UTILS_H_ */
