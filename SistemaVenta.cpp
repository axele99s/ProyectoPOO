#include "SistemaVenta.h"
#include "string_conv.h"


SistemaVenta::SistemaVenta (BaseProductos * baseprod, BaseUsuarios * baseuser, Login * log): bp(baseprod), bu(baseuser),l(log) {
	usuarioVendedor = l->verNombreUsuario();
}	
	

/// Esta func sirve para agregar productos al carrito
bool SistemaVenta::agregarProductoVenta (Producto & p, float n) {
	
	/// Si el producto ya existe, no lo agrega al carrito (puede eliminarlo o agregar mas cantidad)
	for(size_t i=0;i<prod_venta.size();i++) { 
		if(prod_venta[i].verCodigoProducto() == p.verCodigoProducto()) return false;
	}
	
	///@ en caso contrario lo agrego al carrito
	productoVenta pV;
	pV.seleccionar_Producto(p,n);
	prod_venta.push_back(pV);
	return true;
}

bool SistemaVenta::agregarProductoVenta (int codigo, float n) {
	
	
	Producto p = bp->verConCodigo(codigo);
	
//	for(size_t i=0;i<prod_venta.size();i++) { 
//		if( prod_venta[i].verCodigoProducto() == codigo) return false;
//	}
	
//	if(BaseProductos()==codigo and p.verStock()>=n and n>=0) {		
		productoVenta pV;
		pV.seleccionar_Producto(p,n);
		prod_venta.push_back(pV);
		return true;
//	}
	return false;
}


void SistemaVenta::realizarVenta () {
	for(size_t i=0;i<prod_venta.size();i++) { 
		int codigo = prod_venta[i].verCodigoProducto();
		float cantidad_actualizada = bp->verConCodigo(codigo).verStock() - prod_venta[i].verCantidad();
		bp->actualizarCantidad(cantidad_actualizada,codigo);
	}

}



float SistemaVenta::subTotal ( ) {
	precio_final=0;
		for(size_t i=0;i<prod_venta.size();i++) { 
		
		precio_final+=prod_venta[i].obtenerValor();
		
	}
	return precio_final;
}

bool SistemaVenta::agregarClienteVenta (int num) {
	
	Cliente c = bu->verClientePorDNI(num);
	if(bu->check(c)){
		usuarioCliente = "Nombre: " + c.verNombre()+" \ " + " codigo cliente: " + int_to_str(c.verCodigoCliente());
		return true;
	}
	
	return false;
}

string SistemaVenta::carrito ( ) {
	if(prod_venta.size()>0) {
		string carrito="";
		for(size_t i=0;i<prod_venta.size();i++) { 
			carrito+= prod_venta[i].verNombreProducto() + " ("+ float_to_str(prod_venta[i].verCantidad())+")" + "[" + int_to_str(prod_venta[i].verCodigoProducto())+ "]" + "\n";
		}
	return carrito;
	}
	
	return "carrito vacio.";
}

///ver Esta funcion...
bool SistemaVenta::cambiarCantidad (int i, float cantidad) {
	
	int codigo = prod_venta[i].verCodigoProducto();
	
	if(i<prod_venta.size() and cantidad > 0 and cantidad<=bp->verConCodigo(codigo).verStock()){
		
		prod_venta[i].cambiarCantidad(cantidad);
		return true;
	}
	
	return false;
}

void SistemaVenta::eliminarProductoDeCarrito (int i) {
	
	if(i>=0 and i<=(prod_venta.size()-1)) {
		auto it=prod_venta.begin();
		advance(it,i);
		prod_venta.erase(it);
		it=prod_venta.begin();
		
		
	}
}



int SistemaVenta::cantProdCarrito ( ) {
	return prod_venta.size();
}

bool SistemaVenta::agregarProductoVenta (Producto & p) {
	
}

//bool SistemaVenta::agregarProductoVenta (int codigo) {
//	Producto p = bp->verConCodigo(codigo);
//	
//	for(size_t i=0;i<prod_venta.size();i++) { 
//		if( prod_venta[i].verCodigoProducto() == codigo) return false;
//	}
//	
//	if(BaseProductos() == codigo) {		
//		productoVenta pV;
//		pV.seleccionar_Producto(p,0);
//		prod_venta.push_back(pV);
//		return true;
//	}
//	return false;
//}

Producto SistemaVenta::verProductoCarrito (int i) {
	return prod_venta[i].verProductoSeleccionado();
}

void SistemaVenta::clearCarrito ( ) {
	auto it = prod_venta.begin();
	while(it!=prod_venta.end()) {
		prod_venta.erase(it);
		it=prod_venta.begin();
	}
	
}

bool SistemaVenta::estaEnCarrito (int cod) {
	for(size_t i=0;i<prod_venta.size();i++) { 
		if(prod_venta[i].verCodigoProducto() == cod) return true;
	}
	return false;
}

float SistemaVenta::verCant (int i) {
	return prod_venta[i].verCantidad();
}



void SistemaVenta::eliminarProducto (int codigo) {
	auto it = prod_venta.begin();
	for(size_t i=0;i<prod_venta.size();i++) { 
		if(prod_venta[i].verCodigoProducto()==codigo) {
			advance(it,i);
			prod_venta.erase(it);
			break;
		}
		
	}
}

bool SistemaVenta::cambiarCantidad_Codigo (int cod, float cantidad) {
	for(size_t i=0;i<prod_venta.size();i++) { 
		if(prod_venta[i].verCodigoProducto()==cod) {
			prod_venta[i].cambiarCantidad(cantidad);
		}
		
	}
}

int SistemaVenta::verUltimoAgregado ( ) {
	if(prod_venta.size()==0) return -1;
	if(prod_venta.size()==1) {
		return prod_venta[0].verCodigoProducto();
	}
	else return prod_venta[prod_venta.size()-1].verCodigoProducto();
}

int SistemaVenta::verCantConCodigo (int codigo) {
	for(size_t i=0;i<prod_venta.size();i++) { 
		if(prod_venta[i].verCodigoProducto()==codigo) {
			return verCant(i);
		}
	}
}

string SistemaVenta::verCliente ( ) {
	return usuarioCliente;
}

vector<productoVenta> SistemaVenta::verCarritoCompleto ( ) {
	return prod_venta;
}


string SistemaVenta::verEmpleado ( ) {
	return usuarioVendedor;
}

vector<Producto> SistemaVenta::verCarritoDeProductos ( ) {
	vector<Producto> p;
	for(size_t i=0;i<prod_venta.size();i++) { 
		p.push_back(prod_venta[i].verProductoSeleccionado());
	}
}

float SistemaVenta::calcularPrecio (int i) {
	return prod_venta[i].obtenerValor();
}

