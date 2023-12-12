#include "wInformacion.h"

wInformacion::wInformacion(wxWindow *parent) : ventana_Informacion(parent) {
	myLabel1->SetLabel("Este proyecto es un Sistema de gestion de ventas, usuarios y clientes.");
	myLabel2->SetLabel("Fue realizado para la materia de Programacion Orientada a Objetos, UNL - FICH");
	myLabel3->SetLabel("Realizado por el alumno Echevarria Axel Emanuel.");
	myLabel4->SetLabel("Datos de contacto: axelechev@gmail.com");
}

wInformacion::~wInformacion() {
	
}

