#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    RGBTRIPLE temp[height][width];

    for (int x = 1; x < width-1; x++)
    {
        for (int y = 1; y < height-1; y++)
        {
            int gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
            int gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

            int sum_x_r = 0, sum_x_g = 0, sum_x_b = 0;
            int sum_y_r = 0, sum_y_g = 0, sum_y_b = 0;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    int red = image[y + i - 1][x + j - 1].rgbtRed;
                    int blue = image[y + i - 1][x + j - 1].rgbtBlue;
                    int green = image[y + i - 1][x + j - 1].rgbtGreen;
                    
                    sum_x_r += red * gx[i][j];
                    sum_x_g += green * gx[i][j];
                    sum_x_b += blue * gx[i][j];

                    sum_y_r += red * gy[i][j];
                    sum_y_g += green * gy[i][j];
                    sum_y_b += red * gy[i][j];
                }
            }

            int b = (int)round(sqrt(sum_x_b * sum_x_b + sum_y_b * sum_y_b));
            int g = (int)round(sqrt(sum_x_g * sum_x_g + sum_y_g * sum_y_g));
            int r = (int)round(sqrt(sum_x_r * sum_x_r + sum_y_r * sum_y_r));

            temp[y][x].rgbtRed = (r > 255) ? 255 : r;
            temp[y][x].rgbtGreen = (g > 255) ? 255 : g;
            temp[y][x].rgbtBlue = (b > 255) ? 255 : b;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }

    return;
}
