#include "Application.h"
#include "wxfb_project.h"
#include "Login.h"
#include "BaseUsuarios.h"
#include "BaseProductos.h"
#include "SistemaVenta.h"
#include "fecha.h"
#include "registro_Ventas.h"
#include "wLogin.h"


IMPLEMENT_APP(Application)

bool Application::OnInit() {
	m_baseProductos = new BaseProductos();
	m_baseUsuarios = new BaseUsuarios();
	login = new Login(m_baseUsuarios);
	sistema_venta = new SistemaVenta(m_baseProductos,m_baseUsuarios,login);
	m_fecha = new fecha();
	registro_de_ventas = new registro_Ventas();
	base_usuarios = new BaseUsuarios();
	

//	productosVendidosHija win(NULL,"[1234]",m_baseProductos);
//	win.ShowModal();
	
//	Usuario u("","","",1,"",11,"","","","");
//	base_usuarios->AgregarUsuario(u);
//	
//	filtroFechaHija win(NULL,m_fecha,2);
//	win.ShowModal();
	
	/// 
	wLogin ventanaLogin(NULL,login,m_baseUsuarios,m_baseProductos,sistema_venta,m_fecha,registro_de_ventas);
	ventanaLogin.ShowModal();
	
	return true;
}

