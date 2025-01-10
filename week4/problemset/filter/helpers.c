#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    printf("I am here\n");
    for (int x = 0; x < width; x++)
    {
        for (int y = 0; y < height; y++)
        {
            int avg = (image[y][x].rgbtBlue + image[y][x].rgbtGreen + image[y][x].rgbtRed) / 3;
            image[y][x].rgbtBlue = avg;
            image[y][x].rgbtGreen = avg;
            image[y][x].rgbtRed = avg;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // TODO: Add fix for images with odd width.
    for (int x = 0; x < width/2; x++)
    {
        for (int y = 0; y < height; y++)
        {
            RGBTRIPLE tmp = image[y][width-x];
            image[y][width-x] = image[y][x];
            image[y][x] = tmp;

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*im_copy)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    im_copy = image;
    for (int x = 1; x < width-1; x++)
    {
        for (int y = 1; y < height-1; y++)
        {
            int valB = 0, valG = 0, valR = 0;
            int num_elements = 0;
            for (int i = y - 1; i <= y + 1; i++)
            {
                for (int j = x-1; j <= x + 1; j++)
                {
                    valB += im_copy[i][j].rgbtBlue;
                    valG += im_copy[i][j].rgbtGreen;
                    valR += im_copy[i][j].rgbtRed;

                    num_elements++;
                }
            }

            image[y][x].rgbtBlue = valB / num_elements;
            image[y][x].rgbtGreen = valG / num_elements;
            image[y][x].rgbtRed = valR / num_elements;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
