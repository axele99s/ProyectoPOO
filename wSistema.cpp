#include "wSistema.h"
#include "wInformacion.h"
#include "wHistorialVentas.h"
#include "wRealizarVenta.h"
#include "wDatosPersonales.h"
#include "wAgregarUsuario.h"
#include "wEmpleados.h"
#include "wAgregarCliente.h"
#include "wAgregarProducto.h"
#include "wClientes.h"
#include "wListarArticulos.h"
#include "wLogeo.h"

wSistema::wSistema(wxWindow *parent,BaseProductos *base,SistemaVenta *sv,fecha *f,registro_Ventas *reg
				   ,BaseUsuarios *bu,Login *l
				   
				   
				   ) 
	
	
	
	: log(l),base_usuarios(bu),m_fecha(f),registro(reg),sistema_venta(sv),ventanaSistema(parent), bp(base)  {
	fechaLabel->SetValue(m_fecha->obtenerFecha());
	/// *---------------------------------
	
	
	Usuario s = log->verUsuarioLogeado();
	if(s.verTipo() == 0) {
		menuEmpleados->Enable(idEmpleadoMenu,FALSE);
		menuEmpleados->Enable(idAgregarNuevoEmpleado,FALSE);
	}
}

void wSistema::menuInformacionOnMenuSelection( wxCommandEvent& event )  {
	wInformacion win(this);
	win.ShowModal();
}

void wSistema::salirMenu( wxCommandEvent& event )  {
	Close();
}

void wSistema::abrirListaArticulos( wxCommandEvent& event )  {
	wListarArticulos articulos(this,bp);
	articulos.ShowModal();
}

void wSistema::abrirAgregarProducto( wxCommandEvent& event )  {
	wAgregarProducto win(this,bp);
	
	win.ShowModal();
}

void wSistema::abrirListaClientes( wxCommandEvent& event )  {
	wClientes win(this,base_usuarios);
	win.ShowModal();
}

void wSistema::agregarClienteMenu( wxCommandEvent& event )  {
	wAgregarCliente win(this,-1,base_usuarios);
	win.ShowModal();
}

void wSistema::abrirListaEmpleados( wxCommandEvent& event )  {
	wEmpleados win(this,base_usuarios,m_fecha);
	win.ShowModal();
}

void wSistema::agregarEmpleadoMenuOnMenuSelection( wxCommandEvent& event )  {
	wAgregarUsuario win(this,base_usuarios,m_fecha);
	win.ShowModal();
}

void wSistema::menuVerDatosOnMenuSelection( wxCommandEvent& event )  {
	wDatosPersonales win(this,base_usuarios,log);
	win.ShowModal();
}

void wSistema::cerrarSesionMenu( wxCommandEvent& event )  {
	Close();
	wLogeo *win= new wLogeo(NULL,log,base_usuarios,bp,sistema_venta,m_fecha,registro);
	win->Show();
}

void wSistema::realizarNuevaVenta( wxCommandEvent& event )  {
	wRealizarVenta win(this,bp,sistema_venta,m_fecha,registro,log,base_usuarios);
	win.ShowModal();
}

void wSistema::botonHistorialOnButtonClick( wxCommandEvent& event )  {
	wHistorialVentas win(this,registro,bp,base_usuarios);
	win.ShowModal();
}

wSistema::~wSistema() {
	
}

