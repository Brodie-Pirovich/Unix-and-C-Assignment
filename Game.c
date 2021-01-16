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
    printf("Simon stays in normal pose\n\n");
}

void Dance()
{
    printf("Simon dances\n\n");
}

void HandsOnHead()
{
    printf("Simon puts hands on head\n\n");
}

void LeftHandUp()
{
    printf("Simon puts left hand up\n\n");
}

void RightHandUp()
{
    printf("Simon puts right hand up\n\n");
}