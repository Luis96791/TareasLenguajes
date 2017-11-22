#include <stdio.h>
#include <stdlib.h>

struct InfoEmpleado
{
	int codigo_empleado;
	char* nombre_empleado;
	int edad; 	
};

struct InfoEmpleado* nuevoInfoEmpleado( void )
{
	return (struct InfoEmpleado *)malloc(sizeof(struct InfoEmpleado));
}

struct InfoEmpleado* ingresarInfoEmpleado( void )
{
	struct InfoEmpleado* infoEmpleado;

	int codigo_empleado, edad;
	char* nombre_empleado = (char *)malloc(80*sizeof(char));

	printf("Codigo Empleado: ");
	scanf("%d", &codigo_empleado);
	printf("Nombre Empleado: ");
	scanf("%s", nombre_empleado);
	printf("Edad Empleado: ");
	scanf("%d", &edad);

	infoEmpleado = nuevoInfoEmpleado();
	infoEmpleado->codigo_empleado = codigo_empleado;
	infoEmpleado->nombre_empleado = nombre_empleado;
	infoEmpleado->edad = edad;

	return infoEmpleado;
}