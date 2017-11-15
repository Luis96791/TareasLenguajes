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

//void inOrdenRec(raiz _raiz)
//{
// 	if (_raiz != NULL)
// 	{
// 		inOrdenRec(_raiz->hijo_izq);
// 		printf("%d\n", _raiz->numero);
// 		inOrdenRec(_raiz->hijo_der);
// 	}
// }

void inOrden(raiz _raiz)
{
	raiz actual, siguiente;

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
			siguiente = actual->hijo_izq;

			while(siguiente->hijo_der != NULL && siguiente->hijo_der != actual)
			{
				siguiente = siguiente->hijo_der;
			}

			if (siguiente->hijo_der == NULL)
			{
				siguiente->hijo_der = actual;
				actual = actual->hijo_izq;
			}
			else{
				siguiente->hijo_der = NULL;
				printf("%d\n", actual->numero);
				actual = actual->hijo_der;
			}
		}
	}
}



int main(int argc, char const *argv[])
{
	raiz _raiz = NULL;

	insertarNodo(&_raiz, 100);
	insertarNodo(&_raiz, 50);
	insertarNodo(&_raiz, 150);
	insertarNodo(&_raiz, 25);
	insertarNodo(&_raiz, 90);
	insertarNodo(&_raiz, 125);
	insertarNodo(&_raiz, 190);
	insertarNodo(&_raiz, 12);
	insertarNodo(&_raiz, 40);
	insertarNodo(&_raiz, 60);
	insertarNodo(&_raiz, 95);
	insertarNodo(&_raiz, 110);
	insertarNodo(&_raiz, 140);
	insertarNodo(&_raiz, 160);
	insertarNodo(&_raiz, 200);
	insertarNodo(&_raiz, 5);	
	insertarNodo(&_raiz, 20);	
	insertarNodo(&_raiz, 30);	
	insertarNodo(&_raiz, 45);	
	insertarNodo(&_raiz, 55);	
	insertarNodo(&_raiz, 70);	
	insertarNodo(&_raiz, 92);	
	insertarNodo(&_raiz, 96);

	inOrden(_raiz);

	return 0;
}
