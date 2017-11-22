#include <stdio.h>
#include <stdlib.h>

struct EmpleadoMensual
{
	float salario;
};

struct EmpleadoMensual* nuevoEmpleadoMensual( void )
{
	return (struct EmpleadoMensual *)malloc(sizeof(struct EmpleadoMensual));
}

struct EmpleadoMensual* ingresarEmpleadoMensual( void )
{
	struct EmpleadoMensual* empleadoMensual;
	empleadoMensual = nuevoEmpleadoMensual();

	float salario;
	printf("Salario Empleado: ");
	scanf("%f", &salario);

	empleadoMensual->salario = salario;
	return empleadoMensual;
}