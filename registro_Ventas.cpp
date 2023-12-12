#include "registro_Ventas.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include "string_conv.h"
#include "validaciones.h"
//#include "funcionesExtas.h"
#include <algorithm>
using namespace std;

/// Constructor
registro_Ventas::registro_Ventas() {
	cargarHistorialVentas();
}

void registro_Ventas::crearBinario ( ) {
	ofstream ventaBin("historialVentas.bin",ios::binary|ios::trunc);
	
	for(size_t i=0;i<svr_vector.size();i++) { 
		structVentaRealizada svr = svr_vector[i];
		ventaBin.write(reinterpret_cast<char*>(&svr.vendedor),sizeof(svr.vendedor));
		ventaBin.write(reinterpret_cast<char*>(&svr.cliente),sizeof(svr.cliente));
		ventaBin.write(reinterpret_cast<char*>(&svr.fecha_de_venta),sizeof(svr.fecha_de_venta));
		ventaBin.write(reinterpret_cast<char*>(&svr.total),sizeof(svr.total));
		ventaBin.write(reinterpret_cast<char*>(&svr.productoycantidad),sizeof(svr.productoycantidad));
		ventaBin.write(reinterpret_cast<char*>(&svr.nro_transaccion),sizeof(svr.nro_transaccion));
	}
	
	
}
void registro_Ventas::cargarHistorialVentas ( ) {
	svr_vector.clear();
	ifstream ventasBin("historialVentas.bin",ios::binary);
	
	for(;;)
	{
		structVentaRealizada vectorSVR;
		ventasBin.read(reinterpret_cast<char*>(&vectorSVR.vendedor),sizeof(vectorSVR.vendedor)); 
		ventasBin.read(reinterpret_cast<char*>(& vectorSVR.cliente ),sizeof(vectorSVR.cliente)); 
		ventasBin.read(reinterpret_cast<char*>(& vectorSVR.fecha_de_venta),sizeof(vectorSVR.fecha_de_venta)); 
		ventasBin.read(reinterpret_cast<char*>(& vectorSVR.total),sizeof(vectorSVR.total));
		ventasBin.read(reinterpret_cast<char*>(& vectorSVR.productoycantidad),sizeof(vectorSVR.productoycantidad));
		ventasBin.read(reinterpret_cast<char*>(& vectorSVR.nro_transaccion),sizeof(vectorSVR.nro_transaccion));
		
		if(!ventasBin) 
			break;
		svr_vector.push_back(vectorSVR);
		
		
	}
	reverse(svr_vector.begin(),svr_vector.end());
}


void registro_Ventas::guardarVenta (string productonombrecantidad, string fec, string vendedor, string cliente,float total) {
	ofstream ventaBin("historialVentas.bin",ios::binary| ios::app);
	
	
	structVentaRealizada svr = pasarAStruct(productonombrecantidad,fec,vendedor,cliente,total,randomNroTransaccion());
	
	
	ventaBin.write(reinterpret_cast<char*>(&svr.vendedor),sizeof(svr.vendedor));
	ventaBin.write(reinterpret_cast<char*>(&svr.cliente),sizeof(svr.cliente));
	ventaBin.write(reinterpret_cast<char*>(&svr.fecha_de_venta),sizeof(svr.fecha_de_venta));
	ventaBin.write(reinterpret_cast<char*>(&svr.total),sizeof(svr.total));
	ventaBin.write(reinterpret_cast<char*>(&svr.productoycantidad),sizeof(svr.productoycantidad));
	ventaBin.write(reinterpret_cast<char*>(&svr.nro_transaccion),sizeof(svr.nro_transaccion));
	
	
}




int registro_Ventas::cantidadVentas ( ) {
	return svr_vector.size();
}

structVentaRealizada registro_Ventas::verVenta (int i) {
	return svr_vector[i];
}

void registro_Ventas::eliminarVenta (string nro) {
	auto it = svr_vector.begin();
	for(size_t i=0;i<svr_vector.size();i++) { 
		if(nro == verNroTransaccion(i)) {
			advance(it,i);
			svr_vector.erase(it);
			
		}
	}
	crearBinario();
	
}

void registro_Ventas::vaciarRegistro ( ) {
	svr_vector.clear();
	crearBinario();
	cargarHistorialVentas();
}

string registro_Ventas::verNroTransaccion (int i) {
	return svr_vector[i].nro_transaccion;
	
}

string registro_Ventas::randomNroTransaccion ( ) {
	string str;
	long nro = rand()%100000+1;
	string random = gen_random(3);
	str = random + int_to_str(nro);
	for(size_t i=0;i<svr_vector.size();i++) { 
		if(str == verNroTransaccion(i)) {
			nro = rand()%100000+1;
			str = random + int_to_str(nro);
			
			i=0;
		}
	}
	
	return str;
}



//vector<structVentaRealizada> registro_Ventas::buscarPorFecha (string fecha) {
//	vector<structVentaRealizada> svr;
//	for(size_t i=0;i<svr_vector.size();i++) { 
//		
//		string f = svr_vector[i].fecha_de_venta; 
//		string fecha_temp = convertirFecha(f); 		/// la paso a un formato para el filtro 
//		if((fecha_temp).find(fecha)!=string::npos) {
//			svr.push_back(svr_vector[i]);
//		}
//	}
//	
//	
//	return svr;
//}

vector<structVentaRealizada> registro_Ventas::buscarPorTransaccion (string trac) {
	vector<structVentaRealizada> svr;
	for(size_t i=0;i<svr_vector.size();i++) { 
		string aux = svr_vector[i].nro_transaccion;
		if((aux).find(trac)!=string::npos) {
			svr.push_back(svr_vector[i]);
		}
	}
	
	
	return svr;
}


vector<structVentaRealizada> registro_Ventas::buscarPorDia (string dia) {
	vector<structVentaRealizada> svr;
	for(size_t i=0;i<svr_vector.size();i++) { 
		string f = svr_vector[i].fecha_de_venta; 
		string fecha_temp = convertirFecha(f); 		/// la paso a un formato para el filtro 
		if((fecha_temp).find(dia)!=string::npos) {
			svr.push_back(svr_vector[i]);
		}
	}
	
	
	return svr;
}

vector<structVentaRealizada> registro_Ventas::buscarPorMes (string mes) {
	vector<structVentaRealizada> svr;
	for(size_t i=0;i<svr_vector.size();i++) { 
		string f = svr_vector[i].fecha_de_venta; 
		string fecha_temp = convertirFecha(f); 		/// la paso a un formato para el filtro 
		if((fecha_temp).find(mes)!=string::npos) {
			svr.push_back(svr_vector[i]);
		}
	}
	
	
	return svr;
}

vector<structVentaRealizada> registro_Ventas::buscarPorAnio (string anio) {
	vector<structVentaRealizada> svr;
	for(size_t i=0;i<svr_vector.size();i++) { 
		string f = svr_vector[i].fecha_de_venta; 
		string fecha_temp = convertirFecha(f); 		/// la paso a un formato para el filtro 
		if((fecha_temp).find(anio)!=string::npos) {
			svr.push_back(svr_vector[i]);
		}
	}
	
	
	return svr;
}

string registro_Ventas::verProductos (string trac) {
	for(size_t i=0;i<svr_vector.size();i++) { 
		if(svr_vector[i].nro_transaccion == trac) return svr_vector[i].productoycantidad;
	}
}

