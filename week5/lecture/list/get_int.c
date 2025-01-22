#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define LINE_MAX 20


int get_int(char* prompt_text)
{
    char* end;
    char buf[LINE_MAX];
    int user_input;

    do
    {
        printf("%s", prompt_text);
        if (!fgets(buf, sizeof buf, stdin))
            break;
        
        // remove \n
        buf[strlen(buf) - 1] = 0;

        user_input = strtol(buf, &end, 10);
    } while (end != buf + strlen(buf));

    return user_input;
}
