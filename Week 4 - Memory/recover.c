#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILE\n");
        return 1;
    }

    // Open the memory card
    FILE *original_file = fopen(argv[1], "r");

    // Create a buffer for a block of data
    uint8_t buffer[512];
    int located_jpg = 1;
    int count = 0;
    char filename[8];
    FILE *img = NULL;

    // While there's still data left to read from the memory card
    while (fread(buffer, 1, 512, original_file) == 512)
    {
        // Create JPEGs from the data
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            located_jpg = 0;
        }

        if (located_jpg == 0)
        {
            if (count != 0)
            {
                fclose(img);
            }

            sprintf(filename, "%03i.jpg", count);
            count++;

            img = fopen(filename, "w");
            fwrite(buffer, 1, 512, img);

            located_jpg = 1;
        }
        else if (count != 0)
        {
            fwrite(buffer, 1, 512, img);
        }
    }
    fclose(img);
    fclose(original_file);
}
