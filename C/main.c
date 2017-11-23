#include <stdlib.h>
#include <stdio.h>

#include "InfoEmpleado.c"
#include "EmpleadoMensual.c"
#include "EmpleadoComision.c"
#include "EmpleadoPorHora.c"
#include "Empleado.c"
#include "ListaEmpleados.c"
#include "ManejoLista.c"
#include "Informe.c"

typedef enum{false = 0, true = !false}bool;

struct Empleado* agregarNuevoEmpleado()
{
	struct Empleado* empleado;
	int opcion;
	printf("1-. Empleado Mensual\n");
	printf("2-. Empleado Comision\n");
	printf("3-. Empleado Por Hora\n\n");
	printf("Escoja una Opcion: ");
	scanf("%d", &opcion);

	if (opcion > 0 && opcion < 4)
	{
		empleado = ingresarEmpleado(opcion);
	}
	else{
		printf("Opcion invalida\n");
	}
	return empleado;
}

int main(int argc, char const *argv[])
{
	raiz _raiz = NULL;
	struct ListaEmpleados* listaEmpleados;
	listaEmpleados = nuevaListaEmpleados();

	int opcion;

	do
	{
		struct Empleado* empleado;
		printf("\n\t1-. Ingresar Empleado\n");
		printf("\t2-. Salvar a Archivo\n");
		printf("\t3-. Cargar de Archivo\n");
		printf("\t4-. Imprimir Reporte\n");
		printf("\t5-. Salir\n\n");
		printf("Ingrese una opcion: ");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				empleado = agregarNuevoEmpleado();
				agregar(listaEmpleados, empleado);
				break;
			case 2:
				escribirListaEnArchivo(listaEmpleados);
				break;
			case 3:
				leerEmpleado(listaEmpleados);
				imprimirLista(listaEmpleados);
				break;
			case 4:
				agregarListaArbol(listaEmpleados, &_raiz);
				imprimir(_raiz);
				break;
			default:
				exit(EXIT_SUCCESS);
				break;

		}
	} while (true);

	return 0;
}

