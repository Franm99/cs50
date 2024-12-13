#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TEXT_LIMIT 500

char* encrypt_text(char* text, char* key);

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        char *key = argv[1];
        if (strlen(key) != 26)
        {
            printf("Key must be 26 characters long");
        }
        else 
        {
            printf("Do stuff");
        }

        printf("Original:\n");
        char text[TEXT_LIMIT];  // 2000 characters limit, just for simplicity purposes.
        fgets(text, sizeof text, stdin);

        char *result = encrypt_text(text, key);

        printf("Result:\n%s", result);
    }
    else {
        printf("Usage: caesar.exe key");
    }

}


char* encrypt_text(char* text, char* key)
{
    /**
     * 98 - 97 = 1
     * key[1] is the value I want, but if it is lowercase it must be lowercase.
     */
    for (int i = 0; i < strlen(text); i++)
    {
        int offset, index;
        if (text[i] >= 'a' && text[i] <= 'z'){
            offset = 97;
            index = text[i] - offset;
            text[i] = tolower(key[index]);
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            offset = 65;
            index = text[i] - offset;
            text[i] = toupper(key[index]);
        }        
    }
    return text;
}



