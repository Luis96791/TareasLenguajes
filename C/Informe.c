#include <stdlib.h>
#include <stdio.h>

typedef struct Nodo
{
	struct Empleado* empleado;
	struct Nodo *hijo_izq, *hijo_der;
}nodoArbol;

typedef nodoArbol *raiz;

void insertarNodo(raiz *_raiz, struct Empleado* empleado)
{
	if (*_raiz == NULL)
	{
		*_raiz = malloc(sizeof(nodoArbol));
		(*_raiz)->empleado = nuevoEmpleado();
		(*_raiz)->empleado->infoEmpleado = nuevoInfoEmpleado();
		(*_raiz)->empleado->infoEmpleado->codigo_empleado = empleado->infoEmpleado->codigo_empleado;
		(*_raiz)->hijo_der = NULL;
		(*_raiz)->hijo_izq = NULL;
		return;
	}

	if (empleado->infoEmpleado->codigo_empleado < (*_raiz)->empleado->infoEmpleado->codigo_empleado)
	{
		insertarNodo(&(*_raiz)->hijo_izq, empleado);
	}
	else if(empleado->infoEmpleado->codigo_empleado > (*_raiz)->empleado->infoEmpleado->codigo_empleado){
		insertarNodo(&(*_raiz)->hijo_der, empleado);	
	}
}

void imprimir(raiz _raiz)
{
	if (_raiz != NULL)
	{
		imprimir(_raiz->hijo_izq);
		printf("%d\n", _raiz->empleado->infoEmpleado->codigo_empleado);
		imprimir(_raiz->hijo_der);
	}
}

void agregarListaArbol(struct ListaEmpleados* listaEmpleados, raiz *_raiz)
{
	struct Empleado *nodo_temporal = listaEmpleados->inicio_lista;

	while(nodo_temporal != NULL)
	{
		insertarNodo(_raiz, nodo_temporal);
		nodo_temporal = nodo_temporal->siguiente;
	}
}
