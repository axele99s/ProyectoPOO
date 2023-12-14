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
		
//		fecha f(user->verFechaNac()); /// concatenacion de la fecha, lo que hace la clase fecha es "disolver la fecha"
		
		fechaNacUser->SetValue(int_to_str(user->verAnio()));
		diaChoice->SetSelection(user->verDia()-1);
		mesChoice->SetSelection(user->verMes()-1);
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
	int dni = wx_to_int(dniUser->GetValue());
	
	
	
	int dia = (diaChoice->GetCurrentSelection()+1);
	int mes = (mesChoice->GetCurrentSelection()+1);	
	int anio = wx_to_int(fechaNacUser->GetValue());
	if(user==NULL) {
		Usuario user(username,pass,tipo,nombre,dni,dir,loc,email,dia,mes,anio);
		
		string errores = juntar_vector_string(validarUsuario(user,base_usuarios,-1));
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
		int pos = base_usuarios->verPosUsuario(*user);
		Usuario usuario(username,pass,tipo,nombre,dni,dir,loc,email,dia,mes,anio);
		
		string errores = juntar_vector_string(validarUsuario(usuario,base_usuarios,pos));
		if(!errores.empty()) {
			wxMessageBox(errores,"",wxOK);
			
		}
		else {
			
			
			if(base_usuarios->ModificarUsuario(pos,usuario)==true) {
				wxMessageBox("Usuario MODIFICADO correctamente!","",wxOK);
				EndModal(1);
			}
			else {
				wxMessageBox("El dni YA se encuentra registrado!","",wxOK);
				
			}
			
		}
		
	}
	
}

void wAgregarUsuario::cancelarAddUsuarioOnButtonClick( wxCommandEvent& event )  {
	EndModal(0);
}

wAgregarUsuario::~wAgregarUsuario() {
	
}

