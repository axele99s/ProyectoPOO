#include "wClientes.h"
#include "string_conv.h"
#include "wAgregarCliente.h"
#include <wx/msgdlg.h>
#include "validaciones.h"

wClientes::wClientes(wxWindow *parent,BaseUsuarios *bu) : base_usuarios(bu),ventana_Clientes(parent) {
	actualizarGrilla();
	grillaClientes->SetSelectionMode(wxGrid::wxGridSelectRows);
}

void wClientes::barraBusquedaClienteOnText( wxCommandEvent& event )  {
	string buscador = wx_to_std(barraBusquedaCliente->GetValue());
	if(sonLetras(buscador)==true) {
		
		vector<Cliente> vectorTemp = base_usuarios->buscarPorNombre(buscador);
		actualizarGrillaFiltros(vectorTemp);
		
		
	}
	else {
		
		
		if(sonNumeros(buscador)==true) {
			
			vector<Cliente> vectorTemp = base_usuarios->buscarPorDNI(buscador);
			
			actualizarGrillaFiltros(vectorTemp);
			if(vectorTemp.empty() and sonNumeros(buscador)==true) {
				vector<Cliente> vectorTemp = base_usuarios->buscarPorCodigo(buscador);
				
				actualizarGrillaFiltros(vectorTemp);
			}
			
		}
		
		//		if(sonNumeros(buscador)==true) {
		//			
		//			vector<Producto> vectorTemp = bp->buscarPorCodigo(buscador);
		//			actualizarGrillaFiltros(vectorTemp);
		//			
		//		}
		
		
		
	}
}

/// Doble click editar cliente
void wClientes::editarClienteButton( wxGridEvent& event )  {
	int row = grillaClientes->GetGridCursorRow();
	string codigoCliente = wx_to_std(grillaClientes->GetCellValue(row,2));
	
	wAgregarCliente win(this,base_usuarios->verPosCliente(string_to_int(codigoCliente)),base_usuarios);
	
	
	if(win.ShowModal()==true) {  /// Si modifique actualizo la grilla y la palabra del buscador =clear
		barraBusquedaCliente->SetValue("");
		actualizarGrilla();
	}
}
/// agregar desde la lista de empelados
void wClientes::agregarClienteOnButtonClick( wxCommandEvent& event )  {
	wAgregarCliente win(this,-1,base_usuarios);
	win.ShowModal();
	actualizarGrilla();
}

void wClientes::eliminarClienteOnButtonClick( wxCommandEvent& event )  {
	int pos = grillaClientes->GetGridCursorRow();
	Cliente c = base_usuarios->verCliente(pos);
	if(base_usuarios->EliminarCliente(c)==true) {
		wxMessageBox("Se ha eliminado al cliente correctamente!","",wxOK);
		actualizarGrilla();
	}
	else {
		wxMessageBox("Error al elimiar cliente!","",wxOK);
	}
}

wClientes::~wClientes() {
	
}


void wClientes::actualizarGrilla ( ) {
	if(grillaClientes->GetNumberRows()>=1) grillaClientes->DeleteRows(0,grillaClientes->GetNumberRows());
	grillaClientes->AppendRows(base_usuarios->VerCantClientes());
	for(int i=0;i<base_usuarios->VerCantClientes();i++) { 
		Cliente c = base_usuarios->verCliente(i);
		grillaClientes->SetCellValue(i,0,c.verNombre());
		grillaClientes->SetCellValue(i,1,int_to_str(c.verDNI()));
		grillaClientes->SetCellValue(i,2,int_to_str(c.verCodigoCliente()));
		grillaClientes->SetCellValue(i,3,(c.verDireccion()));
		grillaClientes->SetCellValue(i,4,(c.verLocalidad()));
		grillaClientes->SetCellValue(i,5,(c.verEmail()));
		grillaClientes->SetCellValue(i,6,(c.verFechaNac()));
		
	}
}

void wClientes::actualizarGrillaFiltros (vector<Cliente> & vc) {
	if(grillaClientes->GetNumberRows()>=1) grillaClientes->DeleteRows(0,grillaClientes->GetNumberRows());
	grillaClientes->AppendRows(vc.size());
	for(int i=0;i<vc.size();i++) { 
		Cliente c = vc[i];
		grillaClientes->SetCellValue(i,0,c.verNombre());
		grillaClientes->SetCellValue(i,1,int_to_str(c.verDNI()));
		grillaClientes->SetCellValue(i,2,int_to_str(c.verCodigoCliente()));
		grillaClientes->SetCellValue(i,3,(c.verDireccion()));
		grillaClientes->SetCellValue(i,4,(c.verLocalidad()));
		grillaClientes->SetCellValue(i,5,(c.verEmail()));
		grillaClientes->SetCellValue(i,6,(c.verFechaNac()));
		
	}
}



