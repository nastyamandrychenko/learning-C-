#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>

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
    printf("%d", countWords);
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

//    for(int i = 0; i < countWords; i++){
//     printf("%s ", array[i]);
//    }

// initialize the seed of random in each run of the code to get a different random result by srand. 
// using time(NULL) to set a different seed of random through srand
    char *random; 
    srand(time(NULL));
    random = array[rand() % countWords]; 
    printf("\n%s",random); 

  //teardown
  for (x = 0; x < countWords; x++)
    free(array[x]);
  free(array);

    // printf("\n\n\t\tWELCOME TO HANGMAN!!!");
    // printf("\n\n\t\t\tRULES:");
    // printf("\n\t - Maximum 10 mistakes are allowed.");
	// printf("\n\t - All alphabet are in lower case.\n\n");
}