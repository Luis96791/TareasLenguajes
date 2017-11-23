#include <stdlib.h>
#include <stdio.h>

struct ListaEmpleados
{
	struct Empleado* inicio_lista;
	struct Empleado* fin_lista;
};

void escribirListaEnArchivo(struct ListaEmpleados* listaEmpleados);
void escribirEmpleado(struct Empleado* empleado);
void crearArchivo();

struct ListaEmpleados* nuevaListaEmpleados()
{
	struct ListaEmpleados *listaEmpleados;
	listaEmpleados = (struct ListaEmpleados *)malloc(sizeof(struct ListaEmpleados));
	listaEmpleados->inicio_lista = NULL;
	listaEmpleados->fin_lista = NULL;
	return listaEmpleados;
}

struct Empleado* buscar(struct ListaEmpleados* listaEmpleados, int codigo)
{
	struct Empleado* nodo_temporal = listaEmpleados->inicio_lista;

	while(nodo_temporal != NULL)
	{
		if (nodo_temporal->infoEmpleado->codigo_empleado == codigo)
		{
			return nodo_temporal;
		}
		nodo_temporal = nodo_temporal->siguiente;
	}
	return NULL;
}

void agregar(struct ListaEmpleados* listaEmpleados, struct Empleado* empleado)
{
	if (listaEmpleados->inicio_lista == NULL)
	{
		listaEmpleados->inicio_lista = listaEmpleados->fin_lista = empleado;
		return;
	}

	if (buscar(listaEmpleados, empleado->infoEmpleado->codigo_empleado) == NULL)
	{
		listaEmpleados->fin_lista->siguiente = empleado;
		listaEmpleados->fin_lista = empleado;
	}
	else{
		printf("El empleado con este codigo ya existe\n");
	}
}

void escribirListaEnArchivo(struct ListaEmpleados* listaEmpleados)
{
	struct Empleado* nodo_temporal = listaEmpleados->inicio_lista;
	crearArchivo();

	while(nodo_temporal != NULL)
	{
		escribirEmpleado(nodo_temporal);
		nodo_temporal = nodo_temporal->siguiente;
	}
}

void imprimirLista(struct ListaEmpleados* listaEmpleados)
{
	struct Empleado* nodo_temporal = listaEmpleados->inicio_lista;

	while(nodo_temporal != NULL)
	{
		printf("%d %s %d\n", nodo_temporal->infoEmpleado->codigo_empleado, nodo_temporal->infoEmpleado->nombre_empleado,
			nodo_temporal->infoEmpleado->edad);
		nodo_temporal = nodo_temporal->siguiente;
	}
}

