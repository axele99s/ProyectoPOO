#ifndef PRODUCTOVENTA_H
#define PRODUCTOVENTA_H
#include "Producto.h"
#include <vector>
using namespace std;

class productoVenta{
	float cantidad;
	Producto m_p;
	
public:
	productoVenta();
		
	void seleccionar_Producto(Producto &p,float cantidad); 
	
	string verNombreProducto();
	
	int verCodigoProducto();
	
	Producto verProductoSeleccionado();
	
	float verPrecio();
	
	float verCantProductoSeleccionado();
	
	float obtenerValor();
	
	float verCantidad();
	
	void cambiarCantidad(float cant);
	
};

#endif

