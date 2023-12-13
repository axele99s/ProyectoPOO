#include "wRealizarVenta.h"
#include "string_conv.h"
#include "validaciones.h"
#include "wActualizarProducto.h"

wRealizarVenta::wRealizarVenta(wxWindow *parent,BaseProductos *base,SistemaVenta *sv
							   ,fecha *f,registro_Ventas *reg, Login *l) 
	: log(l),registro(reg),m_fecha(f),ventanaRealizarVenta(parent),bp(base),sis_ven(sv) {
	enStock = bp->obtenerProductosEnStock();
	
	actualizarGrillaDisponibles(enStock);
	
	
	grillaCarrito->DisableCellEditControl();
}





void wRealizarVenta::barraBuscadorVentaOnText( wxCommandEvent& event )  {
	string buscador = wx_to_std(barraBuscadorVenta->GetValue());
	if(sonLetras(buscador)==true) {
		
		vector<Producto> vectorTemp = bp->buscarPorNombre(buscador);
		
		
		
		actualizarGrillaCarritoFiltro(vectorTemp); /// No es la del carrito sino la del buscador
		
		
	}
	else {
		
		
		if(sonNumeros(buscador)==true) {
			
			vector<Producto> vectorTemp = bp->buscarPorCodigo(buscador); 
			
			actualizarGrillaCarritoFiltro(vectorTemp);/// No es la del carrito sino la del buscador
			
		}
		
		
		
	}
	if(barraBuscadorVenta->IsEmpty())actualizarGrillaDisponibles(enStock);
	
}

void wRealizarVenta::agregarCarritoEnter( wxMouseEvent& event )  {
	event.Skip();
}

/// Doble click a la lista de producto disponibles
/// en la venta para asi seleccionar la cantidad
void wRealizarVenta::celdaLeftDClick( wxGridEvent& event )  {
	/// Obtengo la fila del producto seleccionado
	int fila = grillaProductosVenta->GetGridCursorRow();
	
	/// Obtengo el codigo del producto en string
	string codi = wx_to_std(grillaProductosVenta->GetCellValue(fila,1));
	
	
	/// base producto -> producto a partir de su codigo
	Producto p = bp->verConCodigo(string_to_int(codi));
	
	if(sis_ven->estaEnCarrito(p.verCodigoProducto()) == true ) wxMessageBox(c_to_wx("El producto ya se encuentra en el carrito!"),"Error",wxOK);
	else {
		
		wActualizarProducto win2(this,p,sis_ven,bp);
		win2.ShowModal();
		actualizarGrillaCarrito();
	}
}

void wRealizarVenta::agregarAlCarrito( wxCommandEvent& event )  {
	int fila = grillaProductosVenta->GetGridCursorRow();
	int code = string_to_int(wx_to_std(grillaProductosVenta->GetCellValue(fila,1)));
	
	if(sis_ven->estaEnCarrito(code) == true ) wxMessageBox(c_to_wx("El producto ya se encuentra en el carrito!"),"",wxOK);
	
	else {
		Producto p = bp->verConCodigo(code);
		wActualizarProducto win2(this,p,sis_ven,bp);
		win2.ShowModal();
		actualizarGrillaCarrito();
	}
}

void wRealizarVenta::editarCantidad( wxGridEvent& event )  {
	int fila = grillaCarrito->GetGridCursorRow();
	Producto p = sis_ven->verProductoCarrito(fila);
	p.CambiarStock(sis_ven->verCant(fila));
	
	
	wActualizarProducto win2(this,p,sis_ven,bp,1);
	win2.ShowModal();	
	actualizarGrillaCarrito();
}

void wRealizarVenta::botonEliminarOnClick( wxCommandEvent& event )  {
	int fila = grillaCarrito->GetGridCursorRow();
	sis_ven->eliminarProductoDeCarrito(fila);
	actualizarGrillaCarrito();
}

void wRealizarVenta::vaciarCarritoOnClick( wxCommandEvent& event )  {
	int res = wxMessageBox(c_to_wx("¿Vaciar Carrito?"),"",wxYES_NO);
	if(res == wxYES){
		sis_ven->clearCarrito();
		actualizarGrillaCarrito();
	}
}

void wRealizarVenta::agregarClienteOnButtonClick( wxCommandEvent& event )  {
	string dni_cliente = wx_to_std(clienteDNItexto->GetValue());
//	/// CORREGIR ABAJO
	if(sonNumeros(dni_cliente)==false) wxMessageBox("Ingrese solo numeros, texto no adminito","Error",wxOK);
	else {
		if(sis_ven->agregarClienteVenta(string_to_int(dni_cliente))==true) {
			nombreClienteLabel->SetValue(std_to_wx(sis_ven->verCliente()));
			
		}
		else {
			nombreClienteLabel->SetValue(sis_ven->verCliente());
		}
		
	}
}

void wRealizarVenta::botonConfirmarOnButtonClick( wxCommandEvent& event )  {
	if(sis_ven->cantProdCarrito()==0) {
		wxMessageBox("Carrito vacio!","Venta",wxOK);
	}
	else {
		int res = wxMessageBox("Desea realizar esta venta?","Confirmacion",wxYES_NO);
		if(res == wxYES) {
			
			
			
			/// Si se guarda la venta mensaje...
			wxMessageBox("La venta se ha realizado con exito!","Venta",wxOK);
			/// GUARDAR VENTANA REGISTRO
			registro->guardarVenta(sis_ven->carrito(), m_fecha->obtenerFechaConHora(),log->verNombreUsuario(),sis_ven->verCliente(), sis_ven->subTotal());
			sis_ven->realizarVenta();
			/// Se limpia el carrito
			sis_ven->clearCarrito();
			
			EndModal(1);
			
		}
		else {
			
		}
	}
}

void wRealizarVenta::botonCancelarVentaOnButtonClick( wxCommandEvent& event )  {
	sis_ven->clearCarrito();
	EndModal(0);
}

wRealizarVenta::~wRealizarVenta() {
	
}


void wRealizarVenta::actualizarGrillaCarrito ( ) {
	if(grillaCarrito->GetNumberRows()>=1) grillaCarrito->DeleteRows(0,grillaCarrito->GetNumberRows());
	//	grillaCarrito->DeleteRows(0,sis_ven->cantProdCarrito());
	//	grillaCarrito->Refresh();
	grillaCarrito->AppendRows(sis_ven->cantProdCarrito());
	for(int i=0;i<sis_ven->cantProdCarrito();i++) { 
		
			grillaCarrito->SetCellValue(i,0,sis_ven->verProductoCarrito(i).verNombreProducto());
			grillaCarrito->SetCellValue(i,1,std_to_wx(float_to_str(sis_ven->verCant(i))));
//			if(grillaCarrito->GetCellValue(i,1)!="")sis_ven->cambiarCantidad(i,string_to_float(wx_to_std(grillaCarrito->GetCellValue(i,1))));
			grillaCarrito->SetCellValue(i,2,std_to_wx(float_to_str(sis_ven->verProductoCarrito(i).verPrecio())));
			
			
			grillaCarrito->SetCellValue(i,4,std_to_wx(float_to_str(sis_ven->calcularPrecio(i))));
			
			if(bp->verProducto(i).verDescuento()==0) grillaCarrito->SetCellValue(i,3,"Sin descuento");
			else 									grillaCarrito->SetCellValue(i,3,std_to_wx(float_to_str(sis_ven->verProductoCarrito(i).verDescuento())));
			
		
	}
	
	total->SetValue(float_to_str(sis_ven->subTotal()));
}

void wRealizarVenta::actualizarGrillaDisponibles (vector<Producto> & v) {
	if(grillaProductosVenta->GetNumberRows()>=1) grillaProductosVenta->DeleteRows(0,grillaProductosVenta->GetNumberRows());
	
	grillaProductosVenta->AppendRows(v.size());
	
	for(int i=0;i<v.size();i++) { 
		grillaProductosVenta->SetCellValue(i,0,v[i].verNombreProducto());
		grillaProductosVenta->SetCellValue(i,1,std_to_wx(int_to_str(v[i].verCodigoProducto())));
	}
}

void limpiarSinStock(vector<Producto> & p) {
	vector<Producto> p_temp;
	for(size_t i=0;i<p.size();i++) { 
		
		if(p[i].verStock()>0) {
			p_temp.push_back(p[i]);
		}
		
	}
	p.clear();
	p = p_temp;
	p_temp.clear();
}



void wRealizarVenta::actualizarGrillaCarritoFiltro (vector<Producto> & p) {
	
	limpiarSinStock(p);
	
	
	if(grillaProductosVenta->GetNumberRows()>=1)grillaProductosVenta->DeleteRows(0,bp->sizeVectProd()); ///remueve las grillas
	grillaProductosVenta->AppendRows(p.size());
	for(int i=0;i<p.size();i++) { 
		
		/// Si hay un producto SIN stock no lo muestro
		/// porque este filtro solo sirve para ver el nombre de productos
		/// 
			
			grillaProductosVenta->SetCellValue(i,0,p[i].verNombreProducto());
			grillaProductosVenta->SetCellValue(i,1,std_to_wx(int_to_str(p[i].verCodigoProducto())));
		
		
	}
}

