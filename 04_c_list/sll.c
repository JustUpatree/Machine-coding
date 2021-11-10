#include "sll.h"

#include <stdio.h>
#include <stdlib.h>

List new_list()
{
    List list;
    return list;
}

void print_list(List *list)
{
    if(list->head == NULL)
    {
        printf("Empty\n");
    }
    else
    {
        for(Node *exmp = list->head; exmp != NULL; exmp = exmp->next)
        {
            printf("%d", exmp->data);
            if(exmp->next == NULL)
            {
                printf("\n");
            }
            else
            {
                printf(", ");
            }
        }
    }
}

void push(List *list, int push_value)
{
    Node *node = malloc(sizeof(Node));
    node->data = push_value;
    node->next = NULL;
    if(list->head == NULL)
    {
        list->head = node;
    }
    else
    {
        Node *s_node = list->head;
        while(s_node->next != NULL)
        {
            s_node = s_node->next;
        }
        s_node->next = node;
    }
}

int pop(List *list)
{
    if(list->head == NULL)
    {
        return 0;
    }
    if(list->head->next == NULL)
    {
        list->head = NULL;
        return 1;
    }
    Node *s_node = list->head;
    while(s_node->next->next != NULL)
    {
        s_node = s_node->next;    
    }
    free(s_node->next);
    s_node->next = NULL;
    return 1;
}

int remove_from_list(List *list, int remove_index_value)
{
    return 1;
}

int insert_in_list(List *list, int insert_index, int insert_value)
{
    return 1;
}

void delete_list(List *list)
{
}