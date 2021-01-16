#ifndef LIST_H
#define LIST_H

typedef void (*func)();

//a struct for storing a command
typedef struct Command
{
    char Simon[20];
    char SimonCommand[20];
    func cmdFunc;
}command_t;

//a struct for each node of a linked list
typedef struct ListNode
{
    command_t value;
    struct ListNode* next;
}list_node_t;

//a struct for the linked list itself that keeps track of the 
//first command node (head), last command node(tail) and count
typedef struct List
{
    list_node_t* head;
    list_node_t* tail;
    int size;
}list_t;

command_t* createCommand();
list_t* createList();
void printList(list_t* list);
void addToList(list_t* list, command_t command);
void freeList(list_t* list);
void deleteFromList(list_t* list);

#endif
