#include <stdio.h>
#include <stdlib.h>

struct EmpleadoComision
{
	char zona;
	float ventas[20];
};

struct EmpleadoComision* nuevoEmpleadoComision( void )
{
	return (struct EmpleadoComision *)malloc(sizeof(struct EmpleadoComision));
}

struct EmpleadoComision* ingresarEmpleadoComision( void )
{
	struct EmpleadoComision* empleadoComision;
	empleadoComision = nuevoEmpleadoComision();

	char zona;
	printf("Ingrese Zona: ");
	scanf("%1s", &zona);
	empleadoComision->zona = zona;

	char seguir = 's';
	int pos = 0, len = (sizeof(empleadoComision->ventas)/4);
	float venta;

	while(seguir == 's' && pos < len)
	{
		printf("Ingrese Venta: ");
		scanf("%f", &venta);
		empleadoComision->ventas[pos] = venta;
		printf("Desea ingresar otra Venta (s/n): ");
		scanf("%1s", &seguir);
		pos++;
	}
	return empleadoComision;
}