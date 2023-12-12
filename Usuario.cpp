#include "Usuario.h"

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
	return fecha;
}

void Usuario::setFecha (string fecha) {
	this->fecha=fecha;
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

Usuario::Usuario (string user, string pass, string fecha, int tipo, string nombre, int dni, string dir, string loc, string mail, string fechanac) {
	this->user=user;
	this->pass=pass;
	this->fecha=fecha;
	this->tipo=tipo;
	this->setNombre(nombre);
	this->setDNI(dni);
	this->setDireccion(dir);
	this->setLocalidad(loc);
	this->setEmail(mail);
	this->setFechaNac(fechanac);
	
}

