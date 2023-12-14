#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include "Persona.h"
using namespace std;

class Cliente : public Persona{
public:
	
	/// constructores
	Cliente(){};
	Cliente(int codigoCliente, string nombre, int dni,string dir,string loc,string mail,int dia,int mes,int anio);
	Cliente(string nombre, int dni,string dir,string loc,string mail,int dia,int mes,int anio);
	
	/// getter / getter
	int verCodigoCliente();
	
	void setCodigoCliente(int code);
	
	
	
//	bool operator==(Cliente &c); /// sin usar <- :/
	
	
	
private:
	int codigo_cliente;
};

#endif


