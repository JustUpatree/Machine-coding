#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "list.h"
#include "sll.h"

const int BUFFER_SIZE = 32;
const char *COMMAND_PREFIX = "> "; 

typedef enum 
{
    CommandDisplay,
    CommandExit,
    CommandNotFound,
    CommandPush,
    CommandPop,
    CommandRemoveIndex,
    CommandInsert
} CommandType;

typedef struct
{
    CommandType type;
    union 
    {
        int push_value;
        int remove_index_value;
        struct 
        {
            int insert_index;
            int insert_value;
        };
    };
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
    else if(strncmp("remove ", buffer, 7) == 0)
    {
        command.remove_index_value = atoi(&buffer[7]);
        command.type = CommandRemoveIndex;
    }
    else if(strncmp("insert ", buffer, 7) == 0)
    {
        command.insert_index = atoi(&buffer[7]);
        command.insert_value = atoi(strchr(&buffer[7], ' '));
        command.type = CommandInsert;
    }
    else
    {
        command.type = CommandNotFound;
    }
    return command;
}

int main()
{
    List list = new_list();
    while(1)
    {
        printf("%s", COMMAND_PREFIX);
        char buffer[BUFFER_SIZE];
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0'; //index new line
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
            push(&list, command.push_value);
            printf("Success push\n");
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
        else if(command.type == CommandRemoveIndex)
        {   
            if(remove_from_list(&list, command.remove_index_value))
            {
                printf("Success remove\n");
            }
            else
            {
                printf("Nothing to remove\n");
            }
        }
        else if(command.type == CommandInsert)
        {
            if(insert_in_list(&list, command.insert_index, command.insert_value))
            {
                printf("Success insert\n");
            }
            else
            {
                printf("Nowhere to insert\n");
            }
        }
        else 
        {
            printf("Command not found: %s\n", buffer);
        }
    }
        delete_list(&list);
    return 0;
}