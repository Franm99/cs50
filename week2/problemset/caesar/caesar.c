#include <stdio.h>
#include <string.h>

#define TEXT_LIMIT 500

char* encrypt_text(char* text, int num);

int main(int argc, char* argv[])
{
    if (argc == 2)
    {
        char *a = argv[1];
        int num = atoi(a);

        printf("Original:\n");
        char text[TEXT_LIMIT];  // 2000 characters limit, just for simplicity purposes.
        fgets(text, sizeof text, stdin);

        char *result = encrypt_text(text, num);

        printf("Result:\n%s", result);
    }
    else {
        printf("Usage: caesar.exe key");
    }

}


char* encrypt_text(char* text, int num)
{
    for (int i = 0; i < strlen(text); i++)
    {
        int offset;
        if (text[i] >= 'a' && text[i] <= 'z'){
            offset = 97;
            text[i] = ((text[i] - offset + num) % 26) + offset;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            offset = 65;
            text[i] = ((text[i] - offset + num) % 26) + offset;
        }        
    }
    return text;
}



