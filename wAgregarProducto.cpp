#include "wAgregarProducto.h"
#include "string_conv.h"
#include "validaciones.h"

wAgregarProducto::wAgregarProducto(wxWindow *parent,BaseProductos *base) : ventanaAgregarProducto(parent), bp(base) {
	
}

void wAgregarProducto::agregarProductoBoton( wxCommandEvent& event )  {
	Producto p;
	p.ponerNombre(wx_to_std(nombreProducto_label->GetValue()));
	p.AgregarDescripcion(wx_to_std(descripcion_label->GetValue()));
	p.ponerPrecio(string_to_float(wx_to_std(precio_label->GetValue())));
	
	
	int tipo = (tipo_label->GetCurrentSelection());
	tipo++;
	if(tipo==1 or tipo==2) {
		p.CambiarStock(string_to_float(wx_to_std(cantidad_label->GetValue())));
		
	}
	else {
		p.CambiarStock(string_to_int(wx_to_std(cantidad_label->GetValue())));
	}
	
	int n =  rand()%10000+1;;
	
	/// Verifica que el codigo de producto creado al azar NO lo tenga otro producto
	/// Si lo tiene otro producto vuelve a hacer un rand
	for(int i=0;i<bp->sizeVectProd();i++) { 
		if(bp->existe(n) == true)  {
			n =  rand()%10000+1;;
			i=0;
		}
	}
	p.cambiarCodigo(n); /// Le asigna el codigo al productoStruct
	p.CambiarDescuento(string_to_float(descuento_label->GetValue().ToStdString())); /// Guarda el descuento asignado
	p.cambiarTipo(tipo);
	string str = juntar_vector_string(ValidarAgregadoProducto(p,bp));
	if(str.empty()){
		bp->AgregarProducto(p);
		EndModal(1);
	}
}

void wAgregarProducto::cancelarBoton( wxCommandEvent& event )  {
	EndModal(0);
}

wAgregarProducto::~wAgregarProducto() {
	
}

