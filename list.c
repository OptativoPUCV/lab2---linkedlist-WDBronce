#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) 
{
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() 
{
  List* Lista = (List*)malloc(sizeof(List));
  if (Lista == NULL) 
  {
    printf("Error: No se pudo asignar memoria para la lista.\n");
    return 0;
  }
  // Lista->head = NULL;
  // Lista->tail = NULL;
  return Lista;
}

void * firstList(List * list) 
{
  if (list== NULL || list->current == NULL )
  {
    return NULL;
  }
  if (list->head == NULL)
  {
    return NULL;  
  }
  list->current = list->head;
  return list->current->data;
}

void * nextList(List * list) 
{
  if (list== NULL || list->current == NULL )
  {
    return NULL;
  }
  if (list->current->next == NULL)
  {
    return NULL;
  }
 
  list->current = list->current->next;
  return list->current->data;
    
}

void * lastList(List * list) 
/*La primera retorna el dato del último elemento en la lista y actualiza el current al nodo correspondiente. */
{
  if (list== NULL || list->current == NULL )
  {
    return NULL;
  }
  if (list->tail == NULL)
  {
    return NULL;  
  }
  list->current = list->tail;
  
    return list->tail->data;
}

void * prevList(List * list) 
/*La segunda función retorna el dato del nodo anterior a current y actualiza el current para que apunte a ese nodo.*/
{
  if (list== NULL || list->current == NULL )
  {
    return NULL;
  }
  if (list->current->prev == NULL)
  {
    return NULL;
  }
 
  list->current = list->current->prev;
  return list->current->data;
}

void pushFront(List * list, void * data) 
/*Programe la función `void pushFront(List * list, void * data)`, la cual agrega un dato al comienzo de la lista. 
> Puede utilizar la función `Node* createNode(void * data)` la cual crea, incializa y retorna un nodo con el dato correspondiente. */
{
  Node* NuevoNodo = createNode(data);
  if (list->head == NULL)
  {
    list->head = NuevoNodo;
    list->tail = NuevoNodo;
  }
  NuevoNodo->next = list->head;
  NuevoNodo->prev = NULL;
  list->head = NuevoNodo;
}

void pushBack(List * list, void * data) 
{
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) 
/*Programe la función `void pushCurrent(List * list, void* data)`, la cual agrega un dato a continuación del nodo apuntado por `list->current`.*/
{
  if (list== NULL || list->current == NULL )
  {
    return;
  }
  Node* NuevoNodo = createNode(data);
  if(list->current->next == NULL)
  {
    list->current->next = NuevoNodo;
    NuevoNodo->prev = list->current;
    list->tail = NuevoNodo;
  }
  else
  {
    NuevoNodo->next = list->current->next;
    list->current->next->prev = NuevoNodo;
    list->current->next = NuevoNodo;
    NuevoNodo->prev = list->current;
  }
  
}

void * popFront(List * list) 
{
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) 
{
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) 
/*6. Programe la función `void* popCurrent(List * list)`, la cual elimina el nodo que está en la posición del current de la lista enlazada, y además retorna el **dato** del nodo eliminado.
> **Nota**: El current debe quedar apuntando al nodo siguiente del eliminado.

Las funciones `pushBack`, `popFront` y `popBack` se pueden implementar usando `popCurrent` y `pushCurrent` (búsquelas en el código).*/
{
  if (list== NULL || list->current == NULL )
  {
    return NULL;
  }
  void* dato = list->current->data;
  if (list->current->next != NULL && list->current->prev != NULL)
  {
    list->current->next->prev = list->current->prev;
    list->current->prev->next = list->current->next;
    list->current->next = NULL;
    list->current->prev = NULL;
    printf("paso el if 1");
  }
  if (list->current == list->head)
  {
    list->current->next->prev = list->current->prev;
    list->current->next = NULL;
    printf("paso el if 2");
  }
  if (list->current == list->tail)
  {
    list->current->prev->next = list->current->next;
    list->current->prev = NULL;
    printf("paso el if 3");
  }
  printf("%d",(*(int*)list->head->data));
 /* if (list->current->next == NULL && list->current->prev == NULL)
  {
    free(list->current);
  }*/
  return dato;
}

void cleanList(List * list) 
{
    while (list->head != NULL) 
    {
        popFront(list);
    }
}