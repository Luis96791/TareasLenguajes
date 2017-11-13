package main 

import (
	"fmt"
	"os"
)

func leerArchivo() string {
	contenido, _ := os.Open("palabras.txt")

	contenido_bytes := make([]byte, 794505)
	contenido.Read(contenido_bytes)
	cadena := string(contenido_bytes)
	contenido.Close()
	
	return cadena
}

func convertirArreglo() []string {
	cadena := leerArchivo()

	palabras := make([]string, 84099)
	var cad string
	idx := 0

	for i := 0; i < 794504; i++ {
		if cadena[i] != '\n' {
			cad += string(cadena[i])
		} else {
			palabras[idx] = cad
			idx++
			cad = ""
		}
	}

	return palabras
}

func imprimirArreglo(palabras []string) {
	for i := 0; i < len(palabras); i++ {
		fmt.Println(palabras[i])
	}
}

func seleccionarSimilares(palabra string, palabras []string) []string {
	
	similares := make([]string, 0)

	for i := 0; i < len(palabras); i++ {
		if len(palabra) == len(palabras[i]) {
			similares = append(similares, palabras[i])
		}
	}
	return similares
}

func convertirPalabra(entrada string, salida string, similares []string) []string {
	
	parents := make([]string, 0)
	
	

	return parents
}

func main() {
	
	palabras := convertirArreglo()
	similares := seleccionarSimilares("lead", palabras)
	parents := convertirPalabra("cat", "dog", similares)

	imprimirArreglo(parents)
}