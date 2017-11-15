#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
	char* valor;
	struct Nodo *hijo_izq, *hijo_der; 
}nodoArbol;

typedef nodoArbol *raiz;

void insertarNodoRAIZ(raiz *_raiz, char* valor)
{
	if (*_raiz == NULL)
	{
		*_raiz = malloc(sizeof(nodoArbol));
		(*_raiz)->valor = valor;
		(*_raiz)->hijo_der = NULL;
		(*_raiz)->hijo_izq = NULL;
		return;
	}
}

void insertarNodoIzq(raiz *_raiz, char* valor)
{
	
}

void insertarNodoDer(raiz *_raiz, char* valor)
{
	
}


void inOrdenRec(raiz _raiz)
{
 	if (_raiz != NULL)
 	{
 		inOrdenRec(_raiz->hijo_izq);
 		printf("%s\n", _raiz->valor);
 		inOrdenRec(_raiz->hijo_der);
 	}
}

int main(int argc, char const *argv[])
{
	raiz _raiz = NULL;

	insertarNodoRAIZ(&_raiz, "+");
	//insertarNodoIzq(&_raiz, "-");
	//insertarNodoDer(&_raiz, "*");

	inOrdenRec(_raiz);

	return 0;
}

