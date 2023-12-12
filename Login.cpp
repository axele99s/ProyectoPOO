#include "Login.h"
#include <fstream>
#include "funcionesExtas.h"
#include <cstdio>
using namespace std;





Login::Login(BaseUsuarios *bu) : b(bu) {
	
	ifstream logUser("logUser.bin",ios::binary);
	
	if(logUser.is_open()) {
		access=true;
		char username[99];
		
		logUser.read(reinterpret_cast<char*>(&username),sizeof(username));
		string nombre_user = username;
		
		LoggedUser = b->verUsuario(nombre_user);
	}
	
	
}



/// verifico si los datos ingresados son correctos

bool Login::entrar (Usuario & u) {
	if( b->check(u)==false) return false;
	Usuario usuarioDeBase = b->verUsuario(b->verPosUsuario(u));
	return (u.verPass()==usuarioDeBase.verPass());
}


/// Si se logeo, se guarda el usuario
/// Para luego modificar o ver sus datos 
/// Desde la pestaña datos personales!
void Login::guardarUsuarioLogeado (Usuario & u) {LoggedUser = u;}


/// Desde la ventana de login si esta "guardar datos"
/// Esta func sirve para guardar los datos en binary
void Login::datosAutomaticos ( ) {
//		access=true;
	ofstream logUser("logUser.bin",ios::binary|ios::trunc);
				
		/// Solo necesito el username
		/// porque esta funcion sirve solo si se confirma el logeo
		
	char username[99];
	strcpy(username, verNombreUsuario().c_str());
		/// guardo en binario	
	logUser.write(reinterpret_cast<char*>(&username),sizeof(username));
				
}



string Login::verNombreUsuario ( ) {
	return LoggedUser.verNombreUsuario();
}

Usuario Login::verUsuarioLogeado ( ) {
	return LoggedUser;
}



void Login::eliminarDatosGuardados ( ) {
//	ofstream logUser("logUser.bin",ios::binary);
//	if(logUser.is_open()) {
		
		if(remove("logUser.bin")==true) ;

}

bool Login::verGuardadoAuto ( ) {
	return access;
}

int Login::verTipo ( ) {
	return LoggedUser.verTipo();
}

