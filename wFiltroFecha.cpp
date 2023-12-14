#include "wFiltroFecha.h"
#include "string_conv.h"
#include "validaciones.h"
#include <wx/msgdlg.h>

wFiltroFecha::wFiltroFecha(wxWindow * parent, fecha * fecha_ptr,int num): ventanaFiltroFecha(parent),fec(fecha_ptr),i(num){
	if(i==2){
		diaText->Hide();
		diaLabel->Hide();
	}
	if(i==3){
		diaText->Hide();
		diaLabel->Hide();
		mesText->Hide();
		mesLabel->Hide();
	}

}

void wFiltroFecha::buscarFechaOnButtonClick( wxCommandEvent& event )  {
//	string dia =wx_to_std(diaLabel->GetValue());
//	string mes =wx_to_std(mesLabel->GetValue());
//	string anio =wx_to_std(anioLabel->GetValue());
//	fecha date(dia,mes,anio);
//	string f = date.verFecha();
//	if(i==1){
//		
//		
//		if(esFecha(f)){
//			fec->setDia(dia);
//			fec->setMes(mes);
//			fec->setAnio(anio);
//			EndModal(1);
//		}
//		else {
//			wxMessageBox("Ingrese una fecha valida","Error fecha",wxOK);
//		}
//		
//	}
//	if(i==2) {
//		f+="01";
//		if(esFecha(f)){
//			fec->setDia("01");
//			fec->setMes(mes);
//			fec->setAnio(anio);
//			EndModal(1);
//		}
//		else {
//			wxMessageBox("Ingrese una fecha valida","Error fecha",wxOK);
//		}
//	}
//	if(i==3){
//		f+="0101";
//		fec->setDia("01");
//		fec->setMes("01");
//		if(esFecha(f)){
//			fec->setAnio(anio);
//			EndModal(1);
//		}
//		else {
//			wxMessageBox("Ingrese una fecha valida","Error fecha",wxOK);
//		}
//	}
}

void wFiltroFecha::backOnButtonClick( wxCommandEvent& event )  {
	EndModal(0);
}

wFiltroFecha::~wFiltroFecha() {
	
}

