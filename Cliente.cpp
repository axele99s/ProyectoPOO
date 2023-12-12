#include "Cliente.h"



int Cliente::verCodigoCliente ( ) {
	return codigo_cliente;
}


void Cliente::setCodigoCliente (int code) {
	this->codigo_cliente=code;
}



//bool Cliente::operator== (Cliente & c) {
//	return c.verDNI() == this->verDNI();
//}





Cliente::Cliente (int codigoCliente, string nombre, int dni, string dir, string loc, string mail, string fechanac) {
	this->codigo_cliente = codigoCliente;
	this->setNombre(nombre);
	this->setDNI(dni);
	this->setDireccion(dir);
	this->setLocalidad(loc);
	this->setEmail(mail);
	this->setFechaNac(fechanac);
}

Cliente::Cliente (string nombre, int dni, string dir, string loc, string mail, string fechanac) {
	this->setNombre(nombre);
	this->setDNI(dni);
	this->setDireccion(dir);
	this->setLocalidad(loc);
	this->setEmail(mail);
	this->setFechaNac(fechanac);
}

