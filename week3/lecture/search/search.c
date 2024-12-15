#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "get_int.h"
#include "get_string.h"

typedef struct
{
    char* name;
    char* number;
}
person;

int search_numbers(void);
int search_strings(void);
int search_phone_number(void);
int search_phone_from_person(void);

int main(void)
{

    // search_numbers();
    // search_strings();
    // search_phone_number();
    search_phone_from_person();
}

int search_numbers(void)
{
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found in position %d.\n", i);
            return 0;
        }
    }
    printf("Not found.\n");
    return 1;
}

int search_strings(void)
{
    char* strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};
    char* text = get_string("String: ");

    for (int i = 0; i < 6; i++){
        if (strcmp(strings[i], text) == 0)
        {
            printf("Found\n");
            free(text);
            return 0;
        }
    }
    printf("Not found.");
    free(text);
    return 1;
}

int search_phone_number(void)
{
    char* names[] = {"Fiona", "David", "Pedro"};
    char* phones[] = {"+34 667 182 738", "+1-617-495-1000", "+1-949-468-2750"};

    char* text = get_string("Name: ");

    for (int i = 0; i < 3; i++){
        if (strcmp(names[i], text) == 0)
        {
            printf("Number: %s\n", phones[i]);
            free(text);
            return 0;
        }
    }
    printf("Not found.");
    free(text);
    return 1;
}

int search_phone_from_person(void)
{
    person people[3];

    people[0].name = "Carter";
    people[0].number = "123";

    people[1].name = "Pedro";
    people[1].number = "456";

    people[2].name = "Juana";
    people[2].number = "789";

    char* name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(people[i].name, name) == 0)
        {
            printf("Number: %s\n", people[i].number);
            free(name);
            return 0;
        }
    }
    printf("Not found.\n");
    free(name);
    return 1;
}
