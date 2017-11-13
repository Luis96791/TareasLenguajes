package main

import (
	"fmt"
	"os"
	"strconv"
)

type Futbol struct {
	Team string
	F int
	A int
}

func leerArchivo() string{
	contenido, _ := os.Open("football.dat")
	contenido.Seek(60, 0)

	contenido_bytes := make([]byte, 1238)
	contenido.Read(contenido_bytes)
	contenido.Close()

	cadena := string(contenido_bytes)
	return cadena
}

func convertirArreglo(futbol []Futbol) []Futbol {
	
	cadena := leerArchivo()
	var cad1, cad2, cad3 string

	idx := 0
	var delimitador int
	for i := 0; i < len(futbol); i++ {

		if i == 17 {
			delimitador += 59; idx += 59	
		}
		delimitador += 23; idx += 6

		for idx < delimitador {
			if cadena[idx] != ' ' {
				cad1 += string(cadena[idx])
			}
			idx++
		}
		delimitador += 22; idx += 16
		
		for idx < delimitador {
			if cadena[idx] != ' ' {
				cad2 += string(cadena[idx])
			}
			idx++
		}
		delimitador += 7; idx += 3

		for idx < delimitador {
			if cadena[idx] != ' ' {
				cad3 += string(cadena[idx])
			}
			idx++
		}
		delimitador += 7; idx += 7

		futbol[i].Team = cad1
		futbol[i].F, _ = strconv.Atoi(cad2)
		futbol[i].A, _ = strconv.Atoi(cad3)
		cad1 = ""; cad2 = ""; cad3 = ""
	}
	return futbol
}

func imprimirArreglo(futbol []Futbol) {
	fmt.Println("Team\t\tF\tA")
	for i := 0; i < len(futbol); i++ {
		fmt.Printf("%s\t %d\t %d\n", futbol[i].Team, futbol[i].F, futbol[i].A)
	}
}

func main() {
	futbol := make([]Futbol, 20)
	futbol = convertirArreglo(futbol)
	imprimirArreglo(futbol)
}