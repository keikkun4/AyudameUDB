#include<iostream>
#include<windows.h>
#include<string.h>

using namespace std;
struct partida
{
       int numpartida;
       int libro;
       char folio[30];
       char lugar[30];
       char madre[30];
       char padre[30];
       char nacionalidadp[30];
       char nacionalidadm[30];
}datos;
struct notas
{
       float lenguaje1;
       float lenguaje2;
       float matematica1;
       float matematica2;
       float ciencias1;
       float ciencias2;
       float sociales1;
       float sociales2;
       float ingles1;
       float ingles2;
       float informatica1;
       float informatica2;
       
}mined;

struct notas2
{
       float matematicas;
       float es;
       float literatura;
       float naturales;
}paes;
int main()
{
    int opc,opc2,opc3, opc4;
    
    
    cout<<"Ingreso de datos NUEVO INGRESO"<<endl;
   
    cout<<"¿Has concluido satisfactoriamente tu bachillerato?"<<endl;
    cout<<"1. Si"<<endl;
    cout<<"2. No"<<endl;
    cin>>opc;
    if(opc==2)

    cout<<"No estas listo para la siguiente etapa"<<endl;
    
    
    else
{
    cout<<"¿Has completado tu formulario socioeconomico?"<<endl;
    cout<<"1. Si"<<endl;
    cout<<"2. No"<<endl;
    cin>>opc4;
    if(opc4==2)
    {
    cout<<"No estas listo para pasar a la siguiente etapa"<<endl;
    }

    else
    {
    cout<<"Tu cuota asignada sera de $68.00"<<endl;
    cout<<"¿Ya adquiriste el paquete informativo"<<endl;
    cout<<"1. Si"<<endl;
    cout<<"2. No"<<endl;
    cin>>opc2;
    if(opc2==2)
    {
               cout<<"Te informamos que los puedes adquirir por tan solo 12 dolares en la colecturia";
               cout<<" ubicada en el edificio R"<<endl;
    }
    else
    {
       
    cout<<"Estas listo para reunir los documentos de ingreso: "<<endl;
    cout<<"****MENU****"<<endl;
    cout<<"1. Partida de nacimiento"<<endl;
    cout<<"2. Notas de los dos ultimos anios de bachillerato(extendidas por el MINED)"<<endl;
    cout<<"3. Resultado PAES"<<endl;
    cout<<"4. Titulo de bachiller"<<endl;
    cout<<"5. Dos fotografias recientes tamanio cedula"<<endl;
    
              
    cin>>opc3;
   
   
    switch(opc3)
    {
         case 1:
              cout<<"***PARTIDA DE NACIMIENTO***"<<endl;
              cout<<"Numero de partida: ";
              cin>>datos.numpartida;
              cout<<"Libro: ";
              
              cin>>datos.libro;
              getchar();
              cout<<"folio: ";
              
              gets(datos.folio);
              getchar();
              cout<<"Lugar de nacimiento: ";
              getchar();
              gets(datos.lugar);
              getchar();
              cout<<"Nombre del padre: ";
              gets(datos.padre);
              getchar();
              cout<<"Nombre de la madre: ";
              
              gets(datos.madre);
              getchar();
              cout<<"Nacionalidad del padre: ";
              gets(datos.nacionalidadp);
              getchar();
              cout<<"Nacionalidad de la madre: ";
              gets(datos.nacionalidadm);
              break;
         
         case 2:
              cout<<"***NOTAS DE BACHILLERATO***"<<endl;
              cout<<"***Primer anio***"<<endl;
              cout<<"Matematica:  ";
              cin>>mined.matematica1;
              cout<<"Lenguaje y literatura: ";
              cin>>mined.lenguaje1;
              cout<<"Ciencias naturales:  ";
              cin>>mined.ciencias1;
              cout<<"Estudios sociales:  ";
              cin>>mined.sociales1;
              cout<<"Ingles:  ";
              cin>>mined.ingles1;
              cout<<"Informatica:  ";
              cin>>mined.informatica1;
              
              cout<<"***Segundo anio***"<<endl;
              cout<<"Matematica:  ";
              cin>>mined.matematica2;
              cout<<"Lenguaje y literatura:  ";
              cin>>mined.lenguaje2;
              cout<<"Ciencias naturales:  ";
              cin>>mined.ciencias2;
              cout<<"Estudios sociales:  ";
              cin>>mined.sociales2;
              cout<<"Ingles:  ";
              cin>>mined.ingles2;
              cout<<"Informatica:  ";
              cin>>mined.informatica2;
              break;
              
              case 3:
              cout<<"***Notas PAES***"<<endl;
              cout<<"Matematica:  ";
              cin>>paes.matematicas;
              cout<<"***Lenguaje y Literatura:  ";
              cin>>paes.literatura;
              cout<<"***Estudios Sociales:   ";
              cin>>paes.es;
              cout<<"***Ciencias Naturales:   ";
              cin>>paes.naturales;
              break;
              
              case 4:
              cout<<"Adjunta tu titulo de bachiller en el folder que entregaras"<<endl;
              break;
              
              
              case 5:
              cout<<"Adjunta tus fotografias en el folder que entregaras"<<endl;
              break;
}



}
}

}

system("pause");
return 0;

}
              
              
              
              
                 
                  
    
