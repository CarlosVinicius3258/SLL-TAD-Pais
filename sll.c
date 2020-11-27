#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pais.h"
#include "sll.h"

typedef struct _SLNode_ 
{
  struct _SLNode_ *next;
  void* data;
} SLNode;

typedef struct _SLList_ 
{
  SLNode *first;
  SLNode *cur;
} SLList;

//Cria uma coleção
SLList *sllCreate()
{
  SLList *l;
  l = (SLList *) malloc(sizeof(SLList));
  if(l!=NULL)
  {
    l->first = NULL;
    return l;
    }
    return NULL;
}

//Adiciona um item na coleção
int sllInsertFirst(SLList *l, void *data)
{
  SLNode *newNode = NULL;
  
  if(l != NULL)
  {
    newNode = (SLNode*) malloc(sizeof(SLNode));
    if(newNode!=NULL)
    {
      newNode->data = data;
      if(l->first == NULL){
        newNode->next = NULL;
      }else{
        newNode->next = l->first;
      }
      l->first = newNode;
      return TRUE;
    }
  }
  return FALSE;
}

void* sllRemoveFirst(SLList *l){
  void *data;
  SLNode *first = NULL;
  if(l!=NULL){
    if(l->first!=NULL){
      first = l->first;
      data = first->data;
      l->first = first->next;
      free(first);
      return data;
    }
  }
  return NULL;
}

int sllDestroy(SLList *l){
  if(l!=NULL){
    if(l->first == NULL){
       free(l);
    return TRUE;
    }
  }
  return FALSE;
}

//Encontra um item na coleção
void *sllFind(SLList *l, void *key, int (*cmp)(void*, void*))
{

  SLNode *spec =NULL;
  
  if(l != NULL)
  {
    if(l->first!=NULL)
    {
      spec = l->first;
      while(spec->next != NULL && cmp(key, spec) != TRUE){
        spec = spec->next;
      }
      if(cmp(key, spec) == TRUE)
      {
          return spec->data;
      }
    }
  }
  return NULL; 
}


void *sllRemove( SLList *l, void *key, int (*cmp)(void*, void*))
{
  int count,count2 = 0;
  SLNode *spec,*prev = NULL;
  void* data;

  if(l != NULL)
  {
    if(l->first != NULL)
    {
      spec, prev = l->first;
      while(spec != NULL && cmp(key, spec) != TRUE){
        spec = spec->next;
        count++;
      }

      if(cmp(key,spec) == TRUE){
        while(count2 < count){
          prev = prev->next;
          count2++;
        }
        data = spec->data;
        prev->next = spec->next;
        free(spec);
        return data;
      }
    }
  return NULL;
  }

}

void *sllgetFirst(SLList *l)
{
  SLNode *first = NULL;
  if(l != NULL)
  {
    if(l->first!=NULL)
    {
     first = l->first;
     l->cur = first;
     return l->cur;
    }
  }
  return NULL;
}


void *sllgetNext(SLList *l)
{
  SLNode *next;
  if(l != NULL)
  {
    if(l->first!=NULL)
    {
      if(l->cur->next!=NULL){
        next = l->cur->next;
        l->cur = next;
        return l->cur;
      }
    }
  }
  return NULL;
}