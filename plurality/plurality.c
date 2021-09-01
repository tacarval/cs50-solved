#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        //return false
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    //Get number of total voters
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        // Candidate's name
        string name = get_string("Vote: ");

        // Check for invalid vote
        // if candidate does not exist
        if (!vote(name))
        {

            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // check if name in the array
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp((string) candidates[i].name, (string) name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
// print each one in different lines

void print_winner(void)
{
    //sorted array
    int max_vote = candidates[0].votes;
    candidate winners[candidate_count];

    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes >= max_vote)
        {
            winners[i] = candidates[i];
            max_vote = candidates[i].votes;
        }
    }

    //check winner or winners


    for (int i = 0; i < candidate_count ; i++)
    {
        if (winners[i].votes == max_vote)
        printf("%s\n", winners[i].name);
    }
    return;
}