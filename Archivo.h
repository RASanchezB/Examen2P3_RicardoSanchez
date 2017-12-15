#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

class Archivo{
protected:
	string texto;
public:
	Archivo();
	Archivo(string);

	void write(ofstream&);
	void read(ifstream&);

	friend ostream& operator<<(ostream&,const Archivo&);
	friend istream& operator>>(istream&,Archivo&);
};
#endif
