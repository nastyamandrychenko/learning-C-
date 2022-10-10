#include <stdio.h>

int main()
{
    int product = 1;
    int n = 10;
    while(n >= 2){
        product = product*n;
        n--;
       
    };
    printf("%d\n", product);
    

    return 0;
}

