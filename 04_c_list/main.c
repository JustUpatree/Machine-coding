#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "list.h"

const int BUFFER_SIZE = 32;
const char *COMMAND_PREFIX = "> "; 

typedef enum 
{
    CommandDisplay,
    CommandExit,
    CommandNotFound,
    CommandPush,
    CommandPop
} CommandType;

typedef struct
{
    CommandType type;
    int push_value;
} Command;

Command parse_command(char *buffer)
{
    Command command;
    if(strcmp("display", buffer) == 0)
    {
        command.type = CommandDisplay;
    }
    else if(strcmp("exit", buffer) == 0)
    {
        command.type = CommandExit;
    }
    else if(strncmp("push ", buffer, 5) == 0)
    {
        command.push_value = atoi(&buffer[5]);
        command.type = CommandPush;
    }
    else if(strcmp("pop", buffer) == 0)
    {
        command.type = CommandPop;
    }
    else
    {
        command.type = CommandNotFound;
    }
    return command;
}

int main()
{
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
        Command command = parse_command(buffer);
        if(command.type == CommandDisplay)
        {
            print_list(&list);
        } 
        else if(command.type == CommandExit)
        {
            printf("Exiting\n");
            break;
        }
        else if(command.type == CommandPush)
        {
            int is_success = push(&list, command.push_value);
            if(is_success)
            {
                printf("Success push\n");
            }
            else
            {
                printf("Not enough memory to push\n");
            }
        }
        else if(command.type == CommandPop)
        {
            int is_success = pop(&list);
            if(is_success)
            {
                printf("Success pop\n");
            }
            else
            {
                printf("Nothing to pop\n");
            }
        }
        else 
        {
            printf("Command not found: %s\n", buffer);
        }
    }
    return 0;
}