#ifndef LOGIN_H
#define LOGIN_H
#include "BaseUsuarios.h"
#include "Usuario.h"

class Login {
private: 
	Usuario LoggedUser;
	bool autoComplete; /// variable para autoguardar datos del ultimo Usuario
	BaseUsuarios *b;
	bool access=false;
public:
	Login (BaseUsuarios *bu);
	
	/// Logear
	bool entrar(Usuario &u);
	
	/// Guardar los datos del usuario logeado
	void guardarUsuarioLogeado(Usuario &u);
	
	/// Ver el usuario Logeado
	Usuario verUsuarioLogeado();
	
	///
	void datosAutomaticos();
	int verTipo();
	string verNombreUsuario();
	
	void eliminarDatosGuardados();
	
	bool verGuardadoAuto();

};

#endif

