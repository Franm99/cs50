#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TEXT_LIMIT 2000

char* get_string(char* message)
{
    printf("%s", message);
    char text[TEXT_LIMIT];  

    fgets(text, sizeof text, stdin);
    int l = strlen(text);
    text[l - 1] = '\0';

    char* result = malloc(l);
    strcpy(result, text);
    return result;
}