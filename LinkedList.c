#include "LInkedList.h"
#include <stdlib.h>
#include <stdio.h>

command_t* createCommand()
{
    command_t* newCommand = (command_t*)calloc(1, sizeof(command_t));
    return newCommand;
}

list_t* createList()
{
    list_t* newList = (list_t*)calloc(1, sizeof(list_t));
    return newList;
}

void printList(list_t* list)
{
    printf("\nThe list contents are: \n");
    list_node_t* current;
    for(current = list->head; current != NULL; current = current->next)
    { 
        printf("%s %s\n", current->value.Simon, current->value.SimonCommand);
    }
}

void addToList(list_t* list, command_t car)
{
    list_node_t* newNode = malloc(1*sizeof(list_node_t));
    newNode->value = car;
    newNode->next = list->head;
    list->head = newNode;
    if(list->size == 0)
    {
        list->tail = newNode;
    }
    list->size++;
}

void freeList(list_t* list)
{
    list_node_t* current, *next;
    while(current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

void deleteFromList(list_t* list)
{
    list_node_t* current;
    current = list->head;
    list->head = list->head->next;

    free(current);
    list->size--;
}