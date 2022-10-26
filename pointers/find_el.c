#include <stdio.h>

int find(int *a, int items, int number){
    int save = -1;
     for(int i = 0; i<items; i++){
         if(a[i] == number){
          save = i;
         }
     }
     if(save == -1){
         return -1;
     }else{
         return save;
     }
 }
 
int main()
{
 int number = 133;
 int a[10] = {1,2,3,4,5,6,55,77,45,101};
int findel = find(a,10,number);
if(findel != -1){

    printf("Number[%d]: %d",  findel, number);
}else{
        printf("No");
}
    return 0;
}

