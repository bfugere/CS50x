#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int CountLetters(string text);
int countWords(string text);
int countSentences(string text);

// Coleman-Liau Index
// .index = 0.0588 * L - 0.296 * S - 15.8
// L = Average number of letters per 100 words.
// S = Average number of sentences per 100 words.

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = CountLetters(text);
    int words = countWords(text);
    int sentences = countSentences(text);

    // Test outputs
    // printf("%i %i %i\n", letters, words, sentences);

    // Compute the Coleman-Liau index
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Print the grade level
    int grade = round(index);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int CountLetters(string text)
{
    // Letter tracker
    int amountOfLetters = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            amountOfLetters++;
        }
    }

    // Return the number of letters in the text
    return amountOfLetters;
}

int countWords(string text)
{
    // Word tracker
    int amountOfWords = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isblank(text[i]))
        {
            amountOfWords++;
        }
    }

    // Return the number of words in the text
    return amountOfWords + 1;
}

int countSentences(string text)
{
    // Sentence tracker
    int amountOfSentences = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            amountOfSentences++;
        }
    }

    // Return the number of sentences in the text
    return amountOfSentences;
}
