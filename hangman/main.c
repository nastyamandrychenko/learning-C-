#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

char* getRandomWord( char **array, int countWords){
// initialize the seed of random in each run of the code to get a different random result by srand. 
// using time(NULL) to set a different seed of random through srand
    char *random; 
    srand(time(NULL));
    random = array[rand() % countWords]; 
    // printf("\n%s",random); 
    return random;
};

int main(void)
{
    int countWords, x;
    char word[30];
    // open our file with words
	FILE *file;    
	file = fopen("words.txt", "r");

	if(file== NULL)
	{
		printf("hangmanwords.txt couldn't found");
		return 0;
	}
    // count how many words in our file
   while ( fscanf(file, "%s", word) == 1){
    countWords++;
    }

   // rewind() function repositions the file pointer associated with stream to the beginning of the file
    rewind(file);

    char **array = malloc(countWords * sizeof(char*));

    x = 0;

    // fill dynamic array with words
    while ( fscanf(file, "%s", word) == 1) {
  // strdup() - duplicate a string
    array[x] = strdup(word);
    x++;
    }
    
   fclose(file);

     printf("\n\t\tWELCOME TO HANGMAN!!!");
    printf("\n\n\t\t\tRULES:");
    printf("\n\t - Maximum 10 mistakes are allowed.");
	printf("\n\t - All alphabet are in lower case.\n");
    
    printf("\n\n\t\t\tMENU");
    printf("\n\t How many letters will be in the word:\n\t Write a number from 2 to 5\n");

    int numberOfLetters;
    // the user enters how many letters he wants in the word
    scanf("%d", &numberOfLetters);
    // check that the entered value is not greater than 5 and not less than 2
   while(numberOfLetters > 5 || numberOfLetters < 2){
     printf("\n\t Write a number from 2 to 5!\n");
     scanf("%d", &numberOfLetters);
   }
    

   while(strlen( getRandomWord(array, countWords)) != numberOfLetters){
    getRandomWord(array, countWords);
   }

   printf("\n%s", getRandomWord(array, countWords));

  //teardown
  for (x = 0; x < countWords; x++)
    free(array[x]);
  free(array);

 
}