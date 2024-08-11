# Project-POO SISTEMA DE VENTAS
Este es un proyecto que hice para la materia de POO de la UNL-FICH, es un sistema de ventas en general (no es para un negocio/tienda/local especifico, sirve para todos).

<h1>Base de usuarios y clientes</h1>

* Cuenta con una base de datos de usuarios (Admnistrador como el Jefe o empleados), cada uno tiene diferentes permisos en este sistema.
* Tambien con una base de clientes.
* Los empleados pueden agregar clientes.

<h1>Sistema de LOGIN para usuarios del sistema </h1>
Como lo dice, sistema de login para poder ingresar al sistema. Solamente pueden ingresar aquellas personas que tengan acceso al sistema.
Tiene un guardado de datos (user y pass) y entrar automaticamente si lo desea el que ingresa.

<h1>Base de productos </h1>

<h3>Base de productos, no hay mucho que decir es una "base de datos" de productos. </h3>
Cada producto tiene las distintas caraceteristicas: 
 <ul>
  <li>Cada producto tiene su cantidad en stock</li>
  <li>Codigo propio</li>
  <li>Precio del producto </li>
  <li>Si esta en descuento o no</li>
</ul>
<h1>VENTAS</h1>

* Esta es la clase encargada de realizar todo el sistema de la venta, teniendo en cuenta el usuario(empleado de la tienda), cliente (encargado de la venta), la lista de productos distintos...
* Cada venta tendra registrada una fecha, hora, el vendedor que realizo la operacion, los productos vendidos y el precio de los mismos. En caso de que el cliente este registrado en el sistema apareceran sus datos y sino aparecera como "cliente final?".
* En caso de no haber registrado una venta (si fue una venta y el empleado decidio no registrarla) se podra agregar manualmente (esto reduce el stock del producto y hace todos los chiches necesarios)
* En caso de haber hecho una venta erronea, se podra eliminar(se elimina la venta del registro, esto hace que el stock del producto vuelta al estado anterior) <--- tambien sirve como devolucion de un producto!
* Sistema de devolucion (se elimina la venta del registro, esto hace que el stock del producto vuelta al estado anterior) <--- lo mismo que eliminar producto :p


<h2>Nota 1: Esta es la version pre-final con algun que otro bug, la ultima version terminada la tengo que subir sin ningun error y se aprobo con 9 😎 aunque la nota es irrelevante xd ).</h2>
<>
<h2>Nota 2: los archivos que inician con la letra "w..." son pura y exclusivamente de wxWidgets, los que no tienen esa inicial son las clases encargadas de las ventas, usuarios, etc.</h2>
