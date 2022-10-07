
#include <stdio.h>


int main()
{
 int array[12] = {12,45,197,12,55,170,14,30,180,0,0,0};
 int maxSpeed[24] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
 for(int i = 0; i<12; i=i+3){
     if(array[i]==0 && array[i+1]==0 && array[i+2]==0){
         break;
     }
     int hour = array[i];
     int speed = array[i+2];
  
    if(maxSpeed[hour]<speed){
        maxSpeed[hour]=speed;
    };
    
    
 };
 for(int j=0; j<24;j++){
        if(maxSpeed[j]>0){
            
            printf("%d:00-%d:59-%d\n", j,j,maxSpeed[j]);
        }
 
    };
 
 
 
    return 0;
}
