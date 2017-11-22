#include <stdio.h>
#include <stdlib.h>


void crearArchivo();
void escribirEmpleado(struct Empleado* empleado);
char obtenerTipoEmpleado(struct Empleado* empleado);
void escribirInfoEmpleado(struct Empleado* empleado, FILE *file);
void escribirEmpleadoMensual(struct Empleado* empleado, FILE* file);


void crearArchivo()
{
	FILE *file;

	file = fopen("ListaEmpleados.list", "w+");

	if (file == NULL)
	 {
	 	printf("Error de archivo\n");
	 }
	 fclose(file); 
}

void escribirEmpleado(struct Empleado* empleado)
{
	FILE *file;
	file = fopen("ListaEmpleados.list", "a");
	char tipo = obtenerTipoEmpleado(empleado), delimitador = ':';

	fprintf(file, "%c", tipo);
	fprintf(file, "%c", delimitador);
	escribirInfoEmpleado(empleado, file);

	if (tipo == 'A')
	{
		escribirEmpleadoMensual(empleado, file);
	}
	else if (tipo == 'B')
	{
		
	}
	else{

	}
	
	fclose(file);
}

char obtenerTipoEmpleado(struct Empleado* empleado)
{
	if (empleado->empleadoMensual != NULL)
	{
		return 'A';
	}

	if (empleado->empleadoComision != NULL)
	{
		return 'B';
	}

	if (empleado->empleadoPorHora != NULL)
	{
		return 'C';
	}
	return ' ';
}

void escribirInfoEmpleado(struct Empleado* empleado, FILE *file)
{
	char* delimitador = ",";
	int codigo_empleado = empleado->infoEmpleado->codigo_empleado;
	char* nombre_empleado = empleado->infoEmpleado->nombre_empleado;
	int edad =  empleado->infoEmpleado->edad;

	fprintf(file, "%d", codigo_empleado);
	fprintf(file, "%s", delimitador);
	fprintf(file, "%s", nombre_empleado);
	fprintf(file, "%s", delimitador);
	fprintf(file, "%d", edad);
	fprintf(file, "%s", delimitador);
}

void escribirEmpleadoMensual(struct Empleado* empleado, FILE* file)
{
	float salario = empleado->empleadoMensual->salario;

	fprintf(file, "%2.f", salario);
	fprintf(file, "%s", "\n");
}