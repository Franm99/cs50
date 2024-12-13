#include <stdio.h>
#include <string.h>
#include <math.h>

#define TEXT_LIMIT 5000
 
int count_letters(char* text);
int count_words(char* text);
int count_sentences(char* text);
int compute_coleman_liau_index(int letters, int words, int sentences);

int main(void)
{
    char text[TEXT_LIMIT];  // 2000 characters limit, just for simplicity purposes.
    fgets(text, sizeof text, stdin);

    int letters = count_letters(text);
    printf("Num. of letters: %d\n", letters);
    int words = count_words(text);
    printf("Num. of words: %d\n", words);
    int sentences = count_sentences(text);
    printf("Num. of sentences: %d\n", sentences);

    int index = compute_coleman_liau_index(letters, words, sentences);
    printf("Grade: ");
    if (index >= 16)
    {
        printf("+16\n");
    }
    else 
    {
        printf("%d", index);
    }
    return 0;
}


int count_letters(char* text)
{
    int count = 0;
    for (int i=0, lim=strlen(text); i<lim; i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            count++;
        }
    }    
    return count;
}

int count_words(char* text)
{
    // Words can be count by finding word separators and using them as stoppers for the current word.
    char* separators = " ,()!?.;-";
    int count = 0;
    int in_word = 0;  // flag
    for (int i=0, lim=strlen(text); i<lim; i++)
    {
        if (in_word == 0)
        {
            if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
            {
                in_word = 1;
                count++;
            }
        }
        else 
        {
            char* pPos = strchr(separators, text[i]);

            if (pPos) // Null pointer, found in separators, end of word.
            {
                in_word = 0;
            }
        }
    }
    return count;
}

int count_sentences(char* text)
{
    // Sentences can be count by finding sentence separators and using them as stoppers for the current word.
    char* separators = "!?.";
    int count = 0;
    int in_sentence = 0;  // flag
    for (int i=0, lim=strlen(text); i<lim; i++)
    {
        if (in_sentence == 0)
        {
            if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
            {
                in_sentence = 1;
                count++;
            }
        }
        else 
        {
            char* pPos = strchr(separators, text[i]);

            if (pPos) // Null pointer, found in separators, end of word.
            {
                in_sentence = 0;
            }
        }
    }
    return count;
}

int compute_coleman_liau_index(int letters, int words, int sentences)
{
    float L = ((float) letters / (float) words) * 100.0;
    float S = ((float) sentences / (float) words) * 100.0;
    int index = (int)round((0.0588 * L) - (0.296 * S) - 15.8);
    return index;
}