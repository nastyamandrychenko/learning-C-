#include <stdio.h>

int main()
{
     int x;
     int y;
      printf("Enter your numbers to print the numbers from x to y\n You can enter any number from 1 to 20\n");
      printf("x:");
      scanf("%d", &x);
      printf("y:");
      scanf("%d", &y);
    int number;
    if(x>0 && y<=20){
        for(x; x<=y; x++){
         number = x;
         printf("%d \t", number);
     };
    }else{
        
        printf("You must enter any number from 1 to 20!");
        
    };
     

    return 0;
}

