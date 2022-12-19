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
  vector<user>usuarios;
  openFile(usuarios);

  vector<curso>cursos;
  openCursos(cursos);

  //Comprobamos que el usuario es un coordinador
  if(usuario.getTipo()=="1"){

	  int opcion=0;

	      cout<<"Vista: Coordinador de Cursos"<<endl;
	      cout<<"--------------------------"<<endl;
	      cout<<"1.Ver listado de cursos (dentro de aqui van: 1. ver participantes 2. editarlo 3.dar de baja)"<<endl;
	      cout<<"2.Añadir un nuevo curso"<<endl;
	      cout<<"3.Ver mis datos"<<endl;
	      cout<<"0.Salir"<<endl;
	      cin>>opcion;

	      switch(opcion){
	      case 1:
	    	  verCursosCoord(cursos, usuarios, usuario);
	      	break;
	      case 2:
	      	cout<<"Por desarrollar"<<endl;
	      	break;
	      case 3:
	      	editarDatosUsuario(usuarios,usuario);
	      	break;
	      case 0:
	      	menuInicio();
	      	break;
	      default:
	      	cout<<"Por favor, seleccione un opcion"<<endl;
	      	menuCoordCursos(usuario);
	      }

  }
}

void menuCoordRecursos(user usuario){

  clearScreen();
  vector<user>usuarios;
  openFile(usuarios);

  //Comprobamos que el usuario es un coordinador
  if(usuario.getTipo()=="2"){

    int opcion=0;

    cout<<"Vista: Coordinador de Recursos"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"1.Ver listado de cursos (dentro de aqui van: 1. ver participantes 2. editarlo 3.dar de baja)"<<endl;
    cout<<"2.Añadir un nuevo curso"<<endl;
    cout<<"3.Ver mis datos"<<endl;
    cout<<"0.Salir"<<endl;
    cin>>opcion;

    switch(opcion){
    case 1:
    	cout<<"Por desarrollar"<<endl;
    	break;
    case 2:
    	cout<<"Por desarrollar"<<endl;
    	break;
    case 3:
    	editarDatosUsuario(usuarios,usuario);
    	break;
    case 0:
    	menuInicio();
    	break;
    default:
    	cout<<"Por favor, seleccione un opcion"<<endl;
    	menuCoordRecursos(usuario);
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
	openCursos(cursos);

	vector<user> usuarios;
	openFile(usuarios);


	while(opcion!=0){
    	cout<<"¿Qué desea hacer?"<<endl;
    	cout<<"1.Ver listado de cursos"<<endl;
    	cout<<"2.Ver Mis Cursos"<<endl;
    	cout<<"3.Ver Mis Datos"<<endl;
    	cout<<"0.Salir"<<endl;

    	cin>>opcion;

    	switch(opcion){
    	case 1:

    		mostrarCursos(cursos,usuario);

    		break;
    	case 2:

    		verMisCursos(usuario,cursos);
    		break;
    	case 3:
    		editarDatosUsuario(usuarios,usuario);
    		break;
    	case 0:
    		cout<<"Saliendo del sistema"<<endl;
    		break;
    	default:
    		cout<<"Seleccione una opcion"<<endl;
    		break;
    	}
    }
	menuInicio();
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
	openFile(usuarios);
  //Funcion que muestra los cursos uno a uno y da a elegir opciones para cada curso
  for(int i = 0; i < cursos.size();)
  {
	  mostrarCurso(cursos[i]);

    int opcion;

    cout << "1. Inscribirse" << endl;
    cout << "2. Siguiente" << endl;
    cout <<"3. Anterior" <<endl;
    cout <<"0. Salir" <<endl;

    cin >> opcion;

    switch (opcion)
    {
    case 1:{
    	cout<<"Sigue dando algun que otro error"<<endl;
    	string id = cursos[i].getId();
    	inscripcion(usuario,id);
    	actualizarUsuario(usuario, usuarios);
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
  volcarUsuarios(usuarios);
  menuAlumno(usuario);
}

void inscripcion(user &usuario, string idCurso){
	if(usuario.getCursosAp() == "-"){
		usuario.setCursosAp(idCurso);
	}
	else{

		string cursostotal = usuario.getCursosAp();
		vector<string> cursossplit;
		cursossplit = split(cursostotal, '-');

		if(checkCursoUser(cursossplit, idCurso)){
			usuario.setCursosAp(usuario.getCursosAp() + "-" +idCurso);
			ordenaCursos(usuario);
			cout<<"Te inscribiste con exito!"<<endl;
		}
		else{
			cout<<"Ya estás inscrito"<<endl;
		}

	}

}

void volcarUsuarios(vector<user> usuarios)
{

	//Limpio el fichero
	limpiarfichero("usuarios.txt");
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

	cout<<"Na mas entra "<<usuario.getCursosAp()<<endl;

	vector<user>usuarios;
	openFile(usuarios);

	string cursostotal = usuario.getCursosAp();
	vector<string> cursosuser;
	cursosuser = split(cursostotal, '-');

	for(int i = 0; i<cursosuser.size();){
		if(checkCursos(curso,cursosuser[i])){
			mostrarCurso(curso[i]);

			cout<<"1.Ver siguiente"<<endl;
			cout<<"2.Ver anterior"<<endl;
			cout<<"3.Dar de baja"<<endl;
			cout<<"0.Salir"<<endl;

			int opt;
			cin>>opt;

			switch(opt){
			case 1:{
				if (i == cursosuser.size()-1){
					i=0;
				}
				else{
					i++;
				}
			}break;
			case 2:{
				if(i==0){
					i=cursosuser.size()-1;
				}
				else{
					i--;
				}
			}break;
			case 3:{
				bajaCursoUsuario(usuario,curso[i].getId());
				actualizarUsuario(usuario, usuarios);
				volcarUsuarios(usuarios);
				menuAlumno(usuario);
			}break;
			case 0:{
				menuAlumno(usuario);
			}break;
			default:{
				cout<<"Por favor, seleccione una opcion"<<endl;
			}break;
			}
		}
		else{
			i++;
		}
	}

}

bool checkCursos(vector<curso>cursos, string curso_id){

	for(int i = 0; i<cursos.size(); i++){
		if(curso_id==cursos[i].getId()){
			return true;
		}
	}
	return false;
}

void ordenaCursos(user &usuario){
	string cursostotal = usuario.getCursosAp();
	vector<string> cursossplit;
	cursossplit = split(cursostotal, '-');

	vector<int>cursosint;

	for(int j=0; j<cursossplit.size(); j++){
		int num = stringToInt(cursossplit[j]);
		cursosint.push_back(num);
	}

	ordenaVector(cursosint);

	string cursosordenados=intToString(cursosint[0]);

	for(int i = 1; i<cursosint.size(); i++){
		string aux = intToString(cursosint[i]);
		cursosordenados = cursosordenados + "-" + aux;
	}

	usuario.setCursosAp(cursosordenados);
}

void limpiarfichero(string nombre){
	ofstream archivo(nombre);
	archivo.close();
}

void editarDatosUsuario(vector<user> vectorusuarios, user &usuario){
	cout<<"------------------------"<<endl;
	cout<<"correo: "<<usuario.getCorreo()<<endl;
	cout<<"contraseña: "<<usuario.getPassword()<<endl;

	cout<<"\n¿Que desea hacer?"<<endl;
	cout<<"1.Editar Contraseña"<<endl;
	cout<<"0.Salir"<<endl;
	int opt;
	cin>>opt;

	if(opt==1){
		cout<<"Ingrese su nueva contraseña"<<endl;
		string passnew;
		cin>>passnew;
		usuario.setPassword(passnew);
		actualizarUsuario(usuario,vectorusuarios);
		volcarUsuarios(vectorusuarios);
		editarDatosUsuario(vectorusuarios,usuario);
	}
	else if(opt==0){
		menuAlumno(usuario);
	}
	else{
		cout<<"Por favor, seleccione una opción"<<endl;
		editarDatosUsuario(vectorusuarios,usuario);
	}
}

void mostrarlistaCursos(vector<curso>cursos){
	for(int i = 0; i<cursos.size(); i++){
		cout << "---------------------------------" << endl;
		    cout << "Nombre:" << cursos[i].getNombre() << endl;
		    cout << "Descripcion:" << cursos[i].getDescripcion() << endl;
		    cout << "Inicion:" << cursos[i].getFechaInicio() << endl;
		    cout << "Fin:" << cursos[i].getFechaFin() << endl;
		    cout << "Aforo total:" << cursos[i].getAforo() << endl;
		    cout << "Plazas ocupadas: " << cursos[i].getAforoActual()<<endl;
		    cout << "Ponentes:" << cursos[i].getPonentes() << endl;
		    cout << "Menciones:" << cursos[i].getMenciones() << endl;
		    cout << "Requerimientos:" << cursos[i].getRequerimientos()<<endl;
		    cout << "---------------------------------" << endl;
	}
}

void mostrarCurso(curso curso){
	cout << "---------------------------------" << endl;
	cout << "Nombre:" << curso.getNombre() << endl;
	cout << "Descripcion:" << curso.getDescripcion() << endl;
	cout << "Inicion:" << curso.getFechaInicio() << endl;
	cout << "Fin:" << curso.getFechaFin() << endl;
	cout << "Aforo total:" << curso.getAforo() << endl;
	cout << "Plazas ocupadas: " << curso.getAforoActual()<<endl;
	cout << "Ponentes:" << curso.getPonentes() << endl;
	cout << "Menciones:" << curso.getMenciones() << endl;
	cout << "Requerimientos:" << curso.getRequerimientos()<<endl;
	cout << "---------------------------------" << endl;
}

int stringToInt(string numero)
{
  int numeroInt = 0;
  for (int i = 0; i < numero.length(); i++)
  {
    numeroInt = numeroInt * 10 + (numero[i] - '0');
  }
  return numeroInt;
}

void ordenaVector(vector<int> &vector){
	int aux;
	  for(int i=0; i<vector.size(); i++){
	    for(int j=0; j<vector.size(); j++){
	      if(vector[i]<vector[j]){
	        aux=vector[i];
	        vector[i]=vector[j];
	        vector[j]=aux;
	      }
	    }
	  }
}

string intToString(int numero){
  stringstream ss;
  ss << numero;
  string str = ss.str();
  return str;
}

bool checkCursoUser(vector<string>cursosuser, string curso_id){
	for(int i = 0; i<cursosuser.size(); i++){
		if(cursosuser[i]==curso_id){
			return false;
		}
	}
	return true;
}

void bajaCursoUsuario(user &usuario, string idcurso){

	cout<<"Curso id: "<<idcurso<<endl;

	string cursostotal = usuario.getCursosAp();
	vector<string> cursossplit;
	cursossplit = split(cursostotal, '-');

	for(int i = 0; i<cursossplit.size(); i++){
		if(cursossplit[i]==idcurso){
			cursossplit.erase(cursossplit.begin()+1);
		}
		cout<<"Cursos split: "<<cursossplit[i]<<endl;
	}

	string cursosnuevo = cursossplit[0];
	for(int i = 1; i<cursossplit.size(); i++){
		cursosnuevo=cursosnuevo + "-" + cursossplit[i];
	}
	cout<<"Cursos nuevos:"<<cursosnuevo<<endl;

	usuario.setCursosAp(cursosnuevo);
}

void verCursosCoord(vector<curso>cursos, vector<user>&usuarios, user usuario){
	for(int i = 0; i<cursos.size(); i++){
		mostrarCurso(cursos[i]);

		cout<<"1.Mostrar siguiente"<<endl;
		cout<<"2.Mostrar anterior"<<endl;
		cout<<"3.Ver participantes"<<endl;
		cout<<"4.Editar curso"<<endl;
		cout<<"5.Dar de baja"<<endl;

		int opt;
		cin>>opt;

		switch(opt){
		case 1:{
			if(i==cursos.size()-1){
				i=0;
			}
			else{
				i++;
			}
		}break;
		case 2:{
			if(i==0){
				i=cursos.size()-1;
			}
			else{
				i--;
			}
		}break;
		case 3:{
			verParticipantesCurso(cursos[i].getId(), usuarios);
			verCursosCoord(cursos,usuarios,usuario);
		}break;
		case 4:{
			editarCurso(cursos[i]);
			volcarCursos(cursos);
		}break;
		case 5:{
			borrarCurso(cursos,cursos[i].getId());
			volcarCursos(cursos);
		}break;
		default:{
			crearCursos(cursos);
		}break;
		}
	}
	menuCoordCursos(usuario);
}

void verParticipantesCurso(string cursoid, vector<user>usuarios){
	int count = 0;
	for(int i = 0; i<usuarios.size(); i++){
		string cursosuser = usuarios[i].getCursosAp();
		vector<string> cursosvector =split(cursosuser,'-');
		for(int j = 0; j<cursosvector.size(); j++){
			if(cursosvector[j]==cursoid){
				count ++;
				cout<<"---------------------------------"<<endl;
				cout<<"Participante "<<count<<": "<<usuarios[i].getNombre()<<endl;
				cout<<"---------------------------------"<<endl;
				cout<<"Acciones:"<<endl;
				cout<<"1.Ver siguiente participante"<<endl;
				cout<<"2.Dar de baja"<<endl;
				cout<<"3.Salir de este curso"<<endl;

				int opt;
				if(opt==2){
					bajaCursoUsuario(usuarios[i],cursoid);
					actualizarUsuario(usuarios[i],usuarios);
					volcarUsuarios(usuarios);
				}
				if(opt ==3){
					i=usuarios.size();
				}
			}
		}

	}
}

void editarCurso(curso &curso){
	mostrarCurso(curso);

	cout<<"1.Cambiar nombre"<<endl;
	cout<<"2.Cambiar descripcion"<<endl;
	cout<<"3.Cambiar fecha inicio"<<endl;
	cout<<"4.Cambiar fecha fin"<<endl;
	cout<<"5.Cambiar ponentes"<<endl;
	cout<<"6.Cambiar menciones"<<endl;
	cout<<"7.Cambiar requerimientos"<<endl;
	cout<<"0.Salir"<<endl;

	int opt;
	cin>>opt;

	while(opt!=0){
		switch(opt){
		case 1:{
			cout<<"Introduzca el nuevo nombre"<<endl;
			string newname;
			curso.setNombre(newname);
		}break;
		case 2:{
			cout<<"Introduzca la nueva descripción"<<endl;
			string newdesc;
			curso.setDescripcion(newdesc);
		}break;
		case 3:{
			cout<<"Introduzca la nueva fecha de inicio"<<endl;
			string newfechin;
			curso.setFechaInicio(newfechin);
		}break;
		case 4:{
			cout<<"Introduzca la nueva fecha de fin"<<endl;
			string newfechfin;
			curso.setFechaFin(newfechfin);
		}break;
		case 5:{
			cout<<"Introduzca los ponentes que van a participar"<<endl;
			string newpon;
			curso.setPonentes(newpon);
		}break;
		case 6:{
			cout<<"Introduzca las menciones del curso"<<endl;
			string newmen;
			curso.setMenciones(newmen);
		}break;
		case 7:{
			cout<<"Introduzca los nuevos requerimientos"<<endl;
			string newreq;
			curso.setRequerimientos(newreq);
		}break;
		case 0:
			cout<<"Saliendo..."<<endl;
			break;
		default:
			cout<<"Escoja una opcion valida"<<endl;
			break;
	}

	}
}

void volcarCursos(vector<curso> cursos)
{

	//Limpio el fichero
	limpiarfichero("cursos.txt");
	//Abrimos el archivo
	ofstream archivo("cursos.txt");
	//Creamos una variable para guardar los datos del archivo
	string linea;

	//Comprobamos que el archivo se ha abierto correctamente
	if (archivo.is_open())
	{
		//Leemos el archivo linea a linea
		for (int i = 0; i < cursos.size(); i++)
		{
		  //Separamos los datos de cada usuario
		  linea = cursos[i].getId() + "," + cursos[i].getNombre() + "," + cursos[i].getDescripcion() + "," + cursos[i].getFechaInicio() + "," + cursos[i].getFechaFin() + "," + cursos[i].getPonentes() + "," + cursos[i].getAforo() + "," + cursos[i].getAforoActual() + "," + cursos[i].getMenciones() + "" + cursos[i].getRequerimientos();
		  //Escribimos en el archivo
		  archivo << linea << endl;
		}
	}
	else
	{
		cout << "Error al abrir el archivo" << endl;
	}
}

void borrarCurso(vector<curso> &cursos, string id)
{
  for (int i = 0; i < cursos.size(); i++)
  {
    if (cursos[i].getId() == id)
    {
      cursos.erase(cursos.begin() + i);
    }
  }

  //Aqui habria que reasignar ids y cotejar con los usuarios y toda la pesca
}

void crearCursos(vector<curso>cursos){
	curso curso;

	//Le asignamos id:
	curso.setId(intToString(cursos.size()+1));

	cout<<"Introduzca el nombre"<<endl;
	string nombre;
	cin>>nombre;
	curso.setNombre(nombre);

	cout<<"Introduzca una descripcion"<<endl;
	string desc;
	cin>>desc;
	curso.setDescripcion(desc);

	cout<<"Introduzca la fecha de inicio"<<endl;
	string fechaini;
	cin>>fechaini;
	curso.setFechaInicio(fechaini);

	cout<<"Introduzca la fecha final"<<endl;
	string fechafin;
	cin>>fechafin;
	curso.setFechaFin(fechafin);

	cout<<"Introduzca los ponentes"<<endl;
	string ponentes;
	cin>>ponentes;
	curso.setPonentes(ponentes);

	cout<<"Introduzca el aforo maximo"<<endl;
	string aforomax;
	cin>>aforomax;
	curso.setAforo(aforomax);
	curso.setAforoActual("0");

	curso.setMenciones("0");

	cout<<"Introduzca los requisitos"<<endl;
	string req;
	cin>>req;
	curso.setRequerimientos(req);

	cursos.push_back(curso);
	volcarCursos(cursos);

}
