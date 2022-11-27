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
char *randomWordFromFile(char *nameOfFile)
{
    int x;
    char word[30];
    // open file
    FILE *file;
    file = fopen(nameOfFile, "r");

    // check if the file is found
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

    // create dynamic array for words from the file
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

    // call the getRandomWord() function, which finds a random word from an array
    char *wordWeNeed = getRandomWord(array, countWords);

    // free dynamic array
    free(array);

    return wordWeNeed;
}

// function converts letters to lower case
char *lowerCase(char *nameOfFile)
{
    char *word = randomWordFromFile(nameOfFile);
    for (int i = 0; word[i]; i++)
    {
        word[i] = tolower(word[i]);
    }
    return word;
}