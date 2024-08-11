# Project-POO SISTEMA DE VENTAS
(esta es la version pre-final con algun que otro bug, la ultima version terminada la tengo que subir y se aprobo con 9 😎)
Este es un proyecto que hice para la materia de POO de la UNL-FICH, es un sistema de ventas en general (para un negocio/tienda/local, sirve para todos).

<h1>Sistema de LOGIN para usuarios del sistema </h1>
 <ul>
  <li> Sistema de login para poder ingresar al sistema. Solamente pueden ingresar aquellas personas que tengan acceso al sistema.</li>
  <li> Tiene un guardado de datos (user y pass)</li>
  
</ul>

<h1>Base de usuarios y clientes</h1>

* Cuenta con una base de datos de usuarios (Admnistrador como el Jefe o empleados), cada uno tiene diferentes permisos en este sistema.
* Tambien con una
 <ul>
    <li>Base de datos de usuarios (Admnistrador como el Jefe o empleados), cada uno tiene diferentes permisos en este sistema. </li>
    <li>Base de clientes por dni y codigo dni (aparte de los datos de direccion, nombre completo... entre otros datos personales)</li>
    <li> Los empelados no pueden ver los datos importantes de otros empleados, si de los clientes </li>
    <li> Los empleados solamente pueden editar su contraseña pero no sus datos personales. SI puede editar los datos de los clientes. </li>
</ul>


<h1>Base de productos</h1>

<h3>Base de productos. </h3>
Cada producto tiene las distintas caraceteristicas: 
 <ul>
  <li>Cada producto tiene su cantidad en stock</li>
  <li>Codigo propio</li>
  <li>Precio del producto </li>
  <li>Si esta en descuento o no</li>
  <li>Cantidad unitaria, gramos, kilogramos...</li>
  <li> Cantidad en stock</li>
  <li> Descripcion del producto</li>
</ul>

<h1>VENTAS</h1>

* Esta es la clase encargada de realizar todo el sistema de la venta, teniendo en cuenta el usuario(empleado de la tienda/jefe), cliente (cliente final o si se encuentra registrado).
* Cada venta tendra registrada una fecha, hora, el vendedor que realizo la operacion, los productos vendidos. En caso de que el cliente este registrado en el sistema apareceran sus datos y sino aparecera como "cliente final".
* En caso de no haber registrado una venta (si fue una venta y el empleado decidio no registrarla) se podra agregar manualmente (esto reduce el stock del producto y hace todos los chiches necesarios)
* En caso de haber hecho una venta erronea, se podra eliminar y se repone el stock correspondiente.



<h1>Login</h1>
- Sistema de logeo para los admin/empleados
- Guardar ultimo ingreso (para asi no tener que ingresar todo el tiempo user y pass)
- Cerrar la sesion actual, etc, etc.


 <ul>
  <li> </li>
</ul>
