#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
}

//So the main idea is to run a double loop from first block to the last block of image[height][width] and
//check if the image.rgbtblue & red & green = 0 and change it to a certain number which you want

for (int i = 0; i < height; i++)
{
    for (int j = 0; j < width; j++)
    {
        // Make black pixels turn red
        if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtBlue == 0x00)
        // or simpley write == 0
        {
            image[i][j].rgbtRed = 0xff;
        }
    }
}