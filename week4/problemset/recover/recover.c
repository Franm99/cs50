#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
 
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

    int block_size = 512;

    BYTE b[512];
    int i = 0;
    int im_count = 0;
    bool in_image = false;

    /**
     * Loop in 512 blocks:
     * - starts with the set of bytes wanted?
     *  If yes:
     *      - was the flag raised?
     *      If No:
     *          - New image starts. Start saving into a new file. Save the current memory block.
     *      If Yes:
     *          - End of previous image. Close its file. Open a new one and save this new block.
     *  If not:
     *      - is the flag raised?
     *      If No:
     *          - No image. Jump to next memory block.
     *      If Yes:
     *          - Still in image. Keep saving to current memory block.
     */
    FILE *imptr = NULL;
    while (fread(&b, sizeof(b), 1, f) != 0)
    {
        // Check jpeg header
        // printf("mem block %d\n", i);
        // i++;
        
        if (b[0] == 0xff && b[1] == 0xd8 && b[2] == 0xff && (b[3] >> 4) == 0xe )
        {
            if (imptr != NULL)
            {
                fclose(imptr);
            }

            im_count++;
            char im_name[20];
            sprintf(im_name, "output/im_%d.jpeg", im_count);
            printf("im %d\n", im_count);

            imptr = fopen(im_name, "wb");
        }
        
        if (imptr != NULL)
        {
            fwrite(b, sizeof(b), 1, imptr);
        }
    }

}