package main

import (
	"fmt"
	"os"
	"strconv"
)

type Clima struct {
	Dy int
	MxT int
	MnT int
}

func leerArchivo() string{
	contenido, _ := os.Open("weather.dat")
	contenido.Seek(91, 0)

	contenido_bytes := make([]byte, 2699)
	contenido.Read(contenido_bytes)
	contenido.Close()

	cadena := string(contenido_bytes)
	return cadena
}

func convertirArreglo(clima []Clima) []Clima{

	cadena := leerArchivo()
	var cad1, cad2, cad3 string
	
	idx := 0
	var delimitador int
	for x := 0; x < len(clima); x++ {
		delimitador += 4
		for idx < delimitador {
			if cadena[idx] != ' ' {
				cad1 += string(cadena[idx])
			}
			idx++
		}
		delimitador += 4

		for idx < delimitador {
			if cadena[idx] != ' ' {
				cad2 += string(cadena[idx])
			}
			idx++
		}
		delimitador += 6

		for idx < delimitador {
			if cadena[idx] != ' ' {
				if cadena[idx] != '*' {
					cad3 += string(cadena[idx])
				}
			}
			idx++
		}

		delimitador += 76; idx += 76

		clima[x].Dy, _ = strconv.Atoi(cad1)
		clima[x].MxT, _ = strconv.Atoi(cad2)
		clima[x].MnT, _ = strconv.Atoi(cad3)
		cad1 = ""; cad2 = ""; cad3 = ""
	 }

	return clima
}

func imprimirArreglo(clima []Clima) {
	fmt.Println("Dia\tMxT\tMnT")
	for i := 0; i < len(clima); i++ {
		fmt.Printf("%d \t%d \t%d \n", clima[i].Dy, clima[i].MxT, clima[i].MnT)
	}
}

func main() {

	clima := make([]Clima, 30)

	clima = convertirArreglo(clima)
	imprimirArreglo(clima)
}