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

//limpieza de pantalla para Windows y Linux
#ifdef WIN32
  #define LimpiarPantalla system( "cls" );
#endif

#ifdef __linux__
  #define LimpiarPantalla system( "clear" );
#endif

struct DatosEstudiantes{
  char Nombre[256];
  char Usuario[256];
  char Contrasena[256];
};

DatosEstudiantes Estudiantes[100];

int TotalEstudiantes = 0;
int NuevosEstudiantes = 0;

char P;//Opcion del menu
char PPP;

void CrearArchivo();//crea el archivo por si las dudas
void LeerArchivo();
void MostraArchivo();
void GuardarArchivo();
bool ExisteEstudiante();

void CrearUsuario();

int main () {
 LeerArchivo();
 //MostraArchivo();
 do{
  cout<<"Menu"<<endl;
  cout<<"1 - Ingresar"<<endl;
  cout<<"2 - Crear nuevo usuario"<<endl;
  cout<<"3 - Salir"<<endl;
  cin>>P;
  LimpiarPantalla;
  switch ( P ){
    case '1':
      if( ExisteEstudiante() ){
        do{
            cout<<"Menu"<<endl;
            cout<<"1 - Modificar hoja de vida "<<endl;
            cout<<"2 - Revisar pasos de ingreso"<<endl;
            cout<<"3 - Cerrar Sesion"<<endl;
            cin>>PPP;
          }while(PPP != '3');
        }
      else{
            cout<<"Error"<<endl;
        }
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
 GuardarArchivo();
}

void CrearArchivo(){
  ofstream fs("Nombres.txt");
  fs.close();
}

void CrearUsuario(){
  char PP;
  do{
    cout<<"Nombre del estudiante"<<endl;  
    scanf("%256s", Estudiantes[TotalEstudiantes+NuevosEstudiantes].Nombre);
    cout<<"Nombre del Usuario"<<endl;
    scanf("%256s", Estudiantes[TotalEstudiantes+NuevosEstudiantes].Usuario);
    cout<<"Nombre del Contrasena"<<endl; 
    scanf("%256s", Estudiantes[TotalEstudiantes+NuevosEstudiantes].Contrasena);
    cout<<"Nombre: "<<Estudiantes[TotalEstudiantes+NuevosEstudiantes].Nombre<<" Usuario: "<<Estudiantes[TotalEstudiantes+NuevosEstudiantes].Usuario<<" Contrasena: "<<Estudiantes[TotalEstudiantes+NuevosEstudiantes].Contrasena<<endl;
    cout<<"Seguro Y/N"<<endl;
    cin>>PP;
  }while(!(PP == 'Y' || PP == 'y'));
  NuevosEstudiantes++;
}

void LeerArchivo(){
  char linea[256];
  char *campo;
  FILE *pArchivo;
  
  pArchivo = fopen("datos.txt", "r");
   
  if (!pArchivo) return;
  while (fgets(linea, 256, pArchivo) != NULL) {
    campo = strtok(linea, " ,\n");
    sscanf(campo, "%s", Estudiantes[TotalEstudiantes].Nombre);
    
    campo = strtok(NULL, " ,\n");
    sscanf(campo, "%s", Estudiantes[TotalEstudiantes].Usuario);
    
    campo = strtok(NULL, " ,\n");
    sscanf(campo, "%s", Estudiantes[TotalEstudiantes].Contrasena);
    
    TotalEstudiantes++;
  }
  fclose(pArchivo);
}

void MostraArchivo(){
  cout<<"Nombre Usuario Controseña"<<endl;
  for (int i=0; i<TotalEstudiantes; i++) {
    cout<<Estudiantes[i].Nombre<<":"<<Estudiantes[i].Usuario<<":"<<Estudiantes[i].Contrasena<<endl;
  }
}

void GuardarArchivo(){
  FILE *pArchivo;
  pArchivo = fopen("datos.txt", "w");
  
   for (int i=0; i<TotalEstudiantes+NuevosEstudiantes; i++) {
      fprintf(pArchivo, "%s,",Estudiantes[i].Nombre);
      fprintf(pArchivo, "%s,",Estudiantes[i].Usuario);
      fprintf(pArchivo, "%s\n",Estudiantes[i].Contrasena);
   }
  
  fclose(pArchivo);
}

bool ExisteEstudiante(){
  char LogUsuario[256];
  char LogContrasena[256];

  cout<<"Ingrese su usuario"<<endl;
  cout<<"Nombre del estudiante"<<endl;  
  scanf("%256s", LogUsuario);
  cout<<"Nombre del contrasena"<<endl; 
  scanf("%256s", LogContrasena);
  
  for( int i = 0; i< TotalEstudiantes+NuevosEstudiantes; i++){
    if( strcmp( LogUsuario , Estudiantes[i].Usuario ) && strcmp( LogContrasena , Estudiantes[i].Contrasena) ){
      return true;
    }
  }
  return false;
}
