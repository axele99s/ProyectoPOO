#ifndef WLISTARARTICULOS_H
#define WLISTARARTICULOS_H
#include "wxfb_project.h"
#include "BaseProductos.h"

class wListarArticulos : public ventanaListaArticulos {
	
private:
	BaseProductos *bp;
protected:
	void barraBuscarArticuloOnText( wxCommandEvent& event )  override;
	void GridDCLICK_cambiarCant( wxGridEvent& event )  override;
	void agregarProdDesdeLista( wxCommandEvent& event )  override;
	void botonEliminarProducto( wxCommandEvent& event )  override;
	
public:
	wListarArticulos(wxWindow *parent=NULL,BaseProductos *base=NULL);
	void actualizarGrilla();
	void actualizarGrillaFiltros(vector<Producto> &vectorTemp);
	~wListarArticulos();
};

#endif

