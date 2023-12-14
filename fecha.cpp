#include "fecha.h"
#include <ctime>
#include <iostream>
#include "validaciones.h"
#include "string_conv.h"
using namespace std;

fecha::fecha() {
	
}


string fecha::obtenerFecha ( ) {
	
		time_t t = std::time(nullptr);
		std::tm* now = std::localtime(&t);
		
		char buffer[128];
		strftime(buffer, sizeof(buffer), "%d-%m-%Y", now);
		
		
		return buffer;
	
}

string fecha::obtenerFechaConHora ( ) {
	time_t t = std::time(nullptr);
	std::tm* now = std::localtime(&t);
	
	char buffer[128];
	strftime(buffer, sizeof(buffer), "%d-%m-%Y - %X", now);
	return buffer;
}

bool fecha::validarFecha (string f) {
	
}

fecha::fecha (string f) : m_fecha(f) {
	string fec = convertirFecha(f);
	if(!f.empty() and fec.size()==8) {
		m_dia = string_to_int(fec.substr(0,2));
		m_mes = string_to_int(fec.substr(2,2));
		m_anio = string_to_int(fec.substr(4,4));
		m_fecha = m_dia+m_mes+m_anio;
		
	}
	else f="000000";
}



void fecha::setDia (int dia) {
	m_dia = dia;
}

void fecha::setMes (int mes) {
	m_mes = mes;
}

void fecha::setAnio (int anio) {
	m_anio = anio;
}

int fecha::verDia ( ) {
	return m_dia;
}

int fecha::verMes ( ) {
	return m_mes;
}

int fecha::verAnio ( ) {
	return m_anio;
}



string fecha::verFecha ( ) {
	return int_to_str(m_dia)+"-"+int_to_str(m_mes)+"-"+int_to_str(m_anio);
}

fecha::fecha (int dia, int mes, int anio) : m_dia(dia),m_mes(mes),m_anio(anio) {
	
}

int fecha::verAnioActual ( ) {
	string f = obtenerFecha();
	string str = convertirFecha(f);
	str = str.substr(4,4);
	return string_to_int(str);
}

//fecha::fecha (int ) {
//	string str = obtenerFechaConHora();
//	int dia = 
//	
////	return buffer;
//	
//}

void fecha::fecha_actual () {
	string fec = obtenerFechaConHora();
		m_dia = string_to_int(fec.substr(0,2));
		m_mes = string_to_int(fec.substr(3,2));
		m_anio = string_to_int(fec.substr(6,4));
		m_fecha = m_dia+m_mes+m_anio;
		hora = string_to_int(fec.substr(13,2));
		minuto = string_to_int(fec.substr(16,2));
		segundo = string_to_int(fec.substr(19,2));
	
}

//fecha::fecha (int ) {
//	return 
//}

int fecha::verHora ( ) {
	return hora;
}

int fecha::verMinuto ( ) {
	return minuto;
}

int fecha::verSegundo ( ) {
	return segundo;
}

string fecha::verFechaConHora ( ) {
	return int_to_str(m_dia)+"-"+int_to_str(m_mes)+"-"+int_to_str(m_anio)+" - "+int_to_str(hora)+":"+int_to_str(minuto)+"-"+int_to_str(segundo);
}

