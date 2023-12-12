#ifndef REGISTRO_VENTAS_H
#define REGISTRO_VENTAS_H
#include <vector>
#include "productoVenta.h"
#include <iostream>
#include <map>
#include "funcionesExtas.h"
using namespace std;





class registro_Ventas {
public:
	registro_Ventas();
	void guardarVenta(string str,string fec,string vendedor, string cliente,float total);
	int cantidadVentas();
	void cargarHistorialVentas();
	void crearBinario();
	
	string verNroTransaccion(int i);
	
	structVentaRealizada verVenta(int i);
	string verProductos(string trac);
	
	
	void eliminarVenta(string nro);
	void vaciarRegistro();
	
	string randomNroTransaccion();
	
	
	vector<structVentaRealizada> buscarPorFecha(string fecha);
	vector<structVentaRealizada> buscarPorHora(string hora);
	vector<structVentaRealizada> buscarPorTransaccion(string trac);
	
	vector<structVentaRealizada> buscarPorDia(string dia);
	vector<structVentaRealizada> buscarPorMes(string mes);
	vector<structVentaRealizada> buscarPorAnio(string anio);
	
private:
	
	vector<structVentaRealizada> svr_vector;
};

#endif
