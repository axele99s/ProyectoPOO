#include "Usuario.h"
#include "string_conv.h"
#include <iostream>
using namespace std;

Usuario::Usuario() {
	
}


string Usuario::verNombreUsuario ( ) {
	return user;
}

string Usuario::verPass ( ) {
	return pass;
}



void Usuario::setUser (string s) {
	user=s;
}

void Usuario::setPass (string p) {
	pass=p;
}




string Usuario::verFecha ( ) {
	return int_to_str(dia_reg)+"-"+int_to_str(mes_reg)+"-"+int_to_str(anio_reg);
}


Usuario::Usuario (string usuario, string pass) {
	user = usuario;
	this->pass = pass;
}

void Usuario::setTipo (int t) {
	tipo = t;
}

int Usuario::verTipo ( ) {
	return tipo;
}

Usuario::Usuario (string user, string pass, int tipo, string nombre, int dni, string dir, string loc, string mail, int dia,int mes,int anio) {
	this->user=user;
	this->pass=pass;
	this->fecha=fecha;
	this->tipo=tipo;
	this->setNombre(nombre);
	this->setDNI(dni);
	this->setDireccion(dir);
	this->setLocalidad(loc);
	this->setEmail(mail);
	this->setDia(dia);
	this->setMes(mes);
	this->setAnio(anio);
	
}

int Usuario::verDia_Reg ( ) {
	return dia_reg;
}

int Usuario::verMes_Reg ( ) {
	return mes_reg;
}

int Usuario::verAnio_Reg ( ) {
	return anio_reg;
}

void Usuario::setDia_Reg (int a) {
	dia_reg = a;
}

void Usuario::setMes_Reg (int a) {
	mes_reg = a;
}

void Usuario::setAnio_Reg (int a) {
	anio_reg = a;
}

