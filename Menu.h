#include "LInkedList.h"
#define MAX_LENGTH 256

void Menu(list_t* list);
void GiveCommands(list_t* list);
void AssignCommand(command_t* cmd);
void LoadCommands(list_t* list, char* fileName);
void DeleteCommands(list_t* list);
void Exit();