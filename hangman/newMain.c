#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include "./functions/printGallow.c"
#include "./functions/randomWordsFromFile.c"
#include "./functions/userNumber.c"
#include "./functions/checkUserLetters.c"


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
            word = lowerCase("./words/three.txt");
            break;

        case '4':
        // get random word from file
            word = lowerCase("./words/four.txt");
            break;

        case '5':
        // get random word from file
            word = lowerCase("./words/five.txt");
            break;

        case '6':
        // get random word from file
            word = lowerCase("./words/six.txt");
            break;

        case '7':
        // get random word from file
            word = lowerCase("./words/seven.txt");
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
