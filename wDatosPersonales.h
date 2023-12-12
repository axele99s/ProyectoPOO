#ifndef WDATOSPERSONALES_H
#define WDATOSPERSONALES_H
#include "wxfb_project.h"
#include "BaseUsuarios.h"
#include "Login.h"

class wDatosPersonales : public ventana_DatosPersonales {
	
private:
	BaseUsuarios *base_usuarios;
	Login *login;
protected:
	void showPassOnCheckBox( wxCommandEvent& event )  override;
	void botonModificarOnButtonClick( wxCommandEvent& event )  override;
	void SalirOnButtonClick( wxCommandEvent& event )  override;
	void modificarPersonalesOnButtonClick( wxCommandEvent& event )  override;
	
public:
	wDatosPersonales(wxWindow *parent=NULL,BaseUsuarios *bu=NULL,Login *l=NULL);
	void actualizarDatosPersonales();
	~wDatosPersonales();
};

#endif

