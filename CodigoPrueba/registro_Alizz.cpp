#include<iostream>
#include<fstream>
using namespace std;
struct Registro
{
	char nombre_completo[30];
	int  edad;
	char genero[10];
	char direccion[50];
	char DUI[20];
	char NIT[20];
	int  nota_PAES;
	char encargado[20];
	int numero_telefonico;
	char carrera_a_optar[20];
	char correo_electronico[15];
}nuevoingreso;
struct Registro_Verificacion 
{
	char nombre_completo[30];
	int edad;
	char genero[10];
	char direccion[10];
	char DUI[20];
	char NIT[20];
	char carrera_cursada[20];
	char correo_electronico[15];
	int  numero_telefonico;
}antiguoingreso;
int main()
{
	char nombre_completo[30];
	int  edad;
	char genero[10];
	char direccion[50];
	char DUI[20];
	char NIT[20];
	int  nota_PAES;
	char encargado[20];
	int numero_telefonico;
	char carrera_a_optar[20];
	char correo_electronico[15];
	char carrera_cursada[20];
	int n,i;
	int m,j;
	n=1;
	m=1;
	ofstream registronuevo;
	ofstream registroantiguo;
	registronuevo.open("nuevoingreso.txt",ios::out);
	registroantiguo.open("antiguoingreso.txt",ios::out);
	if(!registronuevo)
	{
		cerr<<"no se puede abrir el archivo"<<endl;
		exit(1);
	}	
	cout<<"\nREGISTRARE:"; 
	cin>>n;
	while(i<=n)
	{
		registronuevo<<endl;
		cout<<"\n";
		cout<<"\ndigite nombre completo:";
		cin>>nombre_completo;
		cout<<"\ndigite edad:";
		cin>>edad;
		cout<<"digite genero:";
		cin>>genero;
		cout<<"digite direccion:";
		cin>>direccion;
		cout<<"\ndigite DUI:";
		cin>>DUI;
		cout<<"\ndigite NIT:";
		cin>>NIT;
		cout<<"\ndigite nota PAES:";
		cin>>nota_PAES;
		cout<<"\ndigite encargado:";
		cin>>encargado;		
		cout<<"\ndigite correo electronico:";
		cin>>correo_electronico;	
		cout<<"\ndigite numero telefonico:";
		cin>>numero_telefonico;	
		cout<<"\ndigite carrera a optar:";
		cin>>carrera_a_optar;
		registronuevo<<nombre_completo<<""<<edad<<""<<genero<<""<<direccion<<""<<DUI<<""<<NIT<<""<<nota_PAES<<""<<encargado<<""<<correo_electronico<<""<<numero_telefonico<<""<<carrera_a_optar;
	    i++;	
	}
		if(!registroantiguo)
	{
		cerr<<"no es puede abrir el archivo"<<endl;
		exit(1);
	}
	  cout<<"\nREGISTRATE:"; 
	  cin>>m;
		while(j<=m)
	{
	   registroantiguo<<endl;
	   cout<<"\n";
		cout<<"\ndigite nombre completo:";
		cin>>nombre_completo;
		cout<<"\ndigite edad:";
		cin>>edad;
		cout<<"digite genero:";
		cin>>genero;
		cout<<"digite direccion:";
		cin>>direccion;
		cout<<"\ndigite DUI:";
		cin>>DUI;
		cout<<"\ndigite NIT:";
		cin>>NIT;	
		cout<<"\ndigite correo electronico:";
		cin>>correo_electronico;	
		cout<<"\ndigite numero telefonico:";
		cin>>numero_telefonico;	
		cout<<"\ndigite carrera cursada:";
		cin>>carrera_cursada;
		registroantiguo<<nombre_completo<<""<<edad<<""<<genero<<""<<direccion<<""<<DUI<<""<<NIT<<""<<correo_electronico<<""<<numero_telefonico<<""<<carrera_cursada;
	    j++;
	}
	registronuevo.close();
	registroantiguo.close();
	cout<<"\nse termino de agregar datos al archivo";
	system("pause");
	return 0;
}

	

