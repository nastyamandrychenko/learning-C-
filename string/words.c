#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int below(char *str){
   int i,j;
   for(i=0;i<strlen(str);i++){
       if(str[i] ==' '){
        printf("\n");
       for(j=i; j<strlen(str); j++){
            str[j] = str[j+1];
        }
    }
    printf("%c", str[i]);
   }
}


int main(){
    char s[100];
     fgets(s, sizeof(s), stdin);;
   below(s);
    return 0;
}

