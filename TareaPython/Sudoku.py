
class Sudoku(object):
	
	def __init__(self):
		self.matriz = []
		self.tamanio = 9
		
	def inicilizarMatriz(self):
		for x in range(self.tamanio):
			self.matriz.append([])
			for y in range(self.tamanio):
				self.matriz[x].append(0)
		self.valoresIniciales()

	def imprimirMatriz(self):
		for x in range(self.tamanio):
			for y in range(self.tamanio):
				if y == 2 or y == 5:
					sep = "|"
				else:
					sep = ""
				print self.matriz [x][y], sep,
			print
			if x == 2 or x == 5:
				print("---------------------------")

	def valoresIniciales(self):
		self.matriz[0][1] = 5;	self.matriz[0][5] = 2;	self.matriz[0][6] = 8;
		self.matriz[0][7] = 9;	self.matriz[1][2] = 6;	self.matriz[1][8] = 2;
		self.matriz[2][1] = 8;	self.matriz[2][2] = 9;	self.matriz[2][4] = 3;
		self.matriz[2][7] = 5;	self.matriz[3][1] = 1;	self.matriz[3][2] = 2;
		self.matriz[3][3] = 4;	self.matriz[3][6] = 7;	self.matriz[3][8] = 9;
		self.matriz[4][1] = 6;	self.matriz[4][4] = 8;	self.matriz[4][7] = 1;
		self.matriz[5][0] = 5;	self.matriz[5][2] = 8;	self.matriz[5][6] = 4;
		self.matriz[5][7] = 3;	self.matriz[6][1] = 2;	self.matriz[6][3] = 8;
		self.matriz[6][6] = 9;	self.matriz[6][7] = 7;	self.matriz[7][6] = 3;
		self.matriz[8][2] = 1;	self.matriz[8][3] = 7;	self.matriz[8][7] = 2;

	def resolver(self, fila, columna):
		if columna == self.tamanio:
			columna = 0
			fila += 1
			if fila == self.tamanio:
				return True

		if self.matriz[fila][columna] > 0:
			return self.resolver(fila, columna+1)

		pivote = 1
		for pivote in range(self.tamanio+1):
			if self.evaluar(fila, columna, pivote):
				self.matriz[fila][columna] = pivote
				if self.resolver(fila, columna+1):
					return True
				else:
					self.matriz[fila][columna] = 0
		return False


	def evaluar(self, fila, columna, pivote):
		if (not self.evaluarVertical(columna, pivote)) or (not self.evaluarHorizontal(fila, pivote)) or (not self.evaluarSubMatriz(fila, columna, pivote)):
			return False
		return True

	def evaluarHorizontal(self, fila, pivote):
		for x in range(self.tamanio):
			if self.matriz[fila][x] == pivote:
				return False
		return True

	def evaluarVertical(self, columna, pivote):
		for y in range(self.tamanio):
			if self.matriz[y][columna] == pivote:
				return False
		return True

	def evaluarSubMatriz(self, fila, columna, pivote):
		_fila = (fila/3)*3
		_columna = (columna/3)*3
		for i in range(3):
			if self.matriz[_fila][_columna+i] == pivote or self.matriz[_fila+1][_columna+i] == pivote or self.matriz[_fila+2][_columna+i] == pivote:
				return False
		return True

def main():
	sudoku = Sudoku()

	sudoku.inicilizarMatriz()
	sudoku.resolver(0, 0)
	sudoku.imprimirMatriz()

if __name__ == '__main__':
	main()	