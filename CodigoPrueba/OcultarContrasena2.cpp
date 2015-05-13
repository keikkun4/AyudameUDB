#include<conio.h>
#include<string>
#include<iostream>
using namespace std;

int main() {
    string pass="",user;
    char ch;
    int num=3;
    
    for(int i=1; i<=num; i++){
        cout<<"\nOportunidad "<<i<<" de 3";
        cout<<"\n\nIngrese su nombre de usuario: ";
        cin>>user;
        cout>>"\n\nIngrese su contrasena: ";
        ch =_getch();
        
        while (ch!=13){
                pass.push_back(ch);
                cout<<'*'; 
                ch=_getch();
        }
        
        if(pass=="Hola"&& user=="Leonel"){
        
            cout<<"\n\nBienvenido"<<user<<"Acceso consedido\n\n";
            num=0; //si la contraseña y usuario son correcto basa con igualar num a 0 asi la variable  i sera que num
        }
        else {
        
            cout<<"\n\nError datos ingresados invalidos, intente nuevamente\n\n";
            pass="";
            user="";
        }
    }
 //system("pause");
 return 0;
}