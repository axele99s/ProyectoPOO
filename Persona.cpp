#include "Persona.h"

Persona::Persona() {
	
}


Persona::Persona (string nombre, string direccion, string mail, int dni, string fecha_nac, string localidad) {
	m_nombre_apellido = nombre;
	m_direccion = direccion;
	m_email = mail;
	m_dni = dni;
	m_fecha_nac = fecha_nac;
	m_localidad = localidad;
}

string Persona::verNombre ( ) {
	return m_nombre_apellido;
}

string Persona::verDireccion ( ) {
	return m_direccion;
}

string Persona::verFechaNac ( ) {
	return m_fecha_nac;
}

string Persona::verEmail ( ) {
	return m_email;
}

string Persona::verLocalidad ( ) {
	return m_localidad;
}

int Persona::verDNI ( ) {
	return m_dni;
}



void Persona::setNombre (string nombre) {
	m_nombre_apellido = nombre;
}

void Persona::setDireccion (string dir) {
	m_direccion = dir;
}

void Persona::setFechaNac (string fecha) {
	m_fecha_nac = fecha;
}

void Persona::setEmail (string mail) {
	m_email = mail;
}

void Persona::setLocalidad (string loc) {
	m_localidad = loc;
}

void Persona::setDNI (int dni) {
	m_dni = dni;
}

