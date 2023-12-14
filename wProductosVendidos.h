#ifndef WPRODUCTOSVENDIDOS_H
#define WPRODUCTOSVENDIDOS_H
#include "wxfb_project.h"
#include "BaseProductos.h"
#include <vector>
#include "funcionesExtas.h"
using namespace std;

class wProductosVendidos : public ventanaProductosVendidos {
	
private:
	BaseProductos *base_productos;
protected:
	void cerrarOnButtonClick( wxCommandEvent& event )  override;
	
public:
	wProductosVendidos(wxWindow *parent=NULL,vector<prodsVenta>* pv=NULL,BaseProductos *bp=NULL);
//	void obtenerProductos(vector<Producto> &v);
	~wProductosVendidos();
};

#endif

