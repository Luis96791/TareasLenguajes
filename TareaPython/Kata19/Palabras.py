
class Palabra(object):
	
	def __init__(self):
		self.arreglo = []
		self.arregloLongi = [] #para palabras de la misma longitud
		self.palabrasDelimitadas = [] #para acotar las posibilidades

	def agregarPalabra(self, palabra):
		self.arreglo.append(palabra)

	def agregarPalabraML(self, palabraOrigen, palabraDestino):
		if len(palabraOrigen) == len(palabraDestino):
			for x in range(len(self.arreglo)):
				if len(self.arreglo[x])-1 == len(palabraOrigen):
					self.arregloLongi.append(self.arreglo[x])
			self.delimitarPalabra(palabraOrigen, palabraDestino)

	def buscarPalabra(self, palabra):
		for x in range(len(self.arregloLongi)):
			if self.arregloLongi[x][0] == palabra[0]:
				return x
		return -1


	def delimitarPalabra(self, palabraOrigen, palabraDestino):
		pos1 = self.buscarPalabra(palabraOrigen)
		pos2 = self.buscarPalabra(palabraDestino)

		if pos1 != -1 or pos2 != -1:
			if pos1 < pos2:
				while pos1 <= pos2:
					self.palabrasDelimitadas.append(self.arregloLongi[pos1])
					pos1+=1

			if pos1 > pos2:
				while pos1 >= pos2:
					self.palabrasDelimitadas.append(self.arregloLongi[pos1])
					pos1-=1

	def leerArchivo(self):
		archivo = open("palabras.txt")
		
		for linea in archivo.readlines():
			self.agregarPalabra(linea)
		archivo.close()

	def imprimir(self, arreglo):
		for x in range(len(arreglo)):
			print arreglo[x],
		
def main():
	palabra = Palabra()

	palabra.leerArchivo()
	palabra.agregarPalabraML('zero', 'soap')
	palabra.imprimir(palabra.palabrasDelimitadas)

if __name__ == '__main__':
	main()