#include <stdio.h>
#include "get_int.h"

void draw(int n);
void draw_inverted(int n);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);
    draw_inverted(height);
    return 0;
}

void draw_inverted(int n)
{
    if (n <= 0)
    {
        return;
    }

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");

    draw_inverted(n - 1);

}

void draw(int n)
{
    if (n <= 0)
        return;

    draw(n - 1);

    for (int i = 0; i < n; i++)
        printf("#");
        
    printf("\n");

}