#include "wHistorialVentas.h"
#include "string_conv.h"
#include "validaciones.h"
#include "wFiltroFecha.h"
#include "wProductosVendidos.h"

wHistorialVentas::wHistorialVentas(wxWindow *parent,registro_Ventas *r,BaseProductos *bp) : base_productos(bp),registro(r),ventanaHistorialVentas(parent) {
	registro->cargarHistorialVentas();
	actualizarGrilla();
	fec = new fecha();
}

void wHistorialVentas::historialVentasBuscadorOnText( wxCommandEvent& event )  {
	string busqueda = wx_to_std(historialVentasBuscador->GetValue());
	
	
	
	
	/// Busqueda en caso de que sea FECHA
//	string aux = convertirFecha(busqueda); /// primero convierto la busqueda en fecha, es decir sin espacios ni guiones o barrras /
//	string aux2 = convertirHora(busqueda); /// primero convierto la busqueda en fecha, es decir sin espacios ni guiones o barrras /
	
	/// Valido primero que el aux no este vacio y sea menor a 8 (debido a la fecha mmddaaaa)
	/// Por ultimo que sean numeros, una fecha no pueden ser letras...
	
//	if(sonNumeros(busqueda)==false) {
		vector<structVentaRealizada> v = registro->buscarPorTransaccion(busqueda);
		actualizarGrillaFiltro(v);
//	}
//	else {
		actualizarGrilla();
		//		if(sonNumeros(aux)==true) {	/// caso en busqueda por hora
		//			vector<structVentaRealizada> v = registro->buscarPorFecha(aux);
		//			actualizarGrillaFiltro(v);
		//		}
		//		else {
		//			/// caso busqueda por fecha y/o hora
		//			vector<structVentaRealizada> v = registro->buscarPorHora(aux);
		//			actualizarGrillaFiltro(v);
		//			
		//		}
//	}
}

void wHistorialVentas::reloadOnButtonClick( wxCommandEvent& event )  {
	actualizarGrilla();
}

void wHistorialVentas::diaFiltroOnButtonClick( wxCommandEvent& event )  {
	wFiltroFecha win(this,fec,1);
	if(win.ShowModal()){
		
		vector<structVentaRealizada> v = registro->buscarPorDia(fec->verFecha());
		if(!v.empty()){	actualizarGrillaFiltro(v);}
		else wxMessageBox("Sin Resultados.","",wxOK);
	}
}

void wHistorialVentas::mesFiltroOnButtonClick( wxCommandEvent& event )  {
	wFiltroFecha win(this,fec,2);
	if(win.ShowModal()==true) {
		vector<structVentaRealizada> v = registro->buscarPorDia(fec->verMes()+fec->verAnio());
		if(!v.empty()){	actualizarGrillaFiltro(v);}
		else wxMessageBox("Sin Resultados.","",wxOK);
	}
}

void wHistorialVentas::anioFiltroOnButtonClick( wxCommandEvent& event )  {
	wFiltroFecha win(this,fec,3);
	if(win.ShowModal()==true) {
		vector<structVentaRealizada> v = registro->buscarPorAnio(fec->verAnio());
		if(!v.empty()){	actualizarGrillaFiltro(v);}
		else wxMessageBox("Sin Resultados.","",wxOK);
	}
}

void wHistorialVentas::grillaRegistroVentasOnGridCellLeftDClick( wxGridEvent& event )  {
	int pos = grillaRegistroVentas->GetGridCursorRow();
	string nro_transac = wx_to_std(grillaRegistroVentas->GetCellValue(pos,1));
	
	wProductosVendidos win(NULL,registro->verProductos(nro_transac),base_productos);
	win.ShowModal();
}

void wHistorialVentas::eliminarVentaOnButtonClick( wxCommandEvent& event )  {
	/// Obtengo la fila de la venta seleccionado
	int fila = grillaRegistroVentas->GetGridCursorRow();
	
	/// Obtengo el nro de transaccion de la venta en string
	string nrotrac = wx_to_std(grillaRegistroVentas->GetCellValue(fila,1));
	
	
	
	
	int res = wxMessageBox("Seguro que desea eliminar la venta?","Eliminar",wxYES_NO);
	if(res==wxYES) {
		registro->eliminarVenta(nrotrac);
		historialVentasBuscador->SetValue("");
		actualizarGrilla();
	}
}

void wHistorialVentas::vaciarRegistroOnButtonClick( wxCommandEvent& event )  {
	int res = wxMessageBox("Seguro que desea vaciar el historia?","Eliminar",wxYES_NO);
	if(res==wxYES) {
		registro->vaciarRegistro();
		actualizarGrilla();
	}
}

wHistorialVentas::~wHistorialVentas() {
	
}


void wHistorialVentas::actualizarGrilla ( ) {
	if(grillaRegistroVentas->GetNumberRows()>=1)grillaRegistroVentas->DeleteRows(0,grillaRegistroVentas->GetNumberRows()); 
	grillaRegistroVentas->AppendRows(registro->cantidadVentas());
	
	
	
	for(int i=0;i<registro->cantidadVentas();i++) { 
		structVentaRealizada svr = registro->verVenta(i);
		
		
		grillaRegistroVentas->SetCellValue(i,0,svr.fecha_de_venta);
		grillaRegistroVentas->SetCellValue(i,1,svr.nro_transaccion);
		grillaRegistroVentas->SetCellValue(i,2,svr.vendedor);
		grillaRegistroVentas->SetCellValue(i,3,float_to_str(svr.total));
		grillaRegistroVentas->SetCellValue(i,4,svr.cliente);
		
	}
}

void wHistorialVentas::actualizarGrillaFiltro (vector<structVentaRealizada> & svr_vector) {
	//	if(svr_vector.empty())return;
	if(grillaRegistroVentas->GetNumberRows()>=1)grillaRegistroVentas->DeleteRows(0,grillaRegistroVentas->GetNumberRows()); 
	grillaRegistroVentas->AppendRows(svr_vector.size());
	
	for(int i=0;i<svr_vector.size();i++) { 
		structVentaRealizada svr = svr_vector[i];
		
		
		
		grillaRegistroVentas->SetCellValue(i,0,svr.fecha_de_venta);
		grillaRegistroVentas->SetCellValue(i,1,svr.nro_transaccion);
		grillaRegistroVentas->SetCellValue(i,2,svr.vendedor);
		grillaRegistroVentas->SetCellValue(i,3,float_to_str(svr.total));
		grillaRegistroVentas->SetCellValue(i,4,svr.cliente);
		
	}
}

