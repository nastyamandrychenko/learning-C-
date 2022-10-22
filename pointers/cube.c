
#include <stdio.h>

void volume_area(int *a, int *b){
    int volume = (*a)*(*a)*(*a);
    *a = 6*(*a)*(*a);
      *b = volume;
    
} 

int main(){
    
     int a,b;
    printf("Side: ");
    scanf("%d",&a);
     
        volume_area(&a,&b); 
    printf("Area: %d\nVolume:%d\n",a,b);
    return 0;
}


