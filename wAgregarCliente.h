#ifndef WAGREGARCLIENTE_H
#define WAGREGARCLIENTE_H
#include "wxfb_project.h"
#include "BaseUsuarios.h"

class wAgregarCliente : public ventanaAgregarCliente {
	
private:
	BaseUsuarios *base_usuarios;
	int pos;
	string padre;
protected:
	void AgregarClienteOnButtonClick( wxCommandEvent& event )  override;
	void volverOnButtonClick( wxCommandEvent& event )  override;
	
public:
	wAgregarCliente(wxWindow *parent=NULL,int i=-1,BaseUsuarios *bu=NULL);
	~wAgregarCliente();
};

#endif

