#ifndef FILTROFECHAHIJA_H
#define FILTROFECHAHIJA_H
#include "wxfb_project.h"
#include "fecha.h"

class filtroFechaHija : public filtroFecha {
	
private:
	fecha *fec;
	int i;
protected:
	void buscarFechaOnButtonClick( wxCommandEvent& event )  override;
	void backOnButtonClick( wxCommandEvent& event )  override;
	
public:
	filtroFechaHija(wxWindow *parent=NULL,fecha *fecha_ptr=NULL,int i=0);
	~filtroFechaHija();
};

#endif

