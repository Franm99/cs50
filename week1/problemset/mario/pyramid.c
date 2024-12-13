#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_HEIGHT 8

int build_pyramid(unsigned height);


int main(void)
{
    int not_finished = 1;
    unsigned height;
    char* response[2];
    while (not_finished)
    {
        printf("Type the height of the pyramid (must be an integer): ");
        scanf(" %s", &response);
        printf(" Hello\n");
        height = (int)response - (int)'0';
        if (height > MAX_HEIGHT)
        {
            printf("Please, the height must be less than %d\n", MAX_HEIGHT);
        }
        else
        {
            build_pyramid(height);
            not_finished = 0;
        }
    }
    return 0;
}


unsigned get_uint()
{
    char inbuf[80], *endp;
    unsigned height;

    puts("Length of the pyramid: ");
    if (!fgets(inbuf, sizeof inbuf, stdin))
        return 1;  /* EOF - just quit */

    errno = 0;
    height = strtou()
    
}

int build_pyramid(unsigned height)
{
    if (height > 8)
    {
        return 1;
    }
    int n_blocks, n_spaces;
    for (int i=1; i<=height; i++)
    {
        n_spaces = height - i;
        n_blocks = i;

        // First pyramid
        for (int j=1; j<=height; j++)
        {
            if (j <= n_spaces)
            {
                printf(" ");
            } else 
            {
                printf("#");
            }
        }

        printf("  ");

        // Second pyramid
        for (int j=1; j<=height; j++)
        {
            if (j <= (height - n_spaces))
            {
                printf("#");
            } else 
            {
                printf(" ");
            }
        }

        printf("\n");
    }
    return 0;
}