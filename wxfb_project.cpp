///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 3.10.1-0-g8feb16b3)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

ventanaLogin::ventanaLogin( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer4->Add( m_staticText2, 0, wxALL, 5 );

	textoUsuario = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer4->Add( textoUsuario, 1, wxALL, 5 );


	bSizer2->Add( bSizer4, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Contraseña"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer5->Add( m_staticText3, 0, wxALL, 5 );

	textoPass = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	bSizer5->Add( textoPass, 0, wxALL, 5 );

	showPassLogin = new wxCheckBox( this, wxID_ANY, wxT("Mostrar Contraseña"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer5->Add( showPassLogin, 0, wxALL, 5 );


	bSizer2->Add( bSizer5, 0, 0, 5 );

	wxBoxSizer* bSizer74;
	bSizer74 = new wxBoxSizer( wxVERTICAL );

	guardarDatos = new wxCheckBox( this, wxID_ANY, wxT("Guardar Datos"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer74->Add( guardarDatos, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer2->Add( bSizer74, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer70;
	bSizer70 = new wxBoxSizer( wxHORIZONTAL );

	botonLogeo = new wxButton( this, wxID_ANY, wxT("Iniciar Sesion"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer70->Add(  botonLogeo, 0, wxALL, 5 );

	Salir = new wxButton( this, wxID_ANY, wxT("Salir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer70->Add( Salir, 0, wxALL, 5 );


	bSizer2->Add( bSizer70, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();
	bSizer2->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	showPassLogin->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ventanaLogin::showPassLoginOnCheckBox ), NULL, this );
	guardarDatos->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ventanaLogin::guardarDatosOnCheckBox ), NULL, this );
	botonLogeo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaLogin::clickBotonIniciar ), NULL, this );
	Salir->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaLogin::SalirOnButtonClick ), NULL, this );
}

ventanaLogin::~ventanaLogin()
{
	// Disconnect Events
	showPassLogin->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ventanaLogin::showPassLoginOnCheckBox ), NULL, this );
	guardarDatos->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ventanaLogin::guardarDatosOnCheckBox ), NULL, this );
	botonLogeo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaLogin::clickBotonIniciar ), NULL, this );
	Salir->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaLogin::SalirOnButtonClick ), NULL, this );

}

ventanaSistema::ventanaSistema( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	menuBar = new wxMenuBar( 0 );
	menuInicio = new wxMenu();
	wxMenuItem* menuInformacion;
	menuInformacion = new wxMenuItem( menuInicio, wxID_ANY, wxString( wxT("Informacion") ) , wxEmptyString, wxITEM_NORMAL );
	menuInicio->Append( menuInformacion );

	wxMenuItem* m_menuItem8;
	m_menuItem8 = new wxMenuItem( menuInicio, wxID_ANY, wxString( wxT("Salir") ) , wxEmptyString, wxITEM_NORMAL );
	menuInicio->Append( m_menuItem8 );

	menuBar->Append( menuInicio, wxT("Inicio") );

	menuArticulos = new wxMenu();
	wxMenuItem* m_menuItem1;
	m_menuItem1 = new wxMenuItem( menuArticulos, wxID_ANY, wxString( wxT("Lista de articulos") ) , wxEmptyString, wxITEM_NORMAL );
	menuArticulos->Append( m_menuItem1 );

	wxMenuItem* m_menuItem2;
	m_menuItem2 = new wxMenuItem( menuArticulos, wxID_ANY, wxString( wxT("Agregar articulo") ) , wxEmptyString, wxITEM_NORMAL );
	menuArticulos->Append( m_menuItem2 );

	menuBar->Append( menuArticulos, wxT("Articulos") );

	menuClientes = new wxMenu();
	wxMenuItem* m_menuItem4;
	m_menuItem4 = new wxMenuItem( menuClientes, wxID_ANY, wxString( wxT("Lista de Clientes") ) , wxEmptyString, wxITEM_NORMAL );
	menuClientes->Append( m_menuItem4 );

	wxMenuItem* m_menuItem5;
	m_menuItem5 = new wxMenuItem( menuClientes, wxID_ANY, wxString( wxT("Agregar nuevo cliente") ) , wxEmptyString, wxITEM_NORMAL );
	menuClientes->Append( m_menuItem5 );

	menuBar->Append( menuClientes, wxT("Clientes") );

	menuEmpleados = new wxMenu();
	wxMenuItem* menuListaEmpleados;
	menuListaEmpleados = new wxMenuItem( menuEmpleados, idEmpleadoMenu, wxString( wxT("Lista de Empleados") ) , wxEmptyString, wxITEM_NORMAL );
	menuEmpleados->Append( menuListaEmpleados );

	wxMenuItem* agregarEmpleadoMenu;
	agregarEmpleadoMenu = new wxMenuItem( menuEmpleados, idAgregarNuevoEmpleado, wxString( wxT("Agregar nuevo empleado") ) , wxEmptyString, wxITEM_NORMAL );
	menuEmpleados->Append( agregarEmpleadoMenu );

	menuBar->Append( menuEmpleados, wxT("Empleados") );

	menuPersonal = new wxMenu();
	wxMenuItem* menuVerDatos;
	menuVerDatos = new wxMenuItem( menuPersonal, wxID_ANY, wxString( wxT("Ver sus datos") ) , wxEmptyString, wxITEM_NORMAL );
	menuPersonal->Append( menuVerDatos );

	wxMenuItem* m_menuItem9;
	m_menuItem9 = new wxMenuItem( menuPersonal, wxID_ANY, wxString( wxT("Cerrar Sesion") ) , wxEmptyString, wxITEM_NORMAL );
	menuPersonal->Append( m_menuItem9 );

	menuBar->Append( menuPersonal, wxT("Usted") );

	this->SetMenuBar( menuBar );

	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxHORIZONTAL );

	m_button6 = new wxButton( this, wxID_ANY, wxT("Realizar venta"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer45->Add( m_button6, 0, wxALL, 5 );

	botonHistorial = new wxButton( this, wxID_ANY, wxT("Historial de ventas"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer45->Add( botonHistorial, 0, wxALL, 5 );


	bSizer9->Add( bSizer45, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxHORIZONTAL );

	fecLabel = new wxStaticText( this, fechaLabelID, wxT("Fecha Actual: "), wxDefaultPosition, wxDefaultSize, 0 );
	fecLabel->Wrap( -1 );
	bSizer46->Add( fecLabel, 0, wxALL, 5 );

	fechaLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fechaLabel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVEBORDER ) );
	fechaLabel->Enable( false );

	bSizer46->Add( fechaLabel, 0, wxALL, 5 );


	bSizer9->Add( bSizer46, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer9 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	menuInicio->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ventanaSistema::menuInformacionOnMenuSelection ), this, menuInformacion->GetId());
	menuInicio->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ventanaSistema::salirMenu ), this, m_menuItem8->GetId());
	menuArticulos->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ventanaSistema::abrirListaArticulos ), this, m_menuItem1->GetId());
	menuArticulos->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ventanaSistema::abrirAgregarProducto ), this, m_menuItem2->GetId());
	menuClientes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ventanaSistema::abrirListaClientes ), this, m_menuItem4->GetId());
	menuClientes->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ventanaSistema::agregarClienteMenu ), this, m_menuItem5->GetId());
	menuEmpleados->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ventanaSistema::abrirListaEmpleados ), this, menuListaEmpleados->GetId());
	menuEmpleados->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ventanaSistema::agregarEmpleadoMenuOnMenuSelection ), this, agregarEmpleadoMenu->GetId());
	menuPersonal->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ventanaSistema::menuVerDatosOnMenuSelection ), this, menuVerDatos->GetId());
	menuPersonal->Bind(wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( ventanaSistema::cerrarSesionMenu ), this, m_menuItem9->GetId());
	m_button6->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaSistema::realizarNuevaVenta ), NULL, this );
	botonHistorial->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaSistema::botonHistorialOnButtonClick ), NULL, this );
}

ventanaSistema::~ventanaSistema()
{
	// Disconnect Events
	m_button6->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaSistema::realizarNuevaVenta ), NULL, this );
	botonHistorial->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaSistema::botonHistorialOnButtonClick ), NULL, this );

}

ventanaAgregarProducto::ventanaAgregarProducto( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Nombre del producto: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer33->Add( m_staticText22, 0, wxALL, 5 );

	nombreProducto_label = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer33->Add( nombreProducto_label, 1, wxALL, 5 );


	bSizer32->Add( bSizer33, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer331;
	bSizer331 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText221 = new wxStaticText( this, wxID_ANY, wxT("Descripcion del producto: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText221->Wrap( -1 );
	bSizer331->Add( m_staticText221, 0, wxALL, 5 );

	descripcion_label = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE );
	bSizer331->Add( descripcion_label, 1, wxALL, 5 );


	bSizer32->Add( bSizer331, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer3311;
	bSizer3311 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText2211 = new wxStaticText( this, wxID_ANY, wxT("Precio"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2211->Wrap( -1 );
	bSizer3311->Add( m_staticText2211, 0, wxALL, 5 );

	precio_label = new wxTextCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer3311->Add( precio_label, 0, wxALL, 5 );


	bSizer32->Add( bSizer3311, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer331111;
	bSizer331111 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText221111 = new wxStaticText( this, wxID_ANY, wxT("Tipo: *"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText221111->Wrap( -1 );
	bSizer331111->Add( m_staticText221111, 0, wxALL, 5 );

	wxString tipo_labelChoices[] = { wxT("gramos"), wxT("kilogramos"), wxT("cantidad unitaria") };
	int tipo_labelNChoices = sizeof( tipo_labelChoices ) / sizeof( wxString );
	tipo_label = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, tipo_labelNChoices, tipo_labelChoices, 0 );
	tipo_label->SetSelection( 0 );
	bSizer331111->Add( tipo_label, 0, wxALL, 5 );


	bSizer32->Add( bSizer331111, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer33111;
	bSizer33111 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText22111 = new wxStaticText( this, wxID_ANY, wxT("Cantidad en stock"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22111->Wrap( -1 );
	bSizer33111->Add( m_staticText22111, 0, wxALL, 5 );

	cantidad_label = new wxTextCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer33111->Add( cantidad_label, 0, wxALL, 5 );


	bSizer32->Add( bSizer33111, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer333;
	bSizer333 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText222 = new wxStaticText( this, wxID_ANY, wxT("% descuento"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText222->Wrap( -1 );
	bSizer333->Add( m_staticText222, 0, wxALL, 5 );

	descuento_label = new wxTextCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer333->Add( descuento_label, 0, wxALL, 5 );

	m_staticText2221 = new wxStaticText( this, wxID_ANY, wxT("Por defecto esta en SIN descuento ( = 0)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2221->Wrap( -1 );
	bSizer333->Add( m_staticText2221, 0, wxALL, 5 );


	bSizer32->Add( bSizer333, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer332;
	bSizer332 = new wxBoxSizer( wxHORIZONTAL );

	m_button19 = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer332->Add( m_button19, 0, wxALL, 5 );

	m_button20 = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer332->Add( m_button20, 0, wxALL, 5 );


	bSizer32->Add( bSizer332, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer32 );
	this->Layout();
	bSizer32->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_button19->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaAgregarProducto::agregarProductoBoton ), NULL, this );
	m_button20->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaAgregarProducto::cancelarBoton ), NULL, this );
}

ventanaAgregarProducto::~ventanaAgregarProducto()
{
	// Disconnect Events
	m_button19->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaAgregarProducto::agregarProductoBoton ), NULL, this );
	m_button20->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaAgregarProducto::cancelarBoton ), NULL, this );

}

ventanaRealizarVenta::ventanaRealizarVenta( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );

	m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("Carrito de productos:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText6->Wrap( -1 );
	bSizer71->Add( m_staticText6, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer10->Add( bSizer71, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer871;
	bSizer871 = new wxBoxSizer( wxVERTICAL );

	m_staticline11 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer871->Add( m_staticline11, 0, wxALL|wxEXPAND, 5 );


	bSizer10->Add( bSizer871, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer72;
	bSizer72 = new wxBoxSizer( wxVERTICAL );

	m_staticText28 = new wxStaticText( this, wxID_ANY, wxT("nombre / codigo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	bSizer72->Add( m_staticText28, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	barraBuscadorVenta = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer72->Add( barraBuscadorVenta, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer36->Add( bSizer72, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer73;
	bSizer73 = new wxBoxSizer( wxVERTICAL );

	grillaProductosVenta = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	grillaProductosVenta->CreateGrid( 0, 2 );
	grillaProductosVenta->EnableEditing( false );
	grillaProductosVenta->EnableGridLines( true );
	grillaProductosVenta->EnableDragGridSize( false );
	grillaProductosVenta->SetMargins( 0, 0 );

	// Columns
	grillaProductosVenta->SetColSize( 0, 80 );
	grillaProductosVenta->SetColSize( 1, 80 );
	grillaProductosVenta->EnableDragColMove( false );
	grillaProductosVenta->EnableDragColSize( true );
	grillaProductosVenta->SetColLabelValue( 0, wxT("Producto") );
	grillaProductosVenta->SetColLabelValue( 1, wxT("Codigo") );
	grillaProductosVenta->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	grillaProductosVenta->EnableDragRowSize( true );
	grillaProductosVenta->SetRowLabelSize( 0 );
	grillaProductosVenta->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	grillaProductosVenta->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer73->Add( grillaProductosVenta, 1, wxALL, 5 );

	botonAgregarProductos = new wxButton( this, wxID_ANY, wxT("Agregar producto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer73->Add( botonAgregarProductos, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer36->Add( bSizer73, 1, wxEXPAND, 5 );


	bSizer19->Add( bSizer36, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer74;
	bSizer74 = new wxBoxSizer( wxVERTICAL );

	grillaCarrito = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	grillaCarrito->CreateGrid( 0, 5 );
	grillaCarrito->EnableEditing( false );
	grillaCarrito->EnableGridLines( true );
	grillaCarrito->EnableDragGridSize( false );
	grillaCarrito->SetMargins( 0, 0 );

	// Columns
	grillaCarrito->EnableDragColMove( false );
	grillaCarrito->EnableDragColSize( true );
	grillaCarrito->SetColLabelValue( 0, wxT("Nombre") );
	grillaCarrito->SetColLabelValue( 1, wxT("Cantidad") );
	grillaCarrito->SetColLabelValue( 2, wxT("Precio") );
	grillaCarrito->SetColLabelValue( 3, wxT("Descuento") );
	grillaCarrito->SetColLabelValue( 4, wxT("SubTotal") );
	grillaCarrito->SetColLabelAlignment( wxALIGN_LEFT, wxALIGN_TOP );

	// Rows
	grillaCarrito->EnableDragRowSize( true );
	grillaCarrito->SetRowLabelSize( 0 );
	grillaCarrito->SetRowLabelAlignment( wxALIGN_LEFT, wxALIGN_TOP );

	// Label Appearance

	// Cell Defaults
	grillaCarrito->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer74->Add( grillaCarrito, 1, wxALL, 5 );


	bSizer11->Add( bSizer74, 1, wxEXPAND, 5 );


	bSizer19->Add( bSizer11, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );

	m_bpButton1 = new wxBitmapButton( this, wxID_ANY, wxNullBitmap, wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW|0 );
	bSizer16->Add( m_bpButton1, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer86;
	bSizer86 = new wxBoxSizer( wxVERTICAL );

	botonEliminarCarrito = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer86->Add( botonEliminarCarrito, 0, wxALL|wxEXPAND, 5 );

	clearCarrito = new wxButton( this, wxID_ANY, wxT("Vaciar carrito de productos"), wxDefaultPosition, wxDefaultSize, 0 );
	clearCarrito->SetBackgroundColour( wxColour( 255, 128, 128 ) );

	bSizer86->Add( clearCarrito, 0, wxALL|wxEXPAND, 5 );


	bSizer16->Add( bSizer86, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer85;
	bSizer85 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText38 = new wxStaticText( this, wxID_ANY, wxT("Total:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText38->Wrap( -1 );
	bSizer85->Add( m_staticText38, 0, wxALL, 5 );

	total = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	total->Enable( false );

	bSizer85->Add( total, 0, wxALL, 5 );


	bSizer16->Add( bSizer85, 0, wxEXPAND, 5 );


	bSizer19->Add( bSizer16, 1, wxEXPAND, 5 );


	bSizer10->Add( bSizer19, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer87;
	bSizer87 = new wxBoxSizer( wxVERTICAL );

	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer87->Add( m_staticline1, 0, wxALL|wxEXPAND, 5 );


	bSizer10->Add( bSizer87, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer361;
	bSizer361 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxHORIZONTAL );

	cliente = new wxStaticText( this, wxID_ANY, wxT("Cliente DNI"), wxDefaultPosition, wxDefaultSize, 0 );
	cliente->Wrap( -1 );
	bSizer84->Add( cliente, 1, wxALL, 5 );

	clienteDNItexto = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer84->Add( clienteDNItexto, 0, wxALL, 5 );

	agregarCliente = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer84->Add( agregarCliente, 0, wxALL, 5 );


	bSizer361->Add( bSizer84, 1, 0, 5 );


	bSizer40->Add( bSizer361, 0, 0, 5 );

	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("Datos del cliente: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer39->Add( m_staticText23, 0, wxALL, 5 );

	nombreClienteLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	nombreClienteLabel->Enable( false );

	bSizer39->Add( nombreClienteLabel, 1, wxALL, 5 );


	bSizer40->Add( bSizer39, 0, wxEXPAND, 5 );


	bSizer41->Add( bSizer40, 1, 0, 5 );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );

	botonConfirmar = new wxButton( this, wxID_ANY, wxT("Confirmar venta"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer37->Add( botonConfirmar, 0, wxALL|wxEXPAND, 5 );

	botonCancelarVenta = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer37->Add( botonCancelarVenta, 0, wxALL|wxEXPAND, 5 );


	bSizer22->Add( bSizer37, 0, wxEXPAND, 5 );


	bSizer41->Add( bSizer22, 0, wxEXPAND, 5 );


	bSizer10->Add( bSizer41, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer10 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	barraBuscadorVenta->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ventanaRealizarVenta::barraBuscadorVentaOnText ), NULL, this );
	grillaProductosVenta->Connect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( ventanaRealizarVenta::agregarCarritoEnter ), NULL, this );
	grillaProductosVenta->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( ventanaRealizarVenta::celdaLeftDClick ), NULL, this );
	botonAgregarProductos->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaRealizarVenta::agregarAlCarrito ), NULL, this );
	grillaCarrito->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( ventanaRealizarVenta::editarCantidad ), NULL, this );
	botonEliminarCarrito->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaRealizarVenta::botonEliminarOnClick ), NULL, this );
	clearCarrito->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaRealizarVenta::vaciarCarritoOnClick ), NULL, this );
	agregarCliente->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaRealizarVenta::agregarClienteOnButtonClick ), NULL, this );
	botonConfirmar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaRealizarVenta::botonConfirmarOnButtonClick ), NULL, this );
	botonCancelarVenta->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaRealizarVenta::botonCancelarVentaOnButtonClick ), NULL, this );
}

ventanaRealizarVenta::~ventanaRealizarVenta()
{
	// Disconnect Events
	barraBuscadorVenta->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ventanaRealizarVenta::barraBuscadorVentaOnText ), NULL, this );
	grillaProductosVenta->Disconnect( wxEVT_ENTER_WINDOW, wxMouseEventHandler( ventanaRealizarVenta::agregarCarritoEnter ), NULL, this );
	grillaProductosVenta->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( ventanaRealizarVenta::celdaLeftDClick ), NULL, this );
	botonAgregarProductos->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaRealizarVenta::agregarAlCarrito ), NULL, this );
	grillaCarrito->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( ventanaRealizarVenta::editarCantidad ), NULL, this );
	botonEliminarCarrito->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaRealizarVenta::botonEliminarOnClick ), NULL, this );
	clearCarrito->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaRealizarVenta::vaciarCarritoOnClick ), NULL, this );
	agregarCliente->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaRealizarVenta::agregarClienteOnButtonClick ), NULL, this );
	botonConfirmar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaRealizarVenta::botonConfirmarOnButtonClick ), NULL, this );
	botonCancelarVenta->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaRealizarVenta::botonCancelarVentaOnButtonClick ), NULL, this );

}

ventana_Informacion::ventana_Informacion( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxVERTICAL );

	myLabel1 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	myLabel1->Wrap( -1 );
	bSizer62->Add( myLabel1, 0, wxALL|wxEXPAND, 5 );

	myLabel2 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	myLabel2->Wrap( -1 );
	bSizer62->Add( myLabel2, 0, wxALL|wxEXPAND, 5 );

	myLabel3 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	myLabel3->Wrap( -1 );
	bSizer62->Add( myLabel3, 0, wxALL|wxEXPAND, 5 );


	bSizer59->Add( bSizer62, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer70;
	bSizer70 = new wxBoxSizer( wxVERTICAL );

	myLabel4 = new wxStaticText( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	myLabel4->Wrap( -1 );
	bSizer70->Add( myLabel4, 0, wxALL|wxALIGN_RIGHT, 5 );


	bSizer59->Add( bSizer70, 0, wxALIGN_RIGHT, 5 );


	this->SetSizer( bSizer59 );
	this->Layout();

	this->Centre( wxBOTH );
}

ventana_Informacion::~ventana_Informacion()
{
}

ventanaListaArticulos::ventanaListaArticulos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText27 = new wxStaticText( this, wxID_ANY, wxT("Ingrese nombre/codigo:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	bSizer51->Add( m_staticText27, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );

	barraBuscarArticulo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer51->Add( barraBuscarArticulo, 1, wxALL|wxEXPAND, 5 );

	m_toggleBtn1 = new wxToggleButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	m_toggleBtn1->SetValue( true );
	bSizer51->Add( m_toggleBtn1, 0, wxALL, 5 );


	bSizer33->Add( bSizer51, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );

	listaArticulosGrid = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	listaArticulosGrid->CreateGrid( 0, 6 );
	listaArticulosGrid->EnableEditing( false );
	listaArticulosGrid->EnableGridLines( true );
	listaArticulosGrid->EnableDragGridSize( false );
	listaArticulosGrid->SetMargins( 0, 0 );

	// Columns
	listaArticulosGrid->SetColSize( 0, 150 );
	listaArticulosGrid->EnableDragColMove( false );
	listaArticulosGrid->EnableDragColSize( true );
	listaArticulosGrid->SetColLabelValue( 0, wxT("Nombre producto") );
	listaArticulosGrid->SetColLabelValue( 1, wxT("Codigo") );
	listaArticulosGrid->SetColLabelValue( 2, wxT("Precio") );
	listaArticulosGrid->SetColLabelValue( 3, wxT("Stock") );
	listaArticulosGrid->SetColLabelValue( 4, wxT("Descuento") );
	listaArticulosGrid->SetColLabelValue( 5, wxT("Descripcion") );
	listaArticulosGrid->SetColLabelSize( 30 );
	listaArticulosGrid->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	listaArticulosGrid->AutoSizeRows();
	listaArticulosGrid->EnableDragRowSize( false );
	listaArticulosGrid->SetRowLabelSize( 0 );
	listaArticulosGrid->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	listaArticulosGrid->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer34->Add( listaArticulosGrid, 1, wxALL|wxEXPAND, 5 );


	bSizer33->Add( bSizer34, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );

	boton_agregarProd = new wxButton( this, wxID_ANY, wxT("Agregar Producto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( boton_agregarProd, 1, wxALL, 5 );

	m_button19 = new wxButton( this, wxID_ANY, wxT("Eliminar Producto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( m_button19, 1, wxALL, 5 );


	bSizer33->Add( bSizer35, 0, wxEXPAND, 5 );


	this->SetSizer( bSizer33 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	barraBuscarArticulo->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ventanaListaArticulos::barraBuscarArticuloOnText ), NULL, this );
	listaArticulosGrid->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( ventanaListaArticulos::GridDCLICK_cambiarCant ), NULL, this );
	boton_agregarProd->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaListaArticulos::agregarProdDesdeLista ), NULL, this );
	m_button19->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaListaArticulos::botonEliminarProducto ), NULL, this );
}

ventanaListaArticulos::~ventanaListaArticulos()
{
	// Disconnect Events
	barraBuscarArticulo->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ventanaListaArticulos::barraBuscarArticuloOnText ), NULL, this );
	listaArticulosGrid->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( ventanaListaArticulos::GridDCLICK_cambiarCant ), NULL, this );
	boton_agregarProd->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaListaArticulos::agregarProdDesdeLista ), NULL, this );
	m_button19->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaListaArticulos::botonEliminarProducto ), NULL, this );

}

ventanaActualizarProducto::ventanaActualizarProducto( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Producto elegido: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer32->Add( m_staticText18, 0, wxALL, 5 );

	productoNombre = new wxStaticText( this, productName, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	productoNombre->Wrap( -1 );
	bSizer32->Add( productoNombre, 0, wxALL, 5 );


	bSizer31->Add( bSizer32, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText30 = new wxStaticText( this, wxID_ANY, wxT("Precio:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	bSizer47->Add( m_staticText30, 0, wxALL, 5 );

	precioLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer47->Add( precioLabel, 0, wxALL, 5 );


	bSizer31->Add( bSizer47, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("Descripcion:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	bSizer41->Add( m_staticText25, 0, wxALL, 5 );

	descripcionLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer41->Add( descripcionLabel, 1, wxALL|wxEXPAND, 5 );


	bSizer31->Add( bSizer41, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("Stock disponible: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer33->Add( m_staticText19, 0, wxALL, 5 );

	cantStock = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer33->Add( cantStock, 0, wxALL, 5 );


	bSizer31->Add( bSizer33, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Cantidad:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer35->Add( m_staticText22, 0, wxALL, 5 );

	cantidadElegida = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( cantidadElegida, 0, wxALL, 5 );


	bSizer31->Add( bSizer35, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Descuento"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	bSizer40->Add( m_staticText24, 0, wxALL, 5 );

	descuentoLabel = new wxTextCtrl( this, descuentoLabelID, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( descuentoLabel, 0, wxALL, 5 );


	bSizer31->Add( bSizer40, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );

	m_button15 = new wxButton( this, wxID_ANY, wxT("Confirmar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( m_button15, 1, wxALL, 5 );

	m_button16 = new wxButton( this, wxID_ANY, wxT("Volver"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( m_button16, 1, wxALL, 5 );


	bSizer31->Add( bSizer34, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer31 );
	this->Layout();
	bSizer31->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	m_button15->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaActualizarProducto::confirmarCarrito ), NULL, this );
	m_button16->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaActualizarProducto::volverElegirProd ), NULL, this );
}

ventanaActualizarProducto::~ventanaActualizarProducto()
{
	// Disconnect Events
	m_button15->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaActualizarProducto::confirmarCarrito ), NULL, this );
	m_button16->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaActualizarProducto::volverElegirProd ), NULL, this );

}

ventanaHistorialVentas::ventanaHistorialVentas( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxVERTICAL );

	m_staticline42 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer42->Add( m_staticline42, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText42 = new wxStaticText( this, wxID_ANY, wxT("Buscar por nro transaccion\n"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	bSizer82->Add( m_staticText42, 0, wxALL, 5 );

	historialVentasBuscador = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer82->Add( historialVentasBuscador, 1, wxALL, 5 );


	bSizer42->Add( bSizer82, 0, wxEXPAND, 5 );

	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer42->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer93;
	bSizer93 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer102;
	bSizer102 = new wxBoxSizer( wxVERTICAL );

	reload = new wxButton( this, wxID_ANY, wxT("Recargar Historial"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer102->Add( reload, 0, wxALL, 5 );


	bSizer93->Add( bSizer102, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer103;
	bSizer103 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText51 = new wxStaticText( this, wxID_ANY, wxT("Filtrar por:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	bSizer103->Add( m_staticText51, 0, wxALL, 5 );

	diaFiltro = new wxButton( this, wxID_ANY, wxT("Dia"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer103->Add( diaFiltro, 0, wxALL, 5 );

	mesFiltro = new wxButton( this, wxID_ANY, wxT("Mes"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer103->Add( mesFiltro, 0, wxALL, 5 );

	anioFiltro = new wxButton( this, wxID_ANY, wxT("Año"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer103->Add( anioFiltro, 0, wxALL, 5 );


	bSizer93->Add( bSizer103, 1, wxEXPAND, 5 );


	bSizer42->Add( bSizer93, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

	m_staticline41 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer42->Add( m_staticline41, 0, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxVERTICAL );

	grillaRegistroVentas = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	grillaRegistroVentas->CreateGrid( 0, 5 );
	grillaRegistroVentas->EnableEditing( false );
	grillaRegistroVentas->EnableGridLines( true );
	grillaRegistroVentas->EnableDragGridSize( false );
	grillaRegistroVentas->SetMargins( 0, 0 );

	// Columns
	grillaRegistroVentas->SetColSize( 0, 178 );
	grillaRegistroVentas->SetColSize( 1, 130 );
	grillaRegistroVentas->SetColSize( 2, 101 );
	grillaRegistroVentas->SetColSize( 3, 118 );
	grillaRegistroVentas->SetColSize( 4, 200 );
	grillaRegistroVentas->EnableDragColMove( false );
	grillaRegistroVentas->EnableDragColSize( false );
	grillaRegistroVentas->SetColLabelValue( 0, wxT("Fecha y hora") );
	grillaRegistroVentas->SetColLabelValue( 1, wxT("Nro Transaccion") );
	grillaRegistroVentas->SetColLabelValue( 2, wxT("Empleado") );
	grillaRegistroVentas->SetColLabelValue( 3, wxT("Total") );
	grillaRegistroVentas->SetColLabelValue( 4, wxT("Cliente") );
	grillaRegistroVentas->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	grillaRegistroVentas->EnableDragRowSize( false );
	grillaRegistroVentas->SetRowLabelSize( 0 );
	grillaRegistroVentas->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	grillaRegistroVentas->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer43->Add( grillaRegistroVentas, 0, wxALL|wxEXPAND, 5 );


	bSizer42->Add( bSizer43, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer83;
	bSizer83 = new wxBoxSizer( wxVERTICAL );

	eliminarVenta = new wxButton( this, wxID_ANY, wxT("Eliminar venta"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer83->Add( eliminarVenta, 0, wxALL, 5 );

	vaciarRegistro = new wxButton( this, wxID_ANY, wxT("Vaciar Carrito"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer83->Add( vaciarRegistro, 0, wxALL, 5 );


	bSizer42->Add( bSizer83, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer42 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	historialVentasBuscador->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ventanaHistorialVentas::historialVentasBuscadorOnText ), NULL, this );
	reload->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaHistorialVentas::reloadOnButtonClick ), NULL, this );
	diaFiltro->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaHistorialVentas::diaFiltroOnButtonClick ), NULL, this );
	mesFiltro->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaHistorialVentas::mesFiltroOnButtonClick ), NULL, this );
	anioFiltro->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaHistorialVentas::anioFiltroOnButtonClick ), NULL, this );
	grillaRegistroVentas->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( ventanaHistorialVentas::grillaRegistroVentasOnGridCellLeftDClick ), NULL, this );
	eliminarVenta->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaHistorialVentas::eliminarVentaOnButtonClick ), NULL, this );
	vaciarRegistro->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaHistorialVentas::vaciarRegistroOnButtonClick ), NULL, this );
}

ventanaHistorialVentas::~ventanaHistorialVentas()
{
	// Disconnect Events
	historialVentasBuscador->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ventanaHistorialVentas::historialVentasBuscadorOnText ), NULL, this );
	reload->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaHistorialVentas::reloadOnButtonClick ), NULL, this );
	diaFiltro->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaHistorialVentas::diaFiltroOnButtonClick ), NULL, this );
	mesFiltro->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaHistorialVentas::mesFiltroOnButtonClick ), NULL, this );
	anioFiltro->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaHistorialVentas::anioFiltroOnButtonClick ), NULL, this );
	grillaRegistroVentas->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( ventanaHistorialVentas::grillaRegistroVentasOnGridCellLeftDClick ), NULL, this );
	eliminarVenta->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaHistorialVentas::eliminarVentaOnButtonClick ), NULL, this );
	vaciarRegistro->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaHistorialVentas::vaciarRegistroOnButtonClick ), NULL, this );

}

ventanaFiltroFecha::ventanaFiltroFecha( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer95;
	bSizer95 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer97;
	bSizer97 = new wxBoxSizer( wxHORIZONTAL );

	diaText = new wxStaticText( this, wxID_ANY, wxT("Dia"), wxDefaultPosition, wxDefaultSize, 0 );
	diaText->Wrap( -1 );
	bSizer97->Add( diaText, 1, wxALL, 5 );

	mesText = new wxStaticText( this, wxID_ANY, wxT("Mes"), wxDefaultPosition, wxDefaultSize, 0 );
	mesText->Wrap( -1 );
	bSizer97->Add( mesText, 1, wxALL, 5 );

	m_staticText54 = new wxStaticText( this, wxID_ANY, wxT("Año"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText54->Wrap( -1 );
	bSizer97->Add( m_staticText54, 1, wxALL, 5 );


	bSizer95->Add( bSizer97, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer96;
	bSizer96 = new wxBoxSizer( wxHORIZONTAL );

	diaLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !diaLabel->HasFlag( wxTE_MULTILINE ) )
	{
	diaLabel->SetMaxLength( 2 );
	}
	#else
	diaLabel->SetMaxLength( 2 );
	#endif
	bSizer96->Add( diaLabel, 0, wxALL, 5 );

	mesLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !mesLabel->HasFlag( wxTE_MULTILINE ) )
	{
	mesLabel->SetMaxLength( 2 );
	}
	#else
	mesLabel->SetMaxLength( 2 );
	#endif
	bSizer96->Add( mesLabel, 0, wxALL, 5 );

	anioLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !anioLabel->HasFlag( wxTE_MULTILINE ) )
	{
	anioLabel->SetMaxLength( 4 );
	}
	#else
	anioLabel->SetMaxLength( 4 );
	#endif
	bSizer96->Add( anioLabel, 0, wxALL, 5 );


	bSizer95->Add( bSizer96, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer98;
	bSizer98 = new wxBoxSizer( wxHORIZONTAL );

	buscarFecha = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer98->Add( buscarFecha, 0, wxALL, 5 );

	back = new wxButton( this, wxID_ANY, wxT("Volver"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer98->Add( back, 0, wxALL, 5 );


	bSizer95->Add( bSizer98, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer95 );
	this->Layout();
	bSizer95->Fit( this );

	this->Centre( wxBOTH );

	// Connect Events
	buscarFecha->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaFiltroFecha::buscarFechaOnButtonClick ), NULL, this );
	back->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaFiltroFecha::backOnButtonClick ), NULL, this );
}

ventanaFiltroFecha::~ventanaFiltroFecha()
{
	// Disconnect Events
	buscarFecha->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaFiltroFecha::buscarFechaOnButtonClick ), NULL, this );
	back->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaFiltroFecha::backOnButtonClick ), NULL, this );

}

ventana_Clientes::ventana_Clientes( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText29 = new wxStaticText( this, wxID_ANY, wxT("buscar Cliente"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText29->Wrap( -1 );
	bSizer53->Add( m_staticText29, 0, wxALL, 5 );

	barraBusquedaCliente = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( barraBusquedaCliente, 1, wxALL, 5 );


	bSizer48->Add( bSizer53, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer49;
	bSizer49 = new wxBoxSizer( wxVERTICAL );

	grillaClientes = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	grillaClientes->CreateGrid( 0, 7 );
	grillaClientes->EnableEditing( false );
	grillaClientes->EnableGridLines( true );
	grillaClientes->EnableDragGridSize( false );
	grillaClientes->SetMargins( 0, 0 );

	// Columns
	grillaClientes->SetColSize( 0, 150 );
	grillaClientes->SetColSize( 1, 80 );
	grillaClientes->SetColSize( 2, 118 );
	grillaClientes->SetColSize( 3, 128 );
	grillaClientes->SetColSize( 4, 114 );
	grillaClientes->SetColSize( 5, 154 );
	grillaClientes->SetColSize( 6, 142 );
	grillaClientes->EnableDragColMove( false );
	grillaClientes->EnableDragColSize( true );
	grillaClientes->SetColLabelValue( 0, wxT("Nombre") );
	grillaClientes->SetColLabelValue( 1, wxT("DNI") );
	grillaClientes->SetColLabelValue( 2, wxT("Codigo Cliente") );
	grillaClientes->SetColLabelValue( 3, wxT("Direccion") );
	grillaClientes->SetColLabelValue( 4, wxT("Localidad") );
	grillaClientes->SetColLabelValue( 5, wxT("Email") );
	grillaClientes->SetColLabelValue( 6, wxT("Fecha de Nacimiento") );
	grillaClientes->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	grillaClientes->EnableDragRowSize( true );
	grillaClientes->SetRowLabelSize( 0 );
	grillaClientes->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	grillaClientes->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer49->Add( grillaClientes, 1, wxALL|wxEXPAND, 5 );


	bSizer48->Add( bSizer49, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer50;
	bSizer50 = new wxBoxSizer( wxHORIZONTAL );

	agregarCliente = new wxButton( this, wxID_ANY, wxT("AgregarCliente"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer50->Add( agregarCliente, 0, wxALL, 5 );

	eliminarCliente = new wxButton( this, wxID_ANY, wxT("Eliminar Cliente"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer50->Add( eliminarCliente, 0, wxALL, 5 );


	bSizer48->Add( bSizer50, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer48 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	barraBusquedaCliente->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ventana_Clientes::barraBusquedaClienteOnText ), NULL, this );
	grillaClientes->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( ventana_Clientes::editarClienteButton ), NULL, this );
	agregarCliente->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_Clientes::agregarClienteOnButtonClick ), NULL, this );
	eliminarCliente->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_Clientes::eliminarClienteOnButtonClick ), NULL, this );
}

ventana_Clientes::~ventana_Clientes()
{
	// Disconnect Events
	barraBusquedaCliente->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ventana_Clientes::barraBusquedaClienteOnText ), NULL, this );
	grillaClientes->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( ventana_Clientes::editarClienteButton ), NULL, this );
	agregarCliente->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_Clientes::agregarClienteOnButtonClick ), NULL, this );
	eliminarCliente->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_Clientes::eliminarClienteOnButtonClick ), NULL, this );

}

ventanaAgregarCliente::ventanaAgregarCliente( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer52->Add( m_staticText31, 0, wxALL, 5 );

	nombreCliente = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer52->Add( nombreCliente, 1, wxALL, 5 );


	bSizer51->Add( bSizer52, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText34 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer53->Add( m_staticText34, 0, wxALL, 5 );

	dniCliente = new wxTextCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( dniCliente, 1, wxALL, 5 );


	bSizer51->Add( bSizer53, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer521;
	bSizer521 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText311 = new wxStaticText( this, wxID_ANY, wxT("Direccion"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText311->Wrap( -1 );
	bSizer521->Add( m_staticText311, 0, wxALL, 5 );

	direccionCliente = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer521->Add( direccionCliente, 1, wxALL, 5 );


	bSizer51->Add( bSizer521, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer522;
	bSizer522 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText312 = new wxStaticText( this, wxID_ANY, wxT("Localidad:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText312->Wrap( -1 );
	bSizer522->Add( m_staticText312, 0, wxALL, 5 );

	localidadCliente = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer522->Add( localidadCliente, 1, wxALL, 5 );


	bSizer51->Add( bSizer522, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer523;
	bSizer523 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText313 = new wxStaticText( this, wxID_ANY, wxT("email"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText313->Wrap( -1 );
	bSizer523->Add( m_staticText313, 0, wxALL, 5 );

	emailCliente = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer523->Add( emailCliente, 1, wxALL, 5 );


	bSizer51->Add( bSizer523, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer524;
	bSizer524 = new wxBoxSizer( wxVERTICAL );

	m_staticText314 = new wxStaticText( this, wxID_ANY, wxT("Fecha de nacimiento"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText314->Wrap( -1 );
	bSizer524->Add( m_staticText314, 0, wxALL, 5 );

	wxBoxSizer* bSizer103;
	bSizer103 = new wxBoxSizer( wxHORIZONTAL );

	wxString diaChoiceChoices[] = { wxT("1"), wxT("2"), wxT("3"), wxT("4"), wxT("5"), wxT("6"), wxT("7"), wxT("8"), wxT("9"), wxT("10"), wxT("11"), wxT("12"), wxT("13"), wxT("14"), wxT("15"), wxT("16"), wxT("17"), wxT("18"), wxT("19"), wxT("20"), wxT("21"), wxT("22"), wxT("23"), wxT("24"), wxT("25"), wxT("26"), wxT("27"), wxT("28"), wxT("29"), wxT("30"), wxT("31") };
	int diaChoiceNChoices = sizeof( diaChoiceChoices ) / sizeof( wxString );
	diaChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, diaChoiceNChoices, diaChoiceChoices, 0 );
	diaChoice->SetSelection( 0 );
	bSizer103->Add( diaChoice, 0, wxALL, 5 );

	wxString mesChoiceChoices[] = { wxT("Enero"), wxT("Febrero"), wxT("Marzo"), wxT("Abril"), wxT("Mayo"), wxT("Junio"), wxT("Julio"), wxT("Agosto"), wxT("Septiembre"), wxT("Octubre"), wxT("Noviembre"), wxT("Diciembre") };
	int mesChoiceNChoices = sizeof( mesChoiceChoices ) / sizeof( wxString );
	mesChoice = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, mesChoiceNChoices, mesChoiceChoices, 0 );
	mesChoice->SetSelection( 0 );
	bSizer103->Add( mesChoice, 0, wxALL, 5 );

	fechaNacCliente = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !fechaNacCliente->HasFlag( wxTE_MULTILINE ) )
	{
	fechaNacCliente->SetMaxLength( 4 );
	}
	#else
	fechaNacCliente->SetMaxLength( 4 );
	#endif
	bSizer103->Add( fechaNacCliente, 0, wxALL, 5 );


	bSizer524->Add( bSizer103, 1, wxEXPAND, 5 );


	bSizer51->Add( bSizer524, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxHORIZONTAL );

	AgregarCliente = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer57->Add( AgregarCliente, 1, wxALL|wxEXPAND, 5 );

	volver = new wxButton( this, wxID_ANY, wxT("Volver"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer57->Add( volver, 1, wxALL|wxEXPAND, 5 );


	bSizer51->Add( bSizer57, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer51 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	fechaNacCliente->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ventanaAgregarCliente::fechaNacClienteOnText ), NULL, this );
	AgregarCliente->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaAgregarCliente::AgregarClienteOnButtonClick ), NULL, this );
	volver->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaAgregarCliente::volverOnButtonClick ), NULL, this );
}

ventanaAgregarCliente::~ventanaAgregarCliente()
{
	// Disconnect Events
	fechaNacCliente->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ventanaAgregarCliente::fechaNacClienteOnText ), NULL, this );
	AgregarCliente->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaAgregarCliente::AgregarClienteOnButtonClick ), NULL, this );
	volver->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaAgregarCliente::volverOnButtonClick ), NULL, this );

}

ventana_Empleados::ventana_Empleados( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText30 = new wxStaticText( this, wxID_ANY, wxT("buscar Usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	bSizer55->Add( m_staticText30, 0, wxALL, 5 );

	busquedaUsuario = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer55->Add( busquedaUsuario, 1, wxALL, 5 );


	bSizer54->Add( bSizer55, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxVERTICAL );

	grillaUsuarios = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	grillaUsuarios->CreateGrid( 0, 4 );
	grillaUsuarios->EnableEditing( false );
	grillaUsuarios->EnableGridLines( true );
	grillaUsuarios->EnableDragGridSize( false );
	grillaUsuarios->SetMargins( 0, 0 );

	// Columns
	grillaUsuarios->SetColSize( 0, 95 );
	grillaUsuarios->SetColSize( 1, 129 );
	grillaUsuarios->SetColSize( 2, 80 );
	grillaUsuarios->SetColSize( 3, 167 );
	grillaUsuarios->EnableDragColMove( false );
	grillaUsuarios->EnableDragColSize( true );
	grillaUsuarios->SetColLabelValue( 0, wxT("Usuario") );
	grillaUsuarios->SetColLabelValue( 1, wxT("Contraseña") );
	grillaUsuarios->SetColLabelValue( 2, wxT("Tipo") );
	grillaUsuarios->SetColLabelValue( 3, wxT("Fecha de Ingreso") );
	grillaUsuarios->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	grillaUsuarios->EnableDragRowSize( true );
	grillaUsuarios->SetRowLabelSize( 0 );
	grillaUsuarios->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	grillaUsuarios->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer56->Add( grillaUsuarios, 1, wxALL|wxEXPAND, 5 );


	bSizer54->Add( bSizer56, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer70;
	bSizer70 = new wxBoxSizer( wxHORIZONTAL );

	agregarDesdeLista = new wxButton( this, wxID_ANY, wxT("Agregar Usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer70->Add( agregarDesdeLista, 0, wxALL, 5 );

	eliminarEmpleado = new wxButton( this, wxID_ANY, wxT("Eliminar Empleado"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer70->Add( eliminarEmpleado, 0, wxALL, 5 );

	volverListaEmpleados = new wxButton( this, wxID_ANY, wxT("Volver"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer70->Add( volverListaEmpleados, 0, wxALL, 5 );


	bSizer54->Add( bSizer70, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer54 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	busquedaUsuario->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ventana_Empleados::busquedaUsuarioOnText ), NULL, this );
	grillaUsuarios->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( ventana_Empleados::grillaUsuariosOnGridCellLeftDClick ), NULL, this );
	agregarDesdeLista->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_Empleados::agregarDesdeListaOnButtonClick ), NULL, this );
	eliminarEmpleado->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_Empleados::eliminarEmpleadoOnButtonClick ), NULL, this );
	volverListaEmpleados->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_Empleados::volverListaEmpleadosOnButtonClick ), NULL, this );
}

ventana_Empleados::~ventana_Empleados()
{
	// Disconnect Events
	busquedaUsuario->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( ventana_Empleados::busquedaUsuarioOnText ), NULL, this );
	grillaUsuarios->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( ventana_Empleados::grillaUsuariosOnGridCellLeftDClick ), NULL, this );
	agregarDesdeLista->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_Empleados::agregarDesdeListaOnButtonClick ), NULL, this );
	eliminarEmpleado->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_Empleados::eliminarEmpleadoOnButtonClick ), NULL, this );
	volverListaEmpleados->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_Empleados::volverListaEmpleadosOnButtonClick ), NULL, this );

}

ventanaAgregarUsuario::ventanaAgregarUsuario( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer103;
	bSizer103 = new wxBoxSizer( wxVERTICAL );

	personalthings = new wxStaticText( this, wxID_ANY, wxT("Datos personales"), wxDefaultPosition, wxDefaultSize, 0 );
	personalthings->Wrap( -1 );
	bSizer103->Add( personalthings, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer58->Add( bSizer103, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer598;
	bSizer598 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText313 = new wxStaticText( this, wxID_ANY, wxT("Nombre y apellido:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText313->Wrap( -1 );
	bSizer598->Add( m_staticText313, 0, wxALL, 5 );

	nombreApeUser = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer598->Add( nombreApeUser, 1, wxALL, 5 );


	bSizer58->Add( bSizer598, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer594;
	bSizer594 = new wxBoxSizer( wxHORIZONTAL );

	direccionUser = new wxStaticText( this, wxID_ANY, wxT("Direccion"), wxDefaultPosition, wxDefaultSize, 0 );
	direccionUser->Wrap( -1 );
	bSizer594->Add( direccionUser, 0, wxALL, 5 );

	dirUser = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer594->Add( dirUser, 1, wxALL, 5 );


	bSizer58->Add( bSizer594, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer595;
	bSizer595 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText314 = new wxStaticText( this, wxID_ANY, wxT("Localidad"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText314->Wrap( -1 );
	bSizer595->Add( m_staticText314, 0, wxALL, 5 );

	locUser = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer595->Add( locUser, 1, wxALL, 5 );


	bSizer58->Add( bSizer595, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer596;
	bSizer596 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText315 = new wxStaticText( this, wxID_ANY, wxT("email"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText315->Wrap( -1 );
	bSizer596->Add( m_staticText315, 0, wxALL, 5 );

	emailUser = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer596->Add( emailUser, 1, wxALL, 5 );


	bSizer58->Add( bSizer596, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText34 = new wxStaticText( this, wxID_ANY, wxT("DNI:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText34->Wrap( -1 );
	bSizer53->Add( m_staticText34, 0, wxALL, 5 );

	dniUser = new wxTextCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( dniUser, 1, wxALL, 5 );


	bSizer58->Add( bSizer53, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer597;
	bSizer597 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText316 = new wxStaticText( this, wxID_ANY, wxT("Fecha Nacimiento"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText316->Wrap( -1 );
	bSizer597->Add( m_staticText316, 0, wxALL, 5 );

	fechaNacUser = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifdef __WXGTK__
	if ( !fechaNacUser->HasFlag( wxTE_MULTILINE ) )
	{
	fechaNacUser->SetMaxLength( 10 );
	}
	#else
	fechaNacUser->SetMaxLength( 10 );
	#endif
	bSizer597->Add( fechaNacUser, 1, wxALL, 5 );


	bSizer58->Add( bSizer597, 1, wxEXPAND, 5 );

	m_staticline3 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer58->Add( m_staticline3, 1, wxEXPAND | wxALL, 5 );

	wxBoxSizer* bSizer1031;
	bSizer1031 = new wxBoxSizer( wxVERTICAL );

	userthings = new wxStaticText( this, wxID_ANY, wxT("Datos de Usuario:"), wxDefaultPosition, wxDefaultSize, 0 );
	userthings->Wrap( -1 );
	bSizer1031->Add( userthings, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer58->Add( bSizer1031, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("nombre de usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer59->Add( m_staticText31, 0, wxALL, 5 );

	usuarioLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer59->Add( usuarioLabel, 1, wxALL, 5 );


	bSizer58->Add( bSizer59, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer591;
	bSizer591 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText311 = new wxStaticText( this, wxID_ANY, wxT("contraseña"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText311->Wrap( -1 );
	bSizer591->Add( m_staticText311, 0, wxALL, 5 );

	passLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer591->Add( passLabel, 1, wxALL, 5 );


	bSizer58->Add( bSizer591, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer592;
	bSizer592 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText312 = new wxStaticText( this, wxID_ANY, wxT("Tipo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText312->Wrap( -1 );
	bSizer592->Add( m_staticText312, 0, wxALL, 5 );

	selectionTipoUsuario = new wxComboBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0, NULL, 0 );
	selectionTipoUsuario->Append( wxT("Empleado") );
	selectionTipoUsuario->Append( wxT("Administrador/Jefe") );
	selectionTipoUsuario->SetSelection( 0 );
	bSizer592->Add( selectionTipoUsuario, 0, wxALL, 5 );


	bSizer58->Add( bSizer592, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer593;
	bSizer593 = new wxBoxSizer( wxHORIZONTAL );

	agregarUsuario = new wxButton( this, wxID_ANY, wxT("Aceptar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer593->Add( agregarUsuario, 1, wxALL|wxEXPAND, 5 );

	cancelarAddUsuario = new wxButton( this, wxID_ANY, wxT("Cancelar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer593->Add( cancelarAddUsuario, 1, wxALL|wxEXPAND, 5 );


	bSizer58->Add( bSizer593, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer58 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	agregarUsuario->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaAgregarUsuario::agregarUsuarioOnButtonClick ), NULL, this );
	cancelarAddUsuario->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaAgregarUsuario::cancelarAddUsuarioOnButtonClick ), NULL, this );
}

ventanaAgregarUsuario::~ventanaAgregarUsuario()
{
	// Disconnect Events
	agregarUsuario->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaAgregarUsuario::agregarUsuarioOnButtonClick ), NULL, this );
	cancelarAddUsuario->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaAgregarUsuario::cancelarAddUsuarioOnButtonClick ), NULL, this );

}

ventana_DatosPersonales::ventana_DatosPersonales( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText33 = new wxStaticText( this, wxID_ANY, wxT("Usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText33->Wrap( -1 );
	bSizer63->Add( m_staticText33, 0, wxALL, 5 );

	usuarioLabelDatos = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	usuarioLabelDatos->Enable( false );

	bSizer63->Add( usuarioLabelDatos, 0, wxALL, 5 );


	bSizer62->Add( bSizer63, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer631;
	bSizer631 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer73;
	bSizer73 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText331 = new wxStaticText( this, wxID_ANY, wxT("Contraseña"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText331->Wrap( -1 );
	bSizer73->Add( m_staticText331, 0, wxALL, 5 );

	passLabelDatos = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_PASSWORD );
	passLabelDatos->Enable( false );

	bSizer73->Add( passLabelDatos, 0, wxALL, 5 );


	bSizer631->Add( bSizer73, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer74;
	bSizer74 = new wxBoxSizer( wxVERTICAL );

	showPass = new wxCheckBox( this, wxID_ANY, wxT("Mostrar Contraseña"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer74->Add( showPass, 0, wxALL, 5 );


	bSizer631->Add( bSizer74, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer62->Add( bSizer631, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer632;
	bSizer632 = new wxBoxSizer( wxHORIZONTAL );

	m_staticText332 = new wxStaticText( this, wxID_ANY, wxT("Fecha de Ingreso/Registro:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText332->Wrap( -1 );
	bSizer632->Add( m_staticText332, 0, wxALL, 5 );

	fechaReg = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	fechaReg->Enable( false );

	bSizer632->Add( fechaReg, 0, wxALL, 5 );


	bSizer62->Add( bSizer632, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer633;
	bSizer633 = new wxBoxSizer( wxHORIZONTAL );

	botonModificar = new wxButton( this, wxID_ANY, wxT("Modificar Usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer633->Add( botonModificar, 0, wxALL, 5 );

	Salir = new wxButton( this, wxID_ANY, wxT("Salir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer633->Add( Salir, 0, wxALL, 5 );


	bSizer62->Add( bSizer633, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer92;
	bSizer92 = new wxBoxSizer( wxVERTICAL );

	modificarPersonales = new wxButton( this, wxID_ANY, wxT("Modificar Datos Personales"), wxDefaultPosition, wxDefaultSize, 0 );
	modificarPersonales->Hide();

	bSizer92->Add( modificarPersonales, 0, wxALL, 5 );


	bSizer62->Add( bSizer92, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer62 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	showPass->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ventana_DatosPersonales::showPassOnCheckBox ), NULL, this );
	botonModificar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_DatosPersonales::botonModificarOnButtonClick ), NULL, this );
	Salir->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_DatosPersonales::SalirOnButtonClick ), NULL, this );
	modificarPersonales->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_DatosPersonales::modificarPersonalesOnButtonClick ), NULL, this );
}

ventana_DatosPersonales::~ventana_DatosPersonales()
{
	// Disconnect Events
	showPass->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( ventana_DatosPersonales::showPassOnCheckBox ), NULL, this );
	botonModificar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_DatosPersonales::botonModificarOnButtonClick ), NULL, this );
	Salir->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_DatosPersonales::SalirOnButtonClick ), NULL, this );
	modificarPersonales->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventana_DatosPersonales::modificarPersonalesOnButtonClick ), NULL, this );

}

ventanaProductosVendidos::ventanaProductosVendidos( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );

	wxBoxSizer* bSizer100;
	bSizer100 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxVERTICAL );

	grillaVendidos = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	grillaVendidos->CreateGrid( 0, 3 );
	grillaVendidos->EnableEditing( false );
	grillaVendidos->EnableGridLines( true );
	grillaVendidos->EnableDragGridSize( false );
	grillaVendidos->SetMargins( 0, 0 );

	// Columns
	grillaVendidos->SetColSize( 0, 91 );
	grillaVendidos->SetColSize( 1, 108 );
	grillaVendidos->SetColSize( 2, 93 );
	grillaVendidos->EnableDragColMove( false );
	grillaVendidos->EnableDragColSize( true );
	grillaVendidos->SetColLabelValue( 0, wxT("Producto") );
	grillaVendidos->SetColLabelValue( 1, wxT("Cantidad") );
	grillaVendidos->SetColLabelValue( 2, wxT("Codigo") );
	grillaVendidos->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	grillaVendidos->EnableDragRowSize( true );
	grillaVendidos->SetRowLabelSize( 0 );
	grillaVendidos->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	grillaVendidos->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer101->Add( grillaVendidos, 1, wxALL|wxEXPAND, 5 );


	bSizer100->Add( bSizer101, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer102;
	bSizer102 = new wxBoxSizer( wxVERTICAL );

	cerrar = new wxButton( this, wxID_ANY, wxT("Cerrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer102->Add( cerrar, 0, wxALL, 5 );


	bSizer100->Add( bSizer102, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer100 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	cerrar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaProductosVendidos::cerrarOnButtonClick ), NULL, this );
}

ventanaProductosVendidos::~ventanaProductosVendidos()
{
	// Disconnect Events
	cerrar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( ventanaProductosVendidos::cerrarOnButtonClick ), NULL, this );

}
