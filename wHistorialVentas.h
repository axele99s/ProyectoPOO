#ifndef WHISTORIALVENTAS_H
#define WHISTORIALVENTAS_H
#include "wxfb_project.h"
#include "registro_Ventas.h"
#include "fecha.h"
#include "BaseProductos.h"

class wHistorialVentas : public ventanaHistorialVentas {
	
private:
	registro_Ventas *registro;
	fecha *fec;
	BaseProductos *base_productos;
protected:
	void historialVentasBuscadorOnText( wxCommandEvent& event )  override;
	void reloadOnButtonClick( wxCommandEvent& event )  override;
	void diaFiltroOnButtonClick( wxCommandEvent& event )  override;
	void mesFiltroOnButtonClick( wxCommandEvent& event )  override;
	void anioFiltroOnButtonClick( wxCommandEvent& event )  override;
	void grillaRegistroVentasOnGridCellLeftDClick( wxGridEvent& event )  override;
	void eliminarVentaOnButtonClick( wxCommandEvent& event )  override;
	void vaciarRegistroOnButtonClick( wxCommandEvent& event )  override;
	
public:
	wHistorialVentas(wxWindow *parent=NULL,registro_Ventas *reg=NULL,BaseProductos *bp=NULL);
	void actualizarGrilla();
	void actualizarGrillaFiltro(vector<structVentaRealizada> &svr_vector);
	~wHistorialVentas();
};

#endif

