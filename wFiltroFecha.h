#ifndef WFILTROFECHA_H
#define WFILTROFECHA_H
#include "wxfb_project.h"
#include "fecha.h"

class wFiltroFecha : public ventanaFiltroFecha {
	
private:
	fecha *fec;
	int i;
protected:
	void buscarFechaOnButtonClick( wxCommandEvent& event )  override;
	void backOnButtonClick( wxCommandEvent& event )  override;
	
public:
	wFiltroFecha(wxWindow *parent=NULL,fecha *fecha_ptr=NULL,int i=0);
	~wFiltroFecha();
};

#endif

