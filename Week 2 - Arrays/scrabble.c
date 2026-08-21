#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Create an index of letter scores based on the alphabet
int calculatePoints[] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,
                         1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
int calculateScore(string word);

int main(void)
{
    // Prompt the user for two words
    string player1Word = get_string("Player 1 Word: ");
    string player2Word = get_string("Player 1 Word: ");

    // Compute the score of each word
    int player1Score = calculateScore(player1Word);
    int player2Score = calculateScore(player2Word);

    // Print the winner
    if (player1Score > player2Score)
    {
        printf("Player 1 Wins with %i points!\n", player1Score);
    }
    else if (player1Score < player2Score)
    {
        printf("Player 2 Wins with %i points!\n", player2Score);
    }
    else
    {
        printf("It's a tie! Points: %i\n", player1Score);
    }
}

int calculateScore(string word)
{
    // Score tracker
    int score = 0;

    // Calculate the score
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += calculatePoints[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += calculatePoints[word[i] - 'a'];
        }
    }
    return score;
}
