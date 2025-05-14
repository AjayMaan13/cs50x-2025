#include <cs50.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, string argv[])
{
    FILE *input = fopen(argv[1], "r");

    // uint8_t means unsigned integer of 8 bits i.e 1 byte
    uint8_t buffer[4]; // It creates a buffer(filename) which has a space of 4 bytes to help us to read the file

    fread(buffer, 1, 4, input);
//it read data from the file input to buffer in which each packet has 1 byte size and we'll read a total of 4 packets

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", buffer[i]);
        fclose(input);
    }

    fclose(input); // to free up the space we used by creating a 4byte space
    // these errors can be found using "valgrind ./file_name reading_file_name"
}