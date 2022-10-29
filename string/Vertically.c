#include <stdio.h>
#include <string.h>
int main () {
 char s[100];
 printf("Enter string:\n");
 scanf("%s", s);
 
 for (int i = 0;i<strlen(s); i++) {
      printf("%c\n", s[i]);
  }
   return 0;
}

