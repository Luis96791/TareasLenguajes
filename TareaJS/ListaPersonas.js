function Persona(nombre, edad) {
	this.nombre = nombre;
	this.edad = edad;
	this.siguiente = null;

	Persona.prototype.getNombre = function() {
		return this.nombre;
	};

	Persona.prototype.getEdad = function() {
		return this.edad;
	};

	Persona.prototype.setNombre = function(nombre) {
		this.nombre = nombre;
	};

	Persona.prototype.setEdad = function(edad) {
		this.edad = edad;
	};

	Persona.prototype.imprimir = function() {
		console.log(this.getNombre()+" "+this.getEdad());
	};
}

function ListaPersonas() {
	this.inicio_lista = null;
	this.fin_lista = null;

	ListaPersonas.prototype.isListaVacia = function() {
		if (this.inicio_lista == null) {
			console.log("La lista esta Vacia");
			return true;
		}
		return false;
	};
		
	ListaPersonas.prototype.agregar = function(nombre, edad) {
		var persona = new Persona(nombre, edad);
		var nodo_temporal = this.inicio_lista;

		if (this.inicio_lista == null) {
			this.inicio_lista = this.fin_lista = persona;
			return;
		}

		this.fin_lista.siguiente = persona;
		this.fin_lista = persona;
	};

	ListaPersonas.prototype.imprimir = function() {

		if (this.isListaVacia()) {
			return;
		}

		var nodo_temporal = this.inicio_lista;

		while(nodo_temporal != null) {
			nodo_temporal.imprimir();
			nodo_temporal = nodo_temporal.siguiente;
		}		
	};
}

function main() {
	var listaPersonas = new ListaPersonas();
	
	listaPersonas.agregar("luis", 22);
	listaPersonas.agregar("jose", 25);
	listaPersonas.agregar("maria", 27);
	listaPersonas.agregar("marco", 35);
	var detener = false;
	var readline = require('readline');
	var rl = readline.createInterface({
		input: process.stdin,
  		output: process.stdout
	});
	var respuesta;

	do
	{
		console.log("-- Lista enlazada simple Personas --");
		console.log("\t1-. Agregar");
		console.log("\t2-. Buscar");
		console.log("\t3-. Eliminar");
		console.log("\t4-. Imprimir Lista");
		console.log("\t5-. Pasar a Arreglo");
		console.log("\t6-. Imprimir Arreglo");
		console.log("\t7-. Salir");
		rl.question('Escoja una opcion: ', function (respuesta) {
		  // TODO: Registrar la respuesta en una base de datos
		  console.log('Has registrado el numero: ', respuesta);

		  console.log(respuesta);
		  rl.close();
		});
		
		//switch()
	}while(respuesta =! 7);

	//listaPersonas.imprimir();
}

main();