#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Menu.h"
#include "LInkedList.h"

int main(int argc, char *argv[])
{
    char fileName[10];
    if (argc > 1)
    {
        strcpy(fileName, argv[1]);
        list_t* tempList = createList();
        LoadCommands(tempList, fileName);
        Menu(tempList);
    }
    
    list_t* tempList = createList();
    Menu(tempList);

    return 0;
}
