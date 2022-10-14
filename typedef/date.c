
#include <stdio.h>

typedef struct Date
{
  int year, month, day;
} Date;

typedef struct Competitor
{
  char name[31];
  Date birth;
  int rank;
} Competitor;


int
main ()
{
  Competitor competitors[5] = {
    {"Am, Erica", {1984, 5, 6}, 1},
    {"Abnorm, Al", {1982, 9, 30}, 3},
    {"Pri, Mary", {1988, 8, 25}, 2},
    {"Duck, Ling", {1979, 6, 10}, 5},
    {"Mac, Donald", {1992, 4, 5}, 4},
  };
   /* name of competitor 0 - printf %s */
  printf ("%s",competitors[0].name);
  /* rank of competitor 2 */
  printf ("\n%d",competitors[2].rank);
  
//   void Date_print(competitors[4].birth);

    /* birth date of competitor 4, use the given function */
    
/* the first letter of the name of competitor 1 (a string is an array of characters) */
    int count = 0;
    for(int i = 0;competitors[1].name[i]!='\0';i++){
        count++;
    }
    printf("\n%c",competitors[1].name[0]);
    
    /* is competitor 1 among the best three? yes/no, may use ?: operator */
    competitors[1].rank>=3?printf("\nCompetitor 1 among the best three"):printf("\nCompetitor 1 is not among the best three");
    /* is competitor 4 faster than competitor 3? */
    competitors[4].rank>competitors[3].rank?printf("\nCompetitor 3 is faster"):printf("\nCompetitor 4 is faster");
    
    /* was competitor 1 born in the same year as competitor 2? */
    competitors[1].birth.year==competitors[2].birth.year?printf("\nCompetitor 1 born in the same year as competitor 2"):printf("\nCompetitor 1 and competitor 2 were born in different years");
    

    /* complete the Competitor_print() function,
     * then print all data of competitor 1 */
      Competitor_print (competitors[1]);
    
    /* at last print all data of all competitors. */
    for(int i=0;i<5;i++){
       printf("\n%s:%d/%d/%d Rank:%d",competitors[i].name, competitors[i].birth.day,competitors[i].birth.month, competitors[i].birth.year,competitors[i].rank);
    
    };
    
    return 0;
}



void
Competitor_print (Competitor c)
{
    
 printf("\n%s, %d/ %d/ %d/ %d\n", c.name, c.birth.year, c.birth.month, c.birth.day, c.rank);
  
}


