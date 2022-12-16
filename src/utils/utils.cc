//Archivo para simular utilidades de nuestro programa

#include "utils.h"

using namespace std;

//Valores por defecto
#define passlength 8

//Funcion para generar contraseñas aleatorias
string generatePassword()
{
  string password;
  char character;
  int random;

  for (int i = 0; i < passlength; i++)
  {
    random = rand() % 3;
    switch (random)
    {
      case 0:
        character = rand() % 10 + 48;
        break;
      case 1:
        character = rand() % 26 + 65;
        break;
      case 2:
        character = rand() % 26 + 97;
        break;
    }
    password += character;
  }

  //Muestro por pantalla la contraseña
    cout << "La contraseña generada es: " << password << endl;
    cout << "Por favor, recuerde cambiarla lo antes posible." << endl;
    cout << "Presione cualquier tecla para continuar..." << endl;
    cin.ignore();

  return password;

  //Cada vez que se genere una contraseña se borrará la terminal
}