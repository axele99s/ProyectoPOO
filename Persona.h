#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;

class Persona {
private:
	string m_nombre_apellido="";
	string m_direccion="";
	int m_dni=0;
	int dia_nac,mes_nac,anio_nac;
//	string m_fecha_nac=""; /// concatenacion de la fecha
	string m_email="";
	string m_localidad="";
public:
	Persona();
	Persona(string nombre,string direccion,string mail,int dni,string localidad,int dia,int mes,int anio);
	
	/// GETTERS
	string verNombre();
	string verDireccion();
	string verFechaNac();
	string verEmail();
	string verLocalidad();
	int verDNI();
	
	int verDia();
	int verMes();
	int verAnio();
	
	/// SETTERS
	
	void setNombre(string);
	void setDireccion(string);
	void setEmail(string);
	void setLocalidad(string);
	void setDNI(int);
	void setDia(int dia);
	void setMes(int mes);
	void setAnio(int anio);
	

};

#endif

