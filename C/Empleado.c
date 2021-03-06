#include <stdio.h>
#include <stdlib.h>

struct Empleado
{
	struct InfoEmpleado *infoEmpleado;
	struct EmpleadoMensual *empleadoMensual;
	struct EmpleadoComision *empleadoComision;
	struct EmpleadoPorHora *empleadoPorHora;
	struct Empleado *siguiente;
};


struct Empleado* nuevoEmpleado( void )
{
	struct Empleado *empleado;
	empleado = (struct Empleado *)malloc(sizeof(struct Empleado));
	empleado->infoEmpleado = NULL;
	empleado->empleadoMensual = NULL;
	empleado->empleadoComision = NULL;
	empleado->empleadoPorHora = NULL;
	empleado->siguiente = NULL;
	return empleado;
}

struct Empleado* ingresarEmpleado(int tipo)
{
	struct Empleado* empleado = nuevoEmpleado();
	empleado->infoEmpleado = ingresarInfoEmpleado();

	if (tipo == 1)
	{
		empleado->empleadoMensual = ingresarEmpleadoMensual();
		return empleado;
	}

	if (tipo == 2)
	{
		empleado->empleadoComision = ingresarEmpleadoComision();
		return empleado;
	}

	if (tipo == 3)
	{
		empleado->empleadoPorHora = ingresarEmpleadoPorHora();
		return empleado;
	}

	return NULL;
}