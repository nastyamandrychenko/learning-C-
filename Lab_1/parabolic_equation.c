#include <stdio.h>
#include <math.h>

int main()
{
     int a, b, c;
    printf("Enter your values to solve the equation ax2+bx+c=0x1x2: \n");
     printf("a:");
    scanf("%d", &a);
    printf("b:");
    scanf("%d", &b);
    printf("c:");
    scanf("%d", &c);
    int discriminant = b*b-4.*a*c;
     int x1 = (-b + sqrt(discriminant)) / (2.*a);
     int x2 = (-b - sqrt(discriminant)) / (2.*a);
    if (discriminant > 0) {
   
         printf("Result: \n x1:%d \n x2:%d",x1,x2);
    }else if(discriminant == 0){
        x1 = x2 = -b / (2 * a);
        printf("x1 = x2 = %d;", x1);
    }else{
        printf("There are no solutions");
    };
   
   return 0;
}

