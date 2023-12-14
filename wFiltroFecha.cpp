#include "wFiltroFecha.h"
#include "string_conv.h"
#include "validaciones.h"
#include <wx/msgdlg.h>

wFiltroFecha::wFiltroFecha(wxWindow * parent, fecha * fecha_ptr,int num): ventanaFiltroFecha(parent),fec(fecha_ptr),i(num){
	if(i==2){
		/// escondo el label de dia y la seleccion de dia
		diaText->Hide(); diaChoice->Hide();
	}
	if(i==3){
		/// escondo label y seleccion de mes y dia
		diaChoice->Hide(); diaText->Hide();
		mesChoice->Hide(); mesText->Hide();
	}

}

void wFiltroFecha::buscarFechaOnButtonClick( wxCommandEvent& event )  {
	
	int dia = (diaChoice->GetCurrentSelection()+1);
	int mes = (mesChoice->GetCurrentSelection()+1);
	
	int anio = wx_to_int(anioLabel->GetValue());
	fecha date(dia,mes,anio);
	
//	string f = date.verFecha();
	if(i==1){
			fec->setDia(dia);
			fec->setMes(mes);
			fec->setAnio(anio);
			EndModal(1);
//		}
//		else {
//			wxMessageBox("Ingrese una fecha valida","Error fecha",wxOK);
//		}
		
	}
	if(i==2) {
			fec->setDia(1);
			fec->setMes(mes);
			fec->setAnio(anio);
			EndModal(1);
//		}
//		else {
//			wxMessageBox("Ingrese una fecha valida","Error fecha",wxOK);
//		}
	}
	if(i==3){
			fec->setAnio(anio);
			EndModal(1);
//		else {
//			wxMessageBox("Ingrese una fecha valida","Error fecha",wxOK);
//		}
	}
}

void wFiltroFecha::backOnButtonClick( wxCommandEvent& event )  {
	EndModal(0);
}

wFiltroFecha::~wFiltroFecha() {
	
}

