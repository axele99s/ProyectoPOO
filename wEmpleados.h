#ifndef WEMPLEADOS_H
#define WEMPLEADOS_H
#include "wxfb_project.h"
#include "fecha.h"
#include "BaseUsuarios.h"

class wEmpleados : public ventana_Empleados {
	
private:
	BaseUsuarios *base_usuarios;
	fecha * m_fecha;
protected:
	void busquedaUsuarioOnText( wxCommandEvent& event )  override;
	void grillaUsuariosOnGridCellLeftDClick( wxGridEvent& event )  override;
	void agregarDesdeListaOnButtonClick( wxCommandEvent& event )  override;
	void eliminarEmpleadoOnButtonClick( wxCommandEvent& event )  override;
	void volverListaEmpleadosOnButtonClick( wxCommandEvent& event )  override;
	
public:
	wEmpleados(wxWindow *parent=NULL,BaseUsuarios *bu=NULL,fecha *m_fecha=NULL);
	void actualizarGrilla();
	void actualizarGrillaFiltro(vector<Usuario> &u);
	~wEmpleados();
};

#endif

