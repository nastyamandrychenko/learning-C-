#include <stdio.h>
#include <math.h>

int main()
{
    int x1, x2, y1, y2;
    printf("Enter your values: \n");
    printf("x1:");
    scanf("%d", &x1);
    printf("y1:");
    scanf("%d", &y1);
    printf("x2:");
    scanf("%d", &x1);
    printf("y2:");
    scanf("%d", &y2);
    
    int result = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    
    printf("Result: %d", result);
    

    return 0;
}

