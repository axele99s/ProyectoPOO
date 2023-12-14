
#include "registro_Ventas.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include "string_conv.h"
#include "validaciones.h"
#include "funcionesExtas.h"
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
		ventaBin.write(reinterpret_cast<char*>(&svr.total),sizeof(svr.total));
		ventaBin.write(reinterpret_cast<char*>(&svr.nro_transaccion),sizeof(svr.nro_transaccion));
		ventaBin.write(reinterpret_cast<char*>(&svr.dia),sizeof(svr.dia));
		ventaBin.write(reinterpret_cast<char*>(&svr.mes),sizeof(svr.mes));
		ventaBin.write(reinterpret_cast<char*>(&svr.anio),sizeof(svr.anio));
		ventaBin.write(reinterpret_cast<char*>(&svr.hora),sizeof(svr.hora));
		ventaBin.write(reinterpret_cast<char*>(&svr.minuto),sizeof(svr.minuto));
		ventaBin.write(reinterpret_cast<char*>(&svr.segundo),sizeof(svr.segundo));
		ventaBin.write(reinterpret_cast<char*>(&svr.n),sizeof(svr.n));
		
		for(int j=0;j<svr.n;j++) { 
			prodsVenta prods_venta = svr.pv[j];
			ventaBin.write(reinterpret_cast<char*>(&prods_venta.nombre),sizeof(&prods_venta.nombre));
			ventaBin.write(reinterpret_cast<char*>(&prods_venta.codigo),sizeof(prods_venta.codigo));
			ventaBin.write(reinterpret_cast<char*>(&prods_venta.cantidad),sizeof(prods_venta.cantidad));
			ventaBin.write(reinterpret_cast<char*>(&prods_venta.precio),sizeof(&prods_venta.precio));
			
		}
	}
	
	
}
void registro_Ventas::cargarHistorialVentas ( ) {
	svr_vector.clear();
	ifstream ventasBin("historialVentas.bin",ios::binary);
	if(!ventasBin.is_open()) return;
	
	
	
	for(;;)
	{
		structVentaRealizada vectorSVR;
		ventasBin.read(reinterpret_cast<char*>(&vectorSVR.vendedor),sizeof(vectorSVR.vendedor)); 
		ventasBin.read(reinterpret_cast<char*>(& vectorSVR.cliente ),sizeof(vectorSVR.cliente)); 
		ventasBin.read(reinterpret_cast<char*>(& vectorSVR.total),sizeof(vectorSVR.total));
		ventasBin.read(reinterpret_cast<char*>(& vectorSVR.nro_transaccion),sizeof(vectorSVR.nro_transaccion));
		ventasBin.read(reinterpret_cast<char*>(&vectorSVR.dia),sizeof(vectorSVR.dia));
		ventasBin.read(reinterpret_cast<char*>(&vectorSVR.mes),sizeof(vectorSVR.mes));
		ventasBin.read(reinterpret_cast<char*>(&vectorSVR.anio),sizeof(vectorSVR.anio));
		ventasBin.read(reinterpret_cast<char*>(&vectorSVR.hora),sizeof(vectorSVR.hora));
		ventasBin.read(reinterpret_cast<char*>(&vectorSVR.minuto),sizeof(vectorSVR.minuto));
		ventasBin.read(reinterpret_cast<char*>(&vectorSVR.segundo),sizeof(vectorSVR.segundo));
		ventasBin.read(reinterpret_cast<char*>(&vectorSVR.n),sizeof(vectorSVR.n));
		
		
		
		for(int i=0;i<vectorSVR.n;i++) { 
			prodsVenta prods_venta;
			
			ventasBin.read(reinterpret_cast<char*>(&prods_venta.nombre),sizeof(&prods_venta.nombre));
			ventasBin.read(reinterpret_cast<char*>(&prods_venta.codigo),sizeof(prods_venta.codigo));
			ventasBin.read(reinterpret_cast<char*>(&prods_venta.cantidad),sizeof(prods_venta.cantidad));
			ventasBin.read(reinterpret_cast<char*>(&prods_venta.precio),sizeof(&prods_venta.precio));
			
			vectorSVR.pv.push_back(prods_venta);
		}
		
		if(!ventasBin) 
			break;
		svr_vector.push_back(vectorSVR);
		
		
	}
	reverse(svr_vector.begin(),svr_vector.end());
}


void registro_Ventas::guardarVenta (vector<productoVenta> pv, string vendedor, int cliente,float total) {
	
	ofstream ventaBin("historialVentas.bin",ios::binary| ios::app);
	
	
	
	
	structVentaRealizada svr = pasarAStruct(pv,vendedor,cliente,total,randomNroTransaccion(),pv.size());
	svr_vector.push_back(svr);
	
	
	
	crearBinario();
//	ventaBin.write(reinterpret_cast<char*>(&svr.vendedor),sizeof(svr.vendedor));
//	ventaBin.write(reinterpret_cast<char*>(&svr.cliente),sizeof(svr.cliente));
//	ventaBin.write(reinterpret_cast<char*>(&svr.total),sizeof(svr.total));
//	ventaBin.write(reinterpret_cast<char*>(&svr.nro_transaccion),sizeof(svr.nro_transaccion));
//	
//	
//	
//	ventaBin.write(reinterpret_cast<char*>(&svr.dia),sizeof(svr.dia));
//	ventaBin.write(reinterpret_cast<char*>(&svr.mes),sizeof(svr.mes));
//	ventaBin.write(reinterpret_cast<char*>(&svr.anio),sizeof(svr.anio));
//	ventaBin.write(reinterpret_cast<char*>(&svr.hora),sizeof(svr.hora));
//	ventaBin.write(reinterpret_cast<char*>(&svr.minuto),sizeof(svr.minuto));
//	ventaBin.write(reinterpret_cast<char*>(&svr.segundo),sizeof(svr.segundo));
//	ventaBin.write(reinterpret_cast<char*>(&svr.n),sizeof(svr.n));
//	
//	for(size_t i=0;i<pv.size();i++) { 
//		ventaBin.write(reinterpret_cast<char*>(&svr.pv[i].nombre),sizeof(&svr.pv[i].nombre));
//		ventaBin.write(reinterpret_cast<char*>(&svr.pv[i].codigo),sizeof(&svr.pv[i].codigo));
//		ventaBin.write(reinterpret_cast<char*>(&svr.pv[i].cantidad),sizeof(&svr.pv[i].cantidad));
//		ventaBin.write(reinterpret_cast<char*>(&svr.pv[i].precio),sizeof(&svr.pv[i].precio));
//	}
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

	inline string gen_random(const int len) {
static const char alphanum[] = "abcdefghijklmnopqrstuvwxyz";
string tmp_s;
tmp_s.reserve(len);

for (int i = 0; i < len; ++i) {
	tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
}

		return tmp_s;
	}
	

string registro_Ventas::randomNroTransaccion ( ) {
	string str;
	long nro = rand()%100000+1;
	
	
	string random = gen_random(3);
	str = random+int_to_str(nro);
	
	while(transaccionExistente(str)==true){
		nro = rand()%100000+1;
		random = gen_random(3);
		str = random + int_to_str(nro);
	}
	
	
	return str;
}


bool registro_Ventas::transaccionExistente (string trac) {
	
	//	if(svr_vector.empty())return false;
//	for(size_t i=0;i<svr_vector.size();i++) { 
//		string nrotrac = svr_vector[i].nro_transaccion;
//		if(nrotrac == trac ) return true;
//	}
	return false;
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
		
		
		
//		fecha f(svr_vector[i].dia,svr_vector[i].mes,svr_vector[i].anio);
		
		string f = verFechaVenta(i); 

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
		
		
		
		string f = verFechaVenta(i); 
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
		string f = verFechaVenta(i); 
//		string fecha_temp = convertirFecha(f); 		/// la paso a un formato para el filtro 
		if((f).find(anio)!=string::npos) {
			svr.push_back(svr_vector[i]);
		}
	}
	
	
	return svr;
}

vector<prodsVenta> registro_Ventas::verProductos (string trac) {
	for(size_t i=0;i<svr_vector.size();i++) { 
		if(svr_vector[i].nro_transaccion == trac) return svr_vector[i].pv;
	}
}





string registro_Ventas::verFechaVenta (string tranc) {
	for(size_t i=0;i<svr_vector.size();i++) { 
		
		string transaccion = svr_vector[i].nro_transaccion;
		
		if(transaccion == tranc){
			string fecha_venta = int_to_str(svr_vector[i].dia) + " " + int_to_str(svr_vector[i].mes) + " " +int_to_str(svr_vector[i].anio); 
			return fecha_venta;
		}
			
	}
}

string registro_Ventas::verFechaVenta (int i ) {
	
	
	return int_to_str(svr_vector[i].dia) + "-" + int_to_str(svr_vector[i].mes) + "-" +int_to_str(svr_vector[i].anio)+" "+int_to_str(svr_vector[i].hora) + ":" + int_to_str(svr_vector[i].minuto) + ":" +int_to_str(svr_vector[i].segundo);
}



