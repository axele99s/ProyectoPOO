#ifndef WCLIENTES_H
#define WCLIENTES_H
#include "wxfb_project.h"
#include "BaseUsuarios.h"

class wClientes : public ventana_Clientes {
	
private:
	BaseUsuarios *base_usuarios;
protected:
	void barraBusquedaClienteOnText( wxCommandEvent& event )  override;
	void editarClienteButton( wxGridEvent& event )  override;
	void agregarClienteOnButtonClick( wxCommandEvent& event )  override;
	void eliminarClienteOnButtonClick( wxCommandEvent& event )  override;
	
public:
	wClientes(wxWindow *parent=NULL,BaseUsuarios *bu=NULL);
	void actualizarGrilla();
	void actualizarGrillaFiltros(vector<Cliente> &c);
	~wClientes();
};

#endif

