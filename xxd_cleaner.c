#include <stdio.h>

int main()
{
    while (1)
    {
        int c = getc(stdin);
        // if end of file
        if (c == EOF)
        {
            break;
        }

        // if comment
        if (c == '#')
        {
            // skip the rest of the line
            while (1) 
            {
                c = getc(stdin);
                if (c == '\n' || c == EOF)
                {
                    break;
                }
            }

        }

        putc(c, stdout);
    }
}
