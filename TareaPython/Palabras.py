
class Palabra(object):
	"""docstring for Palabras"""
	def __init__(self):
		self.arreglo = []

	def agregar(self, palabra):
		self.arreglo.append(palabra)

	def leerArchivo(self):
		archivo = open("palabras.txt")
		
		for x in range(84099):
			linea = archivo.readline()
			self.agregar(linea)
		archivo.close()

	def imprimir(self):
		for x in range(84099):
			print self.arreglo[x]
		
def main():
	palabra = Palabra()

	palabra.leerArchivo()
	palabra.imprimir()

	print palabra.arreglo[0]
	print palabra.arreglo[1]
	print palabra.arreglo[2]
	print palabra.arreglo[3]
	print palabra.arreglo[4]
	print palabra.arreglo[5]
	print palabra.arreglo[6]
	print palabra.arreglo[7]
	print palabra.arreglo[8]
	print palabra.arreglo[9]
	print palabra.arreglo[10]

if __name__ == '__main__':
	main()