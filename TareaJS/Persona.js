
function Persona(nombre, edad) {
	this.nombre = nombre;
	this.edad = edad;
}

Persona.prototype.imprimir = function() {
	console.log(this.nombre+" "+this.edad);
};

var persona1 = new Persona("Luis", 22);
var persona2 = new Persona("Ana", 21);

persona1.imprimir();
persona2.imprimir();
