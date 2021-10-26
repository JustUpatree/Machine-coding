#ifndef LIST_H
#define LIST_H

typedef struct 
{
    int size;
    int *data;
} List;

void print_list(List *list);
int push(List *list, int push_value);
int pop(List *list);

extern const int LIST_CAPACITY;

#endif
