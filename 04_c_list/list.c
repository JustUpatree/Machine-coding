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

void push(List *list, int push_value)
{
    if(list->size == list->capacity)
    {
        list->capacity *= 2;
        list->data = realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size] = push_value;
    list->size++;
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

int remove_from_list(List *list, int remove_index_value)
{
    if(remove_index_value < 0 || remove_index_value >= list->size)
    {
        return 0;
    }
    for(int i = remove_index_value; i < list->size - 1; i++)
    {
        list->data[i] = list->data[i + 1];
    }
    list->size--;
    return 1;
}

int insert_in_list(List *list, int insert_index, int insert_value)
{
    if(insert_index > list->size || insert_index < 0)
    {
        return 0;
    }
    if(list->size == list->capacity)
    {
        list->capacity *= 2;
        list->data = realloc(list->data, list->capacity * sizeof(int));
    }
    list->size++;
    for(int i = list->size; i > insert_index; i--)
    {
        list->data[i] = list->data[i - 1];
    }
    list->data[insert_index] = insert_value;
    return 1;
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