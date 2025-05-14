#include "helpers.h"
#include "math.h"

typedef struct
{
    int red;
    int green;
    int blue;
}
sample_image;


int height_img;
int width_img;

// temperary structure for reflect filter
sample_image img;

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int gray_scale;

    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            //Generating gray scale value for a pixel
            gray_scale = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            //applying the filter on the pixel
            image[i][j].rgbtRed = gray_scale;
            image[i][j].rgbtBlue = gray_scale;
            image[i][j].rgbtGreen = gray_scale;
        }
    }
    return;
}

// Reflect image horizontally
// Main method of my code is to replace the first pixel with the last pixel horizontally using a temp structure
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int half_width = round(width / 2);
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {
            //For a even numberd pixels in a image
            if (width % 2 == 0 && j < half_width)
            {
                //copying image's data to temperary structure
                img.red = image[i][j].rgbtRed;
                img.green = image[i][j].rgbtGreen;
                img.blue = image[i][j].rgbtBlue;

                // changing the value of left hand side pixel to the right hand side pixel(opposite)
                image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
                image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
                image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

                //Finally changing the right hand side pixel to the temp pixel stored earliar
                image[i][width - j - 1].rgbtRed = img.red;
                image[i][width - j - 1].rgbtGreen = img.green;
                image[i][width - j - 1].rgbtBlue = img.blue;
            }

            // Odd numbered pixel image using the same principle
            // The secound condition leaves middle vertical line of pixel as it is an odd numbered width image
            else if (width % 2 == 1 && j < (half_width))
            {

                img.red = image[i][j].rgbtRed;
                img.green = image[i][j].rgbtGreen;
                img.blue = image[i][j].rgbtBlue;


                image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
                image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
                image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;

                image[i][width - j - 1].rgbtRed = img.red;
                image[i][width - j - 1].rgbtGreen = img.green;
                image[i][width - j - 1].rgbtBlue = img.blue;

            }

        }
    }
    return;
}



// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    height_img = height;
    width_img = width;

    //Generating a temp structure with a black boundary around it
    sample_image blur_img[height + 1][width + 1];

    for (int i = 0 ; i < height + 1 ; i++)
    {
        // First and final line of black pixels for the boundary
        if (i == 0 || i == (height + 1))
        {
            for (int k = 0 ; k < width + 1 ; k++)
            {
                blur_img[i][k].red = 0;
                blur_img[i][k].blue = 0;
                blur_img[i][k].green = 0;
            }
        }
        else
        {
            for (int j = 0 ; j < width + 1 ; j++)
            {
                // For the extreme left and right boundry of the temp image
                if (j == 0 || j == width + 1)
                {
                    blur_img[i][j].red = 0;
                    blur_img[i][j].green = 0;
                    blur_img[i][j].blue = 0;
                }
                else
                {
                    blur_img[i][j].red = image[i - 1][j - 1].rgbtRed;
                    blur_img[i][j].green = image[i - 1][j - 1].rgbtGreen;
                    blur_img[i][j].blue = image[i - 1][j - 1].rgbtBlue;
                }
            }
        }
    }
    //variables to be used in the code
    int blur_red = 0;
    int blur_green = 0;
    int blur_blue = 0;
    int r = 0;
    int g = 0;
    int b = 0;
    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {

            // Used to check for the box for any pixel in an image
            for (int m = -1 ; m < 2 ; m++)
            {
                for (int n = -1 ; n < 2 ; n++)
                {
                    //Checking if the pixel surrounding the image is boundary
                    if (blur_img[m + j + 1][n + i + 1].red == 0
                        && blur_img[m + j + 1][n + i + 1].green == 0
                        && blur_img[m + j + 1][n + i + 1].blue == 0)
                    {
                        r++;
                        g++;
                        b++;
                    }
                    blur_red += blur_img[m + j + 1][n + i + 1].red;
                    blur_blue += blur_img[m + j + 1][n + i + 1].blue;
                    blur_green += blur_img[m + j + 1][n + i + 1].green;
                }
            }
            // Final implementation of the blur effect on the image

            image[i][j].rgbtRed = round(blur_red / (9 - r));
            image[i][j].rgbtGreen = round(blur_green / (9 - g));
            image[i][j].rgbtBlue = round(blur_blue / (9 - b));
        }
    }

    return;
}


//sepiaRed = .393 * originalRed + .769 * originalGreen + .189 * originalBlue
//sepiaGreen = .349 * originalRed + .686 * originalGreen + .168 * originalBlue
//sepiaBlue = .272 * originalRed + .534 * originalGreen + .131 * originalBlue

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{


    for (int i = 0 ; i < height ; i++)
    {
        for (int j = 0 ; j < width ; j++)
        {

            // Creating three value for the round of the sepia color value
            int sepia_red = round((0.393 * image[i][j].rgbtRed) + (0.769 * image[i][j].rgbtGreen) + (0.189 * image[i][j].rgbtBlue));
            int sepia_green = round((0.349 * image[i][j].rgbtRed) + (0.686 * image[i][j].rgbtGreen) + (0.168 * image[i][j].rgbtBlue));
            int sepia_blue = round((0.272 * image[i][j].rgbtRed) + (0.534 * image[i][j].rgbtGreen) + (0.131 * image[i][j].rgbtBlue));

            //Capping sepia value upto 255
            if (sepia_red > 255)
            {
                sepia_red = 255;
            }
            if (sepia_blue > 255)
            {
                sepia_blue = 255;
            }
            if (sepia_green > 255)
            {
                sepia_green = 255;
            }

            //Final implementation of sepia filter
            image[i][j].rgbtRed = sepia_red;
            image[i][j].rgbtBlue = sepia_blue;
            image[i][j].rgbtGreen = sepia_green;
        }
    }
    return;
}
