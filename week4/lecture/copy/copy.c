#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "get_string.h"

int main(void)
{
    char *s = get_string("s: ");

    if (s == NULL)
        return 1;

    char *t = malloc(strlen(s) + 1);  // allocate memory for other string.
    if (t == NULL)
        return 1;

    strcpy(t, s);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);
    return 0;
}