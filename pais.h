#ifndef PAIS_H
#define PAIS_H

#define TRUE 1
#define FALSE 0


typedef struct _pais_ Pais;

Pais *criarPais(char nome[], int idade, float idh);
int cmpPais(void *pais1, void *pasi2);

char *pegarNome(Pais *pais);
int pegarIdade(Pais *pais);
float pegarIdh(Pais *pais);



#endif