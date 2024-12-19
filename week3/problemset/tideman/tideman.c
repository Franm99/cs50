#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "get_int.h"
#include "get_string.h"

typedef char *string;

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int* ranks = malloc(candidate_count * sizeof(int));

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            char buf[10];
            snprintf(buf, sizeof buf, "Rank %d: ", j + 1);
            string name = get_string(buf);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
        free(ranks);
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            ranks[rank] = i;
            return true;
        }
    }
    return false;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i+1; j < candidate_count; j++)
        {
            preferences[ranks[i]][ranks[j]]++;
        }
    }

    // for (int i = 0; i < candidate_count; i++)
    // {
    //     for (int j = 0; j < candidate_count; j++)
    //     {
    //         printf("'%d' over '%d' -> '%d' times\n", i, j, preferences[i][j]);
    //     }
    // }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    pair_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            if (i == j)
                break;  // Cannot compare candidate with himself.
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[j][i] > preferences[i][j])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int higher = preferences[pairs[i].winner][pairs[i].loser];
        pair higher_strength_pair = pairs[i];
        int higher_strength_pair_idx = i;
        for (int j = i + 1; j < pair_count; j++)
        {
            int current_preference = preferences[pairs[j].winner][pairs[j].loser];
            if (current_preference > higher)
            {
                higher_strength_pair = pairs[j];
                higher_strength_pair_idx = j;
            }
        }

        // swap
        pair tmp = pairs[i];
        pairs[i] = higher_strength_pair;
        pairs[higher_strength_pair_idx] = tmp;
    }

    printf("Pairs after sorting:\n");
    for (int i = 0; i < pair_count; i++)
    {
        printf("'%d' over '%d' (preference = '%d')\n", pairs[i].winner, pairs[i].loser, preferences[pairs[i].winner][pairs[i].loser]);
    }
    return;
}

// Checks if a winner-loser pair creates a cycle in the graph.
bool has_cycle(int winner, int loser)
{
    while (winner != -1 && winner != loser)
    {
        bool found = false;
        for (int i = 0; i < candidate_count; i++)
        {
            if (locked[i][winner]) // Did anyone won previously to 'winner'?
            {
                // If so, let's check the "winner" of the winner.
                found = true;
                winner = i;
            }
        }
        if (!found)  // There is no winner for the current winner. No cycle is possible.
        {
            winner = -1;
        }
    }
    if (winner == loser)
    {
        // There is already an edge that places our current winner as a loser.
        return true;
    }
    return false;
}

// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        if (!has_cycle(pairs[i].winner, pairs[i].loser))
        {
            locked[pairs[i].winner][pairs[i].loser] = true;
        }
    }

    // for (int i = 0; i < pair_count; i++)
    // {
    //     for (int j = 0; j < pair_count; j++)
    //     {
    //         printf("%d ", locked[i][j]);
    //     }
    //     printf("\n");
    // }
    return;

}

// Print the winner of the election
void print_winner(void)
{
    for (int col = 0; col < MAX; col++)
    {
        bool found_source = true;
        for (int row = 0; row < MAX; row++)
        {
            if (locked[row][col] == true)
            {
                found_source = false;
                break;
            }
        }
        if (found_source)
        {
            printf("%s\n", candidates[col]);
            return;
        }
    }
    return;
}
