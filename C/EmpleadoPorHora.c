#include <stdio.h>
#include <stdlib.h>

struct EmpleadoPorHora
{
	char zona;
	int horasTrabajadas;
};

struct EmpleadoPorHora* nuevoEmpleadoPorHora( void )
{
	return (struct EmpleadoPorHora *)malloc(sizeof(struct EmpleadoPorHora));
}

struct EmpleadoPorHora* ingresarEmpleadoPorHora( void )
{
	struct EmpleadoPorHora* empleadoPorHora;
	empleadoPorHora = nuevoEmpleadoPorHora();

	char zona;
	int horasTrabajadas;

	printf("Ingrese Zona: ");
	scanf("%1s", &zona);
	printf("Ingrese Horas Trabajadas: ");
	scanf("%d", &horasTrabajadas);

	empleadoPorHora->zona = zona;
	empleadoPorHora->horasTrabajadas = horasTrabajadas;

	return empleadoPorHora;
}