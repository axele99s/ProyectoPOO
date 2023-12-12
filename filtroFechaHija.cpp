#include "filtroFechaHija.h"
#include "string_conv.h"
#include <wx/msgdlg.h>
#include "validaciones.h"



filtroFechaHija::~filtroFechaHija() {
	
}

void filtroFechaHija::buscarFechaOnButtonClick( wxCommandEvent& event )  {
	string dia =wx_to_std(diaLabel->GetValue());
	string mes =wx_to_std(mesLabel->GetValue());
	string anio =wx_to_std(anioLabel->GetValue());
	fecha date(dia,mes,anio);
	string f = date.verFecha();
	if(i==1){

		
		if(esFecha(f)){
			fec->setDia(dia);
			fec->setMes(mes);
			fec->setAnio(anio);
			EndModal(1);
		}
		else {
			wxMessageBox("Ingrese una fecha valida","Error fecha",wxOK);
		}
		
	}
	if(i==2) {
		f+="01";
		if(esFecha(f)){
			fec->setDia("01");
			fec->setMes(mes);
			fec->setAnio(anio);
			EndModal(1);
		}
		else {
			wxMessageBox("Ingrese una fecha valida","Error fecha",wxOK);
		}
	}
	if(i==3){
		f+="0101";
		fec->setDia("01");
		fec->setMes("01");
		if(esFecha(f)){
			fec->setAnio(anio);
			EndModal(1);
		}
		else {
			wxMessageBox("Ingrese una fecha valida","Error fecha",wxOK);
		}
	}
}

void filtroFechaHija::backOnButtonClick( wxCommandEvent& event )  {
	EndModal(0);
}


filtroFechaHija::filtroFechaHija (wxWindow * parent, fecha * fecha_ptr,int num): filtroFecha(parent),fec(fecha_ptr),i(num){
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

