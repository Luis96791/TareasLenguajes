#include <stdio.h>
#include <stdlib.h>


typedef struct Nodo
{
	int numero;
	struct Nodo *hijo_izq, *hijo_der;
} nodoArbol;

typedef nodoArbol *raiz;

void insertarNodo(raiz *_raiz, int numero)
{
	if (*_raiz == NULL)
	{
		*_raiz = malloc(sizeof(nodoArbol));
		(*_raiz)->numero = numero;
		(*_raiz)->hijo_der = NULL;
		(*_raiz)->hijo_izq = NULL;
		return;
	}
	
	if (numero < (*_raiz)->numero)
	{
		insertarNodo(&(*_raiz)->hijo_izq, numero);
	}
	else if(numero > (*_raiz)->numero){
		insertarNodo(&(*_raiz)->hijo_der, numero);	
	}
}

// void inOrden(raiz _raiz)
// {
// 	if (_raiz != NULL)
// 	{
// 		inOrden(_raiz->hijo_izq);
// 		printf("%d\n", _raiz->numero);
// 		inOrden(_raiz->hijo_der);
// 	}
// }

void inOrden(raiz _raiz)
{
	raiz actual, previo;

	if (_raiz == NULL)
	{
		return;
	}

	actual = _raiz;
	while(actual != NULL)
	{
		if (actual->hijo_izq == NULL)
		{
			printf("%d\n", actual->numero);
			actual = actual->hijo_der;
		}
		else{
			previo = actual->hijo_izq;

			while(previo->hijo_der != NULL && previo->hijo_der != actual)
			{
				previo = previo->hijo_der;
			}

			if (previo->hijo_der == NULL)
			{
				previo->hijo_der = actual;
				actual = actual->hijo_izq;
			}
			else{
				previo->hijo_der = NULL;
				printf("%d\n", actual->numero);
				actual = actual->hijo_der;
			}
		}
	}
}



int main(int argc, char const *argv[])
{
	raiz _raiz = NULL;

	insertarNodo(&_raiz, 41);
	insertarNodo(&_raiz, 65);
	insertarNodo(&_raiz, 50);
	insertarNodo(&_raiz, 47);
	insertarNodo(&_raiz, 55);
	insertarNodo(&_raiz, 91);
	insertarNodo(&_raiz, 72);
	insertarNodo(&_raiz, 99);
	insertarNodo(&_raiz, 20);
	insertarNodo(&_raiz, 29);
	insertarNodo(&_raiz, 22);
	insertarNodo(&_raiz, 32);
	insertarNodo(&_raiz, 11);
	insertarNodo(&_raiz, 15);
	insertarNodo(&_raiz, 8);

	inOrden(_raiz);

	return 0;
}
