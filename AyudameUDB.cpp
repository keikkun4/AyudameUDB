#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>

using namespace std;

/* AyudameUDB
 
Este programa se trabajo en la Universidad Don Bosco, como proyecto de catedra por las estudiantes:
1) Karla Lissette Hernández, HO122082, Ingeniería Biomédica.
2) Karla Lissette Mayora Claros, MC140395, Ingeniería Biomédica.
3) Allison Lisseth Vigil Argueta, VA130497, Ingeniería Ciencia de la Computación.
4) Sara Abigail Fuentes Mejía, FM140843, Ingeniería Industrial.

Descripcion del proyecto
Crear un programa de apoyo y verificación para estudiantes de antiguo y nuevo ingreso que les facilite 
el proceso de re-ingreso o ingreso y les guie paso a paso todo lo necesario para 
ser estudiante de la Universidad Don Bosco de El Salvador. */

#ifdef WIN32
  #define LimpiarPantalla system( "cls" );
#endif

#ifdef __linux__
  #define LimpiarPantalla system( "clear" );
#endif

char P;//Opcion del menu

void CrearArchivo();//crea el archivo por si las dudas
void LeerArchivo();

void CrearUsuario();

int main () {
 CrearArchivo();
 do{
  cout<<"Menu"<<endl;
  cout<<"1 - Ingresar"<<endl;
  cout<<"2 - Crear nuevo usuario"<<endl;
  cout<<"3 - Salir"<<endl;
  cin>>P;
  LimpiarPantalla;
  switch ( P ){
    case '1':
    cout<<"Ingrese su usuario"<<endl;
    break;
    case '2':
      CrearUsuario();
    break;
    case '3':
     cout<<"Gracias por usar nuestro sistema"<<endl;
    break;
    default:
     cout<<"No existe opcion, intente con otra"<<endl;
    break;
    }
 }while(P != '3');
}

void CrearArchivo(){
  ofstream fs("Nombres.txt");
  fs.close();
}

void CrearUsuario(){
  string Nombre;
  string Usuario;
  string Contrasena;
  char PP;
  do{
    cout<<"Nombre del estudiante"<<endl;  
    cin>>Nombre;
    cout<<"Nombre del estudiante"<<endl;
    cin>>Usuario;
    cout<<"Nombre del estudiante"<<endl; 
    cin>>Contrasena;
    cout<<"Nombre: "<<Nombre<<" Usuario: "<<Usuario<<" Contrasena: "<<Contrasena<<endl;
    cout<<"Seguro Y/N"<<endl;
    cin>>PP;
  }while(PP != 'Y');
  ifstream fe("nombre.txt");
}
