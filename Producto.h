#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
using namespace std;

class Producto {
private:
	string nombre_producto="", descripcion="";
	int tipo, codigo_producto=-1;
	float precio_producto=0.0, cant_stock=0.0;
	float descuento=0.0;
public:
	
	/// constructores
	Producto();
	Producto(int cod);
	Producto(int cod,string nom,float precio,int tipo,float cantidad,float descuento,string desc);
	
	///Getters
	string verNombreProducto();
	int verCodigoProducto();
	float verStock();
	float verPrecio();
	int verTipo();
	float verDescuento();
	string verDescripcion();
	
	/// Setters
	void ponerNombre(string nom_prd);
	void ponerPrecio(float price);
	void CambiarStock(float n);
	void AgregarDescripcion(string str);
	void CambiarDescuento(float i);
	void cambiarTipo(int i);
	void cambiarCodigo(int i);
	
	
	/// Sobrecarga (las use al final?)
	bool operator== (Producto &p);
	bool operator== (int cod);
	
	


};

#endif

