#ifndef COLECAO_H
#define COLECAO_H

#define TRUE 1
#define FALSE 0

typedef struct _colecao_ Colecao;
//-------------------------------------//
//Cria uma coleção
//Pre-condicao: max_items > 0
//Pos-condicao: retorna um ponteiro para uma novo
//TAD Colecao void* vazio*/
Colecao *colCriar(int maxItens);
//-------------------------------------//

//-------------------------------------//
//Adiciona um item na coleção
//Pre-condicao : (c é um TAD Colecao criado por uma chamada a colCriar e (o TAD Colecao nao esta cheio) e (item != NULL)
//Pos-condicao: item foi adicionado ao TAD c
int colInserir(Colecao *c, void *item);
//-------------------------------------//

//-------------------------------------//
//Encontra um item na coleção
//Pre-condicao: (c é um TAD Colecao criado por uma chamada a colCriar) e (key != NULL)
//Pos-condicao: retorna um item identificado por key se ele existir no TAD c, ou return NULL caso contrátrio
void *colBuscar(Colecao *c, void *key, int (*cmp)(void*, void*));
//-------------------------------------//

//-------------------------------------//
//Retira um item da coleção
//Pre-condicao: c é um coleção criada por uma chamada a colCriar existe pelo menos um item na colecao
//Pos-condicao: item foi retirado da colecao
void *colRemover(Colecao *c, void *key, int (*cmp)(void*, void*));
//-------------------------------------//


//-------------------------------------//
//Destrói uma coleção
//Pre-condicao: (c é um TAD Colecao criado por uma chamada a colCriar)
//Pos-condicao: a memoria usada pelo TAD foi liberada
int colDestruir(Colecao *c);
//-------------------------------------//

//-------------------------------------//
//Pega o primeiro elemento da coleção
void *colPegarPrimeiro(Colecao *c);
//-------------------------------------//

//-------------------------------------//
//Pega o proóximo elemento da coleção
void *colPegarProximo(Colecao *c);
//-------------------------------------//

//-------------------------------------//
//Pega o número de elementos adicionados na coleção
int colPegarNumItens(Colecao* c);
//-------------------------------------//

#endif