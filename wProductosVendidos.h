#ifndef WPRODUCTOSVENDIDOS_H
#define WPRODUCTOSVENDIDOS_H
#include "wxfb_project.h"
#include "BaseProductos.h"

class wProductosVendidos : public ventanaProductosVendidos {
	
private:
	string str="";
	BaseProductos *base_productos;
protected:
	void cerrarOnButtonClick( wxCommandEvent& event )  override;
	
public:
	wProductosVendidos(wxWindow *parent=NULL,string str=NULL,BaseProductos *bp=NULL);
	void obtenerProductos(vector<Producto> &v);
	~wProductosVendidos();
};

#endif

