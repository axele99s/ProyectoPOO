#include "BaseProductos.h"
#include <cstring>
#include "string_conv.h"
#include "funcionesExtas.h"
using namespace std;

struct productoStruct{
	char nombre[256];
	int codigo;
	int tipo;
	float cantidad=0.0;
	float precio=0.0;
	float descuento;
	char desc[256];
};

BaseProductos::BaseProductos() {
//	CrearBIN();
	CargarBIN();
}
/**------------------------BINARIOS -------------------------- */
void BaseProductos::CrearBIN ( ) {
	ofstream productosBin("Productos.bin",ios::binary | ios::trunc);
	
	/// String a chars de los productos 
	
		for(size_t i=0;i<productos.size();i++) { 
			
			productoStruct p;
			
			strcpy(p.nombre,productos[i].verNombreProducto().c_str());
			strcpy(p.desc,productos[i].verDescripcion().c_str());
			p.codigo = productos[i].verCodigoProducto();
			p.precio = productos[i].verPrecio();
			p.tipo = productos[i].verTipo();
			p.cantidad = productos[i].verStock();
			p.descuento = productos[i].verDescuento();
			
			productosBin.write(reinterpret_cast<char*>(&p),sizeof(productoStruct));
		}
	
	
}

void BaseProductos::CargarBIN ( ) {
	ifstream productosBin("productos.bin",ios::binary|ios::ate);
	if(productosBin.is_open()) {
	
	int n = productosBin.tellg();
	int cant_productos = n/sizeof(productoStruct);
	
	productosBin.seekg(0);
	
	for(int i=0;i<cant_productos;i++) { 
		productoStruct p;
		productosBin.read(reinterpret_cast<char*>(&p),sizeof(p));
		productos.push_back({p.codigo,p.nombre,p.precio,p.tipo,p.cantidad,p.descuento,p.desc});
		
	}
	}
}





/**--------------- AGREGAR / ELIMINAR -------------------*/

void BaseProductos::AgregarProducto (Producto & p) {
	
	int n =  rand()%10000+1;
	for(size_t i=0;i<productos.size();i++) { 
		if(existe(n) == true)  {
			n =  rand()%10000+1;;
			i=0;
		}
	}
	
	p.cambiarCodigo(n);
	productos.push_back(p); 
	CrearBIN();
}

bool BaseProductos::EliminarProducto (Producto & p) {
	auto it=productos.begin();
	for(size_t i=0;i<productos.size();i++) 
		if(p==productos[i]){ 
		advance(it,i);
		productos.erase(it);
		CrearBIN();
		return true;
	}
	return false;	
}







/// --------------- MODIFICAR

void BaseProductos::ModificarProducto (int i, Producto &pp) {
	productos[i] = pp;
	CrearBIN();
}

/// --------------- Actualizar / MODIFICAR




void BaseProductos::actualizarCantidad (float cantidad, int codigo) {
	int i = verPosProducto(codigo);
	if(i!=-1) {
		productos[i].CambiarStock(cantidad);
		CrearBIN();
	}
}



void BaseProductos::cambiarDescuento (float descuento, int codigo) {
	int i = verPosProducto(codigo);
	if(i!=-1) {
		productos[i].CambiarDescuento(descuento);
		CrearBIN();
	}
}

void BaseProductos::actualizarDescripcion (string descripcion, int codigo) {
	int i = verPosProducto(codigo);
	if(i!=-1) {
		productos[i].AgregarDescripcion(descripcion);
		CrearBIN();
	}
}

void BaseProductos::cambiarPrecio (float precio, int codigo) {
	int i = verPosProducto(codigo);
	if(i!=-1) {
		productos[i].ponerPrecio(precio);
		CrearBIN();
	}
}



/// --------------- Ver producto


int BaseProductos::sizeVectProd ( ) {
	return productos.size();
}

Producto BaseProductos::verConCodigo (int codigo) {
	int i = verPosProducto(codigo);
	if(i!=-1) {
		return productos[i];
		
	}
	
}

Producto BaseProductos::verProducto (int i) {
	return productos[i];
}

int BaseProductos::verPosProducto (int codigo) {
	int i =-1;
	for(size_t i=0;i<productos.size();i++) { 
		if(productos[i].verCodigoProducto() == codigo) return i;
	}
	return i;
}

///------------ BOOLS



bool BaseProductos::existe (int codigo) {
	int i = verPosProducto(codigo);
	return i!=-1;
}








//int BaseProductos::compararCodigo (Producto & p) {
//	for(size_t i=0;i<productos.size();i++) { 
//		if(p.verCodigoProducto() == productos[i].verCodigoProducto()) return i;
//		
//	}
//	return -1;
//}




/// BORRAR
//bool BaseProductos::operator== (int cod) {
//	for(size_t i=0;i<productos.size();i++) { 
//		if(productos[i].verCodigoProducto() == cod) return true;
//	}
//	return false;
//}













//Producto BaseProductos::buscarPorNombre (string nombre_prod,int pos) {
//	Producto p = productos[pos];
//	if(p.verNombreProducto().find(nombre_prod)!=string::npos) return p;
//	return Producto();
//}



vector<Producto> BaseProductos::buscarPorNombre (string nombre_prod) {
	vector<Producto> p;
	for(size_t i=0;i<productos.size();i++) { 
//		string codigoProducto= int_to_str(productos[i].verCodigoProducto()); /// Codigo del producto[pos]
		string nombre_temp = productos[i].verNombreProducto(); 
		if(minuscula(nombre_temp).find(minuscula(nombre_prod))!=string::npos) {p.push_back(productos[i]);}
	}
	
	return p;
}


//Producto BaseProductos::buscarPorCodigo (string codigoTemporal,int pos) {
//	Producto p = productos[pos];
//	string codigoProducto= int_to_str(p.verCodigoProducto()); /// Codigo del producto[pos]
//	
//	
//	if(codigoProducto.find(codigoTemporal)!=string::npos) return p;
//	return Producto();
//}
//
//bool BaseProductos::buscarConNombre (string nombre) {
//	if(nombre=="") return false;
//	for(size_t i=0;i<productos.size();i++) { 
//		if(productos[i].verNombreProducto() == nombre) return true;
//	}
//	return false;
//}

/// FILTROS DE BUSQUEDA 
vector<Producto> BaseProductos::buscarPorCodigo (string codigoTemporal) {
	vector<Producto> p;
	
	for(size_t i=0;i<productos.size();i++) { 
		string codigoProducto = int_to_str(productos[i].verCodigoProducto());
		if(codigoProducto.find(codigoTemporal)!=string::npos) {p.push_back(productos[i]);}
	}
	
	
	
	
	return p;
}


vector<Producto> BaseProductos::obtenerProductosEnStock ( ) {
	vector<Producto> enStock;
	for(int i=0;i<productos.size();i++) { 
		if(productos[i].verStock()>0) {
			enStock.push_back(productos[i]);
		}
	}
	return enStock;
}

