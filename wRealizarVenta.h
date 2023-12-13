#ifndef WREALIZARVENTA_H
#define WREALIZARVENTA_H
#include "wxfb_project.h"
#include "BaseProductos.h"
#include "SistemaVenta.h"
#include "fecha.h"
#include "registro_Ventas.h"
#include <cmath>
using namespace std;

class wRealizarVenta : public ventanaRealizarVenta {
	
private:
	BaseProductos * bp;
	SistemaVenta *sis_ven;
	fecha *m_fecha;
	registro_Ventas * registro;
	Login *log;
	vector<Producto> enStock;
protected:
	void barraBuscadorVentaOnText( wxCommandEvent& event )  override;
	void agregarCarritoEnter( wxMouseEvent& event )  override;
	void celdaLeftDClick( wxGridEvent& event )  override;
	void agregarAlCarrito( wxCommandEvent& event )  override;
	void editarCantidad( wxGridEvent& event )  override;
	void botonEliminarOnClick( wxCommandEvent& event )  override;
	void vaciarCarritoOnClick( wxCommandEvent& event )  override;
	void agregarClienteOnButtonClick( wxCommandEvent& event )  override;
	void botonConfirmarOnButtonClick( wxCommandEvent& event )  override;
	void botonCancelarVentaOnButtonClick( wxCommandEvent& event )  override;
	
public:
	wRealizarVenta(wxWindow *parent=NULL,BaseProductos * base=NULL,SistemaVenta *sis_ven=NULL,fecha *fe=NULL,registro_Ventas *reg=NULL,Login *l=NULL);
	void actualizarGrillaCarrito();
	void actualizarGrillaDisponibles(vector<Producto> &v);
	void actualizarGrillaCarritoFiltro(vector<Producto> &p); /// no es el carrito sino la grilla de productos disponibles
	~wRealizarVenta();
};

#endif

