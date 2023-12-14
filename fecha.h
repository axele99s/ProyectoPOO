#ifndef FECHA_H
#define FECHA_H
#include <string>
using namespace std;

class fecha {
private:
	string m_fecha; /// concatenacion de todo
	int m_dia=0;
	int m_mes=0;
	int m_anio=0;
	
	int hora=0;
	int minuto=0;
	int segundo=0;
	
public:
	fecha();
	fecha(string f);
	fecha(int dia,int mes,int anio);
	string obtenerFecha();
	string obtenerFechaConHora();
	string verFecha();
	string verFechaConHora();
	bool validarFecha(string f);
	
	void fecha_actual(); /// para las ventas, asi guardo un string a ints dia-mes-anio
	
	void setDia(int dia);
	void setMes(int mes);
	void setAnio(int anio);
	
	int verAnioActual();
	int verDia();
	int verMes();
	int verAnio();
	int verHora();
	int verMinuto();
	int verSegundo();
};

#endif

