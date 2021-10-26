#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

const int LIST_CAPACITY = 10; 
const int BUFFER_SIZE = 32;
const int STDIN = 0;
const int STDOUT = 1;
const char *COMMAND_PREFIX = "> "; 

typedef struct 
{
    int size;
    int *data;
} List;


typedef enum 
{
    CommandDisplay,
    CommandExit,
    CommandNotFound 
} Command;

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

Command parse_command(char *buffer)
{
    Command parameter;
    if(strcmp("display", buffer) == 0)
    {
        parameter = CommandDisplay;
    }
    else if(strcmp("exit", buffer) == 0)
    {
        parameter = CommandExit;
    }
    else
    {
        parameter = CommandNotFound;
    }
    return parameter;
}

int main()
{
    srand(time(NULL));
    List list;
    list.size = 0;
    int list_data[LIST_CAPACITY];
    list.data = list_data;
    while(1)
    {
        printf("%s", COMMAND_PREFIX);
        char buffer[BUFFER_SIZE];
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0'; //remove new line
        Command parse_command_value = parse_command(buffer);
        if(parse_command_value == CommandDisplay)
        {
            print_list(&list);
        } 
        else if(parse_command_value == CommandExit)
        {
            printf("Exiting\n");
            break;
        }
        else
        {
            printf("Command not found: %s\n", buffer);
        }
    }
    return 0;
}