#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1

    // Open input file for reading
    // TODO #2

    // Read header
    // TODO #3

    // Use check_format to ensure WAV format
    // TODO #4

    // Open output file for writing
    // TODO #5

    // Write header to file
    // TODO #6

    // Use get_block_size to calculate size of block
    // TODO #7

    // Write reversed audio to file
    // TODO #8
}

int check_format(WAVHEADER header)
{
    // TODO #4
    return 0;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    return 0;
}


                                                             // SOLUTION //


#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1



    if (argc != 3)
    {
        printf("enter wav files");
        return 1;
    }
    else if(strstr(argv[1], ".wav") != NULL && strstr(argv[2], ".wav") != NULL)
    {
        ;
    }
    else
    {
        return 1;
    }


    // Open input file for reading
    // TODO #2

    FILE *input = fopen(argv[1], "r");

    if(input == NULL)
    {
        printf("no file was opened");
        return 1;
    }


    // Read header
    // TODO #3

    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    // TODO #4

    if(check_format(header) == 0)
    {
        return 1;
    }

    // Open output file for writing
    // TODO #5

    FILE *output = fopen(argv[2], "w");

    // Write header to file
    // TODO #6

    fwrite(&header, sizeof(WAVHEADER),1, output);

    // Use get_block_size to calculate size of block
    // TODO #7

    int size = get_block_size(header);

    int audio_size = header.subchunk2Size / size;



    // Write reversed audio to file
    // TODO #8


    BYTE *buffer = malloc(size);

    fseek(input, size, SEEK_END);


    while(ftell(input) - size >= sizeof(header))
    {
        if(fseek(input, -2 * size, SEEK_CUR))
        {
            return 1;
        }
        fread(buffer, size, 1, input);
        fwrite(buffer, size, 1, output);

    }

}

int check_format(WAVHEADER header)
{
    // TODO #4

    BYTE format[] = {'W','A','V','E'};

    for(int i = 0; i < 4; i++)
    {
        if(header.format[i] != format[i])
        {
            return 0;
        }
    }


    return 1;
}

int get_block_size(WAVHEADER header)
{
    int bytes = 0;

    bytes += (header.bitsPerSample / 8) * header.numChannels;

    return (bytes);
}