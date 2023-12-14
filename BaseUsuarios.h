#ifndef BASEUSUARIOS_H
#define BASEUSUARIOS_H
#include "Usuario.h"
#include <vector>
#include <map>
#include <iostream>
#include <cstring>
#include <fstream>
#include "Cliente.h"
using namespace std;




class BaseUsuarios{
private:
	
	vector<Usuario> vector_Usuarios;
	vector<Cliente> vector_Clientes;
	
public:
	
	BaseUsuarios();
	
	/// Creacion o carga de usuarios y clientes;
	void CargarBinarioUser();
	void CargarBinarioCliente();
	void CrearBinarioUser();
	void CrearBinarioCliente();
	
	/// Agregar y eliminar usuarios o clientes
	bool AgregarUsuario(Usuario &u);
	bool AgregarCliente(Cliente &c);
	bool EliminarUsuario(Usuario &u);
	bool EliminarCliente(Cliente &c);
	

	
	/// Valida si existe(o no) usuario/cliente CON SU DNI
	bool checkPorUser(Usuario &u);  /// Este check sirve para ver si se encuentra o no el usuario en la base
	bool CheckPorDNI(Usuario &u);
	
	
	/// Cliente solo con dni
	bool check(Cliente &c); /// Lo mismo en este, con cliente
	
	
	/// ver la cantidad del vector de cada uno
	int VerCantUsuarios();
	int VerCantClientes();
	
	
	/// Ver usuario
	Usuario verUsuario(int i); /// Devuelve un usuario con la posicion i
	Usuario verUsuario(string username);
	int verPosUsuario(Usuario &c); /// Devuelve la posicion del Usuario LO VALIDA CON EL USERNAME
	
	bool esElMismo(int i,Usuario &uu); /// Sirve para la validacion... al MODIFICAR usuario, revisa si no existe ni el dni ni el usuario
	bool usuarioExistente(Usuario &uu);
	///Ver Cliente
	Cliente verCliente(int i); 
	int verPosCliente(Cliente &c);
	int verPosCliente(int codigo);
	Cliente verClientePorDNI(int dni);
	
	/// Modificar cliente o Usuario
	bool ModificarUsuario(int i,Usuario &uu);
	bool ModificarCliente(int i,Cliente &cc);
	
	
	/// sobrecarga de operadores (creo q no los termine usando)
	
	/// codigo random de cliente
	int crearCodigoRandom();
	
	/// Filtros de busqueda CLIENTE
	vector<Cliente> buscarPorNombre(string nombre_cliente);
	vector<Cliente> buscarPorCodigo(string codigo);
	vector<Cliente> buscarPorDNI(string m_dni);
	
	
	
	/// Filtros de busqueda USUARIO
	vector<Usuario> buscarPorUser(string username);
	vector<Usuario> buscarPorFecha(string fecha);
	

};

#endif

