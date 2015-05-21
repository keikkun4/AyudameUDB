#include<iostream>
#include<string>
using namespace std;

int materias();


int main()
{
	int opc;  
	do
	{
		cout<<"------------------------------------------------------------------------------"<<endl;
		cout<<"- El estudiante debe considerar los siguientes pasos                         -"<<endl;
		cout<<"-                                                                            -"<<endl;
		cout<<"- 1. Realizar el proceso de inscripcion en linea.                            -"<<endl;
		cout<<"- 2. Imprimir boleta de pagos                                                -"<<endl;
	    cout<<"- 3. Cancelar en Colecturía, cualquier agencia de banco Citi,                -"<<endl;
		cout<<"-    o medios electrónicos los aranceles correspondientes al inicio de ciclo.-"<<endl;
		cout<<"- 4. Regresar                                                                -"<<endl;
		cout<<"------------------------------------------------------------------------------"<<endl;
		cout<<" "<<endl;
		cout<<"por favor ingrese su opcion"<<endl;
		
		cin>>opc;
		
		switch(opc)
		
		{
			
			case 1:
			char nombre[100];
			char carnet[10];
			char carrera[20];
			float cuota;
			cout<<"para realizar el proceso de inscripción llene los siguientes datos"<<endl;
			cout<<"\n";
			cout<<"ingrese su nombre completo"<<endl;
			fflush(stdin);
			gets(nombre);
			cout<<"carnet"<<endl;
			cin>>carnet;
			cout<<"cuota o mensualidad"<<endl;
			cin>>cuota;
			int opc2;
			do
			{
				
				cout<<"--------------Seleccione su carrera-------------"<<endl;
				cout<<"1.Ingeieria Electronica                        -"<<endl;
				cout<<"2.Ingeieria Electrica                          -"<<endl;
				cout<<"3.Ingeieria Mecanica                           -"<<endl;
				cout<<"4.Ingeieria en Ciencias de la Computacio       -"<<endl;
				cout<<"5.Ingeieria Biomedica                          -"<<endl;
				cout<<"6.Ingeieria Industrial                         -"<<endl;
				cout<<"7.Ingeieria en Telecomunicaciones              -"<<endl;
				cout<<"8.Ingeieria en Automatizacion                  -"<<endl;
				cout<<"9.Ingeieria Mecatronica                        -"<<endl;
				cout<<" "<<endl;
				cout<<" ingrse 10 para regresar                       -"<<endl;
				
				int opc2;
				cin>>opc2;
							
				//en este caso como en todas las carreras el primer ciclo se ursan las mismas materias su ocion es un poco irrelevante
				switch(opc2)
				{
					case 1:
				    	cout<<"Ingeieria Electronica"<<endl;
						int materias();	
					break;
					case 2:
						cout<<"Ingeieria Electrica"<<endl;
						int materias();
					break;
					case 3:
						cout<<"Ingeieria Mecanica"<<endl;
						int materias();
					break;
					case 4:
						cout<<"Ingeieria en Ciencias de la Computacio"<<endl;
						int materias();
					break;
					case 5:
					    cout<<"Ingeieria Biomedica"<<endl;
					    int materias();
					break;
					case 6:
						cout<<"Ingeieria Industrial"<<endl;
						int materias();
					break;
					case 7:
						cout<<"Ingeieria en Telecomunicaciones"<<endl;
						int materias();
					break;
					case 8:
						cout<<"Ingeieria en Automatizacion"<<endl;
						int materias();
					break;
					case 9:
						cout<<"Ingeieria Mecatronica"<<endl;
						int materias();
					break;
					case 10:
						
					break;
					
				}		
								
								
								
			}
			while (opc2!=10);	
			
			break;
			
			case 2:
			cout<<"Imprimir boleta de pagos."<<endl;
			int materias();
			int lab,a;
			if(lab==1)
			{
				lab=43;
			}
			else
			{
				lab=84;
			}
			cout<<"cuantos laboratorios llevara"<<endl;
			cin>>lab;
			cout<<"introduzca la cantidad que paga por mensualidad"<<endl;
			cin>>a;
			float aranceles=44, matricula=65; cuota=a;
			int total=0;
			total=aranceles+matricula+cuota+lab;
			cout<<"........................................................."<<endl;
			cout<<".. object ..............................costo............"<<endl;
			cout<<".. matricula .......................... $35.0 ..........."<<endl;
			cout<<".. mesualidad.........................$"<<a<<"..........."<<endl;
			cout<<"...aranceles............................$44.0 ..........."<<endl;
			cout<<"...laboratorios......................$"<<lab<<" ........."<<endl;
			cout<<"...total a cancelar..................$"<<total<<"........"<<endl;
			cout<<"........................................................."<<endl;
			break;
			
			case 3:
			cout<<"- por favor ,Cancelar en Colecturía, cualquier agencia de banco Citi,"<<endl;
		    cout<<"- o medios electrónicos los aranceles correspondientes al inicio de ciclo."<<endl;
		    cout<<"\n\n"<<endl;
		    cout<<"AVISO IMPORTANTE"<<endl;
		    cout<<"si no cancela antes de que se cumpla en plazo de 24 horas,"<<endl;
			cout<<"su inscripcion se anulara y debera volver a realizar el procesos sujeto a los cupos disponibles"<<endl;
			break;
			
			case 4:
			cout<<" regresar"<<endl;
			return 0;
			break;			
			 		
		}
	}
	while (opc!=4);
		
	system("pause");
	return 0;	
}

int materias()
{
	cout<<"..........materias correspondientes a el ciclo 1............"<<endl;
	cout<<".......MATERIAS......................laboratorios..........."<<endl;
	cout<<".. 1-Matematica 1             .            1               ."<<endl;
	cout<<".. 2-Qumica general           .            1               ."<<endl;
	cout<<".. 3-Algebra linial           .            -               ."<<endl;
	cout<<".. 4-Expresion oral y escrita .            -               ."<<endl;
	cout<<".. 5-Humanistica 1            .            -               ."<<endl;
	cout<<"............................................................"<<endl;
	system("pause");

}


