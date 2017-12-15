#include "ArrayStack.h"
#include <string>

using namespace std;

ArrayStack::ArrayStack(int pSize){
	size=pSize;
	array=new string[size];
	availPos=0;
}
bool ArrayStack::push(string dato){
	bool retval=false;

	if (availPos==size) {
		return retval;
	}else{
		array[availPos++]=dato;
		retval=true;
		return retval;
	}
}

bool ArrayStack::isEmpty(){
	return availPos==0;
}

string ArrayStack::pop(){
	if (isEmpty()) {
		return 0;
	}else{
		string retval=array[availPos-1];
		availPos--;
		return retval;
	}
}
ArrayStack::~ArrayStack(){
	delete[] array;
}
