
#include <stdio.h>

int search(int *a, int number)
{
   int i = 0;
   int *point;
    for(point=a; i<10; point++, i++)
    {
        if((*point)==number)
        {
             return point;		 
        }
    }
    
      return 0;
};

int main()
{
    int a[10] = {1,2,3,4,5,6,7,8,9,11};
    int number = 2;
    
    int p = search(a,number);
    
    if (p)
    {
        
    printf("\nfound, memory address = %d", p);
    }
    else
    {
       printf("\nnot found");
    }
    return 0;
}


