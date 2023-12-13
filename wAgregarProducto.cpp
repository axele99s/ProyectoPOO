#include "wAgregarProducto.h"
#include "string_conv.h"
#include "validaciones.h"

wAgregarProducto::wAgregarProducto(wxWindow *parent,BaseProductos *base) : ventanaAgregarProducto(parent), bp(base) {
	
}

void wAgregarProducto::agregarProductoBoton( wxCommandEvent& event )  {
	Producto p;
	p.ponerNombre(wx_to_std(nombreProducto_label->GetValue()));
	p.AgregarDescripcion(wx_to_std(descripcion_label->GetValue()));

	
	if(!precio_label->IsEmpty()) 	p.ponerPrecio(string_to_float(wx_to_std(precio_label->GetValue())));
	if(!descuento_label->IsEmpty()) p.CambiarDescuento(string_to_float(descuento_label->GetValue().ToStdString()));
	
	int tipo = (tipo_label->GetCurrentSelection());
	tipo++;
	p.cambiarTipo(tipo);
	
	if(!cantidad_label->IsEmpty())  {
		if(tipo==1 or tipo==2) {
			p.CambiarStock(string_to_float(wx_to_std(cantidad_label->GetValue())));
			
		}
		else {
			p.CambiarStock(string_to_int(wx_to_std(cantidad_label->GetValue())));
		}
	}
	
	
//	int n =  rand()%10000+1;;
	

	/// Verifica que el codigo de producto creado al azar NO lo tenga otro producto
	/// Si lo tiene otro producto vuelve a hacer un rand
//	for(int i=0;i<bp->sizeVectProd();i++) { 
//		if(bp->existe(n) == true)  {
//			n =  rand()%10000+1;;
//			i=0;
//		}
//	}
//	p.cambiarCodigo(n); /// Le asigna el codigo al productoStruct
	string errores = juntar_vector_string(ValidarAgregadoProducto(p,bp));
	if(errores.empty()){
		bp->AgregarProducto(p);
		EndModal(1);
	}
	else wxMessageBox(errores,"",wxOK);
}

void wAgregarProducto::cancelarBoton( wxCommandEvent& event )  {
	EndModal(0);
}

wAgregarProducto::~wAgregarProducto() {
	
}

