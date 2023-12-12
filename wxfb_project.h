///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/dialog.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/choice.h>
#include <wx/statline.h>
#include <wx/grid.h>
#include <wx/bmpbuttn.h>
#include <wx/tglbtn.h>
#include <wx/combobox.h>

///////////////////////////////////////////////////////////////////////////

#define menuEmpleadoZ 1000
#define idEmpleadoMenu 1001
#define idAgregarNuevoEmpleado 1002
#define fechaLabelID 1003
#define productName 1004
#define descuentoLabelID 1005
#define ventanaClientesLabel 1006

///////////////////////////////////////////////////////////////////////////////
/// Class ventanaLogin
///////////////////////////////////////////////////////////////////////////////
class ventanaLogin : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText2;
		wxTextCtrl* textoUsuario;
		wxStaticText* m_staticText3;
		wxTextCtrl* textoPass;
		wxCheckBox* showPassLogin;
		wxCheckBox* guardarDatos;
		wxButton*  botonLogeo;
		wxButton* Salir;

		// Virtual event handlers, override them in your derived class
		virtual void showPassLoginOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void guardarDatosOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickBotonIniciar( wxCommandEvent& event ) { event.Skip(); }
		virtual void SalirOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventanaLogin( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~ventanaLogin();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventanaSistema
///////////////////////////////////////////////////////////////////////////////
class ventanaSistema : public wxFrame
{
	private:

	protected:
		wxMenuBar* menuBar;
		wxMenu* menuInicio;
		wxMenu* menuArticulos;
		wxMenu* menuClientes;
		wxMenu* menuEmpleados;
		wxMenu* menuPersonal;
		wxButton* m_button6;
		wxButton* botonHistorial;
		wxStaticText* fecLabel;
		wxTextCtrl* fechaLabel;

		// Virtual event handlers, override them in your derived class
		virtual void menuInformacionOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void salirMenu( wxCommandEvent& event ) { event.Skip(); }
		virtual void abrirListaArticulos( wxCommandEvent& event ) { event.Skip(); }
		virtual void abrirAgregarProducto( wxCommandEvent& event ) { event.Skip(); }
		virtual void abrirListaClientes( wxCommandEvent& event ) { event.Skip(); }
		virtual void agregarClienteMenu( wxCommandEvent& event ) { event.Skip(); }
		virtual void abrirListaEmpleados( wxCommandEvent& event ) { event.Skip(); }
		virtual void agregarEmpleadoMenuOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void menuVerDatosOnMenuSelection( wxCommandEvent& event ) { event.Skip(); }
		virtual void cerrarSesionMenu( wxCommandEvent& event ) { event.Skip(); }
		virtual void realizarNuevaVenta( wxCommandEvent& event ) { event.Skip(); }
		virtual void botonHistorialOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventanaSistema( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 499,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~ventanaSistema();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventanaAgregarProducto
///////////////////////////////////////////////////////////////////////////////
class ventanaAgregarProducto : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText22;
		wxTextCtrl* nombreProducto_label;
		wxStaticText* m_staticText221;
		wxTextCtrl* descripcion_label;
		wxStaticText* m_staticText2211;
		wxTextCtrl* precio_label;
		wxStaticText* m_staticText221111;
		wxChoice* tipo_label;
		wxStaticText* m_staticText22111;
		wxTextCtrl* cantidad_label;
		wxStaticText* m_staticText222;
		wxTextCtrl* descuento_label;
		wxStaticText* m_staticText2221;
		wxButton* m_button19;
		wxButton* m_button20;

		// Virtual event handlers, override them in your derived class
		virtual void agregarProductoBoton( wxCommandEvent& event ) { event.Skip(); }
		virtual void cancelarBoton( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventanaAgregarProducto( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~ventanaAgregarProducto();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventanaRealizarVenta
///////////////////////////////////////////////////////////////////////////////
class ventanaRealizarVenta : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText6;
		wxStaticLine* m_staticline11;
		wxStaticText* m_staticText28;
		wxTextCtrl* barraBuscadorVenta;
		wxGrid* grillaProductosVenta;
		wxButton* botonAgregarProductos;
		wxGrid* grillaCarrito;
		wxBitmapButton* m_bpButton1;
		wxButton* botonEliminarCarrito;
		wxButton* clearCarrito;
		wxStaticText* m_staticText38;
		wxTextCtrl* total;
		wxStaticLine* m_staticline1;
		wxStaticText* cliente;
		wxTextCtrl* clienteDNItexto;
		wxButton* agregarCliente;
		wxStaticText* m_staticText23;
		wxTextCtrl* nombreClienteLabel;
		wxButton* botonConfirmar;
		wxButton* botonCancelarVenta;

		// Virtual event handlers, override them in your derived class
		virtual void barraBuscadorVentaOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void agregarCarritoEnter( wxMouseEvent& event ) { event.Skip(); }
		virtual void celdaLeftDClick( wxGridEvent& event ) { event.Skip(); }
		virtual void agregarAlCarrito( wxCommandEvent& event ) { event.Skip(); }
		virtual void editarCantidad( wxGridEvent& event ) { event.Skip(); }
		virtual void botonEliminarOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void vaciarCarritoOnClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void agregarClienteOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void botonConfirmarOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void botonCancelarVentaOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventanaRealizarVenta( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 795,596 ), long style = wxDEFAULT_DIALOG_STYLE );

		~ventanaRealizarVenta();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventana_Informacion
///////////////////////////////////////////////////////////////////////////////
class ventana_Informacion : public wxDialog
{
	private:

	protected:
		wxStaticText* myLabel1;
		wxStaticText* myLabel2;
		wxStaticText* myLabel3;
		wxStaticText* myLabel4;

	public:

		ventana_Informacion( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 466,190 ), long style = wxDEFAULT_DIALOG_STYLE );

		~ventana_Informacion();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventanaListaArticulos
///////////////////////////////////////////////////////////////////////////////
class ventanaListaArticulos : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText27;
		wxTextCtrl* barraBuscarArticulo;
		wxToggleButton* m_toggleBtn1;
		wxGrid* listaArticulosGrid;
		wxButton* boton_agregarProd;
		wxButton* m_button19;

		// Virtual event handlers, override them in your derived class
		virtual void barraBuscarArticuloOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void GridDCLICK_cambiarCant( wxGridEvent& event ) { event.Skip(); }
		virtual void agregarProdDesdeLista( wxCommandEvent& event ) { event.Skip(); }
		virtual void botonEliminarProducto( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventanaListaArticulos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 710,415 ), long style = wxDEFAULT_DIALOG_STYLE );

		~ventanaListaArticulos();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventanaActualizarProducto
///////////////////////////////////////////////////////////////////////////////
class ventanaActualizarProducto : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText18;
		wxStaticText* productoNombre;
		wxStaticText* m_staticText30;
		wxTextCtrl* precioLabel;
		wxStaticText* m_staticText25;
		wxTextCtrl* descripcionLabel;
		wxStaticText* m_staticText19;
		wxTextCtrl* cantStock;
		wxStaticText* m_staticText22;
		wxTextCtrl* cantidadElegida;
		wxStaticText* m_staticText24;
		wxTextCtrl* descuentoLabel;
		wxButton* m_button15;
		wxButton* m_button16;

		// Virtual event handlers, override them in your derived class
		virtual void confirmarCarrito( wxCommandEvent& event ) { event.Skip(); }
		virtual void volverElegirProd( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventanaActualizarProducto( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Cambiar Cantidad"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~ventanaActualizarProducto();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventanaHistorialVentas
///////////////////////////////////////////////////////////////////////////////
class ventanaHistorialVentas : public wxDialog
{
	private:

	protected:
		wxStaticLine* m_staticline42;
		wxStaticText* m_staticText42;
		wxTextCtrl* historialVentasBuscador;
		wxStaticLine* m_staticline4;
		wxButton* reload;
		wxStaticText* m_staticText51;
		wxButton* diaFiltro;
		wxButton* mesFiltro;
		wxButton* anioFiltro;
		wxStaticLine* m_staticline41;
		wxGrid* grillaRegistroVentas;
		wxButton* eliminarVenta;
		wxButton* vaciarRegistro;

		// Virtual event handlers, override them in your derived class
		virtual void historialVentasBuscadorOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void reloadOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void diaFiltroOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void mesFiltroOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void anioFiltroOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void grillaRegistroVentasOnGridCellLeftDClick( wxGridEvent& event ) { event.Skip(); }
		virtual void eliminarVentaOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void vaciarRegistroOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventanaHistorialVentas( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1026,765 ), long style = wxDEFAULT_DIALOG_STYLE );

		~ventanaHistorialVentas();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventanaFiltroFecha
///////////////////////////////////////////////////////////////////////////////
class ventanaFiltroFecha : public wxDialog
{
	private:

	protected:
		wxStaticText* diaText;
		wxStaticText* mesText;
		wxStaticText* m_staticText54;
		wxTextCtrl* diaLabel;
		wxTextCtrl* mesLabel;
		wxTextCtrl* anioLabel;
		wxButton* buscarFecha;
		wxButton* back;

		// Virtual event handlers, override them in your derived class
		virtual void buscarFechaOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void backOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventanaFiltroFecha( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize, long style = wxDEFAULT_DIALOG_STYLE );

		~ventanaFiltroFecha();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventana_Clientes
///////////////////////////////////////////////////////////////////////////////
class ventana_Clientes : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText29;
		wxTextCtrl* barraBusquedaCliente;
		wxGrid* grillaClientes;
		wxButton* agregarCliente;
		wxButton* eliminarCliente;

		// Virtual event handlers, override them in your derived class
		virtual void barraBusquedaClienteOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void editarClienteButton( wxGridEvent& event ) { event.Skip(); }
		virtual void agregarClienteOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void eliminarClienteOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventana_Clientes( wxWindow* parent, wxWindowID id = ventanaClientesLabel, const wxString& title = wxT("Clientes"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 925,343 ), long style = wxDEFAULT_DIALOG_STYLE );

		~ventana_Clientes();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventanaAgregarCliente
///////////////////////////////////////////////////////////////////////////////
class ventanaAgregarCliente : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText31;
		wxTextCtrl* nombreCliente;
		wxStaticText* m_staticText34;
		wxTextCtrl* dniCliente;
		wxStaticText* m_staticText311;
		wxTextCtrl* direccionCliente;
		wxStaticText* m_staticText312;
		wxTextCtrl* localidadCliente;
		wxStaticText* m_staticText313;
		wxTextCtrl* emailCliente;
		wxStaticText* m_staticText314;
		wxChoice* diaChoice;
		wxChoice* mesChoice;
		wxTextCtrl* fechaNacCliente;
		wxButton* AgregarCliente;
		wxButton* volver;

		// Virtual event handlers, override them in your derived class
		virtual void fechaNacClienteOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void AgregarClienteOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void volverOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventanaAgregarCliente( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 394,384 ), long style = wxDEFAULT_DIALOG_STYLE );

		~ventanaAgregarCliente();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventana_Empleados
///////////////////////////////////////////////////////////////////////////////
class ventana_Empleados : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText30;
		wxTextCtrl* busquedaUsuario;
		wxGrid* grillaUsuarios;
		wxButton* agregarDesdeLista;
		wxButton* eliminarEmpleado;
		wxButton* volverListaEmpleados;

		// Virtual event handlers, override them in your derived class
		virtual void busquedaUsuarioOnText( wxCommandEvent& event ) { event.Skip(); }
		virtual void grillaUsuariosOnGridCellLeftDClick( wxGridEvent& event ) { event.Skip(); }
		virtual void agregarDesdeListaOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void eliminarEmpleadoOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void volverListaEmpleadosOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventana_Empleados( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 590,320 ), long style = wxDEFAULT_DIALOG_STYLE );

		~ventana_Empleados();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventanaAgregarUsuario
///////////////////////////////////////////////////////////////////////////////
class ventanaAgregarUsuario : public wxDialog
{
	private:

	protected:
		wxStaticText* personalthings;
		wxStaticText* m_staticText313;
		wxTextCtrl* nombreApeUser;
		wxStaticText* direccionUser;
		wxTextCtrl* dirUser;
		wxStaticText* m_staticText314;
		wxTextCtrl* locUser;
		wxStaticText* m_staticText315;
		wxTextCtrl* emailUser;
		wxStaticText* m_staticText34;
		wxTextCtrl* dniUser;
		wxStaticText* m_staticText316;
		wxChoice* diaChoice;
		wxChoice* mesChoice;
		wxTextCtrl* fechaNacUser;
		wxStaticLine* m_staticline3;
		wxStaticText* userthings;
		wxStaticText* m_staticText31;
		wxTextCtrl* usuarioLabel;
		wxStaticText* m_staticText311;
		wxTextCtrl* passLabel;
		wxStaticText* m_staticText312;
		wxComboBox* selectionTipoUsuario;
		wxButton* agregarUsuario;
		wxButton* cancelarAddUsuario;

		// Virtual event handlers, override them in your derived class
		virtual void agregarUsuarioOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void cancelarAddUsuarioOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventanaAgregarUsuario( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 303,479 ), long style = wxDEFAULT_DIALOG_STYLE );

		~ventanaAgregarUsuario();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventana_DatosPersonales
///////////////////////////////////////////////////////////////////////////////
class ventana_DatosPersonales : public wxDialog
{
	private:

	protected:
		wxStaticText* m_staticText33;
		wxTextCtrl* usuarioLabelDatos;
		wxStaticText* m_staticText331;
		wxTextCtrl* passLabelDatos;
		wxCheckBox* showPass;
		wxStaticText* m_staticText332;
		wxTextCtrl* fechaReg;
		wxButton* botonModificar;
		wxButton* Salir;
		wxButton* modificarPersonales;

		// Virtual event handlers, override them in your derived class
		virtual void showPassOnCheckBox( wxCommandEvent& event ) { event.Skip(); }
		virtual void botonModificarOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void SalirOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void modificarPersonalesOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventana_DatosPersonales( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 266,229 ), long style = wxDEFAULT_DIALOG_STYLE );

		~ventana_DatosPersonales();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ventanaProductosVendidos
///////////////////////////////////////////////////////////////////////////////
class ventanaProductosVendidos : public wxDialog
{
	private:

	protected:
		wxGrid* grillaVendidos;
		wxButton* cerrar;

		// Virtual event handlers, override them in your derived class
		virtual void cerrarOnButtonClick( wxCommandEvent& event ) { event.Skip(); }


	public:

		ventanaProductosVendidos( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Productos vendidos"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 353,271 ), long style = wxDEFAULT_DIALOG_STYLE );

		~ventanaProductosVendidos();

};

