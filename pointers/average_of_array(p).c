
#include <stdio.h>

float
avgarray (int *a, int max)
{

  float average = 0;
	
for(int i = 0; i<max; i++){
    average = average + a[i];
}
return average = average/max;
};
  
  int main ()
  {
      int arr[10] = {1,2,3,4,5,6,7,8,9,10};
   float avrgarr = avgarray(arr, 10);
 printf("%f", avrgarr);
    return 0;
  }
