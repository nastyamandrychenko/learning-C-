#include <stdio.h>

int main()
{
  int array[10] = {1,2,3,4,5,6,7,8,9,10};  
  int i, firstArray, newArray;
  for(int j=0; j<10;j++){
      firstArray = array[0];
  for(i=0; i<10;i++){
      
     printf("%d ", array[i]);
    array[i]=array[i+1];
  }
     array[i-1] = firstArray;
      printf("\n");
  };
    return 0;
}
