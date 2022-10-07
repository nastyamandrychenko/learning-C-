

#include <stdio.h>

int main()
{
    int array [10] = {25, 69, 54, 8, 77, 6, 29, 10, 3, 98};
 int i;

 int smallestNumber = array[0];
 
   for (i = 0; i < 10; i++) {
       for(int j = 0; j<10; j++){
      if (array[j] < smallestNumber) {
         smallestNumber = array[j];
      }
       };
       
       int arrayCount;
       arrayCount = array[i];
     if(array[i] == smallestNumber){
         printf ("[%d] = %d[MIN] ",i, arrayCount);
     }else{
         printf ("[%d] = %d ",i, arrayCount);
     };
   }

   printf("\nThe smallest number: %d", smallestNumber);

    return 0;
}

