#ifndef SLL_H
#define SLL_H

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;    
} List;

void print_list(List *list);
void push(List *list, int push_value);
int pop(List *list);
int remove_from_list(List *list, int remove_index_value);
int insert_in_list(List *list, int insert_index, int insert_value);
List new_list();
void delete_list(List *list);

#endif