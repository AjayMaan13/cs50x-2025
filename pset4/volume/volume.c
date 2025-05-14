// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Creating a buffer of size 44bits
    uint8_t header[HEADER_SIZE];

    // Reading and Writing one full chunk of 44bit header from input to output
    fread(header, HEADER_SIZE, 1, input);
    fwrite(header, HEADER_SIZE, 1, output);

    // one 16bytes buffer created for copying sample file from input to output
    int16_t sample;
    while (fread(&sample, sizeof(int16_t), 1, input))
    {
        //modifying the volume size of sample
        sample *= factor;
        fwrite(&sample, sizeof(int16_t), 1, output);
    }

    // Closing files
    fclose(input);
    fclose(output);
}
