#ifndef WLOGEO_H
#define WLOGEO_H
#include "wxfb_project.h"
#include "Login.h"
#include "BaseProductos.h"
#include "SistemaVenta.h"
#include "fecha.h"
#include "registro_Ventas.h"
#include "BaseUsuarios.h"

class wLogeo : public ventana_Login {
	
private:
	Login *login;
	
	
	BaseProductos *bp;
	SistemaVenta *sistema_venta;
	fecha *m_fecha;
	registro_Ventas * registro;
	BaseUsuarios *base_usuarios;
protected:
	void showPassLoginOnCheckBox( wxCommandEvent& event )  override;
	void guardarDatosOnCheckBox( wxCommandEvent& event )  override;
	void clickBotonIniciar( wxCommandEvent& event )  override;
	void SalirOnButtonClick( wxCommandEvent& event )  override;
	
public:
	wLogeo(wxWindow *parent=NULL,Login *log=NULL,BaseUsuarios *bu=NULL,BaseProductos * m_baseProductos=NULL,SistemaVenta *m_sistema_venta=NULL,fecha *m_fecha=NULL,registro_Ventas *registro_de_ventas=NULL);
	~wLogeo();
};

#endif

