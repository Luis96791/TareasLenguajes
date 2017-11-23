#include <stdio.h>
#include <stdlib.h>


void crearArchivo();
void escribirEmpleado(struct Empleado* empleado);
char obtenerTipoEmpleado(struct Empleado* empleado);
void escribirInfoEmpleado(struct Empleado* empleado, FILE *file);
void escribirEmpleadoMensual(struct Empleado* empleado, FILE* file);
void escribirEmpleadoComision(struct Empleado* empleado, FILE *file);
void escribirEmpleadoPorHora(struct Empleado* empleado, FILE *file);

void leerEmpleado(struct ListaEmpleados* listaEmpleados);
struct Empleado* cargarEmpleado(char tipo);
char leerTipoEmpleado(char* dataFile);
struct Empleado* cargarEmpleadoMensual(FILE* file, char tipo);
struct Empleado* cargarEmpleadoComision(FILE *file, char tipo);
struct Empleado* cargarEmpleadoPorHora(FILE *file, char tipo);


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
	printf("%c\n", tipo);
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

void leerEmpleado(struct ListaEmpleados* listaEmpleados)
{
	FILE *file;

	file = fopen("ListaEmpleados.list", "r");
	char tipo;

	while(feof(file) == 0)
	{
		struct Empleado* empleado;
		fscanf(file, "%c", &tipo);

		if (tipo == 'A')
		{
			empleado = cargarEmpleadoMensual(file, tipo);
			agregar(listaEmpleados, empleado);
		}

		if (tipo == 'B')
		{
			empleado = cargarEmpleadoComision(file, tipo);
		}

		if (tipo == 'C')
		{
			empleado = cargarEmpleadoPorHora(file, tipo);
			agregar(listaEmpleados, empleado);
		}	
	}

	fclose(file);
}

struct Empleado* cargarEmpleadoMensual(FILE *file, char tipo)
{
	struct Empleado* empleado = cargarEmpleado(tipo);
	char* nombre_empleado = (char *)malloc(sizeof(char)*60);
	int codigo_empleado, edad;
	float salario;
	fscanf(file, "%d %s %d %f",  &codigo_empleado, nombre_empleado, &edad, &salario);

	empleado->infoEmpleado->codigo_empleado = codigo_empleado;
	empleado->infoEmpleado->nombre_empleado = nombre_empleado;
	empleado->infoEmpleado->edad = edad;
	empleado->empleadoMensual->salario = salario;

	return empleado;
}

struct Empleado* cargarEmpleadoComision(FILE *file, char tipo)
{
	struct Empleado* empleado = cargarEmpleado(tipo);
	char* nombre_empleado = (char *)malloc(sizeof(char)*60);
	int codigo_empleado, edad, pos = 0;
	char zona;

	fscanf(file, "%d %s %d %c", &codigo_empleado, nombre_empleado, &edad, &zona);

	while(!file.eof())
	{
		fscanf(file, "%f", &empleado->empleadoComision->ventas[pos]);
		pos++;
	}

	empleado->infoEmpleado->codigo_empleado = codigo_empleado;
	empleado->infoEmpleado->nombre_empleado = nombre_empleado;
	empleado->infoEmpleado->edad = edad;

	return empleado;
}

struct Empleado* cargarEmpleadoPorHora(FILE *file, char tipo)
{
	struct Empleado* empleado = cargarEmpleado(tipo);
	char* nombre_empleado = (char *)malloc(sizeof(char)*60);
	char zona;
	int codigo_empleado, edad, horasTrabajadas;
	fscanf(file, "%d %s %d %c %d", &codigo_empleado, nombre_empleado, &edad, &zona, &horasTrabajadas);

	empleado->infoEmpleado->codigo_empleado = codigo_empleado;
	empleado->infoEmpleado->nombre_empleado = nombre_empleado;
	empleado->infoEmpleado->edad = edad;
	empleado->empleadoPorHora->zona = zona;
	empleado->empleadoPorHora->horasTrabajadas = horasTrabajadas;

	return empleado;
}

struct Empleado* cargarEmpleado(char tipo)
{
	struct Empleado *empleado = nuevoEmpleado();
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