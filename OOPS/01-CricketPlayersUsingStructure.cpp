#include <stdio.h>
#include <string.h>

struct cricket
{
    char playerName[50];
    char teamName[50];
    float battingAverage;
};

int main()
{
    struct cricket players[100];
    int n, i, j;
    char teams[100][50];
    int teamCount = 0;

    printf("Enter number of players: ");
    scanf("%d", &n);

    // Read player information
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details of player %d:\n", i + 1);

        printf("Player Name: ");
        scanf(" %[^\n]", players[i].playerName);

        printf("Team Name: ");
        scanf(" %[^\n]", players[i].teamName);

        printf("Batting Average: ");
        scanf("%f", &players[i].battingAverage);

        // Store unique team names
        int found = 0;

        for (j = 0; j < teamCount; j++)
        {
            if (strcmp(teams[j], players[i].teamName) == 0)
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            strcpy(teams[teamCount], players[i].teamName);
            teamCount++;
        }
    }

    // Display team-wise list
    printf("\n\n========== TEAM-WISE PLAYER LIST ==========\n");

    for (i = 0; i < teamCount; i++)
    {
        printf("\nTeam: %s\n", teams[i]);
        printf("----------------------------------\n");
        printf("Player Name\tBatting Average\n");

        for (j = 0; j < n; j++)
        {
            if (strcmp(players[j].teamName, teams[i]) == 0)
            {
                printf("%-15s %.2f\n",
                       players[j].playerName,
                       players[j].battingAverage);
            }
        }
    }

    return 0;
}