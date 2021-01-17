#include "Game.h"
#include "LInkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PlayGame(list_t* list)
{
    list_node_t* current;
    for(current = list->head; current != NULL; current = current->next)
    { 
        printf("%s %s\n", current->value.Simon, current->value.SimonCommand);
        current->value.cmdFunc();
    }
}

void Didnt()
{
    printf("\n┏(・o･)┓\n\n");
}

void Dance()
{
    printf("\n┏(・o･)┓\n");
    printf("\n♪┏(・o･)┛♪\n");
    printf("\n┗( ･o･)┓♪\n");
    printf("\n♪┏(・o･)┛♪\n");
    printf("\n┗( ･o･)┓♪\n\n");
}

void HandsOnHead()
{
    printf("\n┏(・o･)┓\n");
    printf("\n┗(・o･)┛\n\n");
}

void LeftHandUp()
{
    printf("\n┏(・o･)┓\n");
    printf("\n┗( ･o･)┓\n\n");
}

void RightHandUp()
{
    printf("\n┏(・o･)┓\n");
    printf("\n┏(・o･)┛\n\n");
}