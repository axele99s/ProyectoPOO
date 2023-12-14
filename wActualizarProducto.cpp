#include "wActualizarProducto.h"
#include "string_conv.h"
#include "validaciones.h"
#include <wx/msgdlg.h>

wActualizarProducto::wActualizarProducto(wxWindow *parent,Producto p,SistemaVenta *sis_ven,BaseProductos *bp,int num)
	: i(num),base_productos(bp),sistema_venta(sis_ven),prod(p),ventanaActualizarProducto(parent) 
	
{

	
	
	cantidadElegida->Disable();
	
	
	precioLabel->SetLabel(float_to_str(prod.verPrecio()));
	productoNombre->SetLabel(p.verNombreProducto()); /// En el label muestro el nombre
	
	descripcionLabel->SetLabel(p.verDescripcion());
	descuentoLabel->SetValue(float_to_str(prod.verDescuento()));
	
	/// Si viene de la grilla del carrito, pone la cantidad elegida
	if(i==1)cantidadElegida->SetValue(float_to_str(p.verStock()));
	
	
	/// Carga el stock desde la base de producto
	Producto m = base_productos->verConCodigo(p.verCodigoProducto());
	cantStock->SetLabel(float_to_str((m.verStock()))); /// y el stock disponible
	
	/// En caso de que le llegue un producto 
	/// Desde el carrito VIENE CON LA CANTIDAD ELEGIDA
	/// ESTO ESTA PARA EVITAR QUE SE CONFUNDAN O MEZCLEN LAS CANTIDADES
	if(sistema_venta!=NULL) {
		cantidadElegida->Enable();
		if(base_productos==NULL)cantidadElegida->SetValue("");
		descuentoLabel->Disable();
		precioLabel->Disable();
		descripcionLabel->Disable();
		cantStock->Disable();
		
	}
}

void wActualizarProducto::confirmarCarrito( wxCommandEvent& event )  {
	/// Modificar desde lista de productos
	if(sistema_venta==NULL) {
		
		float descuento = string_to_float(wx_to_std(descuentoLabel->GetValue()));
		
		string descripcion = wx_to_std(descripcionLabel->GetValue());
		float precio = string_to_float(wx_to_std(precioLabel->GetValue()));
		
		Producto p = prod;
		p.cambiarTipo(prod.verTipo());
		if(p.verTipo()==1 or p.verTipo()==2) {
			float cantidad = string_to_float(wx_to_std(cantStock->GetValue()));
			p.CambiarStock(cantidad);
			
		}
		else {
			float cantidad = string_to_int(wx_to_std(cantStock->GetValue()));
			p.CambiarStock(cantidad);
		}
		
		p.CambiarDescuento(descuento);
		p.AgregarDescripcion(descripcion);
		p.ponerPrecio(precio);
		
		
		
		string errores = juntar_vector_string(ValidarAgregadoProducto(p,base_productos));
		
		if(errores.empty()){
			int pos = base_productos->verPosProducto(p.verCodigoProducto());
			base_productos->ModificarProducto(pos,p);
			wxMessageBox("Se ha realizado la modificacion!","Modificado",wxOK);
			EndModal(1);
		}
		else {
			wxMessageBox(errores,"",wxOK);
		}
	}
	
	
	
	/// agregar desde "realizar venta"
	else {
		if(i==-1) {
			/// El producto temporal que cree "prod" toma el valor de la cantidad del label
			/// (o -1 para validar) y hace las respectivas validaciones
			float cantidad = -1.01;
			
			if(prod.verTipo()==1 or prod.verTipo()==2) {
				
				if(cantidadElegida->GetValue()!="")	cantidad = string_to_float(wx_to_std(cantidadElegida->GetValue())); /// Obtengo el valor del label
				
			}
			else {
				if(cantidadElegida->GetValue()!="")	cantidad = string_to_int(wx_to_std(cantidadElegida->GetValue())); /// Obtengo el valor del label
			}
			
			
			prod.CambiarStock(cantidad);
			string errores = juntar_vector_string(ValidarAgregadoCarrito(prod,base_productos));
			if(errores.empty()) { /// Si no hay errores, agrego el producto
				sistema_venta->agregarProductoVenta(prod,cantidad);
				EndModal(1);
			}
			else {
				wxMessageBox(errores,"Error Cantidad",wxOK); 
			}
			
			
			
		}
		/// MODIFCIAR desde el carrito
		else {
			float cantidad = -1.01;
			if(cantidadElegida->GetValue()!="")	cantidad = string_to_float(wx_to_std(cantidadElegida->GetValue())); /// Obtengo el valor del label
			prod.CambiarStock(cantidad);
			string errores = juntar_vector_string(ValidarAgregadoCarrito(prod,base_productos));
			if(errores.empty()) { /// Si no hay errores, agrego el producto
				sistema_venta->cambiarCantidad_Codigo(prod.verCodigoProducto(),cantidad);
				EndModal(1);
			}
			else {
				wxMessageBox(errores,"Error Cantidad",wxOK); 
			}
			
			
		}
	}
}

void wActualizarProducto::volverElegirProd( wxCommandEvent& event )  {
	EndModal(0);
}

wActualizarProducto::~wActualizarProducto() {
	
}

