/*Nomes : Saulo Ricardo Dias Fernandes                Matrícula : 0021581*/

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct nodo
{
	float valor;
	struct nodo *prox;
};

struct lista
{
	int tam;
	struct nodo *inicio;
};

Lista criaLista(void)
{
	Lista l = (Lista) malloc(sizeof(struct lista));
	l->tam = 0;
	l->inicio = NULL;
	return l;
};

Lista destroiLista(Lista l)
{
	while(!vaziaLista(l))
	{
		retiraLista(l,1);
	}
	free(l);
	return NULL;
}

void insereNaLista(Lista l, float valor)
{
	Nodo aux = (Nodo) malloc(sizeof(struct nodo));
	aux->valor = valor;
	if(l->tam == 0)
	{
		aux->prox = NULL;
		l->inicio = aux;
		l->tam++;
		return;
	}
	Nodo ant = l->inicio;
  while(ant->prox != NULL)
  {
  	ant = ant->prox;
  }
  aux->prox = NULL;
  ant->prox = aux;
  l->tam++;
  return;
}

void insereInicioLista(Lista l, float valor)
{
	Nodo aux = (Nodo) malloc(sizeof(struct nodo));
	aux->valor = valor;
	if(l->tam == 0)
	{
		aux->prox = NULL;
		l->inicio = aux;
		l->tam++;
		return;
	}
	aux->prox = l->inicio;
	l->inicio = aux;
	l->tam++;
	return;
}

void retiraLista(Lista l, int pos)
{
	Nodo aux, tirar;
	if(l->tam == 0)
	{
		return;
	}
	if(pos == 1)
	{
		tirar = l->inicio;
		aux = tirar->prox;
		l->inicio = aux;
		free(tirar);
		l->tam--;
		return;
	}
	if(pos >= l->tam)
	{
		tirar = l->inicio;
		aux = NULL;
		while(tirar->prox != NULL)
  	{
  		aux = tirar;
  		tirar = tirar->prox;
  	}
  	free(tirar);
  	aux->prox = NULL;
  	l->tam--;
  	return;
	}
	aux = NULL;
	for(tirar = l->inicio; pos != 1; tirar = tirar->prox)
	{
		aux = tirar;
		pos--;
	}
	aux->prox = tirar->prox;
	free(tirar);
	l->tam--;
	return;
}

int vaziaLista(Lista l)
{
	return(l->inicio == NULL);
}

void printaLista(Lista l)
{
	Nodo aux;
	for(aux = l->inicio; aux != NULL; aux = aux->prox)
	{
		if(aux->prox == NULL)
		{
			printf("%.0f", aux->valor);
		}	
		else
		{
			printf("%.0f -> ", aux->valor);
		}
	}
	printf("\n");
}

void mudaValorLista(Lista l, int pos, float valor)
{
	if(vaziaLista(l))
		return;
	Nodo aux;
	for(aux = l->inicio; pos != 1; aux = aux->prox)
	{
		pos--;
	}	
	aux->valor = valor;
	return;
}

int existeNaLista(Lista l, float valor)
{
	if(vaziaLista(l))
		return 0;
	Nodo aux;
	for(aux = l->inicio; aux != NULL; aux = aux->prox)
	{
		if(aux->valor == valor)
			return aux->valor;
	}
	return 0;
}

float pegaMenorValor(Lista l)
{
	if(vaziaLista(l))
		return 99999;
	Nodo aux;
	float menor = 9999;
	for(aux = l->inicio; aux != NULL; aux = aux->prox)
	{
		if(aux->valor < menor)
		{
			menor = aux->valor;
		}
	}
	return menor;
}

int tamanhoLista(Lista l)
{
	return(l->tam);
}