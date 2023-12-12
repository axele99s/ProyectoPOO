#ifndef FUNCIONESEXTAS_H
#define FUNCIONESEXTAS_H
#include <cstring>
#include <algorithm>
using namespace std;


inline string minuscula(string &str){
	string b = str ;
	transform(b.begin(), b.end(), b.begin(), ::tolower); 
	return b;
}
struct UsuariosChar{
	char user[256];
	char pass[256];
	char fecha[256];
	int tipo;
	char nombre[256];
	char direccion[256];
	char localidad[256];
	char email[256];
	char fecha_nac[256];
	int dni;
};
	
struct ClientesChar{
	char nombre[256];
	char direccion[256];
	char localidad[256];
	char email[256];
	char fecha_nac[256];
	int dni, codigo;
	};


struct structVentaRealizada{
	
	char productoycantidad[9999];
	
	/// total 
	float total;
	
	
	/// Datos del vendedor
	char vendedor[256];
	/// Datos del cliente
	char cliente[256];
	/// fecha de la venta...
	char fecha_de_venta[256];
	
	
	/// numeroVenta
	int nro_venta;
	
	char nro_transaccion[256];
	
};


/// pasa los datos al struct para despues poder
/// cargar/guardar el binario
inline structVentaRealizada pasarAStruct(string nombre_cantidad,string fec,string vendedor, string cliente,float total,string nrotrac){
	structVentaRealizada pS;
	strcpy(pS.vendedor,vendedor.c_str());
	strcpy(pS.productoycantidad,nombre_cantidad.c_str());
	strcpy(pS.cliente,cliente.c_str());
	pS.total = total;
	strcpy(pS.fecha_de_venta,fec.c_str());
	strcpy(pS.nro_transaccion,nrotrac.c_str());
	
	return pS; 
}
#endif

/// Funcion para calcular la cantidad de saltos de linea
	
inline int CantidadSaltos(string str){
	int c=0;
	for(size_t i=0;i<str.size();i++) { 
		if(str[i] == '\n') c++;
	}
	return c;	
}
	inline string gen_random(const int len) {
		static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
		string tmp_s;
		tmp_s.reserve(len);
		
		for (int i = 0; i < len; ++i) {
			tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
		}
		
		return tmp_s;
	}
