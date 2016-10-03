#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "lista.h"
#include "Open_Hash.h"

static int vet_rand[32];

int func_hash(char* pala)
{
	int i;
	unsigned long int x=0;
	for(i=0; i<strlen(pala); i++)
	{
		x = x + (pala[i]*vet_rand[i]);
	}
	return x % tam_hash;
}

void insere_hash(Palavra *Tab_Hash, char* pala)
{
	int i = 0;
	int pos = func_hash(pala);
	int posicoes = 0;
	while(posicoes != tam_hash && Tab_Hash[pos] != NULL )
	{
		pos = (pos+1) % tam_hash;
		posicoes++;
	}
	if(posicoes == tam_hash)
		return;
	Palavra inserir = (Palavra) malloc(sizeof(struct palavra));
	Tab_Hash[pos] = inserir;
	strcpy(Tab_Hash[pos]->pal, pala);
	Tab_Hash[pos]->pag = criaLista();
	return;
}

char* busca_hash(Palavra *Tab_Hash, char* pala)
{
	int i = 0;
	int pos = func_hash(pala);
	int posicoes = 0;
	while(posicoes != tam_hash && Tab_Hash[i] != NULL )
	{
		pos = (pos+1) % tam_hash;
		posicoes++;
	}
	if(posicoes == tam_hash)
		return NULL;
	
	return Tab_Hash[pos]->pal;
}

Palavra* cria_hash()
{
	srand(time(NULL));
	int i;
	Palavra *Tab_Hash = (Palavra*) malloc(sizeof(Palavra)*tam_hash);
	for (i = 0; i < tam_hash; i++)
	{
		Tab_Hash[i] = NULL;
	}

	for(i=0; i<32; i++)
	{
		vet_rand[i] = rand();
	}

	return Tab_Hash;
}

void destroi_hash(Palavra *Tab_Hash)
{
	free(Tab_Hash);
}