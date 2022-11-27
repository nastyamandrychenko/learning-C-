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