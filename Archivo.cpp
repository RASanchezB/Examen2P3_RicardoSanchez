#include "Archivo.h"
istream& operator>>(istream& in, Archivo& archive){
  string buffer;
  //leer una línea del archivo
  getline(in,buffer);
  string parse="";
  int cont=0;
  for(int i = 0; i<buffer.size();i++){
      switch(cont){
        case 0:
          archive.texto = parse;
           break;
      }
      cont++;
  }
  return in;
}
ostream& operator<<(ostream& out, const Archivo& archive){
   out<<archive.texto<<endl;
   return out;
}
Archivo::Archivo(){
	texto="";
}
Archivo::Archivo(string pTexto){
    texto=pTexto;
}
