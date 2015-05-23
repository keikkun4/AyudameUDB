#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
//#include <windows.h>

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

void LeerArchivo();         //Lee los estudiantes registrados al ingresar al programa
void GuardarArchivo();      //Guarda todos los datos en el archivo de los estudiantes
bool iniciarSesion();       //Solicita datos de usuario y retorna  verdadero si existen
void HojaDeVida();          //Se guardan los datos necesarios del usuario para la ficha academica
void LeerHojaDeVida();      //Se muestra el contenido de la hoja de vida del estudiante
void MostrarPasos();        //Despliega los pasos a seguir en el proceso academico
void CrearUsuario();        //Ingreso de datos de Usuario y contraseña para accesar al sistema
void InstruccionesNI();     //Aqui estan desplegadas todas los pasos a seguir para Nuevo Ingreso
void InstruccionesAI();     //Aqui estan desplegadas todos los pasos a seguir para Antiguo Ingreso

int main () {
 char opc;   //Opcion del menu principal
 char opc2;  //Opcion de menu una vez ingrese sesion
 
 LeerArchivo();     //Lee los estudiantes registrados al ingresar al programa
  
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
            cout<<"Te recomendamos llenes la hoja de vida primero, para que reunas de antemano\ntoda la documentacion que necesitas.\n"<<endl;
            cout<<"1 - Crear hoja de vida "<<endl;
            cout<<"2 - Leer hoja de vida "<<endl;
            cout<<"3 - Revisar pasos de ingreso"<<endl;
            cout<<"4 - Cerrar Sesion"<<endl;
            cin>>opc2;
            LimpiarPantalla;
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
 
 //system ("pause");
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
  
  cout<<"Correo Electronico: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, "Correo Electronico: %s\n", campo);
  
  cout<<"Telefono Fijo o Movil: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, "Telefono Fijo o Movil: %s\n", campo);
  
  cout<<"Nota PAES: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, "Nota PAES: %s\n", campo);
  
  cout<<"N°de Partida: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, "N°de Partida: %s\n", campo);
  
  cout<<"DUI: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, "DUI: %s\n", campo);
  
  cout<<"NIT: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, "NIT: %s\n", campo);
  
  cout<<"DATOS DEL ENCARGADO"<<endl;
  cout<<"Primer Nombre: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, "DATOS DEL ENCARGADO. %s\n", campo);
  fprintf(pArchivo, "Nombre: %s", campo);

  cout<<"Segundo Nombre: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, " %s", campo);
  
  cout<<"Primer Apellido: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, " %s", campo);
  
  cout<<"Segunda Apellido: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, " %s\n", campo);
  
  cout<<"Correo Electronico: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, "Correo Electronico: %s\n", campo);
  
  cout<<"Telefono Fijo o Movil: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, "Telefono Fijo o Movil: %s\n", campo);
  
  cout<<"DUI: "<<endl;
  scanf("%256s", campo);
  fprintf(pArchivo, "DUI: %s\n", campo);

  cout<<"IMPORTANTE: Consigue tu paquete informativo para enterarte de\ntoda la documentacion restante para tu proceso de ingreso\n"<<endl;
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
    cout<<"El archivo de hoja de vida no se pudo abrir o no existe\n"<<endl;
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
  InstruccionesNI();
 else
  InstruccionesAI();
}

void InstruccionesNI(){
    char opc2;
    do{
            cout<<"---------------------------------------------"<<endl;  
            cout<<"MENU DE PASOS PARA ALUMNOS NUEVO INGRESO"<<endl;
            cout<<"---------------------------------------------"<<endl;
            cout<<"Los estudiantes de nuevo ingreso son aquellos que se matriculan por primera vez en la Universidad.\n Para ingresar deben realizar los siguientes pasos:\n"<<endl;
            cout<<"1 - Compra de paquete informativo"<<endl;
            cout<<"2 - Visitar Ofician de Nuevo Ingreso"<<endl;
            cout<<"3 - Completar el cuestionario socioeconómico"<<endl;
            cout<<"4 - Cancelar Inscripcion"<<endl;
            cout<<"5 - Salir"<<endl;
            cin>>opc2;
            LimpiarPantalla;
            switch (opc2){
              //Compra de paquete informativo
              case '1':
                cout<<"\nDebes Adquirir paquete informativo, a un precio de $20.00 en colecturia.\nNOTA: Colecturia queda en la segunda planta del edificio R.\n\n";
                break;
              
              //Visitar Ofician de Nuevo Ingreso
              case '2':
                cout<<"\nLuego de comprar tu paquete informativo puedes dirigirte a la oficina de asesoria en la oficina de Nuevo Ingreso.\n Esta esta ubicada en la segunda planta del edificio A, a lado del monumento de Don Bosco, \n muy cerca de donde comprastes tu paquete informativo\n\n";
                break;
                
              case '3':
                cout<<"\nUna vez completes el cuestionario socioeconómico que se encuentra en tu paquete informativo y tengas todos tus documentos\n lo deberas entregar en el Departamento de Gestión Social Estudiantil. Que se encuentra ubicado en el edificio que esta a ubicado al lado\n del edificio C donde tambien encuentras a Pastoral.\n Aqui te asignaran tu couta estudiantil que puede ir de un $68.00 a $210.00\n\n";
                break;
                
               case '4': 
                cout<< "\nUna vez asignada tu couta deberas ir a cancelar en colecturía los costos de ingreso, \nsegun te informe el sistema de incripcion de la universidad,\n ademas recuerda pedir a tu tutor asignada te indique como inscibiras materias. Si no te han asignado solicita te lo asignen a tu jefe de escuela, \n sino sabes quien es \n puedes acercarte nuevamente a la oficina de de Nuevo Ingreso. Recuerda que esta ubicada en la segunda planta del edificio A, a lado del monumento de Don Bosco.\n\n";
                break;
                
               case '5':
                cout<<"\nFue un gusto ayudarte con tu orientacion de inscipcion. Para mas informacion, visita: http://www.udb.edu.sv/nuevoingreso/proceso.html \n\n";
                break;
                
              default:
                cout<<"Opcion no valida."<<endl;
                break;
            }
          }while(opc2 != '5');
}

void InstruccionesAI(){
char opc2;
    do{
            cout<<"---------------------------------------------"<<endl;  
            cout<<"MENU DE PASOS PARA ALUMNOS ANTIGUO INGRESO"<<endl;
            cout<<"---------------------------------------------"<<endl;
            cout<<"La inscripción de materias es el proceso por el cual el estudiante, \ndefine los grupos de clases y de laboratorios de cada materia que va a cursar,\nfinalizando el proceso con el pago de los aranceles correspondientes al ciclo.\n"<<endl;
            cout<<"Elige el paso del que deseas informacion:\n"<<endl;
            cout<<"1 - Solvente de deudas con la Universidad"<<endl;
            cout<<"2 - Pre-incripcion de materias"<<endl;
            cout<<"3 - Retiro de comprobante"<<endl;
            cout<<"4 - Cancelar el pago Inscripcion"<<endl;
            cout<<"5 - Salir"<<endl;
            cin>>opc2;
            LimpiarPantalla;
            switch (opc2){
                //Solvente de deudas con la Universidad
               case '1':
                cout<<"\nEs requisito indispensable, estar solvente en Colecturía, Biblioteca, Administración Académica \ny no tener materias reprobadas en tercera matrícula.\n\n";
                break;
              
                //Pre-incripcion de materias
               case '2':
                cout<<"\nPreinscribir materias en la Escuela respectiva o en línea, revisar bien los grupos asignados y las materias preinscritas \nantes de realizar la impresión del comprobante de pago ya que una vez impreso, \nno se realizará ningún cambio de grupo o cambio de materias. \nLa pre inscripción de materias es responsabilidad directa del estudiante, sino sabes como puedes pedir orientacion a tu tutor asiganado.\n\n";
                break;
                
                //Retiro de comprobante
               case '3':
                cout<<"\nRetirar en Colecturía el comprobante de pagos e inscripción o imprimirlo directamente cuando realiza el trámite en línea.\n\n";
                break;
                
               //Cancelar el pago Inscripcion
               case '4': 
                cout<< "\nCancelar los aranceles del ciclo en la fecha que aparece en la boleta de pago; \nsi no lo hace en el tiempo definido, se le anula el proceso y tiene que realizarlo de nuevo, \nquedando sujeto a los cupos disponibles en los grupos.\n\n";
                break;
                
               case '5':
                cout<<"\nFue un gusto ayudarte con tu orientacion de inscipcion. \nLas materias quedan inscritas automáticamente desde el momento en que se realizan los pagos correspondientes. \nAsi que puedes estar seguro de que puedes seguir estudiando \nPara mas informacion, visita: http://www.udb.edu.sv/udb/index.php/pagina/ver/inscripcion_estudiantes_antiguo_ingreso\n"<<endl;
                
                cout<<"NOTA: existe la Inscripción extraordinaria esta se da cuando un estudiante,\n no puede presentarse a inscribir materias en el período ordinario por motivos de fuerza mayor, \nse establece un período extraordinario de inscripción con un recargo en el pago. \nEn este caso, la inscripción de una asignatura queda sujeta al cupo disponible. \n\n";
                break;
                
              default:
                cout<<"Opcion no valida."<<endl;
                break;
            }
          }while(opc2 != '5');
}