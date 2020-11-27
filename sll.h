#ifndef SLL_H
#define SLL_H

#define TRUE 1
#define FALSE 0


typedef struct _SLNode_ SLNode;
typedef struct _SLList_ SLList;

SLList *sllCreate();

int sllInsertFirst(SLList *l, void *data);

void* sllRemoveFirst(SLList *l);

int sllDestroy(SLList *l);

void *sllFind(SLList *l, void *key, int (*cmp)(void*, void*));

void *sllRemove( SLList *l, void *key, int (*cmp)(void*, void*));

void *sllgetFirst(SLList *l);

void *sllgetNext(SLList *l);

#endif