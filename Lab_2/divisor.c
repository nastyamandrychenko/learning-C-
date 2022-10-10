#include <stdio.h>
#include<conio.h>  

int main()
{
    int num;
    int i = 1;
	printf("Integer: \n");
	scanf("%d", &num);
	printf("Divisor of %d are: \n", num);
	for(i; i < num; i++) {
		if((num%i) == 0){
			printf("%d\n", i);
		}
	};

  int sum = 0;
  int x = 1;

  while (x < num)
    {
      if (num % x == 0)
	sum = sum + x;
      x++;
    }
  if (sum == num){
    printf ("\n%d is Perfect Number\n", num);}
  else{
    printf ("%d is not a Perfect Number\n", num);};

    return 0;
}

