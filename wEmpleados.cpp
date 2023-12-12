#include "wEmpleados.h"
#include "string_conv.h"
#include "validaciones.h"
#include "wAgregarUsuario.h"

wEmpleados::wEmpleados(wxWindow *parent,BaseUsuarios *bu,fecha *f) : m_fecha(f), base_usuarios(bu),ventana_Empleados(parent) {
	actualizarGrilla();
}

void wEmpleados::busquedaUsuarioOnText( wxCommandEvent& event )  {
	string busqueda = wx_to_std(busquedaUsuario->GetValue());
	
	
	
	
	/// Busqueda en caso de que sea FECHA
	string aux = convertirFecha(busqueda); /// primero convierto la busqueda en fecha, es decir sin espacios ni guiones o barrras /
	
	
	/// Valido primero que el aux no este vacio y sea menor a 8 (debido a la fecha mmddaaaa)
	/// Por ultimo que sean numeros, una fecha no pueden ser letras...
	if(sonNumeros(aux)==true and aux.size()<=8 and !aux.empty()) {	
		vector<Usuario> vu = base_usuarios->buscarPorFecha(aux);
		actualizarGrillaFiltro(vu);
	}
	
	
	/// Busqueda por usuario
	else {
		vector<Usuario> vu = base_usuarios->buscarPorUser(wx_to_std(busquedaUsuario->GetValue()));
		actualizarGrillaFiltro(vu);
	}
}

void wEmpleados::grillaUsuariosOnGridCellLeftDClick( wxGridEvent& event )  {
	int pos = grillaUsuarios->GetGridCursorRow();
	string username = wx_to_std(grillaUsuarios->GetCellValue(pos,0));
	
	
	Usuario s = base_usuarios->verUsuario(username);
	wAgregarUsuario win(this,base_usuarios,m_fecha,&s);
	win.ShowModal();
	actualizarGrilla();
}

void wEmpleados::agregarDesdeListaOnButtonClick( wxCommandEvent& event )  {
	wAgregarUsuario win(this,base_usuarios,m_fecha);
	win.ShowModal();
	actualizarGrilla();
}

void wEmpleados::eliminarEmpleadoOnButtonClick( wxCommandEvent& event )  {
	
	
	int pos = grillaUsuarios->GetGridCursorRow();
	string username = wx_to_std(grillaUsuarios->GetCellValue(pos,0));
	int res = wxMessageBox("Seguro que desea eliminar al usuario \n "+username,"Eliminar",wxYES_NO);
	Usuario s = base_usuarios->verUsuario(username);
	if(res == wxYES) {
		base_usuarios->EliminarUsuario(s);
		actualizarGrilla();
	}
}

void wEmpleados::volverListaEmpleadosOnButtonClick( wxCommandEvent& event )  {
	EndModal(0);
}

wEmpleados::~wEmpleados() {
	
}


void wEmpleados::actualizarGrilla ( ) {
	//	grillaUsuarios->DeleteRows(0,99);
	if(grillaUsuarios->GetNumberRows()>=1) grillaUsuarios->DeleteRows(0,grillaUsuarios->GetNumberRows());
	grillaUsuarios->AppendRows(base_usuarios->VerCantUsuarios());
	for(int i=0;i<base_usuarios->VerCantUsuarios();i++) { 
		Usuario s = base_usuarios->verUsuario(i);
		grillaUsuarios->SetCellValue(i,0,s.verNombreUsuario());
		grillaUsuarios->SetCellValue(i,1,s.verPass());
		if(s.verTipo()==1) grillaUsuarios->SetCellValue(i,2,"Administrador/Jefe");
		else grillaUsuarios->SetCellValue(i,2,"Empleado");
		
		grillaUsuarios->SetCellValue(i,3,s.verFecha());
		
	}
}

void wEmpleados::actualizarGrillaFiltro (vector<Usuario> & u) {
	//	grillaUsuarios->DeleteRows(0,99);
	if(grillaUsuarios->GetNumberRows()>=1) grillaUsuarios->DeleteRows(0,grillaUsuarios->GetNumberRows());
	grillaUsuarios->AppendRows(u.size());
	for(int i=0;i<u.size();i++) { 
		Usuario s = u[i];
		grillaUsuarios->SetCellValue(i,0,s.verNombreUsuario());
		grillaUsuarios->SetCellValue(i,1,s.verPass());
		if(s.verTipo()==1) grillaUsuarios->SetCellValue(i,2,"Administrador/Jefe");
		else grillaUsuarios->SetCellValue(i,2,"Empleado");
		
		grillaUsuarios->SetCellValue(i,3,s.verFecha());
		
	}
}

