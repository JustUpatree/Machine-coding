#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

const int LIST_SIZE = 10; 
const int BUFFER_SIZE = 32;
const int STDIN = 0;
const int STDOUT = 1;
const char *COMMAND_PREFIX = ">>>> "; 

typedef enum 
{
    CommandDisplay,
    CommandExit,
    CommandNotFound 
} Command;

void print_list(int *list, int list_size)
{
    for(int i = 0; i < list_size; i++)
    {
        printf("%d", list[i]);
        if(i + 1 != list_size)
        {
            printf(", ");
        }
        else
        {
            printf("\n");
        }
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
    char buffer[BUFFER_SIZE];
    int list[LIST_SIZE];
    for(int i = 0; i < LIST_SIZE; i++)
    {
        list[i] = rand() % 100;
    }
    while(1)
    {
        printf("%s", COMMAND_PREFIX);
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';
        Command parse_command_value = parse_command(buffer);
        if(parse_command_value == CommandDisplay)
        {
            print_list(list, LIST_SIZE);
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