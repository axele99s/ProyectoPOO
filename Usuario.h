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
	int dia_reg,mes_reg,anio_reg;
public:
	
	/// constructores
	Usuario();
	Usuario(string usuario,string pass);
	Usuario(string user,string pass,int tipo,string nombre, int dni,string dir,string loc,string mail,int dia,int mes,int anio);
	
	
	/// Getter
	string verNombreUsuario();
	string verPass();
	string verFecha(); 
	int verTipo();
	int verDia_Reg();
	int verMes_Reg();
	int verAnio_Reg();
	
	/// Setter
	void setUser(string s);
	void setPass(string p);
	void setTipo(int t);
//	void setFecha(string str);
	int setDia_Reg(int);
	int setMes_Reg(int);
	int setAnio_Reg(int);
	
	
	
	
};

#endif

