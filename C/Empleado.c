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
	return (struct Empleado *)malloc(sizeof(struct Empleado));
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