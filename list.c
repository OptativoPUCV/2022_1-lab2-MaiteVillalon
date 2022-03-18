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
    Node * nodo = (Node *)malloc(sizeof(Node));
    nodo->data = data;
    nodo->prev = NULL;
    nodo->next = NULL;
    return nodo;
}

List * createList() 
{
    List * listaNueva = (List *) malloc (sizeof(List));
    listaNueva->head = NULL;
    listaNueva->current = NULL;
    listaNueva->tail = NULL;
    return listaNueva;

}

void * firstList(List * list) 
{
    if (!lista->head) return NULL;
    lista->current=lista->head;

    return lista->head->data;
}

void * nextList(List * list)
{
    if (!lista->current || !lista->current->next ) return NULL;
    lista->current = lista->current->next;
 
    return lista->current->data;
}

void * lastList(List * list) 
{
    if (!lista->prev) return NULL;
    lista->current = lista->prev;
    return list->prev->data;


}

void * prevList(List * list) 
{   
    if (list->head == NULL) return NULL;
    if (list->current == NULL) return NULL;
    if (list->current->prev == NULL) return NULL;

    list->current = list->current->prev;
    return (list->current->data);

}

void pushFront(List * list, void * data) 
{
    Node * nodoNuevo = createNode(data);
    nodoNuevo->next = listaNueva->head;
    if(listaNueva->tail == NULL)
        listaNueva->tail = nodoNuevo;
    listaNueva->head = nodoNuevo;
    nodoNuevo->prev = NULL;
}

}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}