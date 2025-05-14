#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


int main(int argc, char *argv[])
{
    // Checking if the file input in wrong
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE");
        return 1;
    }

    //Creating a file
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        printf("Could not open file");
        return 1;
    }

    //Place where we will read the file's data into
    unsigned char buffer[512];

    //Creating space for the name of jpg
    char *new_jpg = malloc(8 * sizeof(char));

    //The final file for the images
    FILE *output_file = NULL;

    // count the number of files
    int num = 0;
    bool run = false;

    // fread() return either 0 or 512(here)
    while (fread(buffer, sizeof(char), 512, file))
    {

        //Checking if the header matches of a jpg
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // adding the variable string in new_jpg string
            sprintf(new_jpg, "%03i.jpg", num);

            //Generating a new file
            output_file = fopen(new_jpg, "w");

            num++;

        }
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }

    }
    //Closing all the opened files and spaces used
    free(new_jpg);
    fclose(file);
    fclose(output_file);
    return 0;


}