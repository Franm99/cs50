#include <stdio.h>
#include <string.h>


//              A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q,  R, S, T, U, V, W, X, Y, Z
int scores[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_points(char* s);


int main(void)
{
    char s1[50], s2[50];

    printf("Player1: ");
    scanf("%s", &s1);
    printf("Player 2: ");
    scanf("%s", &s2);

    int score_player1 = compute_points(s1);
    int score_player2 = compute_points(s2);

    if (score_player1 > score_player2)
    {
        printf("Player 1 wins! (%d > %d)", score_player1, score_player2);
    }
    else 
    {
        printf("Player 2 wins! (%d > %d)", score_player2, score_player1);
    }

}


int compute_points(char* word)
{
    int word_length = strlen(word);
    int char_points = 0;
    int points = 0;
    for (int i=0; i<word_length; i++)
    {
        if (word[i] >= 'a' && word[i] <= 'z')
        {
            word[i] -= 32;
        }
        
        if (word[i] >= 'A' && word[i] <= 'Z')
        {
            points += scores[word[i] - 65];
        }
    }
    return points;
}

