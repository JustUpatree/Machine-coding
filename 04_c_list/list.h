#ifndef LIST_H
#define LIST_H

typedef struct 
{
    int size;
    int capacity;
    int *data;
} List;

void print_list(List *list);
void push(List *list, int push_value);
int pop(List *list);
List new_list();
void delete_list(List *list);

#endif
