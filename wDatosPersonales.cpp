#include "wDatosPersonales.h"
#include "string_conv.h"
#include "validaciones.h"
#include "fecha.h"
#include "wAgregarUsuario.h"

wDatosPersonales::wDatosPersonales(wxWindow * parent, BaseUsuarios * bu, Login * l) : base_usuarios(bu),login(l),ventana_DatosPersonales(parent){
	actualizarDatosPersonales();
	if(login->verTipo()==1) modificarPersonales->Show();
}


void wDatosPersonales::botonModificarOnButtonClick( wxCommandEvent& event )  {
	/// Si el valor del boton es "Aceptar"
	/// Significa que esta en la modificacion
	if(botonModificar->GetLabel()=="Aceptar") {
		string username = wx_to_std(usuarioLabelDatos->GetValue());
		string pass = wx_to_std(passLabelDatos->GetValue());
		
		Usuario s = login->verUsuarioLogeado();
		int pos = base_usuarios->verPosUsuario(s);
		
		s.setUser(username);
		s.setPass(pass);
		string ss =(s.verFechaNac());
		string m = convertirFecha(ss);
		
		string errores = juntar_vector_string(validarModificarUsuario(s,base_usuarios));
		
		if(!errores.empty()) {
			wxMessageBox(errores,"",wxOK);
			
		}
		else {
			
			base_usuarios->ModificarUsuario(pos,s);
			login->guardarUsuarioLogeado(s);
			actualizarDatosPersonales();
			wxMessageBox("Se han modificado los datos!","",wxOK);
			
		}
		
		
		//		EndModal(1);
	}
	
	else {
		if(login->verTipo()==1)usuarioLabelDatos->Enable(true);
		passLabelDatos->Enable(true);
		botonModificar->SetLabel("Aceptar");
	}
	
}

void wDatosPersonales::SalirOnButtonClick( wxCommandEvent& event )  {
	EndModal(0);
}

void wDatosPersonales::modificarPersonalesOnButtonClick( wxCommandEvent& event )  {
	/// la fecha es necesaria porque es la del registro
	
	fecha * f = new fecha(login->verUsuarioLogeado().verFecha()) ;
	Usuario logeado = login->verUsuarioLogeado();
	wAgregarUsuario win(this,base_usuarios,f,&logeado);
	win.ShowModal();
}

wDatosPersonales::~wDatosPersonales() {
	
}




/// la funcion de abajo simplemente convierte los caracteres en contraseña y viceversa
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

void wDatosPersonales::showPassOnCheckBox( wxCommandEvent& event )  {
	wxTextCtrl_SetPasswordFlag(passLabelDatos,!showPass->GetValue());
}


void wDatosPersonales::actualizarDatosPersonales ( ) {
	Usuario s = login->verUsuarioLogeado();
	usuarioLabelDatos->SetValue(s.verNombreUsuario());
	passLabelDatos->SetValue(s.verPass());
	fechaReg->SetValue(s.verFecha());
}

