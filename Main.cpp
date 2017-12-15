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
		switch (opcion) {
			case 1:{
				cout<<endl;
				//Crear y agregar un mensaje al archivo
				string Mensaje = "";//Mensaje que se agregara al archivo
				string Agregar = "";//Para poder agregar mas de una linea
				cout<<"Ingrese un titulo para el archivo (porfavor excluir el .txt)"<<endl;
				cin>>archive;//nombre del archivo a subir
				archive+=".txt";
				int opcion2 = 1;
				while(opcion2 == 1){
					cout<<"Ingrese lo que va a escribir en el archivo"<<endl;
					cin.ignore();
					getline(cin,Agregar);
					Mensaje+=Agregar;
					cout<<endl;
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
			case 2:{
				cout<<endl;
				//Editar un archivo ya existente
				string Mensaje;//Mensaje que se agregara al archivo
				cout<<"Ingrese un titulo para el archivo a Editar(porfavor excluir el .txt)"<<endl;
				cin>>archive;//nombre del archivo a editar
				archive+=".txt";
				string linea;
				int NumLineas=0;
				ifstream file (archive.c_str());
				if(file.is_open()){
					while(getline(file,linea)){
						NumLineas++;
					}
					file.close();
				}
				ArrayStack* TextoA = new ArrayStack(NumLineas);
				if (file.is_open()){
					cout<<"El contenido del archivo dice: "<<endl;
					cout<<endl;
					while (getline(file,linea)){
						cout<<linea<<'\n';
						TextoA->push(linea);
					}
					while (!TextoA->isEmpty()) {
						cout<<TextoA->pop()<<"";
					}
					cout<<endl;
					delete TextoA;
					file.close();
					cout<<endl;

				}else{
					cout<<"No existe ese archivo"<<endl;
				}
			}break;
			case 3:{
				cout<<"Saliendo"<<endl;
			}break;
			default:{
				cout<<"Su opcion no es valida"<<endl;
			}break;
		}
	}
}
