#include "list.h"

#include <stdlib.h>
#include <stdio.h>



const int DEFAULT_LIST_CAPACITY = 10;    

void print_list(List *list) 
{
    if(list->size != 0)
    {
        for(int i = 0; i < list->size; i++)
        {
            printf("%d", list->data[i]);
            if(i + 1 != list->size)
            {
                printf(", ");
            }
            else
            {
                printf("\n");
            }
        }
    }
    else
    {
        printf("Empty\n");
    }
}

int push(List *list, int push_value)
{
    int is_success;
    if(list->size < list->capacity)
    {
        list->data[list->size] = push_value;
        list->size++;
        is_success = 1;
    }
    else
    {
        is_success = 0;
    }
    return is_success;
}

int pop(List *list)
{
    int is_success;
    if(list->size != 0)
    {
        list->size--;
        is_success = 1;
    }
    else
    {
        is_success = 0;
    }
    return is_success;
}

List new_list()
{
    List list;
    list.size = 0;
    list.capacity = DEFAULT_LIST_CAPACITY;
    list.data = malloc(list.capacity * sizeof(int));
    return list; 
}

void delete_list(List *list)
{
    free(list->data);
}