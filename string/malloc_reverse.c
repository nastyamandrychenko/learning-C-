#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *str = malloc(sizeof(char) * 100);
    for(int i = 0; i<100;i++){
        *(str+i) = ' ';
    };
    scanf("%s", str);
    for(int i = strlen(str)-1; i>=0; i--){
        printf("%c", *(str+i));
    }
    free(str);

    return 0;
}
