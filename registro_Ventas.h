#ifndef REGISTRO_VENTAS_H
#define REGISTRO_VENTAS_H
#include <vector>
#include "productoVenta.h"
#include <iostream>
#include <map>
#include "funcionesExtas.h"
using namespace std;





class registro_Ventas {
	vector<structVentaRealizada> svr_vector;
public:
	registro_Ventas();
	void guardarVenta(vector<productoVenta> pv,string vendedor,int cliente,float total);
	int cantidadVentas();
	
	
	void cargarHistorialVentas();
	void crearBinario();
	
	string verNroTransaccion(int i);
	
	structVentaRealizada verVenta(int i);
	vector<prodsVenta> verProductos(string trac);
	string verFechaVenta(string tranc);
	string verFechaVenta(int i);
	
	void eliminarVenta(string nro);
	void vaciarRegistro();
	
	
	bool transaccionExistente(string);
	
	vector<structVentaRealizada> buscarPorTransaccion(string trac);
	
	vector<structVentaRealizada> buscarPorDia(fecha f);
	vector<structVentaRealizada> buscarPorMes(fecha f);
	vector<structVentaRealizada> buscarPorAnio(fecha f);
	
	string randomNroTransaccion();
	
	
	
//	for(size_t i=0;i<svr_vector.size();i++) { 
//		
//	}

};

#endif
