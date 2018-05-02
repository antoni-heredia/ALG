#include <string>
#include <cstring>
#include <cmath>
#include "Punto.h"
using namespace std;
Punto::Punto(){
	x=0;
	y=0;
}

Punto::Punto(double x,double y){
	setX(x);
	setY(y);
}

double Punto::getX(){
	return x;
}

double Punto::getY(){
	return y;
}

void Punto::setX(double x){
	this->x=x;
}

void Punto::setY(double y){
	this->y=y;
}

string Punto::ToString(){
	string res=to_string(x)+","+to_string(y);
	return res;
}

double Punto::Distancia(Punto b){
	return sqrt(pow(x-b.getX(),2)+pow(y-b.getY(),2));
}


