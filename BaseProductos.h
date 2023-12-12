#ifndef BASEPRODUCTOS_H
#define BASEPRODUCTOS_H
#include <vector>
#include "Producto.h"
#include <fstream>
#include <iostream>
using namespace std;




class BaseProductos {
public:
	BaseProductos();
	
	/// binarios
	void CrearBIN();
	void CargarBIN();
	
	/// agregar / eliminar
	void AgregarProducto (Producto &p);
	bool EliminarProducto (Producto &p);
	
	
	/// modificar
	void ModificarProducto(int i,Producto &pp); /// Modifica al producto[i], por el nuevo dado;
	
	
	/// Actualizar/cambiar datos
	void actualizarDescripcion(string descripcion,int codigo);
	void actualizarCantidad(float cantidad,int codigo);
	void cambiarDescuento(float descuento,int codigo);
	void cambiarPrecio(float precio,int codigo);
	
	/// ver 
	int sizeVectProd();
	Producto verProducto(int i); /// Return un prod del vector con la pos dada
	Producto verConCodigo(int cod);
	int verPosProducto(int codigo);
	
	/// @a borrar 
//	bool operator==(int cod); /// BORRAR
//	int compararCodigo(Producto &p);	 /// return de la pos de un producto de igual codigo
	
	
	/// bools
	bool existe(int cod);
//	bool buscarConNombre(string nombre); /// Esta funcion no me convence del todo, segun lo implemente
//										/// no se pueden agregar productos con mismo nombre
	/// filtro para busqueda
	vector<Producto> buscarPorNombre(string nombre_prod);
	vector<Producto> obtenerProductosEnStock();
	vector<Producto> buscarPorCodigo(string nombre_prod);
	

	
private:
		vector<Producto> productos;
};

#endif

