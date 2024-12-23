#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x: %d, y: %d\n", x, y);
    swap(&x, &y);  // Send the addresses of x and y.
    printf("x: %d, y: %d\n", x, y);

    return 0;
}

/**
 * Expects to receive two pointers instead of two values.
 * As we want to swap the values of two variables, we need their addresses to 
 * first obtain their values, then change their place in memory.
 */
void swap(int *a, int *b) 
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}