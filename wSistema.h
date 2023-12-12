#ifndef WSISTEMA_H
#define WSISTEMA_H
#include "wxfb_project.h"
#include "BaseProductos.h"
#include "SistemaVenta.h"
#include "fecha.h"
#include "registro_Ventas.h"
#include "BaseUsuarios.h"
#include <cmath>
using namespace std;

class wSistema : public ventanaSistema {
	
private:
	BaseProductos *bp;
	SistemaVenta *sistema_venta;
	fecha *m_fecha;
	registro_Ventas * registro;
	BaseUsuarios *base_usuarios;
	Login *log;
protected:
	void menuInformacionOnMenuSelection( wxCommandEvent& event )  override;
	void salirMenu( wxCommandEvent& event )  override;
	void abrirListaArticulos( wxCommandEvent& event )  override;
	void abrirAgregarProducto( wxCommandEvent& event )  override;
	void abrirListaClientes( wxCommandEvent& event )  override;
	void agregarClienteMenu( wxCommandEvent& event )  override;
	void abrirListaEmpleados( wxCommandEvent& event )  override;
	void agregarEmpleadoMenuOnMenuSelection( wxCommandEvent& event )  override;
	void menuVerDatosOnMenuSelection( wxCommandEvent& event )  override;
	void cerrarSesionMenu( wxCommandEvent& event )  override;
	void realizarNuevaVenta( wxCommandEvent& event )  override;
	void botonHistorialOnButtonClick( wxCommandEvent& event )  override;
	
public:
	wSistema(wxWindow *parent=NULL,BaseProductos *base = NULL,SistemaVenta *sv=NULL,fecha *f=NULL,registro_Ventas *r=NULL
			 , BaseUsuarios *bu=NULL,Login *l=NULL
			 
			 );
	~wSistema();
};

#endif

