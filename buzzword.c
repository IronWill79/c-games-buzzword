/*
 * Buzzword
 *
 * A program to create amusing fake jargon
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayUsageAndExit();

int main(int argc, const char *argv[])
{
    int numberOfPhrases = 0;

    if (argc == 1)
    {
        // There were no arguments, so default to one phrase
        numberOfPhrases = 1;
    }
    else if (argc != 2)
    {
        // An incorrect number of arguments was given, so quit with usage message
        displayUsageAndExit();
    }
    else
    {
        // A single argument was given, so attempt to convert it to an integer
        errno = 0;
        char *inputStr;
        long inputNum = (int)strtol(argv[1], &inputStr, 10);

        if (errno == ERANGE || *inputStr != '\0' || inputNum < 1 || inputNum > 99)
        {
            // The argument could not be interpreted as an integer in the required range, so quit with usage message
            displayUsageAndExit();
        }

        numberOfPhrases = (int)inputNum;
    }

    // Display the instructions
    printf("Buzzword Generator\nOriginally by Creative Computing - Morristown, New Jersey\n\n\nThis program prints highly acceptable phrases in 'educator-speak' that you can work into reports and speeches.\n\n");

    if (numberOfPhrases == 1)
    {
        printf("Here's your phrase\n");
    }
    else
    {
        printf("Here are your %i phrases\n", numberOfPhrases);
    }

    // Create three lists of words
    const char *adjectives1[] = {"ability", "basal", "behavioural", "child-centered", "differentiated", "discovery", "flexible", "heterogeneous", "homogenous", "manipulative", "modular", "tavistock", "individualised"};
    const char *adjectives2[] = {"learning", "evaluative", "objective", "cognitive", "enrichment", "scheduling", "humanistic", "integrated", "non-graded", "training", "vertical age", "motivational", "creative"};
    const char *nouns[] = {"grouping", "modification", "accountability", "process", "core curriculum", "algorithm", "performance", "reinforcement", "open classroom", "resource", "structure", "facility", "environment"};

    // Seed the random number generator
    srand((unsigned int)time(NULL));

    // Display the number of randomly generated phrases requested by the user
    for (int i = 0; i < numberOfPhrases; i++)
    {
        printf("\n%s %s %s\n", adjectives1[rand() % 13], adjectives2[rand() % 13], nouns[rand() % 13]);
    };

    return EXIT_SUCCESS;
}

void displayUsageAndExit()
{
    printf("\nUsage: BUZZWORD number_of_phrases\nWhere number of phrases is a whole number from 1 to 99\n");
    exit(EXIT_FAILURE);
}
