#include <stdio.h>

int main()
{
    double e = 0;
    double factorial = 1;
    int i = 1;
    for(i; i < 20; i = i+1){
        e = e + 1/factorial;
        factorial = factorial*i;
    }
    printf("e = %f", e);
    
    return 0;
}

