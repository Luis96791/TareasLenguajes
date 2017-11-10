package main

import (
	"fmt"
)

/*Tipo de dato Persona*/
type Persona struct {
	nombre string
	edad int
	siguiente *Persona
}

/*Tipo de dato ListaPersonas*/
type ListaPersonas struct {
	inicio_lista *Persona
	fin_lista *Persona
}

/*Nuevo objeto Persona*/
func nuevaPersona() *Persona {
	return new(Persona)
}

/*Nuevo objeto ListaPersonas*/
func nuevaListaPersonas() *ListaPersonas {
	return new(ListaPersonas)
}

/*Imprime los atributos de objeto Persona*/
func imprimirPersona(persona *Persona) {
	if persona != nil {
		fmt.Println("Nombre: ", persona.nombre, "Edad: ", persona.edad)	
	}
}

/*Devuelve verdadero si la lista esta vacia*/
func isListaVacia(listaPersonas *ListaPersonas) bool{
	
	if listaPersonas.inicio_lista == nil {
		fmt.Println("La lista esta vacia")
		return true
	}
	return false
}

/*Agrega un nuevo objeto a la listaPersonas*/
func agregarPersonaLista(listaPersonas *ListaPersonas, persona *Persona) {
	
	if listaPersonas.inicio_lista == nil {
		listaPersonas.inicio_lista = persona 
		listaPersonas.fin_lista  = persona
		fmt.Println("Registro Agregado")
		return
	}

	listaPersonas.fin_lista.siguiente = persona
	listaPersonas.fin_lista = persona
	fmt.Println("Registro Agregado")
}

/*Busca objeto Persona en la ListaPersonas*/
func buscarPersona(listaPersonas *ListaPersonas) *Persona{
	nodo_temporal := listaPersonas.inicio_lista
	nombre := ingresarNombre()

	if isListaVacia(listaPersonas) {
		return nil
	}

	for  nodo_temporal !=  nil {
		if nodo_temporal.nombre == nombre {
			return nodo_temporal
		}
		nodo_temporal = nodo_temporal.siguiente
	}
	
	fmt.Println("Valor no encontrado.")
	return nil
}

/*Elimina objeto de la ListaPersonas*/
func eliminarPersona(listaPersonas *ListaPersonas) {

	nodo_temporal:= listaPersonas.inicio_lista
	nombre := ingresarNombre()

	if isListaVacia(listaPersonas) {
		return
	}

	if listaPersonas.inicio_lista.nombre == nombre {
		listaPersonas.inicio_lista = listaPersonas.inicio_lista.siguiente
		return
	}

	for nodo_temporal.siguiente != nil {
		if nodo_temporal.siguiente.nombre == nombre {
			nodo_temporal.siguiente = nodo_temporal.siguiente.siguiente
			return
		}
		nodo_temporal = nodo_temporal.siguiente
	} 
}

/*Imprime todos los items de  ListaPersonas*/
func imprimirLista(listaPersonas *ListaPersonas) {

	nodo_temporal := listaPersonas.inicio_lista

	if isListaVacia(listaPersonas) {
		return
	}

	for nodo_temporal != nil {
		imprimirPersona(nodo_temporal)
		nodo_temporal = nodo_temporal.siguiente
	}
}

/*Imprime todos los items de  ListaPersonas convertido a un arreglo*/
func imprimirArreglo(arregloPersonas []Persona) {
	
	for i := 0; i < len(arregloPersonas); i++ {
		imprimirPersona(&arregloPersonas[i])
	}
}

/*Devuelve el tamaño de la ListaPersonas*/
func tamanioLista(listaPersonas *ListaPersonas) int {
	_tamanio := 0
	nodo_temporal := listaPersonas.inicio_lista

	if isListaVacia(listaPersonas) {
		return _tamanio
	}

	for nodo_temporal != nil {
		_tamanio++
		nodo_temporal = nodo_temporal.siguiente
	}

	return _tamanio
}

/*Convierte la listaPersonas en un arreglo del mismo tipo*/
func convertirEnArreglo(listaPersonas *ListaPersonas) []Persona {
	nodo_temporal := listaPersonas.inicio_lista
	
	if isListaVacia(listaPersonas) {
		return nil
	}

	_tamanio := tamanioLista(listaPersonas)
	arregloPersonas := make([]Persona, _tamanio)

	for i := 0; i < _tamanio; i++ {
		arregloPersonas[i] = *nodo_temporal
		nodo_temporal = nodo_temporal.siguiente
	}

	fmt.Print("\n\tLa lista se ha convertido a un arreglo. \n")

	return arregloPersonas
}

/*Recibe los datos ingresados por el teclado*/
func ingresarDatosAgregar() *Persona {

	persona := nuevaPersona()

	persona.nombre = ingresarNombre()

	fmt.Print("Ingrese Edad: ")
	fmt.Scanln(&persona.edad)

	return persona
}

/*Recibe una cadena del teclado*/
func ingresarNombre() string {

	var nombre string

	fmt.Print("Ingrese Nombre: ")
	fmt.Scanln(&nombre)

	return nombre
}

func main() {
	listaPersonas := nuevaListaPersonas()
	var arregloPersonas []Persona

	seguir := true

	for seguir {
		fmt.Println("-- Lista enlazada doble Personas --")
		fmt.Println("\t1-. Agregar")
		fmt.Println("\t2-. Buscar")
		fmt.Println("\t3-. Eliminar")
		fmt.Println("\t4-. Imprimir Lista")
		fmt.Println("\t5-. Pasar a Arreglo")
		fmt.Println("\t6-. Imprimir Arreglo")
		fmt.Print("Ingrese una Opcion: ")

		var opcion int 
		fmt.Scanln(&opcion)

		switch opcion {
		case 1:
			persona := ingresarDatosAgregar()
			agregarPersonaLista(listaPersonas, persona)
		case 2:
			persona := buscarPersona(listaPersonas)
			imprimirPersona(persona)
		case 3:
			eliminarPersona(listaPersonas)
		case 4:
			imprimirLista(listaPersonas)
		case 5:
			arregloPersonas = convertirEnArreglo(listaPersonas)
			imprimirArreglo(arregloPersonas)
		case 6:
			imprimirArreglo(arregloPersonas)
		default:
			seguir = false				
		}
	}
}