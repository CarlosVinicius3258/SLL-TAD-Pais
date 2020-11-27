#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"
#include "sll.h"

#define TRUE 1
#define FALSE 0

SLList* mundo = NULL;
Pais* pais = NULL;
//----------------OPCOES---------------\\


//1.Funda um pais dentro do mundo
void fundarPais(){
  
  if(mundo==NULL){
  

    printf("\n\t\t\tMundo Criado!!\t\t\t");
    //Criar mundo
    mundo = sllCreate();
     //Adicionar pais ao mundo
  } 

     char nome[30];
     int idade;
     float idh;
     printf("\t\t\t --- Informacoes de pais ---\n");
     printf("\t\t\tNome do pais: ");
     scanf("%s", nome);

     printf("\t\t\tIdade do pais: ");
     scanf("%d", &idade);

     printf("\t\t\tIDH do pais: ");
     scanf("%f", &idh);

     //Fundar pais
     pais = criarPais(nome,idade,idh);

     if(pais!=NULL){
       if(sllInsertFirst(mundo, pais)){
         printf("\n\t\t\tParabéns!! Pais fundado.\n");
       }else{
       printf("\n\t\t\tErro! Tente novamente.\n");
     }

   }else{
     printf("\n\t\t\tErro! Tente novamente.\n");
   } 
   
}

//2. Lista as informações dos paises no mundo
void listarPaises(){
  if(mundo!=NULL){
    pais = sllgetFirst(mundo);

    while(pais!=NULL){
        printf("\n\t\t\t -- PAIS -- \n");
        printf("\t\t\t NOME:  %s\n", pegarNome(pais));
        printf("\t\t\t IDADE:  %d\n", pegarIdade(pais));
        printf("\t\t\t IDH: %f \n\n", pegarIdh(pais));
        
        pais = sllgetNext(mundo); 
    }
  }else{
    printf("\n\t\t\tPRIMEIRO FUNDA ALGUNS PAISES PARA SABER QUAIS EXISTEM. \n");
  }
  
}


//3.Busca paises fundados no mundo

void buscarPais(){
  if (mundo!=NULL){
    char nome[30];
    int idade;
    float idh;

     printf("\t\t\t --- INFORMACOES DO PAIS ---\n");
     printf("\t\t\tNOME DO PAIS: ");
     scanf("%s", nome);

     printf("\t\t\tIDADE DO PAIS: ");
     scanf("%d", &idade);

     printf("\t\t\tIDH DO PAIS: ");
     scanf("%f", &idh);

     pais = criarPais(nome,idade,idh);

     if(pais!=NULL){
       if(colBuscar(mundo, pais, cmpPais) != NULL){
         printf("\n\t\t\t PAIS RECONHECIDO!!\n");
       }else{
         printf("\t\t\t PAIS NAO ENCONTRADO. TENTE NOVAMENTE\n");
       }
     }else{
       printf("\t\t\t ERRO NA INSERCAO DE DADOS.\n\t\t\t TENTE NOVAMENTE\n");
     }
  }else{
    printf("\t\t\t PRIMEIRO FUNDE UM PAIS PARA PROCURAR POR UM.\n\t\t\t TENTE NOVAMENTE.\n");
  }
}

//4. Destruir pais

void destruirPais(){
  if (mundo!=NULL){
    char nome[30];
    int idade;
    float idh;
     printf("\t\t\t --- MODO DESTRUICAO ATIVADA ---\n");
     printf("\t\t\t --- INFORMACOES DO PAIS ---\n");
     printf("\t\t\tNOME DO PAIS: ");
     scanf("%s", nome);

     printf("\t\t\tIDADE DO PAIS: ");
     scanf("%d", &idade);

     printf("\t\t\tIDH DO PAIS: ");
     scanf("%f", &idh);

     pais = criarPais(nome,idade,idh);

     if(pais!=NULL){
       if(colRemover(mundo, pais, cmpPais)!=NULL){
         printf("\n\t\t\tPAIS DESTRUIDO!!\n\n");
       if(!colPegarPrimeiro(mundo)){
         int op;

         printf("\t\t\t Você não tem mais paises no seu mundo. Deseja destrui-lo?\n\t\t\t1. SIM\n \t\t\t2. NAO\n\t\t\tOpcao:");
         scanf("%d", &op);

         if(op==1){
           colDestruir(mundo);
           mundo = NULL;
           
           printf("\n\t\t\tUma grande praga assolou seu mundo! Você está no espaço, volte\n");
           printf("\t\t\t Crie outro para reinar sobre a Terra\n");
         }
         else{
           printf("\t\t\t Bem...Crie novos paises e aproveite seu reinado!!\n");
         }
       }
       }else{
         printf("\t\t\t PAIS NAO ENCONTRADO. TENTE NOVAMENTE\n");
       }
     }else{
       printf("\t\t\t ERRO NA INSERCAO DE DADOS.\n\t\t\t TENTE NOVAMENTE\n");
     }
  }else{
    printf("\t\t\t PRIMEIRO FUNDE UM PAIS PARA DESTRUI-LO.\n\t\t\t TENTE NOVAMENTE.\n");
  }
}

void sair(){
  system("clear");
  printf("\n\t\t\t-----------------*---------------\n");
  printf("\t\t\t------------- BYE BYE --------");
  printf("\n\t\t\t-----------------*---------------\n");
  system("exit");
}
//X. Destruir Mundo
/*void destruirMundo(){
  system("clear");
          if(mundo!=NULL){
            int opcao = 0;
            printf("\n\t\t\t-----------------*---------------\n");
            printf("\t\t\t-----Bomba Atomica / COVID 19 ----\n");
            printf("\n\t\t\t-----------------*---------------\n");
            printf("\n\t\t\t1.Covid 19\n");
            printf("\t\t\t2.Bomba atomica\n");
            scanf("%d", &opcao);
          if(opcao==1){
            printf("\n\t\t\tVocê foi o ultimo sobrevivente, reconstrua-o e destrua-o novamente\n");
            colDestruir(mundo);
          }else if(opcao==2){
            printf("\n\t\t\tDestruicao sucedida!! Voce dizimou seu mundo com maestria. Seu imperio nasce.\n");
            colDestruir(mundo);
          }else{
            printf("Arregou?");
          }
          
          }else{
            printf("\n\t\t\tNAO HA PAISES PARA SEREM DESTRUIDOS!!\n");
          }
}
*/
//5. Sair do programa
