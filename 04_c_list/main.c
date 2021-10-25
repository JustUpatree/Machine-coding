#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

const int LIST_SIZE = 10; 
const int BUFFER_SIZE = 8;
const int STDIN = 0;
const int STDOUT = 1;

typedef enum 
{
    CommandDisplay,
    CommandExit,
    CommandNotFound 
} Command;

void start()
{

}


void print_list()
{
    int list[LIST_SIZE];
    for(int i = 0; i < LIST_SIZE; i++)
    {
        list[i] = rand() % 100;
        printf("%d", list[i]);
        if(i + 1 != LIST_SIZE)
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
    int bytes_read = read(STDIN, buffer, BUFFER_SIZE);
    buffer[bytes_read - 1] = '\0';
    Command parse_command_value = parse_command(buffer);
    if(parse_command_value == CommandDisplay)
    {
        print_list();
    } 
    else if(parse_command_value == CommandNotFound)
    {
        printf("Command not found\n");
    }
    else
    {
        printf("Exiting\n");
    }

    return 0;
}