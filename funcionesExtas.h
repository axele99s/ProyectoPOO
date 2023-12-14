#ifndef FUNCIONESEXTAS_H
#define FUNCIONESEXTAS_H
#include <cstring>
#include <algorithm>
#include "fecha.h"
#include <vector>
#include "productoVenta.h"
using namespace std;


inline string minuscula(string &str){
	string b = str ;
	transform(b.begin(), b.end(), b.begin(), ::tolower); 
	return b;
}
	
struct PersonaStruct{
	char nombre[50];
	char direccion[50];
	char localidad[50];
	char email[20];
	int dia=0, mes=0, anio=0; /// fecha nac
	int dni;
};

struct UsuariosChar{
	PersonaStruct pers;
	char user[20];
	char pass[20];
//	char fecha[10]; /// <- fecha de registro
	
	int dia_reg,mes_reg,anio_reg; /// <- fecha reg
	int tipo;
	
};
	
struct ClientesChar{
	PersonaStruct pers;
	int codigo;
};

struct prodsVenta{
	char nombre[30];
	int codigo=0;
	float cantidad=0;
	float precio=0;
	
	///
//	char nro_transaccion[10];
};

struct structVentaRealizada{
	/// 
	
	vector<prodsVenta> pv;
	int n=0; /// tamaño del vector
	
	/// total 
	float total=-1;
	
	/// USUARIO del vendedor (el usuario es unico)
	char vendedor[20];
	/// Codigo del cliente
	int cliente;
	/// fecha de la venta...
	int dia=-1;
	int mes=-1;
	int anio=-1;
	
	int hora=-1;
	int minuto=-1;
	int segundo=-1;
	/// numeroVenta
	
	/// ej: abc123456
	char nro_transaccion[10];
	
};




/// pasa los datos al struct para despues poder
/// cargar/guardar el binario
inline structVentaRealizada pasarAStruct(vector<productoVenta> &vector_pv,string &vendedor,int &cliente,float &total,string nrotrac,int n){
	
	structVentaRealizada pS;
	
	for(size_t i=0;i<vector_pv.size();i++) { 
		prodsVenta prods;
		prods.codigo =  vector_pv[i].verCodigoProducto();
		prods.cantidad =  vector_pv[i].verCantidad();
		
		prods.precio=vector_pv[i].obtenerValor();
		
		strcpy(prods.nombre,vector_pv[i].verNombreProducto().c_str());
		pS.pv.push_back(prods);
	}
	
	fecha f;
	f.fecha_actual();
	
	pS.n = n;
	
	
	pS.dia=f.verDia();
	pS.mes=f.verMes();
	pS.anio=f.verAnio();
	pS.hora=f.verHora();
	pS.minuto=f.verMinuto();
	pS.segundo=f.verSegundo();
	
	strcpy(pS.vendedor,vendedor.c_str());
	pS.cliente=cliente;
	pS.total = total;
	strcpy(pS.nro_transaccion,nrotrac.c_str());
	
	return pS; 
}
#endif

/// Funcion para calcular la cantidad de saltos de linea
	
//inline int CantidadSaltos(string str){
//	int c=0;
//	for(size_t i=0;i<str.size();i++) { 
//		if(str[i] == '\n') c++;
//	}
//	return c;	
//}
