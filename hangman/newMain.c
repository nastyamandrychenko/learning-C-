#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "./functions/printGallow.c"
#include "./functions/randomWordsFromFile.c"




// the function asks the person for the number of letters in a word and returns its value
char userNumber()
{
    char numberOfLetters;

    // the user enters how many letters he wants in the word
    scanf("%c", &numberOfLetters);

    // check that the entered value is not greater than 5 and not less than 2
    while (numberOfLetters != '3' && numberOfLetters != '4' && numberOfLetters != '5' && numberOfLetters != '6' && numberOfLetters != '7')
    {
        scanf("%c", &numberOfLetters);
    }

    return numberOfLetters;
}

void printGallows(int mistakes);

// function checks if the user has entered a character
bool characterOrNot(char c)
{
    if (isalpha(c) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
};

// the main function that checks the letter entered by the user. The function receives the word to be guessed and its length
void checkUserLetters(char *mainWord, int lengthOfWord)
{
    // variable for counting wrong letters entered by the user
    int mistakes = 0;
    // variable for counting right letters entered by the user
    int rightCharacters = 0;
    char character;
    char dash = '_';

    // create dynamic array for a word not yet guessed(dashes)
    char *dashes = malloc(lengthOfWord * sizeof(char));

    // create dynamic array for a letters that a user already used
    char *alreadyUsed = malloc((lengthOfWord + 10) * sizeof(char));
    // counter for letters
    int numOfChar = 0;
    int lives = 10;
    printf("\n");

    // fill dynamic array "dashes" with dashes
    for (int i = 0; i < lengthOfWord; i++)
    {
        dashes[i] = dash;
    }

    // check the user's letters until the number of mistakes is less than 10
    while (mistakes < 10)
    {
        printf("\n\n");
        // call the function that draws the gallows
        printGallows(mistakes);
        printf("\n");
        // print the word hidden behind a dash
        for (int i = 0; i < lengthOfWord; i++)
        {
            printf("%c ", dashes[i]);
        }
        // print how many attempts we have left before losing
        printf("\n\nYou have %d attempts", lives);
        printf("\n\n\n");

        // while the user enters a number, we will display scanf and wait for him to enter a letter
        do
        {
            printf("\nEnter a character: ");
            printf("\n");
            scanf(" %c", &character);
        } while (!characterOrNot(character));

        // converts users letter to lower case
        character = tolower(character);

        bool characterUsed = true;

        // check if a letter has already been used or not
        while (characterUsed)
        {
            for (int i = 0; i < lengthOfWord + 10; i++)
            {
                // if the letter has not yet been used, then exit the loop
                if (alreadyUsed[i] != character)
                {
                    characterUsed = false;
                }
                else
                {
                    // if the letter has already been used, then we ask the user for a new letter
                    characterUsed = true;
                    do
                    {
                        printf("\nYou have already entered this letter. Try another one: ");
                        printf("\n");

                        scanf(" %c", &character);
                    } while (!characterOrNot(character));
                    character = tolower(character);
                    break;
                }
            }
        }
        // write already used letters to an array alreadyUsed
        alreadyUsed[numOfChar] = character;

        int totalRight = 0;

        for (int i = 0; i < lengthOfWord; i++)
        {
            // check if the letter entered by the user is in the word to be guessed.
            // If yes, then write the letter instead of the dash and add 1 to the "rightCharacters" and "totalRight"
            if (mainWord[i] == character)
            {
                dashes[i] = mainWord[i];
                rightCharacters++;
                totalRight++;
            }
        }

        // we check totalRight 1 or 0. If 0, then we havent users letter in our word. We add 1 to the "mistakes" and take life
        if (totalRight == 0)
        {
            mistakes++;
            lives--;
        };


        //print an array with already used letters
        printf("\nLetters used:");
        for (int i = 0; i < numOfChar; i++)
        {
            printf("%c ", alreadyUsed[i]);
        }
        printf("\n");

      //used letters +1   
        numOfChar++;

    // check if the number of correctly entered letters is equal to the number of letters in the word to be guessed. 
    // If yes, then the user has won.
        if (rightCharacters == lengthOfWord)
        {
            printf("%s", mainWord);
            printf("\n\nYou won!");
            printf("\n");
            break;
        }
    }
// check if the number of correctly entered letters is less than the number of letters in the word to be guessed.
 // If yes, then the user has lost.
    if (rightCharacters < lengthOfWord)
    {
        printf("\n\nYou lost!");
        printf("\nRiddle word:");
        printf("%s", mainWord);
        printf("\n");
        printGallows(mistakes);
    }
    // free dynamic arrays
    free(dashes);
    free(alreadyUsed);
};

int main(void)
{
    bool gameRestart = true;

   
    while (gameRestart == true)
    {
        printf("\n\t\tWELCOME TO HANGMAN!!!");
        printf("\n\n\t\t\tRULES:");
        printf("\n\t - Maximum 10 mistakes are allowed.");
        printf("\n\t - All alphabet are in lower case.\n");

        printf("\n\n\t\t\tMENU");
        printf("\n\t How many letters will be in the word:\n\t Write a number from 3 to 7\n");
        char *word;
        // call a function that returns the value of the number of letters in a word
        char num = userNumber();

    // we check what value the user entered and open the corresponding file with the corresponding number of letters in the word
        switch (num)
        {
        case '3':
        // get random word from file
            word = lowercase("./words/three.txt");
            break;

        case '4':
        // get random word from file
            word = lowercase("./words/four.txt");
            break;

        case '5':
        // get random word from file
            word = lowercase("./words/five.txt");
            break;

        case '6':
        // get random word from file
            word = lowercase("./words/six.txt");
            break;

        case '7':
        // get random word from file
            word = lowercase("./words/seven.txt");
            break;
        };


    // length of random word
        int len = strlen(word);

   //call function that checks the entered letters of the user
        checkUserLetters(word, len);

        int gameRest;
        printf("\n\nIf you want to start the game again press 1\nif you want to end the game, press any other key\n"); // At the end of the game program asks user to replay or not
        // ask if the user wants to restart the game
        scanf("%d", &gameRest);
        if (gameRest == 1)
        {
            gameRestart = true;
        }
        else
        {
            gameRestart = false;
        }
    }
}
