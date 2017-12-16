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
					if(opcion2 == 1){
						Mensaje+="\n";
					}
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
				ifstream fileExtra (archive.c_str());
				if(fileExtra.is_open()){
					while(getline(fileExtra,linea)){
						NumLineas++;
					}
					fileExtra.close();
				}
				ArrayStack* TextoA = new ArrayStack(NumLineas);
				if (file.is_open()){
					cout<<"El contenido del archivo dice: "<<endl;
					cout<<endl;
					while (getline(file,linea)){
						TextoA->push(linea);
					}
					while (!TextoA->isEmpty()) {
						cout<<TextoA->pop()<<"";
					}
					cout<<endl;
					int opcion3 = 0;
					while(opcion3 != 2){
						//Aqui se hace la edicion
						int LineaEditar;
						cout<<"Ingrese la el numero de la linea que quiere cambiar empezando en 0"<<endl;
						cin>>LineaEditar;
						string Cambiar = TextoA->posicion(LineaEditar);
						cout<<Cambiar<<endl;
						string Cambio;
						cout<<"Ingrese la nueva linea que desea ingresar para sustituir la anterior"<<endl;
						cin.ignore();
						getline(cin,Cambio);
						TextoA->sustitucion(Cambio,LineaEditar);
						Cambiar=TextoA->posicion(LineaEditar);
						//aqui termina la edicion
						cout<<"--Menu--"<<endl
						<<"1)Editar mas"<<endl
						<<"2)Terminar la edicion"<<endl
						<<"Ingrese el numero de la opcion que desee"<<endl;
						cin>>opcion3;
					}
					string Guardar;
					for(int i= 0;i<NumLineas;i++){
						Guardar+=TextoA->posicion(i);
						if(i==NumLineas-1){
						}else{
							Guardar+="\n";
						}
					}
					ofstream salida(archive.c_str(), ios::out | ios::trunc );
					Archivo archivo(Guardar);
					salida<<archivo;
					salida.close();
					file.close();
					cout<<endl;
				}else{
					cout<<"No existe ese archivo"<<endl;
				}
				delete TextoA;
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
