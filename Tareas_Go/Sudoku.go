package main

import (
	"fmt"
)

func inicializarMatriz() [][]int {

	matriz := make([][]int, 9)
	for i := 0; i < len(matriz); i++ {
		matriz[i] = make([]int, len(matriz))
		for j := 0; j < len(matriz); j++ {
			matriz[i][j] = 0
		}
	}
	matriz = valoresIniciales(matriz)
	return matriz
}

func valoresIniciales(matriz [][]int) [][]int{
	matriz[0][1] = 5;	matriz[0][5] = 2;	matriz[0][6] = 8;
	matriz[0][7] = 9;	matriz[1][2] = 6;	matriz[1][8] = 2;
	matriz[2][1] = 8;	matriz[2][2] = 9;	matriz[2][4] = 3;
	matriz[2][7] = 5;	matriz[3][1] = 1;	matriz[3][2] = 2;
	matriz[3][3] = 4;	matriz[3][6] = 7;	matriz[3][8] = 9;
	matriz[4][1] = 6;	matriz[4][4] = 8;	matriz[4][7] = 1;
	matriz[5][0] = 5;	matriz[5][2] = 8;	matriz[5][6] = 4;
	matriz[5][7] = 3;	matriz[6][1] = 2;	matriz[6][3] = 8;
	matriz[6][6] = 9;	matriz[6][7] = 7;	matriz[7][6] = 3;
	matriz[8][2] = 1;	matriz[8][3] = 7;	matriz[8][7] = 2;

	return matriz
}

func resolver(matriz [][]int, fila int, columna int) bool {

	if columna == len(matriz) {
		columna = 0
		fila++
		if fila == len(matriz) {
			return true
		}
	}

	if matriz[fila][columna] > 0 {
		return resolver(matriz, fila, columna+1)
	}

	for pivote := 1; pivote <= len(matriz); pivote++ {
		if evaluar(matriz, fila, columna, pivote) {
			matriz[fila][columna] = pivote
			if resolver(matriz, fila, columna+1) {
				return true
			} else {
				matriz[fila][columna] = 0
			}
		}
	}
	return false
}

func evaluar(matriz [][]int, fila int, columna int, pivote int) bool{
	
	for i := 0; i < len(matriz); i++ {
		if matriz[fila][i] == pivote || matriz[i][columna] == pivote {
			return false
		}
	}

	var _fila, _columna int

	_fila = (fila/3)*3
	_columna = (columna/3)*3
	for i := 0; i < 3; i++ {
		if matriz[_fila][_columna+i] == pivote || matriz[_fila+1][_columna+i] == pivote || matriz[_fila+2][_columna+i] == pivote {
			return false
		}
	}
	return true
}

func imprimirMatriz(matriz [][]int) {
	for i := 0; i < len(matriz); i++ {
		for j := 0; j < len(matriz); j++ {
			fmt.Print(matriz[i][j], " ")
			if j == 2 || j == 5 {
				fmt.Print("| ")
			}
		}
		fmt.Println()

		if i == 2 || i == 5 {
			fmt.Println("---------------------")
		}
	}
}

func main() {

	matriz := inicializarMatriz()
	resolver(matriz, 0, 0)
	imprimirMatriz(matriz)
}