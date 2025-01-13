#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
typedef uint8_t  BYTE;

int main(int argc, char *argv[])
{
    char *fname = "card.raw";
    FILE *f = fopen(fname, "rb");
    if (f == NULL)
    {
        printf("Could not open %s.\n", fname);
        return 1;
    }

    BYTE init_bytes = 0xff;
    int block_size = 512;

    BYTE b;
    int i = 0;
    while (fread(&b, sizeof(b) * block_size, 1, f) != 0)
    {
        // Check jpeg header
        printf("im %d\n", i);
        i++;
    }

}