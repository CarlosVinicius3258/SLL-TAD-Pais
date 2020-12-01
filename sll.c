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
    l->cur = NULL;
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
void *sllQuery(SLList *l, void *key, int (*cmp)(void*, void*))
{

  SLNode *spec =NULL;
  
  if(l != NULL)
  {
    if(l->first!=NULL)
    {
      spec = l->first;
      while(spec->next != NULL && cmp(key, spec->data) != TRUE){
        spec = spec->next;
      }
      if(cmp(key, spec->data) == TRUE)
      {
          return spec->data;
      }
    }
  }
  return NULL; 
}


void *sllRemove( SLList *l, void *key, int (*cmp)(void*, void*))
{
  SLNode *spec,*prev = NULL;
  void* data;

  if(l != NULL)
  {
    if(l->first != NULL)
    {
      spec = l->first;
      prev = NULL;
      while(spec->next != NULL && cmp(key, spec->data) != TRUE){
        prev = spec;
        spec = spec->next;
        
      }

      if(cmp(key,spec->data) == TRUE){
        data = spec->data;
        if(spec == l->first){
          l->first = spec->next;
        }else{
          prev->next = spec->next;
        }
        free(spec);
          return data;
      }
    }
  return NULL;
  }

}

void* sllgetFirst(SLList *l)
{
  SLNode *first = NULL;
  void* data = NULL;
  if(l != NULL)
  {
    if(l->first!=NULL)
    {
     first = l->first;
     l->cur = first;
     data = first->data;
     return data;
    }
  }
  return NULL;
}


void *sllgetNext(SLList *l)
{
  SLNode *next;
  void* data = NULL;
  if(l != NULL)
  {
    if(l->first!=NULL)
    {
      next = l->cur->next;
      if(l->cur->next!=NULL){
        l->cur = next;
        data = next->data;
        return data;
      }
    }
  }
  return NULL;
}

void* SLLGetData(SLList *l){
  void* data = NULL;
  if(l!=NULL){
    data = l->cur->data;

    return data;
  }
  return NULL;
}