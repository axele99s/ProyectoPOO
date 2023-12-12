#include "Producto.h"

/// Constructores

Producto::Producto ( ) {
	
}

Producto::Producto (int cod) {
		
}


Producto::Producto (int cod,string nom,float precio,int tipo,float cantidad,float desc,string descrip) {
	nombre_producto=nom;
	codigo_producto=cod;
	precio_producto=precio;
	cant_stock=cantidad;
	this->tipo = tipo;
	descuento = desc;
	descripcion = descrip;
}

/// Ver Productos
string Producto::verNombreProducto ( ) {
	return nombre_producto;
}

int Producto::verCodigoProducto ( ) {
	return codigo_producto;
}

string Producto::verDescripcion() {
	return descripcion;
}

float Producto::verDescuento ( ) {
	return descuento;
}
/// Definir productos

void Producto::ponerNombre (string nom_prd) {
	nombre_producto=nom_prd;
}

void Producto::ponerPrecio (float price) {
	precio_producto=price;
}

void Producto::CambiarStock (float n) {
	cant_stock=n;
}

float Producto::verStock ( ) {
	return cant_stock;
}

float Producto::verPrecio ( ) {
	return precio_producto;
}

int Producto::verTipo ( ) {
	return tipo;
}

bool Producto::operator== (Producto & p) {
	return this->codigo_producto == p.verCodigoProducto();
}

void Producto::AgregarDescripcion (string str) {
	descripcion=str;
}

void Producto::CambiarDescuento (float i) {
	descuento=i;
}


bool Producto::operator== (int cod) {
	return cod == this->codigo_producto;
}

void Producto::cambiarTipo (int i) {
	tipo = i;
}

void Producto::cambiarCodigo (int i) {
	codigo_producto = i;
}

