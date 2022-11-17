#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

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
    char word[10];
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
    for (x = 0; x < countWords; x++)
        free(array[x]);
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

void checkUserLetters(char *mainWord, int lengthOfWord)
{

    int mistakes = 0;
    int rightCharacters = 0;
    char character;
    char dash = '_';
    char *dashes = malloc(lengthOfWord * sizeof(char));
        printf("\n");
  for (int i = 0; i < lengthOfWord; i++)
    {
        // printf("%c ", wordBeforeGuess[i]);
        dashes[i] = dash;
        printf("%c ", dashes[i]);
    }
    while(mistakes < 3){

    printf("\n");
    printf("\nEnter a character: ");
    scanf(" %c", &character);
    character = tolower(character);
 
    int right = 0;
    for (int i = 0; i < lengthOfWord; i++)
    {
        if (mainWord[i] == character)
        {
            dashes[i] = mainWord[i];
            rightCharacters++;
            right++;
        }
        printf("%c ", dashes[i]);
    }


    if (right == 0)
    {
        mistakes++;
    };

    if(rightCharacters == lengthOfWord){
       printf("\n\nYOU WON!");
      break;
    }

    
    }
 


     if(rightCharacters < lengthOfWord){
    printf("\n\nYOU LOST!");	
    }
    free(dashes);
};

int main(void)
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

    default:
        break;
    };
    int len = strlen(word);
    // char *word = lowercase("four.txt");
    printf("\n%s -> %d", word, len);

    checkUserLetters(word, len);
}