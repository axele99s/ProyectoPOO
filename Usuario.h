#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "Persona.h"



using namespace std;

class Usuario : public Persona {
private:
	string user="";
	string pass="";
	string fecha="Sin definir"; /// Es la fecha de agregado del usuario, TODOS tienen una fecha de cuando fueron agregados
	int tipo=0; /// 0 = empleado ; 1 = Admin/Jefe
public:
	
	/// constructores
	Usuario();
	Usuario(string usuario,string pass);
	Usuario(string user,string pass,string fecha,int tipo,string nombre, int dni,string dir,string loc,string mail,string fechanac);
	
	
	/// Getter
	string verNombreUsuario();
	string verPass();
	string verFecha(); 
	int verTipo();
	
	
	/// Setter
	void setUser(string s);
	void setPass(string p);
	void setTipo(int t);
//	bool operator==(Usuario &u);
	void setFecha(string str);
	
	
	
	
	
};

#endif

