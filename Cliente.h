#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include "Persona.h"
using namespace std;

class Cliente : public Persona{
public:
	
	/// constructores
	Cliente(){};
	Cliente(int codigoCliente, string nombre, int dni,string dir,string loc,string mail,string fechanac);
	Cliente(string nombre, int dni,string dir,string loc,string mail,string fechanac);
	
	/// getter / getter
	int verCodigoCliente();
	
	void setCodigoCliente(int code);
	
	
	
//	bool operator==(Cliente &c); /// sin usar <- :/
	
	
	
private:
	int codigo_cliente;
};

#endif


