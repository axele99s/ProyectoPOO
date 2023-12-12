#include "wAgregarUsuario.h"
#include "string_conv.h"
#include "validaciones.h"
#include <wx/msgdlg.h>

wAgregarUsuario::wAgregarUsuario(wxWindow *parent,BaseUsuarios *bu,fecha *f,Usuario *u) : user(u),m_fecha(f),base_usuarios(bu),ventanaAgregarUsuario(parent) {
	if(user!=NULL) {
		usuarioLabel->SetValue(user->verNombreUsuario());
		passLabel->SetValue(user->verPass());
		selectionTipoUsuario->SetSelection(user->verTipo());
		nombreApeUser->SetValue(user->verNombre());
		dirUser->SetValue(user->verDireccion());
		locUser->SetValue(user->verLocalidad());
		dniUser->SetValue(int_to_str(user->verDNI()));
		emailUser->SetValue(user->verEmail());
		fechaNacUser->SetValue(user->verFechaNac());
	}
}

void wAgregarUsuario::agregarUsuarioOnButtonClick( wxCommandEvent& event )  {
	string username = wx_to_std(usuarioLabel->GetValue());
	string pass = wx_to_std(passLabel->GetValue());
	int tipo = selectionTipoUsuario->GetCurrentSelection();
	
	string nombre = wx_to_std(nombreApeUser->GetValue());
	string dir = wx_to_std(dirUser->GetValue());
	string email = wx_to_std(emailUser->GetValue());
	string loc = wx_to_std(locUser->GetValue());
	string fechanac = wx_to_std(fechaNacUser->GetValue());
	int dni = wx_to_int(dniUser->GetValue());
	if(user==NULL) {
		
		Usuario user(username,pass,m_fecha->obtenerFecha(),tipo,nombre,dni,dir,loc,email,fechanac);
		
		string errores = juntar_vector_string(validarUsuario(user,base_usuarios));
		if(!errores.empty()) {
			wxMessageBox(errores,"",wxOK);
			
		}
		else {
			
			base_usuarios->AgregarUsuario(user);
			wxMessageBox("Usuario agregado correctamente!","",wxOK);
			EndModal(1);
			
			
		}
	}
	
	
	if(user!=NULL) {
		
		Usuario usuario(username,pass,user->verFecha(),tipo,nombre,dni,dir,loc,email,fechanac);
		string errores = juntar_vector_string(validarUsuario(usuario,base_usuarios));
		if(!errores.empty() and base_usuarios->check(usuario)==false ) {
			wxMessageBox(errores,"",wxOK);
			
		}
		else {
			
			int pos = base_usuarios->verPosUsuario(*user);
			base_usuarios->ModificarUsuario(pos,usuario);
			wxMessageBox("Usuario MODIFICADO correctamente!","",wxOK);
			EndModal(1);
			
			
			
		}
		
	}
	
}

void wAgregarUsuario::cancelarAddUsuarioOnButtonClick( wxCommandEvent& event )  {
	EndModal(0);
}

wAgregarUsuario::~wAgregarUsuario() {
	
}

