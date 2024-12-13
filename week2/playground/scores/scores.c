#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "get_int.h"

// Macros
#define N 3
#define LINE_MAX 20

// Prototypes
float average(int length, int array[]);

int main(void)
{
    // Get Scores
    int scores[N];
    int user_input;

    for (int i = 0; i < N; i++)
    {
        printf("Score N.%d:\n", i+1);
        user_input = get_int("> ");
        scores[i] = user_input;
    }

    // Print average
    printf("Average: %f\n", average(N, scores));
    return 0;
}

float average(int length, int array[])
{
    // Calculate average
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}