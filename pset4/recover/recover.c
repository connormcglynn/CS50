#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    // check for correct usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover card.raw\n");
        return 1;
    }

    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // make buffer
    unsigned char buffer[512];

    // read input file 512 bytes at a time
    fread(buffer, 512, 1, inptr);

    // count number of pictures recovered
    int counter = 0;

    // create pointer for outfile
    FILE *outptr = NULL;

    char filename[8];

    while (fread(buffer, 512, 1, inptr) == 1)
    {
        if (buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {

            if (counter > 0)
            {
                // jpeg was found, close current pic
                fclose(outptr);
            }

            // create filename for new image
            sprintf(filename, "%03d.jpg", counter);

            // open new image
            outptr = fopen(filename, "w");
            if (outptr == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", filename);
                return 3;
            }

            // increment the counter
            counter++;
        }

        if (outptr != NULL)
        {
            // write 512 bytes until new jpg found
            fwrite(&buffer, 512, 1, outptr);
        }
    }

    // end of file, close
    fclose(outptr);
    fclose(inptr);

    return 0;

}