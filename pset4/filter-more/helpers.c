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

sample_image img;


// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int gray_scale;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            gray_scale = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue)/3.0);

            image[i][j].rgbtRed = gray_scale;
            image[i][j].rgbtBlue = gray_scale;
            image[i][j].rgbtGreen = gray_scale;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int half_width = round(width/2);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {

            if (width%2 == 0 && j < half_width)
            {
                img.red = image[i][j].rgbtRed;
                img.green = image[i][j].rgbtGreen;
                img.blue = image[i][j].rgbtBlue;


                image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
                image[i][j].rgbtGreen =image[i][width - j - 1].rgbtGreen;
                image[i][j].rgbtBlue =image[i][width - j - 1].rgbtBlue;

                image[i][width - j - 1].rgbtRed = img.red;
                image[i][width - j - 1].rgbtGreen = img.green;
                image[i][width - j - 1].rgbtBlue = img.blue;
            }
            else if (width%2 == 1 && j < (half_width))
            {

                img.red = image[i][j].rgbtRed;
                img.green = image[i][j].rgbtGreen;
                img.blue = image[i][j].rgbtBlue;


                image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
                image[i][j].rgbtGreen =image[i][width - j - 1].rgbtGreen;
                image[i][j].rgbtBlue =image[i][width - j - 1].rgbtBlue;

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

    sample_image blur_img[height + 1][width + 1];

    for (int i = 0; i < height + 1; i++)
    {
        if (i == 0 || i == (height + 1))
        {
            for (int k = 0; k < width + 1; k++)
            {
                blur_img[i][k].red = 0;
                blur_img[i][k].blue = 0;
                blur_img[i][k].green = 0;
            }
        }
        else
        {
            for (int j = 0; j < width + 1; j++)
            {
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
    int blur_red = 0;
    int blur_green = 0;
    int blur_blue = 0;
    int r = 0;
    int g = 0;
    int b = 0;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {


            for (int m = -1 ; m < 2 ; m++)
            {
                for (int n = -1 ; n < 2 ; n++)
                {
                    if(blur_img[m + j + 1][n + i + 1].red == 0
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
            image[i][j].rgbtRed = round(blur_red/(9-r));
            image[i][j].rgbtGreen = round(blur_green/(9-g));
            image[i][j].rgbtBlue = round(blur_blue/(9-b));
        }
    }

    return;
}





// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{

    return;
}
