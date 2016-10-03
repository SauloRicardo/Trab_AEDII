#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "Open_Hash.h"

int main()
{
	Palavra *tabela;
	tabela = cria_hash();
	insere_hash(tabela, "sa");
	insere_hash(tabela, "arthur");
	insere_hash(tabela, "wesley");

	printf("%s\n", busca_hash(tabela, "sa"));
	printf("%s\n", busca_hash(tabela, "arthur"));
	printf("%s\n", busca_hash(tabela, "wesley"));

	return 0;
}
