#include "fecha.h"
#include <ctime>
#include <iostream>
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
	strftime(buffer, sizeof(buffer), "%d-%m-%Y", now);
	return buffer;
}

bool fecha::validarFecha (string f) {
	
}

fecha::fecha (string f) : m_fecha(f) {
	
}

void fecha::setDia (string dia) {
	m_dia = dia;
}

void fecha::setMes (string mes) {
	m_mes = mes;
}

void fecha::setAnio (string anio) {
	m_anio = anio;
}

string fecha::verDia ( ) {
	return m_dia;
}

string fecha::verMes ( ) {
	return m_mes;
}

string fecha::verAnio ( ) {
	return m_anio;
}



string fecha::verFecha ( ) {
	return m_dia+m_mes+m_anio;
}

fecha::fecha (string dia, string mes, string anio) : m_dia(dia),m_mes(mes),m_anio(anio) {
	
}

