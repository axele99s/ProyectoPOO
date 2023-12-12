#include "productoVenta.h"
#include <iostream>
using namespace std;

productoVenta::productoVenta() {
	
}




void productoVenta::seleccionar_Producto (Producto & p, float cantidad) {
	this->cantidad = cantidad;
	m_p = p;
	
}

float productoVenta::obtenerValor ( ) {
	float price;
	if(m_p.verDescuento()>0) {
		price = m_p.verPrecio()*cantidad * (1-m_p.verDescuento()/100);
		return price;
	}
	else {
		price = m_p.verPrecio()*cantidad;
	}
	return price;
}

Producto productoVenta::verProductoSeleccionado ( ) {
	return m_p;
}

float productoVenta::verCantProductoSeleccionado ( ) {
	return cantidad;
}

string productoVenta::verNombreProducto ( ) {
	return m_p.verNombreProducto();
}

void productoVenta::cambiarCantidad (float cant ) {
	cantidad = cant;
}

int productoVenta::verCodigoProducto ( ) {
	return m_p.verCodigoProducto();
}

float productoVenta::verCantidad ( ) {
	return cantidad;
}

float productoVenta::verPrecio ( ) {
	return m_p.verPrecio();
}

