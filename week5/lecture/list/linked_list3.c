// Sorting while creating.

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

        // If list is empty
        if (list == NULL)
        {
            list = n;  // This node is the whole list.
        }
        else  if (n->number < list->number) // If number belongs at beginning of list 
        {
            n->next = list;
            list = n;
        }
        else // Number belongs later in list
        {
            for (node *ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If at end of list
                if (ptr->next == NULL)
                {
                    // Append node
                    ptr->next = n;
                    break;
                }

                // If in middle of list
                if (n->number < ptr->next->number)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }

    // Print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%d\n", ptr->number);
    }

    // Free memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }
    return 0;
}