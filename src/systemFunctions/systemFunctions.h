
#ifndef SYSTEM_FUNCTIONS_H
#define SYSTEM_FUNCTIONS_H
#include <string>
#include "../claseAdministrador/administrativo.h"
using namespace std;

void clear();
bool dniIsValid(string dni);
bool existAdministrator(list<Administrativo> listOfAdministrators, string dni);
bool existCoordinator(list<Coordinador> listOfCoordinators, string dni);
void intro();
string login();
int whoIs(list<Administrativo> listOfAdministrators, list<Coordinador> listOfCoordinators,string dni);
int menuAdministrativo();
int menuMonitor();
void errorUserNotFound();
void shutDown();
int menuCursos();
int menuMateriales();
int menuParticipantes();
int menuTrabajadores();

