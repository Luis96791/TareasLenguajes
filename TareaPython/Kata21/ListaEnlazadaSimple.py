class Persona(object):	

	def __init__(self, nombre, edad):
	 	self.nombre = nombre
	 	self.edad = edad
	 	self.siguiente = None

	def getNombre(self):
		return self.nombre

	def getEdad(self):
		return self.edad

	def imprimir(self):
		print "Nombre: ", self.getNombre(), "\tEdad: ", self.getEdad() 


class ListaPersonas(object):

	def __init__(self):
		self.inicio_lista = None
		self.fin_lista = None
		self.arreglo = []

	def isListaVacia(self):
		if self.inicio_lista == None:
			print("La lista esta vacia")
			return True

	def insertar(self, persona):
		if self.inicio_lista == None:
			self.inicio_lista = self.fin_lista = persona
			return

		self.fin_lista.siguiente = persona
		self.fin_lista = persona

	def buscar(self, persona):
		if self.isListaVacia() == True:
			return

		nodo_temporal = self.inicio_lista
		while (nodo_temporal != None):
			if nodo_temporal.nombre == persona.nombre:
				return nodo_temporal
			nodo_temporal = nodo_temporal.siguiente

	def eliminar(self, persona):
		if self.isListaVacia() == True:
			return

		if self.inicio_lista.nombre == persona.nombre:
			self.inicio_lista = self.inicio_lista.siguiente
			return

		nodo_temporal = self.inicio_lista
		while nodo_temporal.siguiente != None:
			if nodo_temporal.siguiente.nombre == persona.nombre:
				nodo_temporal.siguiente = nodo_temporal.siguiente.siguiente
				return
			nodo_temporal = nodo_temporal.siguiente

	def imprimir(self):
		if self.isListaVacia() == True:
			return
		
		nodo_temporal = self.inicio_lista
		while (nodo_temporal != None):
			nodo_temporal.imprimir()
			nodo_temporal = nodo_temporal.siguiente

	def convertirArreglo(self):
		self.arreglo = []
		if self.isListaVacia() == True:
			return

		nodo_temporal = self.inicio_lista
		while  nodo_temporal != None:
			self.arreglo.append(nodo_temporal)
			nodo_temporal = nodo_temporal.siguiente

		print("\n\tLa lista se ha convertido a un arreglo. \n")

	def imprimirArreglo(self):
		x = 0
		while x < len(self.arreglo):
			self.arreglo[x].imprimir()
			x = x+1

def main():
	listaPersonas = ListaPersonas()

	p1 = Persona('Luis', 13)
	p2 = Persona('Jose', 33)
	p3 = Persona('Mario', 16)
	p4 = Persona('Martha', 86)
	p5 = Persona('Jesis', 56)

	listaPersonas.insertar(p1)
	listaPersonas.insertar(p2)
	listaPersonas.insertar(p3)
	listaPersonas.insertar(p4)
	listaPersonas.insertar(p5)

	detener = False

	while detener == False:
		print("-- Lista enlazada simple Personas --")
		print("\t1-. Agregar")
		print("\t2-. Buscar")
		print("\t3-. Eliminar")
		print("\t4-. Imprimir Lista")
		print("\t5-. Pasar a Arreglo")
		print("\t6-. Imprimir Arreglo")
		opcion = input("Ingrese una Opcion: ")

		if opcion == 1:
			nombre = ingresarNombre()
			edad = ingresarEdad()
			persona = pasarParametros(nombre, edad)
			listaPersonas.insertar(persona)
		elif opcion == 2:
			nombre = ingresarNombre()
			persona = pasarParametros(nombre, 0)
			persona = listaPersonas.buscar(persona)
			if persona != None:
				persona.imprimir()
		elif opcion == 3:
			nombre = ingresarNombre()
			persona = pasarParametros(nombre, 0)
			listaPersonas.eliminar(persona)
		elif opcion == 4:
			listaPersonas.imprimir()
		elif opcion == 5:
			listaPersonas.convertirArreglo()
		elif opcion == 6:
			listaPersonas.imprimirArreglo()
		else:
			detener = True

def pasarParametros(nombre, edad):
	persona = Persona(nombre, edad)
	return persona

def ingresarNombre():
	nombre = raw_input("Ingrese Nombre: ")
	return nombre

def ingresarEdad():
	edad = input("Ingrese Edad: ")
	return edad


if __name__ == '__main__':
	main()
