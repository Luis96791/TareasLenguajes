#include <stdlib.h>
#include <stdio.h>

struct ListaEmpleados
{
	struct Empleado* inicio_lista;
	struct Empleado* fin_lista;
};

struct ListaEmpleados* nuevaListaEmpleados()
{
	return (struct ListaEmpleados *)malloc(sizeof(struct ListaEmpleados));
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

