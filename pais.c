#include "pais.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct _pais_{
  char nome[30];
  int idade;
  float idh;

}Pais;
// Compara as variaveis de pais
int cmpPais(void* pais1, void* pais2){

  if(pais1!=NULL && pais2 != NULL){
    char* nome1 = ((Pais*) pais1)->nome;
    int idade1 = ((Pais*) pais1)->idade;
    int idh1 = ((Pais*) pais1)->idh;

    char* nome2 = ((Pais*) pais2)->nome;
    int idade2 = ((Pais*) pais2)->idade;
    int idh2 = ((Pais*) pais2)->idh;

    if( strcmp(nome1,nome2) == 0 && idade1==idade2 & idh1==idh2){
      return TRUE;
    }
  }
  return FALSE; 
}

//Funcao que retorna um pais criado a partir das entradas correspondentes dos atributos
Pais* criarPais(char nome[], int idade, float idh){
  Pais* pais = (Pais*) malloc(sizeof(Pais));
  if(pais!=NULL){
   strcpy(pais->nome, nome);
   pais->idade = idade;
   pais->idh = idh; 

   return pais;
  }
  return NULL;
}

//retorna as variaveis de país-> usada no Listar País
char* pegarNome(Pais* pais){
  if(pais!=NULL){
    return pais->nome;
  }
  return NULL;
}

//Retorna idade do pais
int pegarIdade(Pais* pais){
  if(pais!=NULL){
    return pais->idade;
  }
  return -1;
}

//Retorna idh do país
float pegarIdh(Pais* pais){
  if(pais!=NULL){
    return pais->idh;
  }
  return -1;
}


