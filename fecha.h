#ifndef FECHA_H
#define FECHA_H
#include <string>
using namespace std;

class fecha {
private:
	string m_fecha;
	string m_dia;
	string m_mes;
	string m_anio;
	
public:
	fecha();
	fecha(string f);
	fecha(string dia,string mes,string anio);
	string obtenerFecha();
	string obtenerFechaConHora();
	string verFecha();
	bool validarFecha(string f);
	
	void setDia(string dia);
	void setMes(string mes);
	void setAnio(string anio);
	
	int verAnioActual();
	string verDia();
	string verMes();
	string verAnio();
};

#endif

