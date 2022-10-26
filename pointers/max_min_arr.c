#include <stdio.h>

void max_min(int *a, int max)
{
    int maxi = *a;
    int min = *a;
   for(int i = 0; i<max; i++){
if(a[i]>maxi){
    maxi = a[i];
};

if(a[i]<min){
    min = a[i];
};
}
printf("Max: %d, Min: %d", maxi, min);
};
  
  int main ()
  {
      int arr[10] = {1,2,3,4,5,6,7,8,9,10};
 max_min(arr, 10);
    return 0;
  }
