
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

module.exports = Persona;


