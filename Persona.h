#ifndef PERSONA_H
#define PERSONA_H
#include <string>
using namespace std;

class Persona {
public:
	Persona();
	Persona(string nombre,string direccion,string mail,int dni,string fecha_nac,string localidad);
	
	/// GETTERS
	string verNombre();
	string verDireccion();
	string verFechaNac();
	string verEmail();
	string verLocalidad();
	int verDNI();
	
	/// SETTERS
	
	void setNombre(string);
	void setDireccion(string);
	void setFechaNac(string);
	void setEmail(string);
	void setLocalidad(string);
	void setDNI(int);
	
private:
	string m_nombre_apellido;
	string m_direccion;
	int m_dni;
	string m_fecha_nac;
	string m_email;
	string m_localidad;
};

#endif

