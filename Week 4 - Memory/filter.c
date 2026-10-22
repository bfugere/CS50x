#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int average = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            average = (int) round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);

            image[i][j].rgbtBlue = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int sepiaRed = 0;
    int sepiaGreen = 0;
    int sepiaBlue = 0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            sepiaRed = (int) round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            sepiaGreen = (int) round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            sepiaBlue = (int) round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // Update pixel with sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    int myWidth = 0;

    if (width % 2 == 0)
    {
        myWidth = width / 2;
    }
    else
    {
        myWidth = width / 2 + 1;
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < myWidth; j++)
        {
            // Swap pixels
            temp[i][j] = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = temp[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int tempRed = 0;
            int tempGreen = 0;
            int tempBlue = 0;
            int pixelCount = 0;

            // Find average of surround pixels first with pixel count
            for (int current_i = i - 1; current_i <= i + 1; current_i++)
            {
                for (int current_j = j - 1; current_j <= j + 1; current_j++)
                {
                    if (current_i >= 0 && current_i < height && current_j >= 0 && current_j < width)
                    {
                        tempRed += image[current_i][current_j].rgbtRed;
                        tempGreen += image[current_i][current_j].rgbtGreen;
                        tempBlue += image[current_i][current_j].rgbtBlue;

                        pixelCount++;
                    }
                }
            }
            // Update pixel value to have the average now
            temp[i][j].rgbtRed = (int) round(tempRed / (pixelCount * 1.0));
            temp[i][j].rgbtGreen = (int) round(tempGreen / (pixelCount * 1.0));
            temp[i][j].rgbtBlue = (int) round(tempBlue / (pixelCount * 1.0));
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp[i][j];
        }
    }

    return;
}
