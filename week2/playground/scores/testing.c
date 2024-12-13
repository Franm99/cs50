#include <stdio.h>
#include "get_int.h"

int main(void)
{
    int user_input = get_int("Your input: ");
    printf("%d", user_input);
    return 0;
}