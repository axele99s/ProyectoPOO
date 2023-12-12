#ifndef VALIDACIONES_H
#define VALIDACIONES_H
#include <vector>
#include "Producto.h"
#include "Cliente.h"
#include "BaseUsuarios.h"
#include "BaseProductos.h"
#include <wx/msgdlg.h>
#include "Usuario.h"
#include "string_conv.h"
#include "fecha.h"

/// Posibles errores al agregar una persona (cliente o usuario)







inline bool sonNumeros(string str){
	string s="0123456789";
	for(size_t i=0;i<str.size();i++) {  
		if(s.find(str[i])==string::npos) return false;
	}
	return true;
}
	
	
inline string convertirFecha(string &str){
	string copy = str;
	auto it = copy.begin() ;
	
	
	
	while(it!=copy.end())	{
		string str_aux(1,*it);
		
		if(sonNumeros(str_aux)==false) {
			
			it = copy.erase(it); 
			it--;
		}
		it++;
	}
	
	if(copy.size()>=9)copy.erase(8,6);
	return copy;
}
inline bool esFecha(string &str){
	
	
	
	if(sonNumeros(str)==false )return false;
	
	if(str.size()!=8) return false;
	return true;
}
//inline string convertirHora(string &str){
//	
//	
//	string copy = str;
//	auto it = copy.begin() ;
//		while(it!=copy.end())	{
//			string str_aux(1,*it);
//			
//			if(sonNumeros(str_aux)==false) {
//				it = copy.erase(it); 
//				it--;
//			}
//			it++;
//		}
//	if(copy.size()>=9)copy.erase(0,8);
//	return copy ;
//}
	
inline string juntar_vector_string(vector<string> v){
	string str;
	for(size_t i=0;i<v.size();i++) { 
		str+= v[i]+"\n";
	}
	return str;
}
	
inline bool sonLetras(string str){
	string a="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for(size_t i=0;i<str.size();i++) { 		
		if(a.find(str[i])==string::npos) return false;
	}
	return true;
}
inline vector<string> erroresPersona(Persona &c){
	vector<string> errores;
	
	string aux = c.verFechaNac();
	
	string fecha_nac = convertirFecha(aux);
	
	int anio = string_to_int(fecha_nac.substr(4,4));
	fecha f;
	if(anio>f.verAnioActual()) errores.push_back("Año incorrecto, acaso vienes del futuro?");
	if(anio<=1900) errores.push_back("Año incorrecto, tienes mas de 100 años? Increible");
	
//	if(esFecha(fecha_nac)==false) errores.push_back("Ingrese correctamente la fecha!");
	if(c.verEmail().find("@")==string::npos) errores.push_back("Email invalido!");
	if(c.verDNI()==0) errores.push_back("El dni NO puede ser vacio ni pueden ser letras!");
	if(c.verDNI()<=0) {	errores.push_back("DNI INEXISTENTE");}
	return errores;		
}
	/// al agregar
	inline vector<string> validarUsuario(Usuario &u,BaseUsuarios *bu,int pos){
		vector <string> errores;
		if(u.verNombre()=="") errores.push_back("El nombre no puede estar vacio!"); 
		if(u.verPass()=="") errores.push_back("La contraseña no puede estar en blanco!");
		
		/// Si viene para AGREGAR uno nuevo, viene con pos -1
		if(bu->check(u)==true and pos == -1) errores.push_back("El nombre de usuario ya existe!");
		if(bu->check(u)==true and pos==-1) {errores.push_back("El dni ya existe en la base!");}
		
		/// Si viene para MODIFICAR, viene con pos
		if(bu->esElMismo(pos,u)==false and bu->check(u)==true) {errores.push_back("El dni ya existe en la base!");}
		if(bu->esElMismo(pos,u)==false and pos!=-1) errores.push_back("El nombre de usuario ya esta registado!");;
		
		Persona p(u.verNombre(),u.verDireccion(),u.verEmail(),u.verDNI(),u.verFechaNac(),u.verLocalidad());
		vector<string> errores_persona = erroresPersona(p);
		if(!errores_persona.empty()) {
			for(size_t i=0;i<errores_persona.size();i++) { 
				errores.push_back(errores_persona[i]);
			}
		}
		
		return errores;
		
	}
	
inline vector<string>  errores_agregar_cliente(Cliente &c,BaseUsuarios *bu,int pos=-1) {
	vector<string> errores;
	if(sonLetras(c.verNombre())==false or c.verNombre()=="") {
		errores.push_back("El nombre debe no estar vacio! Tampoco pueden ser numeros! ");
	}
	if(bu->check(c)==true and pos==-1) {errores.push_back("El dni ya existe en la base!");}
	Persona p(c.verNombre(),c.verDireccion(),c.verEmail(),c.verDNI(),c.verFechaNac(),c.verLocalidad());
	vector<string> errores_persona = erroresPersona(p);
	if(!errores_persona.empty()) {
		for(size_t i=0;i<errores_persona.size();i++) { 
			errores.push_back(errores_persona[i]);
		}
	}
	
	return errores;
}
inline bool validarClienteAlAgregar(Cliente &c,BaseUsuarios *bu){
	
	if(c.verDNI()==-1) {
		return false;
	}
	
	if(sonLetras(c.verNombre())==false or c.verNombre()=="") {
		return false;
	}
	if(bu->check(c)==true) {
		return false;
	}
	return true;
}

/// Valida que el producto a agregar cumpla con ciertas condiciones
inline vector<string> ValidarAgregadoProducto(Producto &p,BaseProductos *bp) {
	
	vector<string> v; /// se almacenan los errores
	if(sonLetras(p.verNombreProducto())==false){
		v.push_back("El nombre del producto solo pueden ser letras");
	}
	if(p.verNombreProducto().empty()) v.push_back("El Nombre no puede estar vacio");
	if(p.verStock() < 0) v.push_back("El stock no puede ser <0!");
	if(p.verPrecio() < 0) v.push_back("El precio no puede ser <0!");
	
//	for(size_t i=0;i<bp->sizeVectProd();i++) { 
//		if(p.verNombreProducto() == bp->verProducto(i).verNombreProducto()) {
//			v.push_back("El nombre del producto YA EXISTE!");
//			i=bp->sizeVectProd();
//		}
//	}
	
	return v;
}

inline vector<string> ValidarAgregadoCarrito(Producto &p,BaseProductos *bp) {
	
	vector<string> v; /// se almacenan los errores
	if(p.verStock() <=0) v.push_back("El stock no puede ser <=0!");
	if(p.verStock() > bp->verConCodigo(p.verCodigoProducto()).verStock()) v.push_back("No hay stock suficiente");
	
	
	return v;
}

inline bool ValidarAgregado(Producto &p,BaseProductos *bp){
	vector<string> v = ValidarAgregadoProducto(p,bp);
	if(p.verNombreProducto()!="" && p.verPrecio()>=0 && p.verStock()>=0 && v.size()==0) return true;
	return false; 
}
#endif
