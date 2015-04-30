#include <cstdlib>
#include <iostream>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "stdio.h"
#define MAX 4
#define MIN 0
using namespace std;
                                     //SISTEMA DE REGISTRO DE USUARIOS 

//CONSTANTES
const char FINCAD = char(0);
const int MAXCAD = 20;

const char SP = ' ';
char contrasena;
int i;
int contador=0;
//TIPOS
typedef char TCadena[MAXCAD+1]; // MAXCAD caracteres + FINCAD
struct Persona_R
{
TCadena PASS;
};
// CABECERA DE PROCEDIMIENTOS Y FUNCIONES
void pausa();
void finalizar_programa();
void borrar_pantalla();
void Ingresar_PASS(Persona_R &p);
void confirmar_PASS(Persona_R &p);
// Algoritmos de Manejo de Ficheros de Texto
void insertarPersonaTXT(TCadena nombreFichero, Persona_R p);
void EscribePersonaFicheroTXT(ofstream &fichero, Persona_R p);
void verificar_existencia_fichero(TCadena nombreFichero);
void verificar_existencia_de_usuario(TCadena nombreFichero);
void verificar_contrasena(TCadena nombreFichero,Persona_R &password);

// PROGRAMA PRINCIPAL
int main()
{
Persona_R p;;
Persona_R password;;
char opcion;
int num;
bool fin,encontrado;
TCadena nombre_usuario_registrado;
int opcion_menu;
cout << "BIENVENIDOS A..." << endl;
cout << "----------------------------" << endl;
cout << "1. Ingresar como Usuario" << endl;
cout << "2. Registrarse" << endl;
cout << "3. Ingrersar como Visitante" << endl;
cout << "4. Salir del Programa." << endl;
cout << "----------------------------\n\n" << endl;
cout << "Introduzca Opcion:  ";
cin >> opcion_menu;
if (opcion_menu==4) {finalizar_programa();}
if((opcion_menu<MIN)||(opcion_menu>MAX)){        
try {        system("cls");
             cout<<"\n\n\t  ============================\n"
                 <<"\n\n\t | ESTA OPCION  ES INCORRECTA |\n"
                 <<"\n\n\t  ============================\n"; 
                 Sleep(1500);    //SEGUNDO Y MEDIO QUE DURA
                 system("cls"); //LIMPIA TODO  
                 main();//Y VUELVE AL MEN�  
    }//TRY
    catch(...)
	{cout << "\n UN ERROR HA OCURRIDO " << endl; } }  
	
switch(opcion_menu)
{
case 1: 
cout << "\nDigite su Nombre de Usuario:     ";//INGRESAR COMO USUARIO
cin >> nombre_usuario_registrado;
verificar_existencia_fichero(nombre_usuario_registrado);
//confirmar_PASS(password);
verificar_contrasena(nombre_usuario_registrado,password);
Sleep(1000);borrar_pantalla();main();
break;


case 2: 
cout << "\nEscriba su Nuevo Nombre de Usuario:    ";//REGISTRO
cin >> nombre_usuario_registrado;
verificar_existencia_de_usuario(nombre_usuario_registrado);
Ingresar_PASS(p);
insertarPersonaTXT(nombre_usuario_registrado,p);
Sleep(1000);borrar_pantalla();main();
break;

case 3: 
cout << "\nHOLA VISITANTE !!!... \n"; // Ingresar como visitante
Sleep(1500); borrar_pantalla();main();
break;
}
return 0;
}









// IMPLEMENTACI�N DE PROCEDIMIENTOS Y FUNCIONES
void finalizar_programa()
{
borrar_pantalla();     
printf("El Programa CERRARA en Cualquier Momento"); Sleep(3000);
exit(0);
}
void pausa()
{
system("PAUSE");
}
void borrar_pantalla()
{
system("CLS");
}
void Ingresar_PASS(Persona_R &p)
{
cout << "Escriba su Nuevo PASS:                 " ;
cin >> p.PASS;
cout<<"\nSE HA REGISTRADO CORRECTAMENTE"<<endl; Sleep(2500); 
}
void confirmar_PASS(Persona_R &password)
{
cout << "Escriba su PASS:                 " ;
cin >> password.PASS;
}

// Algoritmos de Manejo de Ficheros de Texto
void insertarPersonaTXT(TCadena nombreFichero, Persona_R p)
{
ofstream out;
out.open(nombreFichero,ios::app);
// Abro el fichero para a�adir
if (out.bad()){
// El fichero no existe ... lo creo
out.open(nombreFichero);}	
EscribePersonaFicheroTXT(out,p);
out.close();
}

void EscribePersonaFicheroTXT(ofstream &fichero, Persona_R p)
{
fichero << p.PASS << SP;
}

void verificar_existencia_fichero(TCadena nombreFichero)
{
	    ifstream archivo(nombreFichero); 
    if (!archivo)
    {    
          cout<<"\nNombre de Usuario INCORRECTO.....INTENTELO DE NUEVO\n"<<endl; Sleep(2500); borrar_pantalla();main();  
    }
             else 
             {
              cout<<"\nNombre de Usuario CORRECTO..!!!\n"<<endl;Sleep(2500);     
              } 
}

void verificar_existencia_de_usuario(TCadena nombreFichero)
{
    ifstream archivo(nombreFichero); 
    if (!archivo)
    {
             cout<<"\nNombre de Usuario DISPONIBLE\n"<<endl;Sleep(2500);
             }
             else 
             {
             cout<<"\n Este Nombre de Usuario ya Existe.....INTENTELO DE NUEVO"<<endl; Sleep(2500); borrar_pantalla();main();      
             }   
}

void verificar_contrasena(TCadena nombreFichero,Persona_R &password)
{
string cadena;
string contrase;
cout << "Escriba su PASS:                 " ;
cin >> password.PASS;
ifstream fichero(nombreFichero,ios::in);	
   
   while(!fichero.eof()) {                 
      fichero >> cadena;   
      //cadena = strstr (fichero,"simple");
  
  }
  if(cadena!=password.PASS){
  cout<<"\n PASS es INCORRECTO.....INTENTELO DE NUEVO\n"<<endl;Sleep(2000);
  fichero.close();}
  
if(cadena==password.PASS){
cout<<"\n Su PASS es CORRECTA..!!! \n"<<endl; Sleep(2500);
cout<<"\n BIENVENIDO..!!! \n"<<endl; Sleep(2500);
}
}
