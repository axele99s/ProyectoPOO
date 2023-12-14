#include "Persona.h"
#include "string_conv.h"

Persona::Persona() {
	
}


Persona::Persona (string nombre, string direccion, string mail, int dni, string localidad, int dia,int mes,int anio) {
	m_nombre_apellido = nombre;
	m_direccion = direccion;
	m_email = mail;
	m_dni = dni;
	
	m_localidad = localidad;
	this->setDia(dia);
	this->setMes(mes);
	this->setAnio(anio);
}


string Persona::verNombre ( ) {
	return m_nombre_apellido;
}

string Persona::verDireccion ( ) {
	return m_direccion;
}

//string Persona::verFechaNac ( ) {
//	return m_fecha_nac;
//}

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

//void Persona::setFechaNac (string fecha) {
//	
//	m_fecha_nac = fecha;
//}

void Persona::setEmail (string mail) {
	m_email = mail;
}

void Persona::setLocalidad (string loc) {
	m_localidad = loc;
}

void Persona::setDNI (int dni) {
	m_dni = dni;
}

int Persona::verDia ( ) {
	return dia_nac;
}

int Persona::verMes ( ) {
	return mes_nac;
}

int Persona::verAnio ( ) {
	return anio_nac;
}

void Persona::setDia (int dia) {
	dia_nac = dia;
}

void Persona::setMes (int mes) {
	mes_nac = mes;
}

void Persona::setAnio (int anio) {
	anio_nac = anio;
}



string Persona::verFechaNac ( ) {
	return int_to_str(dia_nac)+"-"+int_to_str(mes_nac)+"-"+int_to_str(anio_nac);
}

