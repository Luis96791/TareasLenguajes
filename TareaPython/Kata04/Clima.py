class Temperatura(object):

	def __init__(self, dia, MxT, MnT):
		self.dia = dia
		self.MxT = MxT
		self.MnT = MnT

	def imprimir(self):
		print self.dia, "\t", self.MxT, "\t", self.MnT

class ArregloTemperatura(object):
	"""docstring for ArregloTemperatura"""
	def __init__(self):
		self.arreglo = []

	def leerArchivo(self):
		archivo = open("weather.dat")
		archivo.seek(93, 0)

		for x in range(30):
			dia = int(archivo.read(2))
			archivo.seek(2, 1)
			Mxt = int(archivo.read(2))
			archivo.seek(4, 1)
			Mnt = int(archivo.read(2))
			archivo.seek(78, 1)
			temperatura = Temperatura(dia, Mxt, Mnt)
			self.agregar(temperatura)
		archivo.close()

	def agregar(self, temperatura):
		self.arreglo.append(temperatura)

	def imprimir(self):
		print "Dy\t", "MxT\t", "MnT"
		print("-------------------")
		for x in range(len(self.arreglo)):
			self.arreglo[x].imprimir()

	def obtenerMnT(self):
		temp = Temperatura(0,0,100)

		for x in range(len(self.arreglo)):
			if self.arreglo[x].MnT < temp.MnT:
				temp = self.arreglo[x]
		print "Dia: ", temp.dia, " MnT: ", temp.MnT


	def obtenerMxT(self):
		temp = Temperatura(0,0,0)

		for x in range(len(self.arreglo)):
			if self.arreglo[x].MxT > temp.MxT:
				temp = self.arreglo[x]
		print "Dia: ", temp.dia, " MxT: ", temp.MxT

def main():

	arregloTemperatura = ArregloTemperatura()

	arregloTemperatura.leerArchivo()
	arregloTemperatura.imprimir()
	arregloTemperatura.obtenerMnT()
	arregloTemperatura.obtenerMxT()


if __name__ == '__main__':
	main()
