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

char UsuarioActual[256] = "";

struct DatosEstudiantes{
  char Usuario[256];
  char Contrasena[256];
};

DatosEstudiantes Estudiantes[3];

int TotalEstudiantes = 0;
int NuevosEstudiantes = 0;

const char InstruccionesNI[] =
"Paso 1 -    \n"
"dgdsgdsg    \n"
"Lorem ipsum    \n"
"fkdds d   fdfdsf\n";


const char InstruccionesAI[] =
"";

void LeerArchivo();//Lee los estudiantes registrados al ingresar al programa
void GuardarArchivo();//Guarda todos los datos en el archivo de los estudiantes
bool iniciarSesion();//Solicita datos de usuario y retorna  verdadero si existen
void HojaDeVida();//Se guardan los datos necesarios del usuario para la ficha academica
void LeerHojaDeVida();//Se muestra el contenido de la hoja de vida del estudiante
void MostrarPasos();//Despliega los pasos a seguir en el proceso academico
void CrearUsuario();

int main () {
 char opc;//Opcion del menu principal
 char opc2;//Opcion de menu una vez ingrese sesion
 
 LeerArchivo();//Lee los estudiantes registrados al ingresar al programa
  
 do{
  cout<<"------------------------------------------------"<<endl;  
  cout<<"BIENVENIDO al Menu Principal de Ayudame UDB"<<endl;
  cout<<"------------------------------------------------"<<endl;  
  cout<<"<--- Seleccione una opcion del menu--->"<<endl;
  cout<<"1 - Iniciar Sesion"<<endl;
  cout<<"2 - Crear Nuevo Usuario"<<endl;
  cout<<"3 - Salir"<<endl;
  cin>>opc;
  LimpiarPantalla;
  switch ( opc ){
    
    //Inicio de sesion
    case '1':
      if( iniciarSesion() ){
        do{
            cout<<"---------------------------------------------"<<endl;  
            cout<<"Seleccione una opcion"<<endl;
            cout<<"---------------------------------------------"<<endl;
            cout<<"1 - Crear hoja de vida "<<endl;
            cout<<"2 - Leer hoja de vida "<<endl;
            cout<<"3 - Revisar pasos de ingreso"<<endl;
            cout<<"4 - Cerrar Sesion"<<endl;
            cin>>opc2;
            switch (opc2){
              //Modifica hoja de vida
              case '1':
                HojaDeVida();
                break;
              
              //Muestra lee hoja de vida
              case '2':
                LeerHojaDeVida();
                break;
                
              case '3':
                MostrarPasos();
                break;
                
              default:
                cout<<"Opcion no valida."<<endl;
                break;
            }
          }while(opc2 != '4');
        }
      else{
            cout<<"Ingreso mal sus datos. Vuelva a intentarlo."<<endl<<endl;         
        }
    break;
    
    //Creacion de nuevo usuario
    case '2':
      CrearUsuario();
    break;
    
    //Despedida del programa
    case '3':
     cout<<"Gracias por hacer uso de AYUDAME UDB."<<endl<<endl;
    break;
    
    default:
     cout<<"Opcion no valida."<<endl;
    break;
    }
 }while(opc != '3');
 GuardarArchivo();
}

void CrearUsuario(){
  char opc;
  do{
    cout<<"Ingrese sus datos para crear la cuenta"<<endl;
    cout<<"Usuario:"<<endl;
    scanf("%256s", Estudiantes[TotalEstudiantes+NuevosEstudiantes].Usuario);
    cout<<"Contrasena:"<<endl; 
    scanf("%256s", Estudiantes[TotalEstudiantes+NuevosEstudiantes].Contrasena);
    cout<<"--------------------------"<<endl;
    cout<<"Datos ingresados:"<<endl;
    cout<<"--------------------------"<<endl;
    cout<<"Usuario: "<<Estudiantes[TotalEstudiantes+NuevosEstudiantes].Usuario<<endl; 
    cout<<"Contrasena: "<<Estudiantes[TotalEstudiantes+NuevosEstudiantes].Contrasena<<endl<<endl;
    cout<<"Seguro S/N"<<endl;
    cin>>opc;
  }while(!(opc == 'S' || opc == 's'));
  NuevosEstudiantes++;
}

void LeerArchivo(){
  char linea[256];
  char *campo;
  FILE *pArchivo;
  
  pArchivo = fopen("datos.txt", "r"); //Abre el archivo en modo lectura
   
  if (!pArchivo) return;
  while (fgets(linea, 256, pArchivo) != NULL) {
    campo = strtok(linea, " ,\n");
    sscanf(campo, "%s", Estudiantes[TotalEstudiantes].Usuario);
    
    campo = strtok(NULL, " ,\n");
    sscanf(campo, "%s", Estudiantes[TotalEstudiantes].Contrasena);
    
    TotalEstudiantes++;
  }
  fclose(pArchivo);

  
//  for (int i=0; i<TotalEstudiantes; i++)
//    printf("%s, %s, %s\n", Estudiantes[i].Nombre, Estudiantes[i].Usuario, Estudiantes[i].Contrasena);
}

void GuardarArchivo(){
  FILE *pArchivo;
  pArchivo = fopen("datos.txt", "w"); //Abre el archivo modo escritura
  if (!pArchivo) return;              //Retorna en caso de no poder crearlo
  
   for (int i=0; i<TotalEstudiantes+NuevosEstudiantes; i++) {
      fprintf(pArchivo, "%s,",Estudiantes[i].Usuario);
      fprintf(pArchivo, "%s\n",Estudiantes[i].Contrasena);
   }
  
  fclose(pArchivo);
}

bool iniciarSesion(){
  char LogUsuario[256];
  char LogContrasena[256];

  cout<<"INICIO DE SESION"<<endl;
  cout<<"Usuario: "<<endl;  
  scanf("%256s", LogUsuario);
  cout<<"Contrasena: "<<endl; 
  scanf("%256s", LogContrasena);
  
  for( int i = 0; i< TotalEstudiantes+NuevosEstudiantes; i++){
 
    if( strcmp( LogUsuario , Estudiantes[i].Usuario )==0 && strcmp( LogContrasena , Estudiantes[i].Contrasena)==0 ){
      strcpy(UsuarioActual, LogUsuario);
      return true;
    }
  }
  return false;
}

void HojaDeVida(){
  char opc;
  char NombreArchivo[256];
  char campo[256];
  FILE *pArchivo;

  //Elabora la cadena con el archivo de texto que contendra la hoja de vida
  sprintf(NombreArchivo, "%s.txt", UsuarioActual);

  //Intenta abrir el archivo en modo lectura para saber si existe
  pArchivo = fopen(NombreArchivo, "r");

  if (pArchivo) {
    //Sabemos que el archivo existe, asi que se cierra
    fclose(pArchivo);

    cout<<"El archivo de hoja de vida ya existe. Desea sobre-escribirlo?"<<endl;
    cout<<"S/N"<<endl;
    cin>>opc;
    if (opc != 'S' && opc != 's') return;
  }

  //Abre el archivo de hoja de vida en modo de escritura
  pArchivo = fopen(NombreArchivo, "w");

  //En caso de no poder crear el archivo retorna
  if (!pArchivo) return;

  cout<<"HOJA DE VIDA" <<endl; 
  cout<<"Ingrese todos los datos que se le solicitan." <<endl; 
  cout<<"Primer Nombre: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, "Nombre: %s", campo);

  cout<<"Segundo Nombre: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, " %s", campo);
  
  cout<<"Primer Apellido: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, " %s", campo);
  
  cout<<"Segundo Apellido: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, " %s\n", campo);
  
  fclose(pArchivo);
}

void LeerHojaDeVida(){
  char NombreArchivo[256];
  char linea[256];
  FILE *pArchivo;
  
  //Elabora la cadena con el archivo de texto que contendra la hoja de vida
  sprintf(NombreArchivo, "%s.txt", UsuarioActual);

  pArchivo = fopen(NombreArchivo, "r"); //Abre el archivo en modo lectura
  if (!pArchivo) {
    cout<<"El archivo de hoja de vida no se pudo abrir o no existe"<<endl;
    return;
  }

  while (fgets(linea, 256, pArchivo) != NULL) {
    printf("%s\n", linea);
  }

  fclose(pArchivo);
}

void MostrarPasos(){
  char opc;
 cout<<"Es usted estudiante de Nuevo Ingreso: "<<endl;
 cout<<"S/N"<<endl;
 cin>>opc;
 
 if (opc == 'S')
  cout<<InstruccionesNI;
 else
  cout<<InstruccionesAI;
}