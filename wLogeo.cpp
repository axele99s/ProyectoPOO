#include "wLogeo.h"
#include "string_conv.h"
#include "wSistema.h"
#include <wx/msgdlg.h>

wLogeo::wLogeo(wxWindow * parent, Login * log, BaseUsuarios * bu, BaseProductos * m_baseProductos, 
			   SistemaVenta * m_sistema_venta, fecha * fecha, registro_Ventas * registro_de_ventas) 
			: base_usuarios(bu),login(log),ventana_Login(parent),m_fecha(fecha),registro(registro_de_ventas),sistema_venta(m_sistema_venta),bp(m_baseProductos)
{
	if(log->verGuardadoAuto()==true) {
		guardarDatos->SetValue(true);
		Usuario s = log->verUsuarioLogeado();
		textoUsuario->SetLabel(s.verNombreUsuario());
		textoPass->SetLabel(s.verPass());
	}
}

wLogeo::~wLogeo() {
	Close();
}



void wLogeo::guardarDatosOnCheckBox( wxCommandEvent& event )  {
	event.Skip();
}

void wLogeo::clickBotonIniciar( wxCommandEvent& event )  {
	/// Obtengo los datos y lo convierto a user 
	string user = wx_to_std(textoUsuario->GetValue());
	string pass = wx_to_std(textoPass->GetValue());
	
	Usuario u(user,pass);
	/// log in -> 
	
	if(login->entrar(u)==true) {
		u = base_usuarios->verUsuario(user);
		login->guardarUsuarioLogeado(u);
		
		if(guardarDatos->GetValue()==true) {
			login->datosAutomaticos();
		}
		else {
			login->eliminarDatosGuardados();
		}
		
		
		
		//		EndModal(1);
		Close();
		wSistema *win= new wSistema(NULL,bp,sistema_venta,m_fecha,registro,base_usuarios,login);
		win->Show();
		
	}
	else{
		
		wxMessageBox("Datos ERRONEOS!!","Error",wxOK);
	}
}



void wLogeo::SalirOnButtonClick( wxCommandEvent& event )  {
	Close();
}


inline void wxTextCtrl_SetPasswordFlag(wxTextCtrl* win, bool active)
{
#ifdef __WXMSW__
	HWND hwnd = (HWND)win->GetHandle();
#if wxUSE_UNICODE
	static wchar_t password_char = 0x25CF;
	static bool initialized = false;
	if (win->HasFlag(wxTE_PASSWORD) && !initialized)
	{
		password_char = (wchar_t)SendMessage(hwnd, EM_GETPASSWORDCHAR, 0, 0);
		initialized = true;
	}
#else
	const char password_char = '*';
#endif
	SendMessage(hwnd, EM_SETPASSWORDCHAR, active ? password_char : 0, 0);
#endif
	win->Refresh();
}


void wLogeo::showPassLoginOnCheckBox( wxCommandEvent& event )  {
	wxTextCtrl_SetPasswordFlag(textoPass,!showPassLogin->GetValue());
}
