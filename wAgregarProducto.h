#ifndef WAGREGARPRODUCTO_H
#define WAGREGARPRODUCTO_H
#include "wxfb_project.h"
#include "BaseProductos.h"

class wAgregarProducto : public ventanaAgregarProducto {
	
private:
	BaseProductos * bp;
protected:
	void agregarProductoBoton( wxCommandEvent& event )  override;
	void cancelarBoton( wxCommandEvent& event )  override;
	
public:
	wAgregarProducto(wxWindow *parent=NULL,BaseProductos *base=NULL);
	~wAgregarProducto();
};

#endif

