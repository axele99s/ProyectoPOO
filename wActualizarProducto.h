#ifndef WACTUALIZARPRODUCTO_H
#define WACTUALIZARPRODUCTO_H
#include "wxfb_project.h"
#include "SistemaVenta.h"
#include "BaseProductos.h"

class wActualizarProducto : public ventanaActualizarProducto {
	
private:
	Producto prod;
	float cantidad_elegida;
	SistemaVenta *sistema_venta;
	BaseProductos *base_productos;
	int i;
protected:
	void confirmarCarrito( wxCommandEvent& event )  override;
	void volverElegirProd( wxCommandEvent& event )  override;
	
public:
	wActualizarProducto(wxWindow *parent=NULL, Producto p=NULL,SistemaVenta *sis_ven=NULL,BaseProductos *baseprod=NULL,int i=-1);
	~wActualizarProducto();
};

#endif

