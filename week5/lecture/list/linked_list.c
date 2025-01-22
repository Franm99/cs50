#include <stdio.h>
#include <stdlib.h>
#include "get_int.h"

typedef struct node
{
    int number;
    struct node *next;
} node;

int main(void)
{
    node *list = NULL;  // This node will always be the head node.

    // Build list
    for (int i = 0; i < 3; i++)
    {
        // Allocate node for number
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->number = get_int("Number: ");
        n->next = NULL;  // When creating a new node, it will become the new head, so cannot point to another node.

        // Prepend node to list
        n->next = list;  // Does not make too much sense the first time, but the second, it does.
        list = n;  // n becomes the new head. 

        // The second iteration, the new n will point its 'next' attribute to the previous node, then it will become the new head.
    }

    node *ptr = list;
    while (ptr != NULL)
    {
        printf("New node:\n");
        printf("Number: %d, Points to: %p\n", ptr->number, ptr->next);
        ptr = ptr->next;
    }
    return 0;
}