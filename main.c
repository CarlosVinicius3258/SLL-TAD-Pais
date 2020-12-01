#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"
#include "sll.h"
#include "function.h"

#define TRUE 1
#define FALSE 0


int main(void){
  int op = 0;

  do{
      printf("\n\t\t\t-----------------*---------------\n");
      printf("\t\t\t---------- Colecao Pais ---------");
      printf("\n\t\t\t-----------------*---------------\n");
      
      printf("\t\t\t1. Fundar Pais\n");
      printf("\t\t\t2. Listar Paises\n");
      printf("\t\t\t3. Buscar Pais\n");
      printf("\t\t\t4. Destruir Pais\n");
      printf("\t\t\t5. Sair\n");
      printf("\t\t\tOpção: ");  
      scanf("%d", &op);

      switch(op){
        case 1:
          fundarPais();
          break;
        case 2:
          listarPaises();
          break; 
        case 3:
          buscarPais();
        break;
        case 4: 
          destruirPais();
        break;
        case 5:
          sair(); 
          break;

        default:
          system("clear");
          printf("\n\t\t\t-----------------*---------------\n");
          printf("\t\t\t------------ OPCAO INVALIDA -------\n");
          printf("\n\t\t\t-----------------*---------------\n");
          break;

      }
    }while(op!=5);
 



  return 0;
}



