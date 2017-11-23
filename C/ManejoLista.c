#include <stdio.h>
#include <stdlib.h>


void crearArchivo();
void escribirEmpleado(struct Empleado* empleado);
char obtenerTipoEmpleado(struct Empleado* empleado);
void escribirInfoEmpleado(struct Empleado* empleado, FILE *file);
void escribirEmpleadoMensual(struct Empleado* empleado, FILE* file);
void escribirEmpleadoComision(struct Empleado* empleado, FILE *file);
void escribirEmpleadoPorHora(struct Empleado* empleado, FILE *file);

void leerEmpleado();
struct Empleado* cargarEmpleado(char tipo);
char leerTipoEmpleado(char* dataFile);
struct Empleado* cargarEmpleadoMensual(FILE* file, struct Empleado* empleado);


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
	char tipo = obtenerTipoEmpleado(empleado);

	fprintf(file, "%c\n", tipo);
	escribirInfoEmpleado(empleado, file);

	if (tipo == 'A')
	{
		escribirEmpleadoMensual(empleado, file);
	}
	else if (tipo == 'B')
	{
		escribirEmpleadoComision(empleado, file);
	}
	else if (tipo == 'C')
	{
		escribirEmpleadoPorHora(empleado, file);
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
	int codigo_empleado = empleado->infoEmpleado->codigo_empleado;
	char* nombre_empleado = empleado->infoEmpleado->nombre_empleado;
	int edad =  empleado->infoEmpleado->edad;

	fprintf(file, "%d\n", codigo_empleado);
	fprintf(file, "%s\n", nombre_empleado);
	fprintf(file, "%d\n", edad);
}

void escribirEmpleadoMensual(struct Empleado* empleado, FILE* file)
{
	float salario = empleado->empleadoMensual->salario;

	fprintf(file, "%2.f\n", salario);
}

void escribirEmpleadoComision(struct Empleado* empleado, FILE *file)
{
	char zona = empleado->empleadoComision->zona;
	fprintf(file, "%c\n", zona);
	int pos = 0;

	while(empleado->empleadoComision->ventas[pos] != 0)
	{
		fprintf(file, "%2.f%s", empleado->empleadoComision->ventas[pos], " ");
		pos++;
	}
	fprintf(file, "%s", "\n");
}

void escribirEmpleadoPorHora(struct Empleado* empleado, FILE *file)
{
	char zona = empleado->empleadoPorHora->zona;
	int horasTrabajadas = empleado->empleadoPorHora->horasTrabajadas;
	fprintf(file, "%c\n", zona);
	fprintf(file, "%d\n", horasTrabajadas);
}

// -----------------------------------------------------------------------------
// -----------------------------------------------------------------------------

void leerEmpleado()
{
	FILE *file;
	struct Empleado* empleado;

	file = fopen("ListaEmpleados.list", "r");

	char linea[2];

	fgets(linea, (sizeof(linea)/sizeof(char)), file);
	empleado = cargarEmpleado(linea[0]);
	empleado = cargarEmpleadoMensual(file, empleado);

	fclose(file);
}

struct Empleado* cargarEmpleadoMensual(FILE *file, struct Empleado* empleado)
{
	char linea[20];
	empleado->infoEmpleado->codigo_empleado = atoi(fgets(linea, (sizeof(linea)/sizeof(char)), file));
}

struct Empleado* cargarEmpleado(char tipo)
{
	struct Empleado *empleado;
	empleado->infoEmpleado = nuevoInfoEmpleado();

	if (tipo == 'A')
	{
		empleado->empleadoMensual = nuevoEmpleadoMensual();
		return empleado;
	}

	if (tipo == 'B')
	{
		empleado->empleadoComision = nuevoEmpleadoComision();
		return empleado;
	}

	if (tipo == 'C')
	{
		empleado->empleadoPorHora = nuevoEmpleadoPorHora();
		return empleado;
	}	
	return NULL;
}