Prueba:	Main.o Archivo.o ArrayStack.o
	g++ Main.o Archivo.o ArrayStack.o -o Prueba

Main.o:	ArrayStack.h Archivo.h Main.cpp
	g++ -c Main.cpp

Archivo.o:	Archivo.h Archivo.cpp
	g++ -c Archivo.cpp

ArrayStack.o:	ArrayStack.h ArrayStack.cpp
	g++ -c ArrayStack.cpp

clear:
	rm *.o run
