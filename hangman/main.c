#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#define __STDC_WANT_LIB_EXT2__ 1
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
    rewind(file);
    char **array = malloc(countWords * sizeof(char*));
    x = 0;
    while ( fscanf(file, "%29s", word) == 1) {
    array[x] = strdup(word);
    x++;
    }
   fclose(file);
   for(int i = 0; i < countWords; i++){
    printf("%s ", array[i]);
   }
  for (x = 0; x < countWords; x++)
    free(array[x]);
  free(array);
    // printf("\n\n\t\tWELCOME TO HANGMAN!!!");
    // printf("\n\n\t\t\tRULES:");
    // printf("\n\t - Maximum 10 mistakes are allowed.");
	// printf("\n\t - All alphabet are in lower case.\n\n");
}