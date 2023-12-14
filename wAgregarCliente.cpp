#include "wAgregarCliente.h"
#include "string_conv.h"
#include "validaciones.h"
/// SI LA POSICIONES ES 0 ESTOY VINIENDO DESDE LA VENTANA MODIFICAR
/// ES DECIR, VENTANA EMPLEADOS -> Doble click para modificarlo
/// POS = 0

/// SI LA POS ES -1 ES PORQUE VOY A AGREGAR NUEVO CLIENTE
wAgregarCliente::wAgregarCliente(wxWindow * parent, int i,BaseUsuarios *bu) : pos(i),base_usuarios(bu),ventanaAgregarCliente(parent) { 
	
	if(pos!=-1) {
		AgregarCliente->SetLabel("Modificar");
		AgregarCliente->SetName("Modificar");
		nombreCliente->SetValue(base_usuarios->verCliente(i).verNombre());
		dniCliente->SetValue(int_to_str(base_usuarios->verCliente(i).verDNI()));
		direccionCliente->SetValue(base_usuarios->verCliente(i).verDireccion());
		localidadCliente->SetValue(base_usuarios->verCliente(i).verLocalidad());
		emailCliente->SetValue(base_usuarios->verCliente(i).verEmail());
//		fecha f(base_usuarios->verCliente(i).verFechaNac());
		fechaNacCliente->SetValue(int_to_str(base_usuarios->verCliente(i).verAnio()));
		diaChoice->SetSelection(base_usuarios->verCliente(i).verDia()-1);
		mesChoice->SetSelection(base_usuarios->verCliente(i).verMes()-1);
		
	}
}



void wAgregarCliente::AgregarClienteOnButtonClick( wxCommandEvent& event )  {
	/// Agregando cliente
	/// Si se hace desde la ventana principal del sistema
	/// esto es para reutilizar clase de añadir/edit cliente
	
	
	int dia = (diaChoice->GetCurrentSelection()+1);
	int mes = (mesChoice->GetCurrentSelection()+1);
	
	int anio = wx_to_int(fechaNacCliente->GetValue());
	
	
	string nombre = wx_to_std(nombreCliente->GetValue());
	string dir= wx_to_std(direccionCliente->GetValue());	
	string loc= wx_to_std(localidadCliente->GetValue());	
	string mail= wx_to_std(emailCliente->GetValue());	
	
	int dni=-1;
	if(dniCliente->GetValue() !="") {
		dni = wx_to_int(dniCliente->GetValue());
	}
	
	
	Cliente c(nombre,dni,dir,loc,mail,dia,mes,anio);
	
	/// -1 = agregar nuevo cliente
	if(pos==-1) {
		string errores = juntar_vector_string(errores_agregar_cliente(c,base_usuarios,-1)); /// copio los errores (si es q los hay)
		if(errores.empty()) {
			base_usuarios->AgregarCliente(c);
			wxMessageBox("Se ha agregado con exito el cliente","",wxOK);
			EndModal(1);
			
		}
		else {
			wxMessageBox(errores,"",wxOK); /// Muestro los errores
		}
	}
	
	/// cualquier otro caso, es modificar
	else {
		
			
		string errores = juntar_vector_string(errores_agregar_cliente(c,base_usuarios,1)); /// copio los errores (si es q los hay)
		if(errores.empty()) {
			
			
			c.setCodigoCliente(base_usuarios->verCliente(pos).verCodigoCliente()); /// VER!!!!!!
			if(base_usuarios->ModificarCliente(pos,c))
				wxMessageBox("Se ha modificado al cliente!","",wxOK);
			else wxMessageBox("El dni ya esta registrado!","",wxOK);
			EndModal(1);
		}
		else {
			wxMessageBox(errores,"",wxOK); /// Muestro los errores
		}
	}
}

void wAgregarCliente::volverOnButtonClick( wxCommandEvent& event )  {
	EndModal(0);
}

wAgregarCliente::~wAgregarCliente() {
	
}



