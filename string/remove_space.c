#include <stdio.h>
#include <string.h>

void trim(char *str, char *result){
    int firstPosition = 0;
  int lastPosition = strlen (str);
  while (str[firstPosition] == ' ')
    {
      firstPosition++;
    };
  while (str[lastPosition] == ' ')
    {
      lastPosition--;
    };
  int j = 0;
  for (int i = firstPosition; i <= lastPosition; i++)
    {
      result[j] = str[i];
      j++;
    }
  printf ("%s", result); 
}

int
main ()
{
  char str[100];
  printf("Enter your sentence:\n");
//   gets(str);
  fgets(str, sizeof(str), stdin);
  char result[100] = "";
  trim(str,result);

  return 0;
}

