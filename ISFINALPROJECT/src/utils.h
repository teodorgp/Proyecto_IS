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
bool checkCursos(vector<curso>cursos, string curso_id);
void ordenaCursos(user &usuario);
void limpiarfichero(string nombre);
void editarDatosUsuario(vector<user> vectorusuarios, user &usuario);
void mostrarlistaCursos(vector<curso>cursos);
void mostrarCurso(curso curso);
int stringToInt(string numero);
void ordenaVector(vector<int> &vector);
string intToString(int numero);
bool checkCursoUser(vector<string>cursosuser, string curso_id);
void bajaCursoUsuario(user &usuario, string idcurso);
void verCursosCoord(vector<curso>cursos, vector<user>&usuarios, user usuario);
void verParticipantesCurso(string cursoid, vector<user>usuarios);
void editarCurso(curso &curso);
void volcarCursos(vector<curso> cursos);
void borrarCurso(vector<curso> &cursos, string id);
void crearCursos(vector<curso>cursos);

#endif /* UTILS_H_ */
