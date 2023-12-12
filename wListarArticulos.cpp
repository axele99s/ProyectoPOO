#include "wListarArticulos.h"
#include "string_conv.h"
#include "validaciones.h"
#include <wx/grid.h>
#include "wxfb_project.h"
#include "wActualizarProducto.h"
#include "wAgregarProducto.h"

wListarArticulos::wListarArticulos(wxWindow *parent,BaseProductos *base) : bp(base),ventanaListaArticulos(parent) {
	actualizarGrilla();
}

void wListarArticulos::barraBuscarArticuloOnText( wxCommandEvent& event )  {
	string buscador = wx_to_std(barraBuscarArticulo->GetValue());
	if(sonLetras(buscador)==true) {
		
		vector<Producto> vectorTemp = bp->buscarPorNombre(buscador);
		actualizarGrillaFiltros(vectorTemp);
		
		
	}
	else {
		
		
		if(sonNumeros(buscador)==true) {
			
			vector<Producto> vectorTemp = bp->buscarPorCodigo(buscador);
			actualizarGrillaFiltros(vectorTemp);
			
		}
		
		
		
	}
}

void wListarArticulos::GridDCLICK_cambiarCant( wxGridEvent& event )  {
	/// Obtengo la fila del producto seleccionado
	int fila = listaArticulosGrid->GetGridCursorRow();
	
	/// Obtengo el codigo del producto en string
	string codi = wx_to_std(listaArticulosGrid->GetCellValue(fila,1));
	
	
	/// base producto -> producto a partir de su codigo
	Producto p = bp->verConCodigo(string_to_int(codi));
	wActualizarProducto win2(this,p,NULL,bp); /// No es solo la ventana de actualizar producto, se reutiliza para otras cosas
	win2.ShowModal();
	actualizarGrilla();
}

void wListarArticulos::agregarProdDesdeLista( wxCommandEvent& event )  {
	wAgregarProducto win(this,bp);
	win.ShowModal();
	actualizarGrilla();
}

void wListarArticulos::botonEliminarProducto( wxCommandEvent& event )  {
	/// Obtengo la fila del producto seleccionado
	int fila = listaArticulosGrid->GetGridCursorRow();
	
	/// Obtengo el codigo del producto en string
	string codi = wx_to_std(listaArticulosGrid->GetCellValue(fila,1));
	
	/// Me copio el producto(codigo) 
	/// base de productos -> ver producto a partir del codigo
	Producto p = bp->verConCodigo(string_to_int(codi));
	
	int res = wxMessageBox("Seguro que desea eliminar el producto: "+p.verNombreProducto(),"Eliminar",wxYES_NO);
	
	if(res==wxYES) {
		bp->EliminarProducto(p);
		actualizarGrilla();
	}
}

wListarArticulos::~wListarArticulos() {
	
}


void wListarArticulos::actualizarGrilla ( ) {
	if(listaArticulosGrid->GetNumberRows()>=1)listaArticulosGrid->DeleteRows(0,listaArticulosGrid->GetNumberRows()); ///<---- viejo
	listaArticulosGrid->AppendRows(bp->sizeVectProd());
	for(int i=0;i<bp->sizeVectProd();i++) { 
		listaArticulosGrid->SetCellValue(i,0,bp->verProducto(i).verNombreProducto());
		listaArticulosGrid->SetCellValue(i,1,std_to_wx(int_to_str(bp->verProducto(i).verCodigoProducto())));
		listaArticulosGrid->SetCellValue(i,2,std_to_wx(float_to_str(bp->verProducto(i).verPrecio())));
		listaArticulosGrid->SetCellValue(i,3,std_to_wx(float_to_str(bp->verProducto(i).verStock())));
		listaArticulosGrid->SetCellValue(i,4,std_to_wx(float_to_str(bp->verProducto(i).verDescuento())));
		listaArticulosGrid->SetCellValue(i,5,bp->verProducto(i).verDescripcion());
		
	}
}

void wListarArticulos::actualizarGrillaFiltros (vector<Producto> & vectorTemp) {
	/// el if esta asi para evitar error de "si la grilla esta vacia no hace delete rows"
	if(listaArticulosGrid->GetNumberRows()>=1)listaArticulosGrid->DeleteRows(0,bp->sizeVectProd()); ///remueve las grillas
	listaArticulosGrid->AppendRows(vectorTemp.size());
	for(int i=0;i<vectorTemp.size();i++) { 
		listaArticulosGrid->SetCellValue(i,0,vectorTemp[i].verNombreProducto());
		listaArticulosGrid->SetCellValue(i,1,std_to_wx(int_to_str(vectorTemp[i].verCodigoProducto())));
		listaArticulosGrid->SetCellValue(i,2,std_to_wx(int_to_str(vectorTemp[i].verPrecio())));
		listaArticulosGrid->SetCellValue(i,3,std_to_wx(int_to_str(vectorTemp[i].verStock())));
		listaArticulosGrid->SetCellValue(i,4,std_to_wx(int_to_str(vectorTemp[i].verDescuento())));
		listaArticulosGrid->SetCellValue(i,5,vectorTemp[i].verDescripcion());
		
	}
}

