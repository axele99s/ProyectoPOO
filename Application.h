#ifndef APPLICATION_H
#define APPLICATION_H

#include "BaseProductos.h"
#include "BaseUsuarios.h"
#include <wx/app.h>
#include "Login.h"
#include "SistemaVenta.h"

class Application : public wxApp {
private: 
	BaseProductos *m_baseProductos;
	BaseUsuarios * m_baseUsuarios;
	Login *login;
	SistemaVenta *sistema_venta;
	registro_Ventas *registro_de_ventas;
	fecha *m_fecha;
	BaseUsuarios *base_usuarios;
public:
	virtual bool OnInit();
};

#endif
