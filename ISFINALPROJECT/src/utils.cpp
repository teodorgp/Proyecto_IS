/*
 * utils.cpp
 *
 *  Created on: Dec 17, 2022
 *      Author: vic
 */

#include "utils.h"

#define passlenght 8

using namespace std;



void clearScreen(){
	system("clear");
}

void menuInicio(){

	int opt;
	vector<user> usuarios;
	vector<curso> cursos;

	do{
		cout<<"Bienvenido"<<endl;
		cout << "1. Iniciar sesión" << endl;
		cout << "2. Continuar sin iniciar sesion" << endl;
		cout << "0. Salir" << endl;
		cout << "Introduzca una opción: ";

		cin>>opt;

		switch(opt){
		case 1:
			usuarios.clear();
			openFile(usuarios);
			login(usuarios);
			break;
		case 2:
			menuVisitante();
			break;
		case 0:
			cout<<"Gracias por su visita"<<endl;
			break;
		default:
			cout<<"Opcion no valida"<<endl;
			break;
		}

	}while(opt!=0);
	exit(0);
}

void login(vector<user> usuarios){
	//clearScreen();

	  string correo;
	  string password;

	  cout << "Introduzca su correo: ";
	  cin >> correo;
	  cout << "Introduzca su contraseña: ";
	  cin >> password;

	  if (checkUser(usuarios, correo, password))
	  {
	    cout << "Bienvenido al sistema" << endl;
	    //Creamos un usuario especifico para el usuario que se ha logueado
	    user user = getUser(usuarios, correo, password);
	    //Comprobamos el tipo de usuario
	    checkType(user);
	  }
	  else
	  {
	    cout << "Usuario o contraseña incorrectos" << endl;
	  }
}

bool checkUser(vector<user> usuarios, string correo, string password){
  for (int i = 0; i < usuarios.size(); i++)
  {
    if (usuarios[i].getCorreo() == correo && usuarios[i].getPassword() == password)
    {
      return true;
    }
  }
  return false;
}

user getUser(vector<user> usuarios, string correo, string password){
  for (int i = 0; i < usuarios.size(); i++)
  {
    if (usuarios[i].getCorreo() == correo && usuarios[i].getPassword() == password)
    {
      return usuarios[i];
    }
  }
}

void checkType(user usuario){

  if(usuario.getTipo()=="0"){
    menuAdmin(usuario);
  }
  else if(usuario.getTipo()=="1"){
    menuCoordCursos(usuario);
  }
  else if(usuario.getTipo()=="2"){
      menuCoordRecursos(usuario);
    }
  else if(usuario.getTipo()=="3"){
      menuAlumno(usuario);
    }
}

void openFile(vector<user> &usuarios){

	  ifstream archivo("usuarios.txt");

	  string linea;

	  vector<string> datos;

	  if (archivo.is_open())
	  {
		while(getline(archivo, linea)) {
			  datos = split(linea, ',');
		        //Creamos un usuario con los datos del vector
		      user usuario(datos[0], datos[1], datos[2], datos[3],datos[4]);
		        //Añadimos el usuario al vector de usuarios
		      usuarios.push_back(usuario);
		      }
	  }
	  else
	  {
	    cout << "Error al abrir el archivo" << endl;
	  }
}

vector<string> split(string linea, char separador){

  vector<string> datos;

  string temp;

  for (int i = 0; i < linea.length(); i++)
  {

    if (linea[i] == separador)
    {

      datos.push_back(temp);

      temp = "";
    }
    else
    {

      temp += linea[i];
    }
  }

  datos.push_back(temp);

  return datos;
}

void menuVisitante(){

  clearScreen();
  int wait;
  cout<<"Bienvenido visitante"<<endl;
  cin>>wait;
}

void menuCoordCursos(user usuario){

  clearScreen();

  //Comprobamos que el usuario es un coordinador
  if(usuario.getTipo()=="1"){

    int opcion;

    cout<<"Vista: Coordinador de cursos"<<endl;
    cin>>opcion;

    switch(opcion){

    }

  }
}

void menuCoordRecursos(user usuario){

  clearScreen();

  //Comprobamos que el usuario es un coordinador
  if(usuario.getTipo()=="2"){

    int opcion;

    cout<<"Vista: Coordinador de recursos"<<endl;
    cin>>opcion;

    switch(opcion){

    }

  }
}

void menuAdmin(user usuario){

  clearScreen();

  //Comprobamos que el usuario es un administrador
  if(usuario.getTipo()=="0"){

    int opcion;

    cout<<"Vista: Administrador"<<endl;
    cin>>opcion;

    switch(opcion){

    }

  }
}

void menuAlumno(user usuario){

  clearScreen();

  //Comprobamos que el usuario es un Alumno
  if(usuario.getTipo()=="3"){
    cout<<"Vista: Alumno"<<endl;


	int opcion=99999;
	vector<curso> cursos;


	while(opcion!=0){
    	cout<<"¿Qué desea hacer?"<<endl;
    	cout<<"1.Ver listado de cursos"<<endl;
    	cout<<"2.Ver Mis Cursos"<<endl;
    	cout<<"3.Ver Mis Datos"<<endl;
    	cout<<"0.Salir"<<endl;

    	cin>>opcion;

    	switch(opcion){
    	case 1:
    		openCursos(cursos);
    		mostrarCursos(cursos,usuario);

    		break;
    	case 2:
    		verMisCursos(usuario,cursos);
    		break;
    	case 3:
    		cout<<"Implementar funcion"<<endl;
    		break;
    	case 0:
    		cout<<"Saliendo del sistema"<<endl;
    		break;
    	default:
    		cout<<"Seleccione una opcion"<<endl;
    		break;
    	}
    }

  }
}

void openCursos(vector<curso> &cursos){
	//Abrimos el archivo
	  ifstream archivo("cursos.txt");
	  //Creamos una variable para guardar los datos del archivo
	  string linea;
	  //Creamos un vector para guardar los datos de cada usuario
	  vector<string> datos;

	  //Comprobamos que el archivo se ha abierto correctamente
	  if (archivo.is_open())
	  {
	    //Leemos el archivo linea a linea
	    while (getline(archivo, linea))
	    {
	      //Separamos los datos de cada usuario
	      datos = split(linea, ',');
	      //Creamos un usuario con los datos del vector
	      curso curso(datos[0], datos[1], datos[2], datos[3], datos[4],datos[5],datos[6],datos[7],datos[8],datos[9]);
	      //Añadimos el usuario al vector de usuarios
	      cursos.push_back(curso);
	    }
	  }
	  else
	  {
	    cout << "Error al abrir el archivo" << endl;
	  }
}

void mostrarCursos(vector<curso> cursos, user usuario)
{

	vector<user> usuarios;
  //Funcion que muestra los cursos uno a uno y da a elegir opciones para cada curso
  for(int i = 0; i < cursos.size();)
  {
	cout << "---------------------------------" << endl;
    cout << "Nombre:" << cursos[i].getNombre() << endl;
    cout << "Descripcion:" << cursos[i].getDescripcion() << endl;
    cout << "Inicion:" << cursos[i].getFechaInicio() << endl;
    cout << "Fin:" << cursos[i].getFechaFin() << endl;
    cout << "Aforo total:" << cursos[i].getAforo() << endl;
    cout << "Plazas ocupadas" << cursos[i].getAforoActual()<<endl;
    cout << "Ponentes:" << cursos[i].getPonentes() << endl;
    cout << "Menciones:" << cursos[i].getMenciones() << endl;
    cout << "Requerimientos:" << cursos[i].getRequerimientos()<<endl;
    cout << "---------------------------------" << endl;

    int opcion;

    cout << "1. Inscribirse" << endl;
    cout << "2. Siguiente" << endl;
    cout <<"3. Anterior" <<endl;
    cout <<"0. Salir" <<endl;

    cin >> opcion;

    switch (opcion)
    {
    case 1:{
    	string id = cursos[i].getId();
    	inscripcion(usuario,id);
    	openFile(usuarios);
    	actualizarUsuario(usuario, usuarios);
    	volcarUsuarios(usuarios);
    }break;
    case 2:{

      if(i== cursos.size()-1){
        i=cursos.size()-1;
      }
      else{
        i++;
      }
    }break;
    case 3:{
      if(i==0){
        i=0;
      }
      else{
        i--;
      }
    }
      break;
    case 0:{
    	i=cursos.size()+1;
    }break;
    default:
      cout << "Opcion no valida" << endl;
      break;
    }
  }
}

void inscripcion(user &usuario, string idCurso){
	if(usuario.getCursosAp() == "-"){
		usuario.setCursosAp(idCurso);
	}
	else{
		usuario.setCursosAp(usuario.getCursosAp() + "-" +idCurso);
		//Funcion para volcar nuestro vector de usuarios en el fichero
	}
	cout<<"Te inscribiste con exito!"<<endl;
}

void volcarUsuarios(vector<user> usuarios)
{
  //Abrimos el archivo
  ofstream archivo("usuarios.txt");
  //Creamos una variable para guardar los datos del archivo
  string linea;

  //Comprobamos que el archivo se ha abierto correctamente
  if (archivo.is_open())
  {
    //Leemos el archivo linea a linea
    for (int i = 0; i < usuarios.size(); i++)
    {
      //Separamos los datos de cada usuario
      linea = usuarios[i].getNombre() + "," + usuarios[i].getCorreo() + "," + usuarios[i].getPassword() + "," + usuarios[i].getTipo() + "," + usuarios[i].getCursosAp();
      //Escribimos en el archivo
      archivo << linea << endl;
    }
  }
  else
  {
    cout << "Error al abrir el archivo" << endl;
  }
}

void actualizarUsuario(user &usuario, vector<user> &usuarios){
	for(int i = 0; i<usuarios.size(); i++){
		if(usuarios[i].getNombre()==usuario.getNombre()){
			usuarios[i].setCorreo(usuario.getCorreo());
			usuarios[i].setPassword(usuario.getPassword());
			usuarios[i].setCursosAp(usuario.getCursosAp());

		}
	}
}

void verMisCursos(user &usuario, vector<curso> curso){
	vector<string> cursos;
	string cursostotal;

	cursostotal=usuario.getCursosAp();
	cout<<"Cursos:"<<cursostotal;
	cursos=split(cursostotal,'-');

	for(int i = 0; i<cursos.size();){
		cout<<"----------------------"<<endl;
		findcurso(cursos[i], curso);

		cout<<"¿Que desea hacer?"<<endl;
		cout<<"1.Ver siguiente"<<endl;
		cout<<"2.Ver anterior"<<endl;
		cout<<"3.Dar de baja"<<endl;
		cout<<"0.Salir"<<endl;

		int op;
		cin>>op;

		switch(op){
		case 1:{
			if(i<cursos.size()-1){
				i++;
			}
			else{
				i=0;
			}
		}break;
		case 2:{
			if(i==0){
				i=0;
			}
			else{
				i--;
			}
		}break;
		case 3:{
			cout<<"Implementar dar de baja"<<endl;
		}break;
		case 0:{
			i=cursos.size();
		}break;
		default:{
			cout<<"Opcion no valida"<<endl;
		}break;
		}
	}
}

void findcurso(string curso_id, vector<curso>curso){
	for(int i = 0; i<curso.size(); i++){
		if(curso[i].getId()==curso_id){
			cout<<curso[i].getNombre()<<endl;
		}
	}
}
