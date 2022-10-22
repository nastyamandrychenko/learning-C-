
#include <stdio.h>

int
odd_even (int *a)
{
  for (int i = 0; i < 10; i++)
    {
      if (a[i] % 2 == 0)
	{
	  printf ("even: %d\n", a[i]);
	}
    };
    
  for (int i = 0; i < 10; i++)
    {
      if (a[i] % 2 != 0)
	{
	  printf ("odd: %d\n", a[i]);
	}
    };
return 0;

};

int
main ()
{
  int a[10];

  printf ("enter numbers:\n");
  for (int i = 0; i < 10; i++)
    {
      scanf ("%d", &a[i]);
      a[i] =+ i;
    };
    
   odd_even (a);
  return 0;
}
