#include <stdio.h>
#include <string.h>

  int doubleSpace(char *str){
    int i;
for (i = 0;i<strlen(str); i++) {
    
    if(str[i] ==' '){
        printf(" ");
       
    }
    printf("%c", str[i]);
  }
    }
int main()
{
    char str[100];
     fgets(str, sizeof(str), stdin);
    doubleSpace(str);
  
    return 0;
}

