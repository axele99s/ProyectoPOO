#ifndef SISTEMAVENTA_H
#define SISTEMAVENTA_H
#include "fecha.h"
#include "Producto.h"
#include "productoVenta.h"
#include "BaseProductos.h"
#include "Login.h"
#include "registro_Ventas.h"


class SistemaVenta {
	
	BaseProductos *bp;
	BaseUsuarios *bu;
	Login *l;
	
	
	/// Eliminar las 2 de abajo
	registro_Ventas rV;
	fecha f;
	
	
	vector<productoVenta> prod_venta; /// vector temporal de los productos que se van a vender	
	string fecha_venta;
	float precio_final=0;
	
	string usuarioVendedor= "";
	string usuarioCliente = "Cliente final";
public:
	SistemaVenta(BaseProductos *baseprod=NULL,BaseUsuarios* baseuser=NULL,Login *log=NULL);
	
	/// Agregar cliente a la venta (o cliente final)
	bool agregarClienteVenta(int num);
	
	///
	string verCliente();
	string verEmpleado();
	/// carrito de venta
	bool agregarProductoVenta(Producto &p, float n);
	bool agregarProductoVenta(Producto &p);
	bool agregarProductoVenta(int codigo, float n);
	bool agregarProductoVenta(int codigo);
	bool cambiarCantidad(int i,float cantidad);
	bool cambiarCantidad_Codigo(int cod,float cantidad);
	void eliminarProductoDeCarrito(int i);
	int verUltimoAgregado();
	void eliminarProducto(int codigo);
	void clearCarrito();
	float subTotal();
	float calcularPrecio(int i);
	string carrito();
	vector<Producto> verCarritoDeProductos();
	
	/// Cantidad elegida del producto[i]
	float verCant(int i);
	int verCantConCodigo(int codigo);
	
	/// confirmar la venta
	void realizarVenta();
	bool estaEnCarrito(int cod);
	/// ver 
	int cantProdCarrito();
	
	Producto verProductoCarrito(int i); /// <- problema?
	
	vector<productoVenta> verCarritoCompleto();
};

#endif

	
