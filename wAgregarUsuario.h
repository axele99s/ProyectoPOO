#ifndef WAGREGARUSUARIO_H
#define WAGREGARUSUARIO_H
#include "wxfb_project.h"
#include "BaseUsuarios.h"
#include "fecha.h"

class wAgregarUsuario : public ventanaAgregarUsuario {
	
private:
	BaseUsuarios *base_usuarios;
	fecha *m_fecha;
	Usuario * user;
protected:
	void agregarUsuarioOnButtonClick( wxCommandEvent& event )  override;
	void cancelarAddUsuarioOnButtonClick( wxCommandEvent& event )  override;
	
public:
	wAgregarUsuario(wxWindow *parent=NULL,BaseUsuarios *bu=NULL,fecha *f=NULL,Usuario * u=NULL);
	~wAgregarUsuario();
};

#endif

