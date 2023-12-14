#include "wProductosVendidos.h"
#include "string_conv.h"
#include "funcionesExtas.h"

wProductosVendidos::wProductosVendidos(wxWindow *parent,vector<prodsVenta> *pv,BaseProductos*bp) : base_productos(bp),ventanaProductosVendidos(parent) {
	
	vector<prodsVenta> vec = *pv;
	grillaVendidos->AppendRows(vec.size());
	
	for(size_t i=0;i<vec.size();i++) {  
		prodsVenta vendidos = vec[i];
		grillaVendidos->SetCellValue(i,0,vendidos.nombre);
		int pos = bp->verPosProducto(vendidos.codigo);
		if( pos == -1){
			
			grillaVendidos->SetCellValue(i,4,"Descontinuado");
		}
		else {
			grillaVendidos->SetCellValue(i,4,"En venta");
		}
		
	
		grillaVendidos->SetCellValue(i,3,int_to_str(vendidos.codigo));
		grillaVendidos->SetCellValue(i,1,float_to_str(vendidos.cantidad));
		grillaVendidos->SetCellValue(i,2,"$"+float_to_str(vendidos.precio));
	}
}

void wProductosVendidos::cerrarOnButtonClick( wxCommandEvent& event )  {
	EndModal(0);
}

wProductosVendidos::~wProductosVendidos() {
	
}


//void wProductosVendidos::obtenerProductos (vector<Producto> & P) {
//	string productos_str = str;
//	if(!productos_str.empty())
//		while(productos_str.find("[")!=string::npos) {
//		int pos1=productos_str.find("[");
//		int pos2=productos_str.find("]");
//		
//		string str_codigo = productos_str.substr(pos1+1,pos2-pos1-1);
//		Producto p = base_productos->verConCodigo(string_to_int(str_codigo));
//		
//		int pos3=productos_str.find("(");
//		int pos4=productos_str.find(")");
//		
//		string cantidad = productos_str.substr(pos3+1,pos4-pos3-1);
//		
//		if(p.verTipo()==1 or p.verTipo()==2)
//			p.CambiarStock(string_to_float(cantidad));
//		else {
//			p.CambiarStock(string_to_int(cantidad));
//		}
//		
//		int pos5=productos_str.find("{");
//		int pos6=productos_str.find("}");
//		float precio = string_to_float(productos_str.substr(pos5+1,pos6-pos5-1));
//		p.ponerPrecio(precio);
//		P.push_back(p);
//		productos_str.erase(pos1,pos2-1);
//		
//	}
//}


