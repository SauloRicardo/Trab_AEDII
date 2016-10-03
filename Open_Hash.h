#ifndef Teste_Hash
#define Teste_Hash

struct palavra
{
	char pal[33];
	Lista pag;
};

typedef struct palavra *Palavra;

#define tam_hash 100
typedef Palavra Tab_Hash[tam_hash];

int func_hash(char* x);
void insere_hash(Palavra *Tab_Hash, char* pala);
char* busca_hash(Palavra *Tab_Hash, char* pala);
Palavra* cria_hash();
void destroi_hash(Palavra *Tab_Hash);

#endif