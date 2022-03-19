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
    if (!list->head) return NULL;
    list->current=list->head;

    return list->head->data;
}

void * nextList(List * list)
{
    if (!list->current || !list->current->next ) return NULL;
    list->current = list->current->next;
 
    return list->current->data;
}

void * lastList(List * list) 
{
    if (!list->tail) return NULL;
    list->current = list->tail;
    return list->tail->data;


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
    nodoNuevo->next = list->head;
    if(list->tail == NULL)
        list->tail = nodoNuevo;
    list->head = nodoNuevo;
    nodoNuevo->prev = NULL;
}



void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) 
{
    Node * nodo2 = createNode(data);
    Node * x = createNode(data);
    if (list->current);
    if (list->current == list->head)
    {

        if (list->current->next)
        {
            x=list->current->next;
            list->current->next=nodo2;
            nodo2->next= x;
            nodo2->prev=list->head; 
        }

    }




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