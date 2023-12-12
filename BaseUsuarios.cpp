#include "BaseUsuarios.h"
#include <iostream>
#include "string_conv.h"
#include "funcionesExtas.h"
#include "validaciones.h"






BaseUsuarios::BaseUsuarios() {
	
	CargarBinarioUser();
	CargarBinarioCliente();
	
}


///------------------ METODOS DE CLIENTES ------------------------- ///


///------------------ Binarios DE CLIENTES ------------------------- ///
void BaseUsuarios::CargarBinarioCliente ( ) {
	///------------------Carga de CLIENTES, desde el binario al vector ------------------------- ///
	
ifstream archi_clientes("Clientes.bin",ios::binary|ios::ate);    
	if(archi_clientes.is_open()) {
		int n_clientes = archi_clientes.tellg();									
		int cant_clientes = n_clientes/sizeof(ClientesChar); 				
		archi_clientes.seekg(0);
		for(int i=0;i<cant_clientes;i++) { 
			ClientesChar c;
			archi_clientes.read(reinterpret_cast<char*>(&c),sizeof(c));
			
			vector_Clientes.push_back({c.codigo,c.nombre,c.dni,c.direccion,c.localidad,c.email,c.fecha_nac});
		}
	}
}
void BaseUsuarios::CrearBinarioCliente ( ) {
	ofstream archi_clientes("Clientes.bin",ios::binary | ios::trunc);
	for(size_t i=0;i<vector_Clientes.size();i++) { 
		ClientesChar c;
		strcpy(c.nombre,vector_Clientes[i].verNombre().c_str());
		
		
		strcpy(c.nombre,vector_Clientes[i].verNombre().c_str());
		strcpy(c.direccion,vector_Clientes[i].verDireccion().c_str());
		strcpy(c.localidad,vector_Clientes[i].verLocalidad().c_str());
		strcpy(c.email,vector_Clientes[i].verEmail().c_str());
		strcpy(c.fecha_nac,vector_Clientes[i].verFechaNac().c_str());
		c.dni = vector_Clientes[i].verDNI();
		c.codigo = vector_Clientes[i].verCodigoCliente();
		
		archi_clientes.write(reinterpret_cast<char*>(&c),sizeof(c));
	}
}


///----------------- Getters de Cliente
int BaseUsuarios::verPosCliente (Cliente & c) {
	for(size_t i=0;i<vector_Clientes.size();i++) { 
		if(c.verDNI() == vector_Clientes[i].verDNI()) return i;
	}
	return -1;
}
int BaseUsuarios::VerCantClientes ( ) {
	return vector_Clientes.size();
}
Cliente BaseUsuarios::verCliente (int i) {
	return vector_Clientes[i];
}

int BaseUsuarios::verPosCliente (int codigo) {
	for(size_t i=0;i<vector_Clientes.size();i++) { 
		if(vector_Clientes[i].verCodigoCliente() == codigo) return i;
	}
}

Cliente BaseUsuarios::verClientePorDNI (int dni) {
	for(size_t i=0;i<vector_Clientes.size();i++) { 
		
		if(vector_Clientes[i].verDNI() == dni) return vector_Clientes[i];
		
	}
	return Cliente();
}

///------------------- Setter Cliente

bool BaseUsuarios::ModificarCliente (int i, Cliente & cc) {
	
	for(size_t j=0;j<vector_Clientes.size();j++) { 
		if(vector_Clientes[j].verDNI()== cc.verDNI() and i!=j)return false;
	}
	
	
	vector_Clientes[i].setDNI(cc.verDNI());
	vector_Clientes[i].setNombre(cc.verNombre());
	vector_Clientes[i].setDireccion(cc.verDireccion());
	vector_Clientes[i].setLocalidad(cc.verLocalidad());
	vector_Clientes[i].setEmail(cc.verEmail());
	vector_Clientes[i].setFechaNac(cc.verFechaNac());
	vector_Clientes[i].setCodigoCliente(cc.verCodigoCliente());
	CrearBinarioCliente();
	return true;
}




//bool BaseUsuarios::checkDNICliente (int dni) {
//	for(size_t i=0;i<vector_Clientes.size();i++) { 
//		if(vector_Clientes[i].verDNI() == dni) return true;
//	}
//	return false;
//}

/**----------  OTROS METODOS ---------------------*/
bool BaseUsuarios::AgregarCliente (Cliente & c) {
	
	/// IGUAL QUE EN USUARIO, checkeo si esta o no, creo los binarios y lo paso a actualizar la base binaria
	if(check(c)==false) {
		//				ClientesChar cc;
		//				strcpy(cc.nombre,c.verNombre().c_str());
		//				cc.dni=c.verDNI();
		//				cc.codigo = crearCodigoRandom();
		//				c.setCodigoCliente(cc.codigo);
		vector_Clientes.push_back(c);
		CrearBinarioCliente();
		return true;
	}
	return false;
}

bool BaseUsuarios::EliminarCliente (Cliente & c) {
	if(check(c)==true) {
		auto it= vector_Clientes.begin();
		int pos = verPosCliente(c);
		advance(it,pos);
		
		vector_Clientes.erase(it);
		CrearBinarioCliente();
		
		return true;
	}
	
	return false;
}


/// Verifica si existe(o no) un cliente en la base de Clientes
/// Por su dni...
bool BaseUsuarios::check (Cliente &c) {
	if(vector_Clientes.size()==0) {
		return false;
	}
	for(size_t i=0;i<vector_Clientes.size();i++) { 
		if(c.verDNI() == vector_Clientes[i].verDNI()) {
			return true; /// Si coincide el dni devuelve true
		}
	}
	return false;
}



/// Codigo random al crear un nuevo cliente en la base
int BaseUsuarios::crearCodigoRandom ( ) {
	int codigo = rand()%100000+1;
	for(int i=0;i<VerCantClientes();i++) { 
		if(codigo == vector_Clientes[i].verCodigoCliente()) {
			codigo = rand()%100000+1;
			i=0;
		}
		
	}
	return codigo;
}


///----------------------METODOS DE USUARIOS  ------------------------- ///


/// 		--------	Binarios---------

void BaseUsuarios::CargarBinarioUser ( ) {
	
	///------------------Carga de USUARIOS, desde el binario al vector ------------------------- ///
	ifstream archi_usuarios("Usuarios.bin", ios::binary|ios::ate);       
	
	if(archi_usuarios.is_open()) {
	
		int n_usuarios = archi_usuarios.tellg();									
		int cant_usuarios = n_usuarios/sizeof(UsuariosChar); 				
		archi_usuarios.seekg(0);
		
		for(int i=0;i<cant_usuarios;i++) { 
			UsuariosChar c;
			archi_usuarios.read(reinterpret_cast<char*>(&c),sizeof(c));
			vector_Usuarios.push_back({c.user,c.pass,c.fecha,c.tipo,c.nombre,c.dni,c.direccion,c.localidad,c.email,c.fecha_nac});
		}
	}

}

void BaseUsuarios::CrearBinarioUser ( ) {
	ofstream archi_usuarios("Usuarios.bin",ios::binary | ios::trunc);
	
	
	for(size_t i=0;i<vector_Usuarios.size();i++) {
		/// Como en el vector de clientes hay strings, paso todo un struct de chars
		UsuariosChar u;
		strcpy(u.user,vector_Usuarios[i].verNombreUsuario().c_str());
		strcpy(u.pass,vector_Usuarios[i].verPass().c_str());
		strcpy(u.fecha,vector_Usuarios[i].verFecha().c_str());
		u.tipo = vector_Usuarios[i].verTipo();
		
		
		strcpy(u.nombre,vector_Usuarios[i].verNombre().c_str());
		strcpy(u.direccion,vector_Usuarios[i].verDireccion().c_str());
		strcpy(u.localidad,vector_Usuarios[i].verLocalidad().c_str());
		strcpy(u.email,vector_Usuarios[i].verEmail().c_str());
		strcpy(u.fecha_nac,vector_Usuarios[i].verFechaNac().c_str());
		u.dni = vector_Usuarios[i].verDNI();
		
		archi_usuarios.write(reinterpret_cast<char*>(&u),sizeof(u));
	}
	
}




/// -------------Getters Usuario----------



Usuario BaseUsuarios::verUsuario ( int i) {
	return vector_Usuarios[i];
}
/// Devuelve el Usuario a partir de un username
Usuario BaseUsuarios::verUsuario (string username) {
	
	for(size_t i=0;i<vector_Usuarios.size();i++) { 
		if(username==vector_Usuarios[i].verNombreUsuario()) {
			return vector_Usuarios[i];
		}
	}
	return Usuario();
}

/// Setters Usuarios

bool BaseUsuarios::esElMismo(int i, Usuario & uu){
	for(size_t j=0;j<vector_Usuarios.size();j++) { 
		
		if(vector_Usuarios[j].verNombreUsuario()== uu.verNombreUsuario() and i!=j) {
			
			return false;
		}
	}
	return true;
}


bool BaseUsuarios::ModificarUsuario (int i, Usuario & uu) {
	
	for(size_t j=0;j<vector_Usuarios.size();j++) { 
		if(vector_Usuarios[j].verDNI()== uu.verDNI() and i!=j)return false;
	}
	vector_Usuarios[i].setUser(uu.verNombreUsuario());
	vector_Usuarios[i].setPass(uu.verPass());
	vector_Usuarios[i].setTipo(uu.verTipo());
	vector_Usuarios[i].setFecha(uu.verFecha());
	
	vector_Usuarios[i].setDNI(uu.verDNI());
	vector_Usuarios[i].setNombre(uu.verNombre());
	vector_Usuarios[i].setDireccion(uu.verDireccion());
	vector_Usuarios[i].setLocalidad(uu.verLocalidad());
	vector_Usuarios[i].setEmail(uu.verEmail());
	vector_Usuarios[i].setFechaNac(uu.verFechaNac());
	CrearBinarioUser();
	return true;
}


/// Otros metodos


bool BaseUsuarios::AgregarUsuario ( Usuario &u ) {
	/// Antes de agregar al usuario, checkeo si ya se encuentra en la base de datos
		if(check(u)==false) {
				vector_Usuarios.push_back(u);
				CrearBinarioUser();
			return true;
		}
	return false;
}


bool BaseUsuarios::check (Usuario &u) {
	if(vector_Usuarios.size()==0) return false;
	int pos = verPosUsuario(u); 
	if(pos==-1) return false;
	
	return true;
}



bool BaseUsuarios::EliminarUsuario (Usuario & u) {
	if(check(u)==true) {
		int pos = verPosUsuario(u);
		auto it=vector_Usuarios.begin();
		advance(it,pos);
		
		vector_Usuarios.erase(it);
		CrearBinarioUser();
				
	}
	return false;
}




int BaseUsuarios::verPosUsuario (Usuario & c) {
	for(size_t i=0;i<vector_Usuarios.size();i++) { 
		if(c.verNombreUsuario() == vector_Usuarios[i].verNombreUsuario()) return i;
	}
	return -1;
}

int BaseUsuarios::VerCantUsuarios ( ) {
	return vector_Usuarios.size();
}















//Cliente BaseUsuarios::operator[] (int num) {
//	for(size_t i=0;i<vector_Clientes.size();i++) { 
//		if (vector_Clientes[i].verDNI() == num)return vector_Clientes[i];
//		if (vector_Clientes[i].verCodigoCliente() == num) return vector_Clientes[i];
//	}
//}
//
//Usuario BaseUsuarios::operator[] (string user) {
//	for(size_t i=0;i<vector_Usuarios.size();i++) { 
//		if(vector_Usuarios[i].verNombreUsuario() == user) return vector_Usuarios[i];
//	}
//}





/**-------------------------------------------------------------------------*/
/// Funciones para los filtros del buscador
vector<Cliente> BaseUsuarios::buscarPorNombre (string nombre_cliente) {
	vector<Cliente> c;
	
	for(size_t i=0;i<vector_Clientes.size();i++) { 
		
		string nombre_temp = vector_Clientes[i].verNombre(); 
		
		if(minuscula(nombre_temp).find(minuscula(nombre_cliente))!=string::npos) {c.push_back(vector_Clientes[i]);}
	}
	
	
	return c;
	
	
}

vector<Cliente> BaseUsuarios::buscarPorCodigo (string codigo) {
	vector<Cliente> c;
	
	for(size_t i=0;i<vector_Clientes.size();i++) { 
		string codigoCliente = int_to_str(vector_Clientes[i].verCodigoCliente());
		if(codigoCliente.find(codigo)!=string::npos) {c.push_back(vector_Clientes[i]);}
	}
	
	
	return c;
}

vector<Cliente> BaseUsuarios::buscarPorDNI (string m_dni) {
	vector<Cliente> c;
	
	for(size_t i=0;i<vector_Clientes.size();i++) { 
		string dni_string = int_to_str(vector_Clientes[i].verDNI());
		if(dni_string.find(m_dni)!=string::npos) {c.push_back(vector_Clientes[i]);}
	}
	
	
	return c;
}






vector<Usuario> BaseUsuarios::buscarPorUser (string username) {
	vector<Usuario> vu;
	
	for(size_t i=0;i<vector_Usuarios.size();i++) { 
		
		string nombre_temp = vector_Usuarios[i].verNombreUsuario(); 
		
		if(minuscula(nombre_temp).find(minuscula(username))!=string::npos) {vu.push_back(vector_Usuarios[i]);}
	}
	
	
	return vu;
}



vector<Usuario> BaseUsuarios::buscarPorFecha (string fecha) {
	vector<Usuario> vu;
	for(size_t i=0;i<vector_Usuarios.size();i++) { 
		
		string f = vector_Usuarios[i].verFecha(); /// obtengo la fecha
		string fecha_temp = convertirFecha(f); 		/// la paso a un formato para el filtro 
		if((fecha_temp).find(fecha)!=string::npos) {vu.push_back(vector_Usuarios[i]);}
	}
	
	
	return vu;
}
/**-------------------------------------------------------------------------*/






