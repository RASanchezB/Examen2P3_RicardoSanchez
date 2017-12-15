#include <iostream>
#include "Stack.h"
#include "ArrayStack.h"
#include "Archivo.h"

using namespace std;

int main(){
	int opcion = 0;
	std::string archive;
	cout<<"Examen 2 Programacion 3"<<endl;
	cout<<endl;
	while(opcion != 3){
		cout<<"___MENU___"<<endl
		<<"1)Crear"<<endl
		<<"2)Editar"<<endl
		<<"3)Salir"<<endl
		<<"Ingrese la opcion que desee"<<endl;
		cin>>opcion;
		cout<<endl;
		cout<<opcion<<endl;
		cout<<endl;
		switch (opcion) {
			case 1:{
				string Mensaje;
				cout<<"Ingrese un titulo para el archivo (porfavor excluir el .txt)"<<endl;
				cin>>archive;
				archive+=".txt";
				int opcion2 = 1;
				while(opcion2 == 1){
					cout<<"Ingrese lo que va a escribir en el archivo"<<endl;
					cin.ignore();
					getline(cin,Mensaje);
					cout<<"El mensaje dice: "<<Mensaje<<endl;
					cout<<"--Menu secundario--"<<endl
					<<"1)Escribir otra linea"<<endl
					<<"2)Terminar"<<endl
					<<"Elija la opcion que desea"<<endl;
					cin>>opcion2;
					Mensaje+="\n";
				}
				ofstream salida(archive.c_str(), ios::app );
				Archivo archivo(Mensaje);
				salida<<archivo;
				salida.close();
			}break;
			case 2:{}break;
			case 3:{
				cout<<"Saliendo"<<endl;
			}break;
			default:{
				cout<<"Su opcion no es valida"<<endl;
			}break;
		}
	}
}
