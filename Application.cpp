#include "Application.h"
#include "wxfb_project.h"
#include "Login.h"
#include "BaseUsuarios.h"
#include "BaseProductos.h"
#include "SistemaVenta.h"
#include "fecha.h"
#include "registro_Ventas.h"
#include "wLogeo.h"


IMPLEMENT_APP(Application)

bool Application::OnInit() {
	m_baseProductos = new BaseProductos();
	m_baseUsuarios = new BaseUsuarios();
	login = new Login(m_baseUsuarios);
	m_fecha = new fecha();
	registro_de_ventas = new registro_Ventas();
	sistema_venta = new SistemaVenta(m_baseProductos,m_baseUsuarios,login,registro_de_ventas);
	base_usuarios = new BaseUsuarios();
	
	registro_de_ventas->cargarHistorialVentas();
//	wLogin win(NULL,login,m_baseUsuarios,m_baseProductos,sistema_venta,m_fecha,registro_de_ventas);
//	win.ShowModal();
	wLogeo *win= new wLogeo(NULL,login,m_baseUsuarios,m_baseProductos,sistema_venta,m_fecha,registro_de_ventas);
	win->Show();
	
	return true;
}

