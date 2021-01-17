#include "Menu.h"
#include "LInkedList.h"
#include "Game.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu(list_t* list)
{
    char fileName[10];

    int option = 0;
    printf("\nMenu!");

    while(option != 6)
    {
        printf("\nPlease select an option: \n");
        printf("1: Give commands\n2: Load commands\n3: Delete Commands\n4: Play a game\n5: Print commands\n6: Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            GiveCommands(list);
            break;

        case 2:
            printf("Enter a file name! \n");
            scanf("%s", fileName);
            LoadCommands(list, fileName);
            break;

        case 3:
            DeleteCommands(list);
            break;

        case 4:
            PlayGame(list);
            break;

        case 5:
            printList(list);
            break;
        
        default:
            break;
        } 
    }  

    Exit();
}

void GiveCommands(list_t* list)
{
    int amount;
    int simon;

    printf("Please type an amount of commands to give: \n");
    scanf("%d", &amount);

    for(int i = 0; i < amount; i++)
    {   
        printf("Type 1 for a simon says and 2 for a simon didn't say: \n");
        scanf("%d", &simon);

        if(simon == 1)
        {
            command_t* tempCommand = createCommand();
            strcpy(tempCommand->Simon, "Simon Says");

            AssignCommand(tempCommand);
            addToList(list, *tempCommand);

        }
        else if(simon == 2)
        {
            command_t* tempCommand = createCommand();
            strcpy(tempCommand->Simon, "Simon Didn't Say");

            AssignCommand(tempCommand);
            tempCommand->cmdFunc = Didnt;
            addToList(list, *tempCommand);
        }
        else
        {
            printf("Please type either 1 or 2\n");
        }
    }
    printf("Commands given!\n");
}

void AssignCommand(command_t* cmd)
{
    int option;
    printf("Please select a valid simon says command: \n");
    printf("1:Hands on head\n2: Dance\n3: Right hand up\n4: Left hand up\n");
    scanf("%d", &option);

    switch (option)
    {
        case 1:
            strcpy(cmd->SimonCommand, "hands on head");
            cmd->cmdFunc = HandsOnHead;
            break;
        case 2:
            strcpy(cmd->SimonCommand, "Dance");
            cmd->cmdFunc = Dance;
            break;
        case 3:
            strcpy(cmd->SimonCommand, "Right hand up");
            cmd->cmdFunc = RightHandUp;
            break;
        case 4:
            strcpy(cmd->SimonCommand, "Left hand up");
            cmd->cmdFunc = LeftHandUp;
            break;
        default:
            break;
    }
}

void LoadCommands(list_t* list, char* fileName)
{
    char line[MAX_LENGTH];
    char wordOne[6];
    char wordTwo[9];
    char restOfString[MAX_LENGTH];
    char wordThree[6];
    char command[20];
    char says[6] = "says";
    char word[5];
    char dance[5] = "Dance";
    char hand[5] = "Hands";
    char left[5] = "Left";
    char right[6] = "Right";

    FILE *file = fopen(fileName, "r");

    while(fgets(line, 256, file) != NULL)
    {
        sscanf(line, "%5s %8s %255[^\n]", wordOne, wordTwo, restOfString);

        if(strcmp(wordTwo, says) == 0)
        {
            sscanf(restOfString, " %5s %255[^\n]", word, command);
            command_t* tempCommand = createCommand();
            strcpy(tempCommand->Simon, "Simon Says");
            if(strcmp(dance, word) == 0)
            {
                tempCommand->cmdFunc = Dance;
                printf("Dance match\n");
            }
            else if (strcmp(hand, word) == 0)
            {
                tempCommand->cmdFunc = HandsOnHead;
                printf("Hand match\n");
            }
            else if (strcmp(left, word) == 0)
            {
                tempCommand->cmdFunc = LeftHandUp;
                printf("Left match\n");
            }
            else if (strcmp(right, word) == 0)
            {
                tempCommand->cmdFunc = RightHandUp;
                printf("Right match\n");
            }
            else
            {
                printf("No match\n");
            }  
            strcpy(word, strcat(word, " "));
            strcpy(tempCommand->SimonCommand, strcat(word ,command));          
            addToList(list, *tempCommand);
        }
        else
        {
            sscanf(restOfString, "%5s %255[^\n]", wordThree, command);
            command_t* tempCommand = createCommand();
            strcpy(tempCommand->Simon, "Simon Didn't Say");
            strcpy(tempCommand->SimonCommand, command);
            tempCommand->cmdFunc = Didnt;
            addToList(list, *tempCommand);
        } 
    }
    fclose(file);
    printf("Commands loaded!\n");
}

void DeleteCommands(list_t* list)
{
    int amount;
    printf("Enter amount of commands to delete!\n");
    scanf("%d", &amount);

    printf("%d commands are to be deleted!\n", amount);

    for(int i = 0; i < amount; i++)
    {
        deleteFromList(list);
    }
}

void Exit()
{
    printf("\nSee you later :) \n");
}