#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

// function get random word from array
char *getRandomWord(char **array, int countWords)
{
    // initialize the seed of random in each run of the code to get a different random result by srand.
    // using time(NULL) to set a different seed of random through srand
    char *random;
    srand(time(NULL));
    random = array[rand() % countWords];
    return random;
};

// function receive name of file, then open this file and count how many words in it. Then in the function we create dynamic array
// and fill with words from the file. we call the function to get a random word, then we clear the dynamic array and finally return the random word from our file
char *getWordFromFile(char *nameOfFile)
{
    int x;
    char word[30];
    // open file
    FILE *file;
    file = fopen(nameOfFile, "r");

    if (file == NULL)
    {
        printf(" couldn't found txt file");
        return 0;
    }

    // count how many words in our file
    int countWords;
    while (fscanf(file, "%s", word) == 1)
    {

        countWords++;
    }

    // rewind() function repositions the file pointer associated with stream to the beginning of the file

    rewind(file);

    // create dynamic array
    char **array = malloc(countWords * sizeof(char *));

    x = 0;

    // fill dynamic array with words
    while (fscanf(file, "%s", word) == 1)
    {
        // strdup() - duplicate a string
        array[x] = strdup(word);
        x++;
    }

    fclose(file);

    char *wordWeNeed = getRandomWord(array, countWords);

    // teardown
    free(array);

    return wordWeNeed;
}

// function converts letters to lower case
char *lowercase(char *nameOfFile)
{
    char *word = getWordFromFile(nameOfFile);
    for (int i = 0; word[i]; i++)
    {
        word[i] = tolower(word[i]);
    }
    return word;
}

// the function asks a person for a number and returns it
int userNumber()
{
    int numberOfLetters;
    // the user enters how many letters he wants in the word
    scanf("%d", &numberOfLetters);

    // check that the entered value is not greater than 5 and not less than 2
    while (numberOfLetters < 3 || numberOfLetters > 7)
    {
        printf("\n\t Write a number from 3 to 7!\n");
        scanf("%d", &numberOfLetters);
    }
    return numberOfLetters;
}

char *getCharacters()
{
    FILE *file = fopen("alphabet.txt", "r");
    char *arrChar;
    int n = 0;
    int c;

    arrChar = malloc(52);

    while ((c = fgetc(file)) != -1)
    {
        arrChar[n++] = (char)c;
    }

    return arrChar;
}

void printGallows(int mistakes);

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

bool digitOrNot(char number)
{
    if (isdigit(number) != 0)
    {
        return true;
    }
    else
    {
        return false;
    }
};

void checkUserLetters(char *mainWord, int lengthOfWord)
{

    int mistakes = 0;
    int rightCharacters = 0;
    char character;
    char dash = '_';
    char *dashes = malloc(lengthOfWord * sizeof(char));
    char *alreadyUsed = malloc((lengthOfWord + 10) * sizeof(char));
    int numOfChar = 0;
    int lives = 10;
    printf("\n");

    for (int i = 0; i < lengthOfWord; i++)
    {
        dashes[i] = dash;
    }

    while (mistakes < 10)
    {
        printf("\n\n");
        printGallows(mistakes);
        printf("\n");
        for (int i = 0; i < lengthOfWord; i++)
        {
            printf("%c ", dashes[i]);
        }
        printf("\n\nYou have %d attempts", lives);
        printf("\n\n\n");

        char *alphabet = getCharacters();

        do
        {
            printf("\nEnter a character: ");
            printf("\n");

            scanf(" %c", &character);
        } while (characterOrNot(character) != true);

        character = tolower(character);

        bool characterUsed = true;

        while (characterUsed == true)
        {
            for (int i = 0; i < lengthOfWord + 10; i++)
            {
                if (alreadyUsed[i] != character)
                {
                    characterUsed = false;
                }
                else
                {
                    characterUsed = true;
                    printf("\nYou have already entered this letter. Try another one: ");
                    scanf(" %c", &character);
                    character = tolower(character);
                    break;
                }
            }
        }

        alreadyUsed[numOfChar] = character;

        int right = 0;
        for (int i = 0; i < lengthOfWord; i++)
        {
            if (mainWord[i] == character)
            {
                dashes[i] = mainWord[i];
                rightCharacters++;
                right++;
            }
        }

        if (right == 0)
        {
            mistakes++;
            lives--;
        };

        if (rightCharacters == lengthOfWord)
        {
            printf("%s", mainWord);
            printf("\n\nYou won!");
            printf("\n");
            break;
        }

        numOfChar++;
        printf("\nLetters used:");
        for (int i = 0; i < numOfChar; i++)
        {
            printf("%c ", alreadyUsed[i]);
        }
        printf("\n");
    }

    if (rightCharacters < lengthOfWord)
    {
        printf("\n\nYou lost!");
        printf("\nRiddle word:");
        printf("%s", mainWord);
        printf("\n");
        printGallows(mistakes);
    }
    free(dashes);
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
        int number = userNumber();
          
        switch (number)
        {
        case 3:
            word = lowercase("three.txt");
            break;

        case 4:
            word = lowercase("four.txt");
            break;

        case 5:
            word = lowercase("five.txt");

            break;

        case 6:
            word = lowercase("six.txt");
            break;
        case 7:
            word = lowercase("seven.txt");
            break;
        };

        int len = strlen(word);
        // char *word = lowercase("four.txt");
        // printf("\n%s -> %d", word, len);

        checkUserLetters(word, len);

        int gameRest;
        printf("\n\nIf you want to start the game again press 1\nif you want to end the game, press any other key\n"); // At the end of the game program asks user to replay or not

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

void printGallows(int mistakes)
{
    switch (mistakes)
    {
    case 1:
        printf("\n\n    ___||___");
        break;
    case 2:
        printf("\n\n       ||\n       ||\n    ___||___");
        break;

    case 3:
        printf("\n\n       ||\n       ||\n       ||\n       ||\n    ___||___");
        break;

    case 4:
        printf("\n\n       ||==\n       ||\n       ||\n       ||\n    ___||___");
        break;

    case 5:
        printf("\n\n       ||====\n       ||\n       ||\n       ||\n    ___||___");
        break;

    case 6:
        printf("\n\n       ||=======\n       ||\n       ||\n       ||\n    ___||___");
        break;

    case 7:
        printf("\n\n       ||=======\n       ||      |\n       ||\n       ||\n    ___||___");
        break;

    case 8:
        printf("\n\n       ||=======\n       ||      |\n       ||      0\n       ||\n    ___||___");
        break;

    case 9:
        printf("\n\n       ||=======\n       ||      |\n       ||      0\n       ||     /|%c\n    ___||___", 92);
        break;

    case 10:
        printf("\n\n       ||=======\n       ||      |\n       ||      0\n       ||     /|%c\n    ___||___  / %c", 92, 92);
        break;
    default:
        break;
    }
}