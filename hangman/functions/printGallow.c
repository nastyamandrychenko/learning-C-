// a function that prints the appropriate part of the gallows, depending on the number of errors made by the user
void printGallows(int mistakes){
    switch (mistakes)
    {
    case 1:
         printf("\n\n\n\n\n    ___||___");
        break;
    case 2:
     printf("\n\n\n\n\n       ||\n       ||\n    ___||___");
     break;

      case 3:
      printf("\n\n\n\n\n       ||\n       ||\n       ||\n       ||\n    ___||___");
     break; 

     case 4:
        printf("\n\n\n\n\n       ||==\n       ||\n       ||\n       ||\n    ___||___");
     break;

    case 5:
       printf("\n\n\n\n\n       ||====\n       ||\n       ||\n       ||\n    ___||___");
     break;

    case 6:
    printf("\n\n\n\n\n       ||=======\n       ||\n       ||\n       ||\n    ___||___");
     break;

    case 7:
     printf("\n\n\n\n\n       ||=======\n       ||      |\n       ||\n       ||\n    ___||___");
     break;

    case 8:
     printf("\n\n\n\n\n       ||=======\n       ||      |\n       ||      0\n       ||\n    ___||___");
     break;

    case 9:
    printf("\n\n\n\n\n       ||=======\n       ||      |\n       ||      0\n       ||     /|%c\n    ___||___",92);
     break;

    case 10:
     printf("\n\n\n\n\n       ||=======\n       ||      |\n       ||      0\n       ||     /|%c\n    ___||___  / %c",92,92);
     break;
    default:
        break;
    }
}